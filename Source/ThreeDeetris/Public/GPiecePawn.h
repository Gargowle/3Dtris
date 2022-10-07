// Copyright (c) 2022 Gargowle. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GPiecePawn.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;


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
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	// Timer handle for the timer triggering the step-wise downward movement
	FTimerHandle DownwardMovementTimerHandle;

	// Time in between the times that the piece moves down the
	float DownwardMovementTimePeriod;

	UFUNCTION()
	void MoveDown();

	UFUNCTION()
	void MoveForward();
	
	UFUNCTION()
	void MoveBackward();
	
	UFUNCTION()
	void MoveLeft();
	
	UFUNCTION()
	void MoveRight();

public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
