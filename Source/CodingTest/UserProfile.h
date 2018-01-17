// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ColoredTexture.h"
#include "EnumName.h"
#include "UserProfile.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CODINGTEST_API UUserProfile : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		float HpMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		FString Email;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = HUD)
		FColoredTexture texture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Status)
		TEnumAsByte<Status> status;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Stats)
		TSubclassOf<UObject> UClassOfPlayer; 	// Displays any UClasses

	// Deriving from UObject in a dropdown menu in Blueprints
	// Displays string names of UCLASSes that derive from
	// the GameMode C++ base class
	UPROPERTY(EditAnywhere, meta = (MetaClass = "GameMode"), Category = Unit)
		FStringClassReference UClassGameMode;
	
	UFUNCTION(BlueprintCallable, Category = Properties)
		FString toString();
	
};
