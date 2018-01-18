// Fill out your copyright notice in the Description page of Project Settings.

#include "HierarchyActor.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/EngineTypes.h"


// Sets default values
AHierarchyActor::AHierarchyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	root = CreateDefaultSubobject<USceneComponent>("Root");
	childSceneComponent = CreateDefaultSubobject<USceneComponent>("ChildSceneComponent");
	boxOne = CreateDefaultSubobject<UStaticMeshComponent>("BoxOne");
	boxTwo = CreateDefaultSubobject<UStaticMeshComponent>("BoxTwo");

	auto meshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));
	if (meshAsset.Object != nullptr)
	{
		boxOne->SetStaticMesh(meshAsset.Object);
		boxTwo->SetStaticMesh(meshAsset.Object);
	}

	RootComponent = root;
	boxOne->AttachToComponent(root,FAttachmentTransformRules::KeepRelativeTransform);
	boxOne->SetRelativeLocation(FVector(0, 0, 50));
	boxTwo->AttachToComponent(childSceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	childSceneComponent->AttachToComponent(root, FAttachmentTransformRules::KeepRelativeTransform);
	childSceneComponent->SetRelativeLocation(FVector(250, 0, 250));
}

// Called when the game starts or when spawned
void AHierarchyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHierarchyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

