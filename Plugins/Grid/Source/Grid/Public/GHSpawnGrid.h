// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GHHexActor.h"
#include "GHSpawnGrid.generated.h"

UCLASS()
class GRID_API AGHSpawnGrid : public AActor
{
	GENERATED_BODY()
	
public:	

	AGHSpawnGrid();

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void  HexSpawn();
	
	FVector CalculateSpawnTransform(int i, int j);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* SceneComponent;
	
	void SpawnGridInConstruct();

	UPROPERTY(EditAnywhere, Category = "MeshColor")
	TSoftObjectPtr<UStaticMesh> StatickMesh;

	UPROPERTY(BlueprintReadWrite)
	TArray<AGHHexActor*> HexArray;
	
private:
	void FindFriendsToAllHex();
	
public:
	FInitSpawn InitSpawn;
	FOnClickToMove OnClickToMove;
	FOnBeginMouseOverlap OnBeginMouseOverlap;
	FOnEndMouseOverlap OnEndMouseOverlap;
	
	UPROPERTY(EditAnywhere, Category = "SizeGrid")
	int32 SizeX = 10; 

	UPROPERTY(EditAnywhere, Category = "SizeGrid")
	int32 SizeY = 10;
	
private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<AGHHexActor> HexActorClass;
	
	UPROPERTY()
	AGHHexActor* Hex;
	
	UPROPERTY(VisibleAnywhere)
	TArray<UMeshComponent*> ArrayHexComponents;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* HexComponent;

	UFUNCTION()
	void NeedMove(AGHHexActor* ActorEnd);

	UFUNCTION()
	void EndOverlap(AGHHexActor* ActorEnd);

	UFUNCTION()
	void BeginOverlap(AGHHexActor* ActorStart,AGHHexActor* ActorEnd);

	UFUNCTION()
	void Init();
};





