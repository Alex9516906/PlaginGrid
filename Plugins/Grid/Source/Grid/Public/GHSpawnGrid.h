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

	UPROPERTY(BlueprintReadWrite)
	TArray<AGHHexActor*> HexArray;
	
public:
	FInitSpawn InitSpawn;
	FOnClickToMove OnClickToMove;
	FOnBeginMouseOverlap OnBeginMouseOverlap;
	FOnEndMouseOverlap OnEndMouseOverlap;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "SizeGrid")
	int32 SizeX = 10; 

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = "SizeGrid")
	int32 SizeY = 10;
	
private:
	virtual void OnConstruction(const FTransform& Transform) override;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<AGHHexActor> HexActorClass;
	
	UPROPERTY()
	AGHHexActor* Hex;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UStaticMesh> HexMesh;
	
	UFUNCTION()
	void NeedMove(AGHHexActor* ActorEnd);

	UFUNCTION()
	void EndOverlap(AGHHexActor* ActorEnd);

	UFUNCTION()
	void BeginOverlap(AGHHexActor* ActorStart,AGHHexActor* ActorEnd);

	UFUNCTION()
	void Init();

	void FindFriendsToAllHex();

	static FVector2D GetPointHex(float Size, FVector Centre, int I);

	void DrawHex(const FVector& Centre, const FVector& BoxBounds) const;

	void DrawDebugHexOnConstruct();
		
};





