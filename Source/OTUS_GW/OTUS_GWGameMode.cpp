// Copyright Epic Games, Inc. All Rights Reserved.

#include "OTUS_GWGameMode.h"
#include "OTUS_GWCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOTUS_GWGameMode::AOTUS_GWGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SpaceMarine/Characters/MainCharSpaceMarine/Blueprints/BP_MainCharSpaceMarine"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
