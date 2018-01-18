// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMeshComponent");
	auto meshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (meshAsset.Object != nullptr)
	{
		mesh->SetStaticMesh(meshAsset.Object);
	}

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

