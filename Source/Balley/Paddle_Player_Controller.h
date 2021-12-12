// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Paddle_Player_Controller.generated.h"

class ABall;

/**
 * 
 */
UCLASS()
class BALLEY_API APaddle_Player_Controller : public APlayerController
{
	GENERATED_BODY()

public:
	APaddle_Player_Controller();


	UFUNCTION()
		virtual void SetupInputComponent() override;

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveHorizontal(float AxisValue);

	//ball references
	
	void Launch();

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABall> BallObj;

	ABall* MyBall;

	FVector SpawnLocation = FVector(10.f, 0.f, 40.f);
	FRotator SpawnRotation = FRotator();
	FActorSpawnParameters SpawnInfo;

public:
	void SpawnNewBall();
};
