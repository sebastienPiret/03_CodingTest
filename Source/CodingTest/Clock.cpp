// Fill out your copyright notice in the Description page of Project Settings.

#include "Clock.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AClock::AClock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	rootSceneComponent = CreateDefaultSubobject<USceneComponent>("rootSceneComponent");
	clockFace = CreateDefaultSubobject<UStaticMeshComponent>("clockFace");
	hourHand= CreateDefaultSubobject<UStaticMeshComponent>("hourHand");
	minuteHand= CreateDefaultSubobject<UStaticMeshComponent>("minuteHand");

	hourHandle= CreateDefaultSubobject<USceneComponent>("hourHandle");
	minuteHandle = CreateDefaultSubobject<USceneComponent>("minuteHandle");
	auto meshAsset = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (meshAsset.Object != nullptr)
	{
		clockFace->SetStaticMesh(meshAsset.Object);
		hourHand->SetStaticMesh(meshAsset.Object);
		minuteHand->SetStaticMesh(meshAsset.Object);
	}
	RootComponent = rootSceneComponent;
	clockFace->SetupAttachment(RootComponent);;
	hourHandle->SetupAttachment(RootComponent);
	hourHandle->SetRelativeLocation(FVector(0, 0, 0));
	minuteHandle->SetupAttachment(RootComponent);

	hourHand->SetupAttachment(hourHandle);
	minuteHand->SetupAttachment(minuteHandle);
	

	clockFace->SetRelativeTransform(FTransform(FRotator(90, 0, 0), FVector(10, 0, 0), FVector(2, 2, 0.1)));
	hourHand->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 0, 25), FVector(0.1, 0.1, 0.5)));
	minuteHand->SetRelativeTransform(FTransform(FRotator(0, 0, 0), FVector(0, 0, 50), FVector(0.1, 0.1, 1)));

	
}

// Called when the game starts or when spawned
void AClock::BeginPlay()
{
	Super::BeginPlay();

	theWorld = GetWorld();
	if (theWorld != nullptr)
	{

		UE_LOG(LogTemp, Warning, TEXT("le spawn est fait."));
	}

	TArray<AActor*>timeOfDayHandlers;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATimeOfDayHandler::StaticClass(), timeOfDayHandlers);
	if (timeOfDayHandlers.Num() != 0)
	{
		auto TimeOfDayHandler = Cast<ATimeOfDayHandler>(timeOfDayHandlers[0]);
		myDelegateHandle = TimeOfDayHandler->OnTimeChanged.AddUObject(this, &AClock::TimeChanged);
	}
}

// Called every frame
void AClock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AClock::TimeChanged(int32 hours, int32 minutes)
{
	hourHandle->SetRelativeRotation(FRotator(0, 0, 30 * hours));
	minuteHandle->SetRelativeRotation(FRotator(0, 0, 6 * minutes));
}

