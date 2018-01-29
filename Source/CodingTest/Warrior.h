// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerInput.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Warrior.generated.h"

UCLASS()
class CODINGTEST_API AWarrior : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AWarrior();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PostInitializeComponents() override;

	FVector2D lastInput;

	void Forward(float amount);
	void Backward(float amount);
	void Left(float amount);
	void Right(float amount);

	// implementing camera
	/*FVector2D cameraInput;
	void PitchCamera(float AxisValue);
	void YawCamera(float AxisValue);
	
	UCameraComponent* theCamera;
	USpringArmComponent* OurCameraSpringArm;*/

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void OnOverlapsBegin(
			UPrimitiveComponent* Comp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult&SweepResult);

	UFUNCTION(BlueprintNativeEvent, Category = Collision)
		void OnOverlapsEnd(
			UPrimitiveComponent* Comp,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);
};
