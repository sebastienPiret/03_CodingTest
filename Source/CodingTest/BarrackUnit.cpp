// Fill out your copyright notice in the Description page of Project Settings.

#include "BarrackUnit.h"
#include "TimerManager.h"


// Sets default values
ABarrackUnit::ABarrackUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	visualRepresentation = CreateDefaultSubobject<UParticleSystemComponent>("visualRepresentation");
	auto particleSystem = ConstructorHelpers::FObjectFinder<UParticleSystem>(TEXT("ParticleSystem'/Engine/Tutorial/SubEditors/TutorialAssets/TutorialParticleSystem.TutorialParticleSystem'"));
	if (particleSystem.Object != nullptr)
	{
		visualRepresentation->SetTemplate(particleSystem.Object);
	}
	visualRepresentation->SetRelativeScale3D(FVector(0.5, 0.5, 0.5));
	ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
}

// Called when the game starts or when spawned
void ABarrackUnit::BeginPlay()
{
	Super::BeginPlay();
	
	visualRepresentation->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	SetLifeSpan(10);
}

// Called every frame
void ABarrackUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation() + FVector(10, 0, 0));
}

// Called to bind functionality to input
void ABarrackUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}



