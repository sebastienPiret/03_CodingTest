// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameState.generated.h"

/**
 * a class to calculate he score of the player
 */
UCLASS()
class CODINGTEST_API AMyGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
		AMyGameState();

	UFUNCTION()
		void SetScore(int32 newScore);
	UFUNCTION()
		int32 GetScore();

private:
	UPROPERTY()
		int32 currentScore;
	
	
	
};
