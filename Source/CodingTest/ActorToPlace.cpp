// Fill out your copyright notice in the Description page of Project Settings.

#include "ActorToPlace.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"


// Sets default values
AActorToPlace::AActorToPlace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticCube = CreateDefaultSubobject<UStaticMeshComponent>("staticCube");
	childCube = CreateDefaultSubobject<UStaticMeshComponent>("childCube");
	rootSceneComponent = CreateDefaultSubobject<USceneComponent>("rootSceneComponent");
	childComponent = CreateDefaultSubobject<USceneComponent>("childComponent");
	auto meshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (meshAsset.Object != nullptr)
	{
		staticCube->SetStaticMesh(meshAsset.Object);
		childCube->SetStaticMesh(meshAsset.Object);
	}
	RootComponent = rootSceneComponent;
	staticCube->SetupAttachment(RootComponent);
	childComponent->SetupAttachment(RootComponent);
	childCube->SetupAttachment(childComponent);
	childCube->SetRelativeTransform(FTransform(FRotator(15, 15, 15), FVector(200, 0, 0), FVector(2, 2, 2)));

}

// Called when the game starts or when spawned
void AActorToPlace::BeginPlay()
{
	Super::BeginPlay();
	theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		
		UE_LOG(LogTemp, Warning, TEXT("le spawn est fait."));
	}
}

// Called every frame
void AActorToPlace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

