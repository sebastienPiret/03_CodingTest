// Fill out your copyright notice in the Description page of Project Settings.

#include "OrbitingMovementComp.h"


// Sets default values for this component's properties
UOrbitingMovementComp::UOrbitingMovementComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	rotationSpeed = 5;
	orbitDistance = 100;
	currentValue = 0;
	rotateToFaceTowards = true;
}


// Called when the game starts
void UOrbitingMovementComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOrbitingMovementComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	float currentValueInRadians = FMath::DegreesToRadians<float>(currentValue);
	SetRelativeLocation(FVector(orbitDistance*FMath::Cos(currentValueInRadians), orbitDistance*FMath::Sin(currentValueInRadians), RelativeLocation.Z));
	if (rotateToFaceTowards)
	{
		FVector lookDir = (RelativeLocation).GetSafeNormal();
		FRotator lookAtRot = lookDir.Rotation();
		SetRelativeRotation(lookAtRot);
	}
	currentValue = FMath::Fmod(currentValue + (rotationSpeed*DeltaTime), 360);
}

