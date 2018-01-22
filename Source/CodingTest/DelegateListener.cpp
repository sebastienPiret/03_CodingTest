// Fill out your copyright notice in the Description page of Project Settings.

#include "DelegateListener.h"
#include "CookbookGameMode.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/GameMode.h"


// Sets default values
ADelegateListener::ADelegateListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pointLight = CreateDefaultSubobject<UPointLightComponent>("pointLight");
	RootComponent = pointLight;
	pointLight->SetVisibility(false);
}

// Called when the game starts or when spawned
void ADelegateListener::BeginPlay()
{
	Super::BeginPlay();
	
	UWorld* theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		AGameModeBase* gameMode = UGameplayStatics::GetGameMode(theWorld);
		ACookbookGameMode* myGameMode = Cast<ACookbookGameMode>(gameMode);
		if (myGameMode != nullptr)
		{
			myGameMode->MyStandardDelegate.BindUObject(this, &ADelegateListener::EnableLight);
		}
	}
}

// Called every frame
void ADelegateListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADelegateListener::EnableLight()
{
	pointLight->SetVisibility(true);
}

void ADelegateListener::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UWorld* theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		AGameModeBase* gameMode = UGameplayStatics::GetGameMode(theWorld);
		ACookbookGameMode* myGameMode = Cast<ACookbookGameMode>(gameMode);
		if (myGameMode != nullptr)
		{
			myGameMode->MyStandardDelegate.Unbind();
		}
	}
}

