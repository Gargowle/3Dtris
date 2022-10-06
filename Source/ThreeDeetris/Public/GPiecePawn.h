// Copyright (c) 2022 Gargowle. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GPiecePawn.generated.h"

UCLASS()
class THREEDEETRIS_API AGPiecePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGPiecePawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Timer handle for the timer triggering the step-wise downward movement
	FTimerHandle DownwardMovementTimerHandle;

	// Time in between the times that the piece moves down the
	float DownwardMovementTimePeriod;

	UFUNCTION()
	void MoveDown();

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
