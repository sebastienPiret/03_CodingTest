// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "ActorToPlace.generated.h"

UCLASS()
class CODINGTEST_API AActorToPlace : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorToPlace();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		UStaticMeshComponent* staticCube;
	UPROPERTY()
		UStaticMeshComponent* childCube;
	
	UWorld* theWorld;
	UPROPERTY()
		USceneComponent* rootSceneComponent;
	UPROPERTY()
		USceneComponent* childComponent;
};
