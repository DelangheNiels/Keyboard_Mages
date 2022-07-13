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
	UFUNCTION(BlueprintCallable)
	void CastSpell();

	void ClearTextBox();

protected:

	virtual void BeginPlay() override;

private:

private:
	FInputModeGameOnly m_InputMode;

	UPROPERTY()
	UUserWidget* m_HUD;

	UPROPERTY()
	UEditableTextBox* m_SpellTextBox;
	
};
