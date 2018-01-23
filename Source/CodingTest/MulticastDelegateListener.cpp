// Fill out your copyright notice in the Description page of Project Settings.

#include "MulticastDelegateListener.h"
#include "CookbookGameMode.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameMode.h"


// Sets default values
AMulticastDelegateListener::AMulticastDelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pointLight = CreateDefaultSubobject<UPointLightComponent>("togglingLight");
	RootComponent = pointLight;
}

// Called when the game starts or when spawned
void AMulticastDelegateListener::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		AGameModeBase* gameMode = UGameplayStatics::GetGameMode(theWorld);
		ACookbookGameMode* myGameMode = Cast<ACookbookGameMode>(gameMode);
		if (myGameMode != nullptr)
		{
			myGameMode->MyMulticastDelegate.AddUObject(this, &AMulticastDelegateListener::ToggleLight);
		}
	}
}

// Called every frame
void AMulticastDelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMulticastDelegateListener::ToggleLight()
{
	pointLight->ToggleVisibility();
}

void AMulticastDelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UWorld* theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		AGameModeBase* gameMode = UGameplayStatics::GetGameMode(theWorld);
		ACookbookGameMode* myGameMode = Cast<ACookbookGameMode>(gameMode);
		if (myGameMode != nullptr)
		{
			myGameMode->MyMulticastDelegate.Remove(myDelagateHandle);
		}
	}
}

