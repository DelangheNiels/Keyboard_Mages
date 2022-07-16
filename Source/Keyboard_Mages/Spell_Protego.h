// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSpell.h"
#include "Spell_Protego.generated.h"

/**
 * 
 */
UCLASS()
class KEYBOARD_MAGES_API ASpell_Protego : public ABaseSpell
{
	GENERATED_BODY()

public:

	ASpell_Protego();

	UPROPERTY(EditAnywhere, Category = "Spell")
		FVector m_MeshScale;

	UPROPERTY(EditAnywhere, Category = "Spell")
		float m_TimeToDissapear;

private:

	float m_AliveTimer;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

private:

	
};
