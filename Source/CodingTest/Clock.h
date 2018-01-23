// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeOfDayHandler.h"
#include "Clock.generated.h"

UCLASS()
class CODINGTEST_API AClock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AClock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		USceneComponent* rootSceneComponent;
	UPROPERTY()
		UStaticMeshComponent* clockFace;

	UPROPERTY()
		USceneComponent* hourHandle;
	UPROPERTY()
		UStaticMeshComponent* hourHand;

	UPROPERTY()
		USceneComponent* minuteHandle;
	UPROPERTY()
		UStaticMeshComponent* minuteHand;

	UFUNCTION()
		void TimeChanged(int32 hours, int32 minutes);

	FDelegateHandle myDelegateHandle;
	UWorld* theWorld;
};
