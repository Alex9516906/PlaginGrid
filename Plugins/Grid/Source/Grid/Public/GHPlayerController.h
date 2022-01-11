// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GHPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GRID_API AGHPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void BeginPlay() override;
};
