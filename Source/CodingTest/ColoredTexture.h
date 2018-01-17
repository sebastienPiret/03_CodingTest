// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CodingTest.h"
#include "Engine/Texture.h"
//#include "CoreMinimal.h"
//#include "UObject/NoExportTypes.h"
#include "ColoredTexture.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct CODINGTEST_API FColoredTexture
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
		UTexture* Texture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
		FLinearColor Color;
};