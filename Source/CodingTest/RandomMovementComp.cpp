// Fill out your copyright notice in the Description page of Project Settings.

#include "RandomMovementComp.h"


// Sets default values for this component's properties
URandomMovementComp::URandomMovementComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	movementRadius = 5;

}


// Called when the game starts
void URandomMovementComp::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void URandomMovementComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* parent = GetOwner();
	if (parent)
	{
		parent->SetActorLocation(
			parent->GetActorLocation() +
			FVector(
				FMath::FRandRange(-2, 2)*movementRadius,
				FMath::FRandRange(-2, 2)*movementRadius,
				FMath::FRandRange(-1, 1)*movementRadius
			)
		);
	}
}

