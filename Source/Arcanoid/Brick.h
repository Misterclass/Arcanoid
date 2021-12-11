// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

class UBoxComponent;
class USoundCue;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FBrickDestroyEvent);

UCLASS()
class ARCANOID_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* SM_Brick;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UBoxComponent* Box_Collision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int LivesCount = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USoundCue* DestroySound;

	/*UPROPERTY(EditAnywhere)
		float SpeedModifierOnBounce = 1.05f;*/


	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult& SweepResult);

	void DestroyBrick();

public:
	UPROPERTY(BlueprintAssignable, BlueprintCallable)
		FBrickDestroyEvent BrickDestroyEvent;

};
