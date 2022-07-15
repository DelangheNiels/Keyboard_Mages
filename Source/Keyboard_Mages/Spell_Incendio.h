// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSpell.h"
#include "Spell_Incendio.generated.h"

/**
 * 
 */
UCLASS()
class KEYBOARD_MAGES_API ASpell_Incendio : public ABaseSpell
{
	GENERATED_BODY()

public:

	ASpell_Incendio();

protected:

	virtual void BeginPlay() override;

	virtual void CastSpell() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
