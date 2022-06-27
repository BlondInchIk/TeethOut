// Copyright Epic Games, Inc. All Rights Reserved.

#include "Enemy_AIGameMode.h"
#include "Enemy_AICharacter.h"
#include "UObject/ConstructorHelpers.h"

// Установка персонажа по умолчанию
AEnemy_AIGameMode::AEnemy_AIGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
