// Copyright Epic Games, Inc. All Rights Reserved.

#include "TeethOutGameModeBase.h"
#include "MainCharacter.h"
#include "UObject/ConstructorHelpers.h"

AEnemy_AIGameMode::AEnemy_AIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/MyMainCharacter123"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
