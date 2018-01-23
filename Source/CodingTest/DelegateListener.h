// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/PointLightComponent.h"
#include "DelegateListener.generated.h"

UCLASS()
class CODINGTEST_API ADelegateListener : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADelegateListener();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UFUNCTION()
		void EnableLight();

	UFUNCTION()
		virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	
	UPROPERTY()
		UPointLightComponent* pointLight;
	bool switchLight;
};
