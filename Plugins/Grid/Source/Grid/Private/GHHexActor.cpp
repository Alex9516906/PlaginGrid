// Fill out your copyright notice in the Description page of Project Settings.


#include "GHHexActor.h"

#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/KismetSystemLibrary.h"

AGHHexActor::AGHHexActor()
{
	PrimaryActorTick.bCanEverTick = false;
	MeshGrid = CreateDefaultSubobject<UStaticMeshComponent>("mesh");
	SetRootComponent(MeshGrid);
	//Delegate Cursor
	MeshGrid->OnBeginCursorOver.AddDynamic(this, &AGHHexActor::BeginOverlapCursor);
	MeshGrid->OnEndCursorOver.AddDynamic(this, &AGHHexActor::EndOverlapCursor);
	MeshGrid->OnClicked.AddDynamic(this, &AGHHexActor::OnClickMouse);
}

void AGHHexActor::BeginPlay()
{
	Super::BeginPlay();
	ChangeMaterial(EMaterialToHex::Clear);
	
}

void AGHHexActor::FindFriends()
{
	TArray<AActor*> array;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), this->GetClass(),array);
	for(auto elementArrActor:array)
	{
		auto elementArrHex = Cast<AGHHexActor>(elementArrActor);
		for(auto b:CoordY%2 == 0 ? CoordsEven:CoordsOdd)
		{
			if(b.X+CoordY == elementArrHex->CoordY && b.Y+CoordX == elementArrHex->CoordX)
			{
				FriendsHexArr.Add(elementArrHex);
			}
		}
	}
	if(InitSpawn.IsBound())
	{
		InitSpawn.Broadcast();
	}
}

float AGHHexActor::WhatDistanceToHexEnd(AGHHexActor* EndHex)
{
		return UKismetMathLibrary::Sqrt(UKismetMathLibrary::Square(EndHex->CoordX - CoordX ) + UKismetMathLibrary::Square(EndHex->CoordY - CoordY));
}

void AGHHexActor::BeginOverlapCursor(UPrimitiveComponent* TouchedComponent )
{
	ChangeMaterial(EMaterialToHex::OverlapMouse);
	if(OnBeginMouseOverlap.IsBound())
	{
		OnBeginMouseOverlap.Broadcast(nullptr,this);
	}
}

void AGHHexActor::EndOverlapCursor(UPrimitiveComponent* TouchedComponent)
{
	ChangeMaterial(EMaterialToHex::Clear);
	if(OnEndMouseOverlap.IsBound())
	{
		OnEndMouseOverlap.Broadcast(this);
	}
}

void AGHHexActor::OnClickMouse(UPrimitiveComponent* TouchedComponent,FKey ButtonPressed)
{
	if(ButtonPressed == EKeys::LeftMouseButton)
	{
		OnClickToMove.Broadcast(this);
	}
}
void AGHHexActor::ChangeMaterial(EMaterialToHex NeedSetMaterial)
{
	switch (NeedSetMaterial)
	{
	case Clear:
		if(!StandardMaterial.IsNull() && bOnCharacter==false)
		{
			UMaterial* mat = StandardMaterial.LoadSynchronous();
			MeshGrid->SetMaterial(0, mat);
		}
		break;
	case OverlapMouse:
		if(!OnChosenMaterial.IsNull()&& bOnCharacter==false)
		{
			UMaterial* mat = OnChosenMaterial.LoadSynchronous();
			MeshGrid->SetMaterial(0, mat);
		}
		break;
	case Way:
		if(!OnChosenMaterial.IsNull())
		{
			UMaterial* mat = OnChosenMaterial.LoadSynchronous();
			MeshGrid->SetMaterial(0, mat);
		}
		break;
	case Player:
		if(!OnChosenMaterial.IsNull())
		{
			UMaterial* mat = PlayerOnHexMaterial.LoadSynchronous();
			MeshGrid->SetMaterial(0, mat);
		}
		break;
	case Movable:
		if(!OnChosenMaterial.IsNull())
		{
			UMaterial* mat = MovableMaterial.LoadSynchronous();
			MeshGrid->SetMaterial(0, mat);
		}
		break;
	default:
		break;
	}
	
}

void AGHHexActor::SetCharacterOnHex()
{
	bOnCharacter=true;
	ChangeMaterial(EMaterialToHex::Player);
}

void AGHHexActor::CharacterExitHex()
{
	bOnCharacter=false;
	UMaterial* mat = StandardMaterial.LoadSynchronous();
	MeshGrid->SetMaterial(0, mat);
}

void AGHHexActor::Init()
{
	FHitResult HitResult;
	FVector StartVector = GetActorLocation();
	FVector EndVector = GetActorLocation()+FVector::DownVector*50;
	FCollisionQueryParams Param;
	Param.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(HitResult,StartVector,EndVector,ECollisionChannel::ECC_Visibility,Param);
	if(!HitResult.bBlockingHit)
	{
		Destroy();
	}
}
