// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"


// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWarrior::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWarrior::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AWarrior::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(InputComponent);
	InputComponent->BindAxis("Forward", this, &AWarrior::Forward);
	InputComponent->BindAxis("Backward", this, &AWarrior::Backward);
	InputComponent->BindAxis("Left", this, &AWarrior::Left);
	InputComponent->BindAxis("Right", this, &AWarrior::Right);
}

void AWarrior::Forward(float amount)
{
	// move the player forward by amount given by axis mapping
	AddMovementInput(GetActorForwardVector(), amount);
}

void AWarrior::Backward(float amount)
{
	// move the player forward by amount given by axis mapping
	AddMovementInput(GetActorForwardVector(), amount);
}

void AWarrior::Left(float amount)
{
	// move the player forward by amount given by axis mapping
	AddMovementInput(GetActorRightVector(), amount);
}
void AWarrior::Right(float amount)
{
	// move the player forward by amount given by axis mapping
	AddMovementInput(GetActorRightVector(), amount);
}
