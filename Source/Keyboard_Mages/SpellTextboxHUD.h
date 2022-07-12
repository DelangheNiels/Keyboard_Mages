// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SpellTextboxHUD.generated.h"

/**
 * 
 */

class UEditableTextBox;

UCLASS()
class KEYBOARD_MAGES_API ASpellTextboxHUD : public AHUD
{
	GENERATED_BODY()

public:
	ASpellTextboxHUD();

protected:
	virtual void BeginPlay() override;
	virtual void DrawHUD() override;

private:

	UEditableTextBox* m_pSpellTextBox;
	
};
