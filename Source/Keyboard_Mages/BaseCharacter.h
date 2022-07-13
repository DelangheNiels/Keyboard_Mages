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

	UFUNCTION(BlueprintCallable)
		float GetCurrentHealth();

	UFUNCTION(BlueprintCallable)
		float GetHealthPercentage();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Camera")
	AActor* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	virtual void CastSpell();

private:
	UPROPERTY()
		float m_MaxHealth;
	UPROPERTY()
		float m_CurrentHealth;

	AKeyboardMagesPlayerController* m_pPlayerController;

};
