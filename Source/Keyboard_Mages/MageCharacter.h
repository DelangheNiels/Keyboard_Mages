// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "MageCharacter.generated.h"

/**
 * 
 */

UCLASS()
class KEYBOARD_MAGES_API AMageCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AMageCharacter();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void StartCasting() override;

	virtual void TakeDamage(float damage) override;

private:

	UPROPERTY(EditAnywhere, Category = "Spells")
		float m_WrongSpellWaitTime;

	float m_WrongSpellTimer;

	bool m_CastedWrongSpell;
	
};
