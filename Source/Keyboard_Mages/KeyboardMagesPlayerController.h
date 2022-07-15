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

public:

	FString GetTextboxText() const;

	void ClearTextbox();

	void EnableTextBox(bool enable);

protected:

	virtual void BeginPlay() override;

private:
	FInputModeGameOnly m_InputMode;

	UPROPERTY()
	UUserWidget* m_HUD;

	UPROPERTY()
	UEditableTextBox* m_SpellTextBox;
	
};
