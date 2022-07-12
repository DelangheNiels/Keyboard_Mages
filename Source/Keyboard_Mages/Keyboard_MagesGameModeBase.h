// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Keyboard_MagesGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class KEYBOARD_MAGES_API AKeyboard_MagesGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AKeyboard_MagesGameModeBase();

protected:
	virtual void BeginPlay() override;
};
