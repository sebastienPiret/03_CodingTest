// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyActor.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameModeBase.h"
#include "CookbookGameMode.generated.h"

/**
 * 
 */
DECLARE_DELEGATE(FStandardDelegateSignature)
DECLARE_DELEGATE_OneParam(FParamDelagateSignature,FLinearColor)
DECLARE_MULTICAST_DELEGATE(FMulticastDelegateSignature)
UCLASS()
class CODINGTEST_API ACookbookGameMode : public AGameModeBase
{
	GENERATED_BODY()

		virtual void BeginPlay() override;
	

public:
	FStandardDelegateSignature MyStandardDelegate;
	FParamDelagateSignature MyParamDelegate;
	FMulticastDelegateSignature MyMulticastDelegate;
	
}; 
