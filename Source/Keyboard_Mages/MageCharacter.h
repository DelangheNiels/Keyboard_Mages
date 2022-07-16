// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "MageCharacter.generated.h"

/**
 * 
 */

class ABaseSpell;

UCLASS()
class KEYBOARD_MAGES_API AMageCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AMageCharacter();

	UPROPERTY(EditAnywhere, Category = "Spells")
		TArray<TSubclassOf<ABaseSpell>> m_Spells;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void CastSpell() override;

	virtual void StartCasting() override;

private:


	
};
