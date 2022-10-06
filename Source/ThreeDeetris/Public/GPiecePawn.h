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

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};