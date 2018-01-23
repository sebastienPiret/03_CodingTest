// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTriggerVolume.h"
#include "Engine/Engine.h"
#include "CookbookGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Delegates/DelegateSignatureImpl.inl"


// Sets default values
AMyTriggerVolume::AMyTriggerVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	/*triggerZone = CreateDefaultSubobject<UBoxComponent>("TriggerZone");
	triggerZone->SetBoxExtent(FVector(200, 200, 100));*/
}

// Called when the game starts or when spawned
void AMyTriggerVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTriggerVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTriggerVolume::NotifyActorBeginOverlap(AActor * OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, FString::Printf(TEXT("%s entered me."), *(OtherActor->GetName())));
	
	UWorld* theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("j'entre"));
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(theWorld);
		ACookbookGameMode * MyGameMode = Cast<ACookbookGameMode>(GameMode);
		MyGameMode->MyStandardDelegate.ExecuteIfBound();
		MyGameMode->MyParamDelegate.ExecuteIfBound(FLinearColor(1,0,0,1));
		MyGameMode->MyMulticastDelegate.Broadcast();
		onPlayerEntered.Broadcast();
	}
}

void AMyTriggerVolume::NotifyActorEndOverlap(AActor * OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, FString::Printf(TEXT("%s left me."), *(OtherActor->GetName())));
	UE_LOG(LogTemp, Warning, TEXT("je sors"));
	UWorld* theWorld = GetWorld();
	if (theWorld != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("j'entre"));
		AGameModeBase* GameMode = UGameplayStatics::GetGameMode(theWorld);
		ACookbookGameMode * MyGameMode = Cast<ACookbookGameMode>(GameMode);
		MyGameMode->MyStandardDelegate.ExecuteIfBound();
		MyGameMode->MyParamDelegate.ExecuteIfBound(FLinearColor(255, 255, 255, 1));
		MyGameMode->MyMulticastDelegate.Broadcast();
	}
}

