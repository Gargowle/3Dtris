// Copyright (c) 2022 Gargowle. All rights reserved.


#include "GPiecePawn.h"

// Sets default values
AGPiecePawn::AGPiecePawn()
{
 	// Ticking should not be necessary since piece movement
	// should work out completely based on timers and events
	PrimaryActorTick.bCanEverTick = false;

	DownwardMovementTimePeriod = 1.0;
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
	SetActorLocation(GetActorLocation()-100*FVector::ZAxisVector);
}

// Called to bind functionality to input
void AGPiecePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

