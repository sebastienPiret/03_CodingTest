// Fill out your copyright notice in the Description page of Project Settings.

#include "ParamDelegateListener.h"
#include "CookbookGameMode.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameMode.h"


// Sets default values
AParamDelegateListener::AParamDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pointLight = CreateDefaultSubobject<UPointLightComponent>("pointLightColored");
	RootComponent = pointLight;
	pointLight->SetVisibility(false);
}

// Called when the game starts or when spawned
void AParamDelegateListener::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		AGameModeBase* gameMode = UGameplayStatics::GetGameMode(theWorld);
		ACookbookGameMode* myGameMode = Cast<ACookbookGameMode>(gameMode);
		if (myGameMode != nullptr)
		{
			myGameMode->MyParamDelegate.BindUObject(this, &AParamDelegateListener::SetLightColor,true);
		}
	}
}

// Called every frame
void AParamDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AParamDelegateListener::SetLightColor(FLinearColor lightColor, bool enableLight)
{
	pointLight->SetLightColor(lightColor);
	pointLight->SetVisibility(enableLight);
}

void AParamDelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UWorld* theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		AGameModeBase* gameMode = UGameplayStatics::GetGameMode(theWorld);
		ACookbookGameMode* myGameMode = Cast<ACookbookGameMode>(gameMode);
		if (myGameMode != nullptr)
		{
			myGameMode->MyParamDelegate.Unbind();
		}
	}
}
