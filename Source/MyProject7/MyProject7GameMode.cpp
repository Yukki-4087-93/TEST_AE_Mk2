// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProject7GameMode.h"
#include "MyProject7HUD.h"
#include "MyProject7Character.h"
#include "UObject/ConstructorHelpers.h"

AMyProject7GameMode::AMyProject7GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMyProject7HUD::StaticClass();
}
