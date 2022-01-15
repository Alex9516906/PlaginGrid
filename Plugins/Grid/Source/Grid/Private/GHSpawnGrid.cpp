
#include "GHSpawnGrid.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

AGHSpawnGrid::AGHSpawnGrid()
{
	PrimaryActorTick.bCanEverTick = false;
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);
	//SpawnGridInConstruct();
}

void AGHSpawnGrid::SpawnGridInConstruct()
{
	const auto Mesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("/Grid/Mesh/hexMesh.hexMesh"));
	if(!Mesh.Succeeded())
	{
		return;
	}
	ArrayHexComponents.Reserve(SizeX*SizeY);
	for(int i=0; i<SizeX; i++)
	{
		for(int j = 0; j<SizeY; j++)
		{
			
			HexComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName(FString::Printf(TEXT("x=%d y=%d"), i, j)));
			HexComponent->SetStaticMesh(Mesh.Object);
			HexComponent->SetupAttachment(SceneComponent);
			HexComponent->SetWorldLocation(CalculateSpawnTransform(i,j));
			ArrayHexComponents.Emplace(HexComponent);
		}
	}
}

void AGHSpawnGrid::BeginPlay()
{
	Super::BeginPlay();
	/*HexComponent = nullptr;
	for(auto hexComp:ArrayHexComponents)
	{
		if(HexComp!=nullptr)
		hexComp->DestroyComponent();
	}
	ArrayHexComponents.Empty();*/
	HexSpawn();
	FindFriendsToAllHex();
}

void AGHSpawnGrid::HexSpawn()
{
	if(HexActorClass==nullptr)
	{
		return;
	}
	FActorSpawnParameters spawnParam;
	spawnParam.Owner = this;
	spawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;
	FRotator rotationHex(0,90,0);
	for(int i=0; i<SizeX; i++)
	{
		for(int j = 0; j<SizeY; j++)
		{
			Hex = GetWorld()->SpawnActor<AGHHexActor>(HexActorClass, GetActorLocation(), rotationHex,  spawnParam);
			Hex->SetActorLocation(CalculateSpawnTransform(i, j));
			Hex->CoordX = j;
			Hex->CoordY = i;
			Hex->CheckFloor();
			if(!Hex->IsPendingKill())
			{
				Hex->CheckObject();
				Hex->OnClickToMove.AddDynamic(this, &ThisClass::NeedMove);
				Hex->OnBeginMouseOverlap.AddDynamic(this, &ThisClass::BeginOverlap);
				Hex->OnEndMouseOverlap.AddDynamic(this, &ThisClass::EndOverlap);
				HexArray.Add(Hex);
			}
		}
	}
	HexArray[0]->InitSpawn.AddDynamic(this, &ThisClass::Init);
}

void AGHSpawnGrid::Init()
{
	if(InitSpawn.IsBound())
	{
		InitSpawn.Broadcast();
	}
}

FVector AGHSpawnGrid::CalculateSpawnTransform(int i, int j)
{
	FVector Origin;
	FVector BoxEn;
	float SphereRadius;
	float yMylti;
	float xMylti;
		if(HexComponent!=nullptr)
		{
			UKismetSystemLibrary::GetComponentBounds(HexComponent, Origin, BoxEn, SphereRadius);
			xMylti =  BoxEn.X*1.75;
			yMylti = BoxEn.Y*1.7;
			
			const float x = GetActorLocation().X+ (i * xMylti);
			const float y_a = GetActorLocation().Y+ (j * yMylti);
			const float y_b = (GetActorLocation().Y+ (j * yMylti))+BoxEn.Y*0.85;
			const FVector a(x, y_a, GetActorLocation().Z);
			const FVector b(x, y_b, GetActorLocation().Z);
			
			return UKismetMathLibrary::SelectVector(a, b, i%2==0);
		}
		UKismetSystemLibrary::GetComponentBounds(Hex->GetMesh(), Origin, BoxEn, SphereRadius);
		xMylti = BoxEn.X*1.5;
		yMylti= BoxEn.Y*2;
		const float x = GetActorLocation().X+ (i * xMylti);
		const float y_a = GetActorLocation().Y+ (j * yMylti);
		const float y_b = (GetActorLocation().Y+ (j * yMylti))+BoxEn.Y;
		const FVector a(x, y_a, GetActorLocation().Z);
		const FVector b(x, y_b, GetActorLocation().Z);
	
		return UKismetMathLibrary::SelectVector(a, b, i%2==0);
}

void AGHSpawnGrid::FindFriendsToAllHex()
{
	for(auto elemArray:HexArray)
	{
		elemArray->FindFriends(HexArray);
	}
}

void AGHSpawnGrid::NeedMove(AGHHexActor* ActorEnd)
{
	OnClickToMove.Broadcast(ActorEnd);
}
void AGHSpawnGrid::EndOverlap(AGHHexActor* ActorEnd)
{
	OnEndMouseOverlap.Broadcast(ActorEnd);
}

void AGHSpawnGrid::BeginOverlap(AGHHexActor* ActorStart, AGHHexActor* ActorEnd)
{
	if(OnBeginMouseOverlap.IsBound())
	{
		OnBeginMouseOverlap.Broadcast(ActorStart, ActorEnd);
	}
	
}




