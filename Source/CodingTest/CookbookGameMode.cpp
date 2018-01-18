// Fill out your copyright notice in the Description page of Project Settings.

#include "CookbookGameMode.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

void ACookbookGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Actor spawning!"));
		UE_LOG(LogTemp, Warning, TEXT("Print On Tick"));
	}
	


	FTransform spawnLocation;
	spawnedActor=GetWorld()->SpawnActor<AMyActor>(AMyActor::StaticClass(), spawnLocation);
	

}
