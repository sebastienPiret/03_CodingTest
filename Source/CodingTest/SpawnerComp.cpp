// Fill out your copyright notice in the Description page of Project Settings.

#include "SpawnerComp.h"


// Sets default values for this component's properties
USpawnerComp::USpawnerComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnerComp::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
	// ...
	
}


// Called every frame
void USpawnerComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USpawnerComp::Spawn()
{
	UWorld* theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		FTransform componentTransform(this->GetComponentTransform());
		theWorld->SpawnActor(actorToSpawn, &componentTransform);
		UE_LOG(LogTemp, Warning, TEXT("le spawn est fait."));
	}
}

