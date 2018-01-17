// Fill out your copyright notice in the Description page of Project Settings.

#include "CodingTestGameModeBase.h"
#include "CodingTest.h"
#include "Class.h"
#include "UserProfile.h"

ACodingTestGameModeBase::ACodingTestGameModeBase(const FObjectInitializer& PCIP) : Super(PCIP)
{

}

void ACodingTestGameModeBase::BeginPlay()
{
	ACodingTestGameModeBase *gm = Cast<ACodingTestGameModeBase>(GetWorld()->GetAuthGameMode());

	if (gm)
	{
		// Using ConstructObject:
		//UUserProfile* constructedobject = ConstructObject<UUserProfile>(UUserProfile::StaticClass());
		//UUserProfile* constructedObject = ConstructObject<UUserProfile>(UUserProfile::StaticClass());

		// Using NewObject instead:
		UUserProfile* newobject = NewObject<UUserProfile>((UObject*)GetTransientPackage(), UUserProfile::StaticClass());
	}
}


