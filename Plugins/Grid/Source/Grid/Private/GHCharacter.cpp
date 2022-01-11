

#include "GHCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"

AGHCharacter::AGHCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	MoveComponent = CreateDefaultSubobject<UGHMoveComponent>("MoveComponent");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bDoCollisionTest = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
}

void AGHCharacter::BeginPlay()
{
	Super::BeginPlay();
	InitLocation();
}

void AGHCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGHCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AGHCharacter::InitLocation()
{
	MoveComponent->Init();
}

