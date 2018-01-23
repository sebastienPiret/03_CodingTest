// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickUp.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "PickUpSpawner.generated.h"

UCLASS()
class CODINGTEST_API APickUpSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void PickupCollected();
	UFUNCTION()
		void SpawnPickup();
	UPROPERTY()
		USceneComponent* spawnLocation;
	UPROPERTY()
		APickUp* currentPickup;
	int32 i;
	FTimerHandle myTimer;
};
