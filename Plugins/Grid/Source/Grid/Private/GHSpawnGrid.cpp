
#include "GHSpawnGrid.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

AGHSpawnGrid::AGHSpawnGrid()
{
	PrimaryActorTick.bCanEverTick = false;
	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	SetRootComponent(SceneComponent);
}

void AGHSpawnGrid::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	DrawDebugHexOnConstruct();
}

void AGHSpawnGrid::BeginPlay()
{
	Super::BeginPlay();
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
	for(const auto ElemArray:HexArray)
	{
		ElemArray->FindFriends(HexArray);
	}
}

void AGHSpawnGrid::DrawDebugHexOnConstruct()
{
	UKismetSystemLibrary::FlushPersistentDebugLines(this);
	const auto StaticMeshPtr =HexMesh.LoadSynchronous();
	
	if(!IsValid(StaticMeshPtr)) {return;}
	
	const auto Box = StaticMeshPtr->GetBounds().BoxExtent;
	for(int i=0; i<SizeX; i++)	
	{
		for(int j = 0; j<SizeY; j++)
		{
			const float xMylti = Box.Y*1.5;
			const float yMylti= Box.X*2;
			const float x = GetActorLocation().X+ (i * xMylti);
			const float y_a = GetActorLocation().Y+ (j * yMylti);
			const float y_b = (GetActorLocation().Y+ (j * yMylti))+Box.Y*0.85;
			const FVector a(x, y_a, GetActorLocation().Z);
			const FVector b(x, y_b, GetActorLocation().Z);

			const FVector Centre = UKismetMathLibrary::SelectVector(a, b, i%2==0);
			DrawHex(Centre,Box);
		}
	}
	
}

void AGHSpawnGrid::DrawHex(const FVector& Centre, const FVector& BoxBounds) const
{
	
	float LocationZ = GetActorLocation().Z;
	for(int32 i =0; i<=5; i++)
	{
		FVector2D VectorStart = GetPointHex(BoxBounds.Y,Centre, i);
		FVector2D VectorEnd = GetPointHex(BoxBounds.Y,Centre, i+1);
		DrawDebugLine(GetWorld(),FVector(VectorStart.X,VectorStart.Y,LocationZ),
			FVector(VectorEnd.X,VectorEnd.Y,LocationZ),FColor::Green, false,100000.f,0,5.f);
	}
}

FVector2D AGHSpawnGrid::GetPointHex(const float Size, FVector Centre, int I)
{
	const float AngleDeg = I*60;
	const float AngleRad = AngleDeg* (PI/180);
	return FVector2D(FMath::Cos(AngleRad)*Size,FMath::Sin(AngleRad)*Size) + FVector2D(Centre.X,Centre.Y);
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




