// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "KeyboardMagesPlayerController.generated.h"

/**
 * 
 */

class UUserWidget;
class UEditableTextBox;

UCLASS()
class KEYBOARD_MAGES_API AKeyboardMagesPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AKeyboardMagesPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
		TSubclassOf<UUserWidget> HUD;

protected:

	virtual void BeginPlay() override;

private:
	FInputModeGameAndUI m_InputMode;

	// Variable to hold the widget After Creating it.
	UUserWidget* m_HUD;

	UEditableTextBox* m_SpellTextBox;
	
};
