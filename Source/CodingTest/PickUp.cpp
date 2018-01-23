// Fill out your copyright notice in the Description page of Project Settings.

#include "PickUp.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"



// Sets default values
APickUp::APickUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	pickedUpMesh = CreateDefaultSubobject<UStaticMeshComponent>("pickedUpMesh");
	rotatingComponent = CreateDefaultSubobject<URotatingMovementComponent>("rotatingComponent");
	auto meshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (meshAsset.Object != nullptr)
	{
		pickedUpMesh->SetStaticMesh(meshAsset.Object);
	}
	RootComponent = pickedUpMesh;
	pickedUpMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	pickedUpMesh->SetRelativeScale3D(FVector(0.4, 0.4, 0.4));
	//pickedUpMesh->SetRelativeLocation(FVector(0, 0, 1));
	rotatingComponent->RotationRate = FRotator(10, 0, 10);
}

// Called when the game starts or when spawned
void APickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickUp::NotifyActorBeginOverlap(AActor * OtherActor)
{
	onPickedUp.ExecuteIfBound();
}

