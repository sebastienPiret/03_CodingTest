// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerVolEventListener.h"


// Sets default values
ATriggerVolEventListener::ATriggerVolEventListener()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pointLight = CreateDefaultSubobject<UPointLightComponent>("triggerLight");
	RootComponent = pointLight;
}

// Called when the game starts or when spawned
void ATriggerVolEventListener::BeginPlay()
{
	Super::BeginPlay();
	
	if (triggerEventSource != nullptr)
	{
		triggerEventSource->onPlayerEntered.AddUObject(this, &ATriggerVolEventListener::OnTriggerEvent);
	}
}

// Called every frame
void ATriggerVolEventListener::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATriggerVolEventListener::OnTriggerEvent()
{
	pointLight->SetLightColor(FLinearColor(0,0,1, 1));
}

