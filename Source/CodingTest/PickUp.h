// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "PickUp.generated.h"

DECLARE_DELEGATE(FPickedUpEventSignature)
UCLASS()
class CODINGTEST_API APickUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	UPROPERTY()
		UStaticMeshComponent* pickedUpMesh;
	UPROPERTY()
		URotatingMovementComponent* rotatingComponent;

	FPickedUpEventSignature onPickedUp;
	
};
