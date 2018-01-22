// Fill out your copyright notice in the Description page of Project Settings.

#include "BarrackSpawner.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/World.h"
#include "TimerManager.h"


// Sets default values
ABarrackSpawner::ABarrackSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	buildingMesh = CreateDefaultSubobject<UStaticMeshComponent>("buildingMesh");
	spawnPoint = CreateDefaultSubobject<UParticleSystemComponent>("spawnPoint");
	spawnInterval = 10;
	auto meshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/ENgine/BasicShapes/Cube.Cube'"));
	if (meshAsset.Object != nullptr)
	{
		buildingMesh->SetStaticMesh(meshAsset.Object);
		buildingMesh->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	}
	auto particleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));
	if (particleSystem.Object != nullptr)
	{
		spawnPoint->SetTemplate(particleSystem.Object);
	}
	spawnPoint->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	unitToSpawn = ABarrackUnit::StaticClass();
}

// Called when the game starts or when spawned
void ABarrackSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	RootComponent = buildingMesh;
	spawnPoint->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	FVector spawnFrom = RootComponent->GetComponentLocation();
	spawnPoint->SetRelativeLocation(spawnFrom);
	GetWorld()->GetTimerManager().SetTimer(spawnTimerHandle,this,&ABarrackSpawner::SpawnUnit,spawnInterval,true);
}

// Called every frame
void ABarrackSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrackSpawner::SpawnUnit()
{
	FVector spawnLocation = spawnPoint->GetComponentLocation();
	GetWorld()->SpawnActor(unitToSpawn, &spawnLocation);
}

void ABarrackSpawner::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	GetWorld()->GetTimerManager().ClearTimer(spawnTimerHandle);
}

