// Fill out your copyright notice in the Description page of Project Settings.


#include "GHMoveComponent.h"

#include <ios>

#include "GHCharacter.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

DEFINE_LOG_CATEGORY(LogMoveComp);
UGHMoveComponent::UGHMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UGHMoveComponent::TickComponent(float DeltaTime, ELevelTick Tick, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, Tick, ThisTickFunction);
	if(bIsMoving)
	{
		Moving();
	}
}

void UGHMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	SpawnHexActor = Cast<AGHSpawnGrid>(UGameplayStatics::GetActorOfClass(GetWorld(),SpawnGridActor));
	CharacterOwner = Cast<ACharacter>(GetOwner());
	
}
// This func need to can character move 
void UGHMoveComponent::StartCharacterMove()
{
	if(SpawnHexActor)
	{
		SpawnHexActor->OnClickToMove.AddDynamic(this, &ThisClass::SetMoving);
		SpawnHexActor->OnBeginMouseOverlap.AddDynamic(this, &ThisClass::ShowPath);
		SpawnHexActor->OnEndMouseOverlap.AddDynamic(this, &ThisClass::ClearWay);
	}
	APlayerController* Controller = Cast<APlayerController>(CharacterOwner->GetController());
	if(Controller)
	{
		FVector PosLocation;
		FVector PosDirection;
		Controller->DeprojectMousePositionToWorld(PosLocation,PosDirection);
		
		FVector EndVector = PosLocation +PosDirection*10000;
		FHitResult HitResult;
		GetWorld()->LineTraceSingleByChannel(HitResult,PosLocation,EndVector,ECollisionChannel::ECC_Visibility);
		if(AGHHexActor* Hex = Cast<AGHHexActor>(HitResult.Actor))
		{
			if(ActorLocationHex)
			{
				ShowPath(ActorLocationHex,Hex);
			}
		}
	}
}

void UGHMoveComponent::StopCharacterMove()
{
	if(SpawnHexActor)
	{
		SpawnHexActor->OnClickToMove.RemoveDynamic(this, &ThisClass::SetMoving);
		SpawnHexActor->OnBeginMouseOverlap.RemoveDynamic(this, &ThisClass::ShowPath);
		SpawnHexActor->OnEndMouseOverlap.RemoveDynamic(this, &ThisClass::ClearWay);
	}
	ClearWay(nullptr);
}

void UGHMoveComponent::SetMoving(AGHHexActor* HexEnd)
{
	bIsMoving=true;
}
//Call int tick to move character on the path
void UGHMoveComponent::Moving() 
{
	if(!HexWayCache.IsValidIndex(0))
	{
		if(HexWayArray.IsValidIndex(0))
		{
			GetPositionCharacter()->CharacterExitHex();
			HexWayCache=HexWayArray;
		}
		else
		{
			UE_LOG(LogMoveComp,Warning, TEXT("FUNC Moving HexWayArray not valid"));
			return;
		}
	}
	FVector Origin;
	FVector BoxEn;
	UKismetSystemLibrary::GetActorBounds(HexWayCache[0], Origin, BoxEn);

	float DistanceToTarget = (Origin-CharacterOwner->GetActorLocation()).Size2D();
	float DistanceRange = 10;
	if(DistanceToTarget<=DistanceRange)
	{
		HexWayCache.RemoveAt(0);
	}
	const FVector Direction = (Origin - CharacterOwner->GetActorLocation()).GetSafeNormal2D();
	const FVector ActorDirection = GetOwner()->GetActorRotation().Vector().GetSafeNormal2D();
	const float Scale = FMath::Clamp(FVector::DotProduct(ActorDirection, Direction), 0.5f, 1.0f);
	Cast<APawn>(GetOwner())->AddMovementInput(Direction, Scale);
	if(!HexWayCache.IsValidIndex(0))
	{
		if(HexWayArray.IsValidIndex(0))
		{
			AGHHexActor* LastHexInPath = HexWayArray.Last();
			ClearWay(nullptr);
			ShowPath(GetPositionCharacter(),LastHexInPath);
		}
		ActorLocationHex = GetPositionCharacter();
		GetPositionCharacter()->SetCharacterOnHex();
		bIsMoving = false;
		StopCharacterMove();
	}
}



void UGHMoveComponent::Init()
{
	if(ActorLocationHex==nullptr && GetPositionCharacter()!=nullptr)
	{
		SetActorLocation(GetPositionCharacter());
		GetPositionCharacter()->SetCharacterOnHex();
	}
	else
	{
		UE_LOG(LogMoveComp,Warning, TEXT("FUNC Init CharacterOwner is null or ActorLocationHex!=null"));
	}
}

void UGHMoveComponent::SetActorLocation(AGHHexActor* NewLocation)
{
	if(NewLocation != nullptr)
	{
		ActorLocationHex=NewLocation;
		FVector Origin;
		FVector BoxEn;
		float SphereRadius;
		UKismetSystemLibrary::GetComponentBounds(ActorLocationHex->GetMesh(), Origin, BoxEn, SphereRadius);
		Origin.Z = Origin.Z+CharacterOwner->GetCapsuleComponent()->GetScaledCapsuleHalfHeight();
		CharacterOwner->SetActorLocation(Origin);
	}
	else
	{
		UE_LOG(LogMoveComp,Warning, TEXT("FUNC SetActorLocation NewLocation is null"));
	}
}

void UGHMoveComponent::ShowPath(AGHHexActor* StartHex, AGHHexActor* HexEnd)
{
	/*if(!HexEnd->IsClear())
	{
		return;
	}*/
	for(const auto Hex:GetPath(StartHex,HexEnd))
	{
		Hex->ChangeMaterial(EMaterialToHex::Way);
	}
}

void UGHMoveComponent::FindPath(AGHHexActor* StartHex, AGHHexActor* HexEnd)
{
	if(HexEnd == nullptr || StartHex == HexEnd || HexEnd == ActorLocationHex || StartHex ==nullptr && ActorLocationHex == nullptr)
	{
		UE_LOG(LogMoveComp,Warning, TEXT("FUNC FindPath HexEnd == nullptr or StartHex == HexEnd or HexEnd == ActorLocationHex or StartHex ==nullptr && ActorLocationHex == nullptr"));
		return;
	}
	
	if(StartHex ==nullptr)
	{
		StartHex = ActorLocationHex;
	}
	
	TArray<AGHHexActor*> OpenHex;
	TArray<AGHHexActor*> ClosedHex;
	
	AGHHexActor* CurrentHex;
	
	OpenHex.Add(StartHex);
	
	while (OpenHex.Num()>0)
	{
		CurrentHex = OpenHex[0];

		for(int32 i =0; i<OpenHex.Num();i++)
		{
			if(OpenHex[i]->FCost()<CurrentHex->FCost() || OpenHex[i]->FCost() == CurrentHex->FCost() && OpenHex[i]->HCost < CurrentHex->HCost)
			{
				CurrentHex = OpenHex[i];
			}
		}
		OpenHex.Remove(CurrentHex);
		ClosedHex.Add(CurrentHex);

		if(CurrentHex == HexEnd){RetracePath(StartHex,HexEnd); return;}
		for(const auto OneFriend : CurrentHex->FriendsHexArr)
		{
			if(!OneFriend->IsClear() || ClosedHex.Find(OneFriend)!=INDEX_NONE)
			{
				continue;
			}
			int32 NewMovementCostToNeighbour = CurrentHex->GCost + CurrentHex->GetDistanceToHex(OneFriend);
			if(NewMovementCostToNeighbour< CurrentHex->GCost || OpenHex.Find(OneFriend)==INDEX_NONE)
			{
				OneFriend->GCost = NewMovementCostToNeighbour;
				OneFriend->HCost = FMath::RoundToInt(OneFriend->GetDistanceToHex(HexEnd));
				OneFriend->Parent=CurrentHex;
				if(OpenHex.Find(OneFriend)==INDEX_NONE)
				{
					OpenHex.Add(OneFriend);
				}
			}
		}
	}
}
void UGHMoveComponent::RetracePath(AGHHexActor* Start, AGHHexActor* End)
{
	//TArray<AGHHexActor*> Path;
	AGHHexActor* CurrentHex = End;
	
	while(CurrentHex!=Start)
	{
		HexWayArray.Add(CurrentHex);
		CurrentHex = CurrentHex->Parent;
	}
	Algo::Reverse(HexWayArray);
}

TArray<AGHHexActor*>& UGHMoveComponent::GetPath(AGHHexActor* StartHex, AGHHexActor* HexEnd)
{
	FindPath(StartHex,HexEnd);
	return HexWayArray;
}

AGHHexActor* UGHMoveComponent::GetPositionCharacter()
{
	if(CharacterOwner==nullptr)
	{
		UE_LOG(LogMoveComp,Warning, TEXT("FUNC GetPositionCharacter Character is null"));
		return nullptr;
	}
	FVector StartVector;
	FVector BoxEn;
	float SphereRadius;
	UKismetSystemLibrary::GetComponentBounds(CharacterOwner->GetCapsuleComponent(),StartVector, BoxEn, SphereRadius);
	FVector EndVector = FVector::DownVector*100 + StartVector;
	FCollisionQueryParams Params;
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByChannel(HitResult,StartVector,EndVector,ECollisionChannel::ECC_Visibility);
	if(const auto Actor = Cast<AGHHexActor>(HitResult.Actor))
	{
		return Actor;
	}
	UE_LOG(LogMoveComp, Warning, TEXT("FUNC GetPositionCharacter HitResult.Actor!=HEX"));
	return nullptr;
}

void UGHMoveComponent::ClearWay(AGHHexActor* ActorEnd)
{
	for(auto hex: HexWayArray)
	{
		hex->ChangeMaterial(EMaterialToHex::Clear);
	}
	HexWayArray.Empty();
}
