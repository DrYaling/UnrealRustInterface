// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealRustInterfaceGameMode.h"
#include "UnrealRustInterfacePlayerController.h"
#include "UnrealRustInterfaceCharacter.h"
#include "UObject/ConstructorHelpers.h"
AUnrealRustInterfaceGameMode::AUnrealRustInterfaceGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AUnrealRustInterfacePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}