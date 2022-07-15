// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "KeyboardMagesPlayerController.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_MaxHealth = 100.0f;
	m_CurrentHealth = m_MaxHealth;

	m_IsAttacking = false;
	m_IsHit = false;

}

float ABaseCharacter::GetCurrentHealth() const
{
	return m_CurrentHealth;
}

float ABaseCharacter::GetHealthPercentage() const
{
	return m_CurrentHealth / m_MaxHealth;
}

bool ABaseCharacter::GetIsAttacking() const
{
	return m_IsAttacking;
}

bool ABaseCharacter::GetIsHit() const
{
	return m_IsHit;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	m_pPlayerController = Cast<AKeyboardMagesPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (m_pPlayerController && Camera)
	{
		m_pPlayerController->SetViewTargetWithBlend(Camera);
	}

	if(m_pAttackingMontage)
		m_AttackDuration = m_pAttackingMontage->CalculateSequenceLength();
		
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::CastSpell()
{
	m_IsAttacking = true;
}

