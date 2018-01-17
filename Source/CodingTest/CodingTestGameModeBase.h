// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CodingTestGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CODINGTEST_API ACodingTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	ACodingTestGameModeBase(const FObjectInitializer& PCIP);
	void BeginPlay();
	
	
	
	
};
