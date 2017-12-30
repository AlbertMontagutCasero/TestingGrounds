// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "S05__TestingGroundsGameMode.h"
#include "S05__TestingGroundsHUD.h"
#include "player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

AS05__TestingGroundsGameMode::AS05__TestingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/Character/Behaviour/Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	
	// use our custom HUD class
	HUDClass = AS05__TestingGroundsHUD::StaticClass();
}
