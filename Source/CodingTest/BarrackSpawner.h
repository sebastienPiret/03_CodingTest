// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BarrackUnit.h"
#include "BarrackSpawner.generated.h"

UCLASS()
class CODINGTEST_API ABarrackSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrackSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		UStaticMeshComponent* buildingMesh;
	UPROPERTY()
		UParticleSystemComponent* spawnPoint;
	UPROPERTY()
		UClass* unitToSpawn;
	UPROPERTY(EditAnywhere,Category=Bullet)
		float spawnInterval;
	UFUNCTION()
		void SpawnUnit();
	UFUNCTION()
		void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	UPROPERTY()
		FTimerHandle spawnTimerHandle;
	
};
