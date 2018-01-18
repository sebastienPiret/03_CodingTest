// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameState.h"

AMyGameState::AMyGameState()
{
	currentScore = 0;
}

void AMyGameState::SetScore(int32 newScore)
{
	currentScore = newScore;
}

int32 AMyGameState::GetScore()
{
	return currentScore;
}
