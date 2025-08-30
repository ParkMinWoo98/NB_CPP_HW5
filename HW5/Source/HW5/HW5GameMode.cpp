// Copyright Epic Games, Inc. All Rights Reserved.

#include "HW5GameMode.h"
#include "HW5Character.h"
#include "UObject/ConstructorHelpers.h"

AHW5GameMode::AHW5GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
