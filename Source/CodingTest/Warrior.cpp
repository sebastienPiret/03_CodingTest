// Fill out your copyright notice in the Description page of Project Settings.

#include "Warrior.h"


// Sets default values
AWarrior::AWarrior()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	lastInput = FVector2D::ZeroVector;
	
	/*RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	theCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	theCamera->SetupAttachment(RootComponent);*/
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
	if (Controller)
	{
		float len = lastInput.Size();
		if (len > 1.f)
			lastInput /= len;
		AddMovementInput(GetActorForwardVector(), lastInput.Y);
		AddMovementInput(GetActorRightVector(), lastInput.X);
		lastInput = FVector2D(0.f, 0.f);
	}

	// Implementing camera
	////Rotate our actor's yaw, which will turn our camera because we're attached to it
	//{
	//	FRotator NewRotation = GetActorRotation();
	//	NewRotation.Yaw += cameraInput.X;
	//	SetActorRotation(NewRotation);
	//}

	////Rotate our camera's pitch, but limit it so we're always looking downward
	//{
	//	FRotator NewRotation = GetActorRotation();
	//	NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + cameraInput.Y, -80.0f, -15.0f);
	//	theCamera->SetWorldRotation(NewRotation);
	//}
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
	InputComponent->BindAction("Jump", IE_Pressed, this, &AWarrior::Jump);
	

	// Key mapping for both keyboard and Gamepad
	FInputAxisKeyMapping forwardKey("Forward", EKeys::Z, 1.f);
	FInputAxisKeyMapping GPforwardKey("Forward", EKeys::Gamepad_LeftStick_Up, 1.f);
	FInputAxisKeyMapping backKey("Backward", EKeys::S, 1.f);
	FInputAxisKeyMapping GPbackKey("Backward", EKeys::Gamepad_LeftStick_Down, 1.f);
	FInputAxisKeyMapping rightKey("Right", EKeys::D, 1.f);
	FInputAxisKeyMapping GPrightKey("Right", EKeys::Gamepad_LeftStick_Right, 1.f);
	FInputAxisKeyMapping leftKey("Left", EKeys::Q, 1.f);
	FInputAxisKeyMapping GPleftKey("Left", EKeys::Gamepad_LeftStick_Left, 1.f);
	FInputActionKeyMapping jump("Jump", EKeys::SpaceBar, 0, 0, 0, 0);
	FInputActionKeyMapping GPjump("Jump", EKeys::Gamepad_FaceButton_Bottom, 0, 0, 0, 0);
	

	// assigning the key mapped
	auto input = GetWorld()->GetFirstPlayerController()->PlayerInput;
	input->AddAxisMapping(forwardKey);
	input->AddAxisMapping(GPforwardKey);
	input->AddAxisMapping(backKey);
	input->AddAxisMapping(GPbackKey);
	input->AddAxisMapping(rightKey);
	input->AddAxisMapping(GPrightKey);
	input->AddAxisMapping(leftKey);
	input->AddAxisMapping(GPleftKey);
	input->AddActionMapping(jump);
	input->AddActionMapping(GPjump);
	

	// Implementing camera
	/*InputComponent->BindAxis("CameraPitch", this, &AWarrior::PitchCamera);
	InputComponent->BindAxis("CameraYaw", this, &AWarrior::YawCamera);
	FInputAxisKeyMapping pitchKey("CameraPitch", EKeys::MouseX, 1.f);
	FInputAxisKeyMapping GPpitchKey("CameraPitch", EKeys::Gamepad_RightX, 1.f);
	FInputAxisKeyMapping yawKey("CameraYaw", EKeys::MouseY, 1.f);
	FInputAxisKeyMapping GPyawKey("CameraYaw", EKeys::Gamepad_RightY, 1.f);
	input->AddAxisMapping(pitchKey);
	input->AddAxisMapping(GPpitchKey);
	input->AddAxisMapping(yawKey);
	input->AddAxisMapping(GPyawKey);*/
}

void AWarrior::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	if (RootComponent)
	{
		// Attach contact function to all bounding components.
		GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(
			this, &AWarrior::OnOverlapsBegin);
		GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(
			this, &AWarrior::OnOverlapsEnd);
	}
}

void AWarrior::Forward(float amount)
{
	// move the player forward by amount given by axis mapping
	//AddMovementInput(GetActorForwardVector(), amount);
	// or with normalized Input:
	lastInput.Y += amount;
}

void AWarrior::Backward(float amount)
{
	// move the player forward by amount given by axis mapping
	//AddMovementInput(GetActorForwardVector(), amount);
	lastInput.Y += -amount;
}

void AWarrior::Right(float amount)
{
	// move the player forward by amount given by axis mapping
	//AddMovementInput(GetActorRightVector(), amount);
	lastInput.X += amount;
}

void AWarrior::OnOverlapsBegin_Implementation(
	UPrimitiveComponent* Comp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult&SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior began"));
}


void AWarrior::OnOverlapsEnd_Implementation(UPrimitiveComponent * Comp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlaps warrior ended"));
}

void AWarrior::Left(float amount)
{
	// move the player forward by amount given by axis mapping
	//AddMovementInput(GetActorRightVector(), amount);
	lastInput.X += -amount;
}

//implementing camera
//void AWarrior::PitchCamera(float AxisValue)
//{
//	cameraInput.X = AxisValue;
//}
//
//void AWarrior::YawCamera(float AxisValue)
//{
//	cameraInput.Y = AxisValue;
//}



