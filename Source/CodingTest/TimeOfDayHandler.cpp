// Fill out your copyright notice in the Description page of Project Settings.

#include "TimeOfDayHandler.h"


// Sets default values
ATimeOfDayHandler::ATimeOfDayHandler()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	timeScale = 60;
	hours = 0;
	minutes = 0;
	seconds = 0;
}

// Called when the game starts or when spawned
void ATimeOfDayHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeOfDayHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	seconds += (DeltaTime*timeScale);
	if (seconds > 60)
	{
		seconds -= 60;
		minutes++;
		if (minutes > 60)
		{
			minutes -= 60;
			hours++;
		}
	}
	OnTimeChanged.Broadcast(hours, minutes);
}

