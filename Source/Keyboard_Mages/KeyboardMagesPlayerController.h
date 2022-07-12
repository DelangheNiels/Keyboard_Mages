// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KeyboardMagesPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class KEYBOARD_MAGES_API AKeyboardMagesPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AKeyboardMagesPlayerController();

protected:

	virtual void BeginPlay() override;

private:
	FInputModeGameAndUI m_InputMode;
	
};
