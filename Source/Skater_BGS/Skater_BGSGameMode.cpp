// Copyright Epic Games, Inc. All Rights Reserved.

#include "Skater_BGSGameMode.h"
#include "Skater_BGSCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASkater_BGSGameMode::ASkater_BGSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
