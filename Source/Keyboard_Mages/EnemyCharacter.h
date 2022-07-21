// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "EnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class KEYBOARD_MAGES_API AEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

private:

	UPROPERTY(EditAnywhere, Category = "Attacking")
		float m_TimeToAttack;

	float m_AttackTimer;
	float m_CenterPosX;

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void StartCasting() override;

	virtual void TakeDamage(float damage) override;


};
