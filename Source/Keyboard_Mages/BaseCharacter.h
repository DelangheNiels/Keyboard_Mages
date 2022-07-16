// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class AKeyboardMagesPlayerController;

UCLASS()
class KEYBOARD_MAGES_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
		AActor* Camera;

	UPROPERTY(EditAnywhere, Category = "Animation Montages")
		UAnimMontage* m_pAttackingMontage;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	AKeyboardMagesPlayerController* m_pPlayerController;

	
	float m_MaxHealth;
	
	float m_CurrentHealth;

	bool m_IsAttacking;

	bool m_IsHit;

	bool m_HasCastSpell;

	float m_AttackTime;

	float m_AttackDuration;

	int32 m_SpellIndex;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		virtual void CastSpell() PURE_VIRTUAL(ABaseCharacter::CastSpell,);

	UFUNCTION(BlueprintCallable)
		virtual void StartCasting() PURE_VIRTUAL(ABaseCharacter::StartCasting, );

	UFUNCTION(BlueprintCallable)
		float GetCurrentHealth() const;

	UFUNCTION(BlueprintCallable)
		float GetHealthPercentage() const;

	UFUNCTION(BlueprintCallable)
		bool GetIsAttacking() const;

	UFUNCTION(BlueprintCallable)
		bool GetIsHit() const;

private:
};
