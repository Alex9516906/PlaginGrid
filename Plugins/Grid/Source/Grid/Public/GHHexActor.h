#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GHHexActor.generated.h"


class UBoxComponent;
class AGHHexActor;
class USphereComponent;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnClickToMove, AGHHexActor*, ActorEnd);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBeginMouseOverlap, AGHHexActor*, ActorStart, AGHHexActor*,ActorEnd);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEndMouseOverlap, AGHHexActor*, ActorEnd);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInitSpawn);
UENUM()
enum EMaterialToHex
{
	Way,
	OverlapMouse,
	Player,
	Movable,
	Clear
};
UCLASS()
class GRID_API AGHHexActor : public AActor
{
	GENERATED_BODY()

public:
	AGHHexActor();

protected:
	virtual void BeginPlay() override;

	TArray<FVector2D> CoordsEven{{0,1}, {-1,0},{-1,-1}, {0,-1},{1,-1}, {1,0}};
	TArray<FVector2D> CoordsOdd{{0,1}, {-1,1},{-1,0}, {0,-1},{1,1}, {1,0}};
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,  Category = "Mesh")
	UStaticMeshComponent* MeshGrid;

	UPROPERTY(EditAnywhere, Category = "MeshColor")
	TSoftObjectPtr<UMaterial> OnChosenMaterial;

	UPROPERTY(EditAnywhere, Category = "MeshColor")
	TSoftObjectPtr<UMaterial> StandardMaterial;

	UPROPERTY(EditAnywhere, Category = "MeshColor")
	TSoftObjectPtr<UMaterial> PlayerOnHexMaterial;

	UPROPERTY(EditAnywhere, Category = "MeshColor")
	TSoftObjectPtr<UMaterial> MovableMaterial;
	
	bool bOnCharacter;
	
public:
	FOnClickToMove OnClickToMove;
	
	FOnEndMouseOverlap 	OnEndMouseOverlap;
	
	FOnBeginMouseOverlap OnBeginMouseOverlap;
	
	FInitSpawn InitSpawn;
	
	int32 CoordX;
	
	int32 CoordY;
	
	TArray<AGHHexActor*> FriendsHexArr;
	
	UFUNCTION()
	void BeginOverlapCursor(UPrimitiveComponent* TouchedComponent);
	
	UFUNCTION()
	void EndOverlapCursor(UPrimitiveComponent* TouchedComponent);
	
	UFUNCTION()
	void OnClickMouse(UPrimitiveComponent* TouchedComponent,FKey ButtonPressed);
	
	virtual void FindFriends(const TArray<AGHHexActor*>& Array);
	
	float WhatDistanceToHexEnd(AGHHexActor* EndHex);
	
	void ChangeMaterial(EMaterialToHex NeedSetMaterial);

	UStaticMeshComponent* GetMesh() const {return MeshGrid;}

	void SetCharacterOnHex();

	void CharacterExitHex();

	void CheckFloor();
};
