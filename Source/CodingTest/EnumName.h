// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CodingTest.h"
#include "EnumName.generated.h"

/**
 * 
 */
UENUM()
enum Status
{
	Stopped	UMETA(DisplayName="Stopped"),
	Moving	UMETA(DisplayName = "Moving"),
	Attacking	UMETA(DisplayName = "Attacking"),
};