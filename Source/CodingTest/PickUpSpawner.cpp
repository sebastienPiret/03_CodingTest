// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUpSpawner.h"


// Sets default values
APickUpSpawner::APickUpSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	spawnLocation = CreateDefaultSubobject<USceneComponent>("spawnLocation");
}

// Called when the game starts or when spawned
void APickUpSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnPickup();
}

// Called every frame
void APickUpSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUpSpawner::PickupCollected()
{
	GetWorld()->GetTimerManager().SetTimer(myTimer, this, &APickUpSpawner::SpawnPickup, 5, false);
	currentPickup->onPickedUp.Unbind();
	currentPickup->Destroy();
	i++;
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("You picked up %d cube."), i));
}

void APickUpSpawner::SpawnPickup()
{
	UWorld* theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		currentPickup = theWorld->SpawnActor<APickUp>(APickUp::StaticClass(),FVector(FMath::RandRange(-1000.f,1000.f),FMath::RandRange(-1000.f,1000.f),100),FRotator::ZeroRotator);
		currentPickup->onPickedUp.BindUObject(this, &APickUpSpawner::PickupCollected);
		
	}
}

