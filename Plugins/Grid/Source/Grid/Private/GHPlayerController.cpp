// Fill out your copyright notice in the Description page of Project Settings.


#include "GHPlayerController.h"

void AGHPlayerController::BeginPlay()
{
	Super::BeginPlay();
	SetInputMode(FInputModeGameAndUI());
	bShowMouseCursor=true;
	bEnableMouseOverEvents = true;
	bEnableClickEvents = true;
}
