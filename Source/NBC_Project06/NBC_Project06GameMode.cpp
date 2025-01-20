// Copyright Epic Games, Inc. All Rights Reserved.

#include "NBC_Project06GameMode.h"
#include "NBC_Project06Character.h"
#include "UObject/ConstructorHelpers.h"

ANBC_Project06GameMode::ANBC_Project06GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
