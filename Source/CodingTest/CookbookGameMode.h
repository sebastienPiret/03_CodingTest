// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameMode.h"
#include "CookbookGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CODINGTEST_API ACookbookGameMode : public AGameMode
{
	GENERATED_BODY()

		virtual void BeginPlay() override;
	
	UPROPERTY()
		AMyActor* spawnedActor;
	
};
