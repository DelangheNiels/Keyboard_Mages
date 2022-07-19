// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class AKeyboardMagesPlayerController;
class ABaseSpell;

UCLASS()
class KEYBOARD_MAGES_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
		AActor* Camera;

	UPROPERTY(EditAnywhere, Category = "Animation Montages")
		UAnimMontage* m_pAttackingMontage;

	UPROPERTY(EditAnywhere, Category = "Animation Montages")
		UAnimMontage* m_pHitReactionMontage;

	UPROPERTY(EditAnywhere, Category = "Animation Montages")
		UAnimMontage* m_pDeadMontage;

	UPROPERTY(EditAnywhere, Category = "Spells")
		TArray<TSubclassOf<ABaseSpell>> m_Spells;

	UPROPERTY(EditAnywhere, Category = "Animation Montages")
		FName m_BonenameToSpawnSpell;

	UPROPERTY(EditAnywhere)
		class UWidgetComponent* m_pHealthBarWidgetComp;

	UPROPERTY()
	AKeyboardMagesPlayerController* m_pPlayerController;

	UPROPERTY()
	ABaseSpell* m_pCastedSpell;
	
	float m_MaxHealth;
	
	float m_CurrentHealth;

	bool m_IsAttacking;

	bool m_IsHit;

	bool m_HasCastSpell;

	float m_AttackTime;

	float m_AttackDuration;

	int32 m_SpellIndex;

	float m_HitStunDuration;
	float m_StunTimer;

	bool m_IsDead;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		virtual void CastSpell();

	UFUNCTION(BlueprintCallable)
		virtual void StartCasting() PURE_VIRTUAL(ABaseCharacter::StartCasting, );

	UFUNCTION()
		virtual void TakeDamage(float damage) PURE_VIRTUAL(ABaseCharacter::TakeDamage, );

	UFUNCTION(BlueprintCallable)
		float GetCurrentHealth() const;

	UFUNCTION(BlueprintCallable)
		float GetHealthPercentage() const;

	UFUNCTION(BlueprintCallable)
		bool GetIsAttacking() const;

	UFUNCTION(BlueprintCallable)
		bool GetIsHit() const;

private:

	float m_DeadTimer;
	float m_TimeToPauseDeadAnimation;

};
