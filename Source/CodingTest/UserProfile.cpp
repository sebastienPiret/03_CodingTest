// Fill out your copyright notice in the Description page of Project Settings.

#include "UserProfile.h"
#include "CodingTest.h"
#include "Runtime/Core/Public/Containers/UnrealString.h"

FString UUserProfile::toString()
{
	return FString::Printf(TEXT("An instance of UPRofile: %s"),*Name);
}
