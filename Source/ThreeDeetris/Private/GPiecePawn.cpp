// Copyright (c) 2022 Gargowle. All rights reserved.


#include "GPiecePawn.h"

#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AGPiecePawn::AGPiecePawn()
{
 	// Ticking should not be necessary since piece movement
	// should work out completely based on timers and events
	PrimaryActorTick.bCanEverTick = false;

	DownwardMovementTimePeriod = 1.0;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;
	
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);
	// enable camera angles different from horizontal alignment (driven by the Control Rotation)
	SpringArmComp->bUsePawnControlRotation = true;

	// The rotation of spring arm is controlled with pawn control rotation already. This disables a subtle side effect where rotating the
	// CapsuleComponent (eg. caused by bOrientRotationToMovement in Character Movement) will rotate the spring arm until it self corrects later in the update.
	// This may cause unwanted effects when using CameraLocation during Tick as it may be slightly offset from the final camera position.
	SpringArmComp->SetUsingAbsoluteRotation(true);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AGPiecePawn::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(DownwardMovementTimerHandle, this, &AGPiecePawn::MoveDown, DownwardMovementTimePeriod, true);
}

void AGPiecePawn::MoveDown()
{
	// move down by a meter
	SetActorLocation(GetActorLocation() - 100*FVector::ZAxisVector);
}

void AGPiecePawn::MoveForward()
{
	// TODO: adjust to consider view direction
	SetActorLocation(GetActorLocation() + 100*FVector::XAxisVector);	
}

void AGPiecePawn::MoveBackward()
{
	// TODO: adjust to consider view direction
	SetActorLocation(GetActorLocation() - 100*FVector::XAxisVector);	
}

void AGPiecePawn::MoveLeft()
{
	// TODO: adjust to consider view direction
	SetActorLocation(GetActorLocation() + 100*FVector::YAxisVector);	
}

void AGPiecePawn::MoveRight()
{
	// TODO: adjust to consider view direction
	SetActorLocation(GetActorLocation() - 100*FVector::YAxisVector);	
}

// Called to bind functionality to input
void AGPiecePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction(TEXT("MoveForward"), IE_Pressed, this, &AGPiecePawn::MoveForward);
	PlayerInputComponent->BindAction(TEXT("MoveBackward"), IE_Pressed, this, &AGPiecePawn::MoveBackward);
	PlayerInputComponent->BindAction(TEXT("MoveLeft"), IE_Pressed, this, &AGPiecePawn::MoveLeft);
	PlayerInputComponent->BindAction(TEXT("MoveRight"), IE_Pressed, this, &AGPiecePawn::MoveRight);
}

