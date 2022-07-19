// Fill out your copyright notice in the Description page of Project Settings.


#include "MageCharacter.h"
#include "KeyboardMagesPlayerController.h"
#include "BaseSpell.h"

AMageCharacter::AMageCharacter()
{
}

void AMageCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMageCharacter::StartCasting()
{
	FString spellLowercase = m_pPlayerController->GetTextboxText().ToLower();
	m_pPlayerController->ClearTextbox();

	for (int32 i = 0; i < m_Spells.Num(); i++)
	{
		if (m_Spells[i].GetDefaultObject()->GetSpellName() == spellLowercase)
		{
			m_SpellIndex = i;
		}
	}

	if (m_SpellIndex > -1)
	{
		m_IsAttacking = true;
		m_pPlayerController->EnableTextBox(false);
	}

}

void AMageCharacter::TakeDamage(float damage)
{
	m_CurrentHealth -= damage;

	if (m_CurrentHealth > 0)
	{
		m_pPlayerController->EnableTextBox(false);
		m_IsHit = true;
	}

	else
	{
		m_pPlayerController->EnableTextBox(false);
	}
}

void AMageCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_CurrentHealth > 0)
	{
		if (m_IsAttacking)
		{
			m_AttackTime += DeltaTime;
			if (m_AttackTime >= m_AttackDuration)
			{
				m_AttackTime = 0;
				m_IsAttacking = false;
				m_pPlayerController->EnableTextBox(true);
				m_HasCastSpell = false;
			}

			if (m_AttackTime >= m_AttackDuration * 0.47 && !m_HasCastSpell)
			{
				CastSpell();
			}
		}

		if (m_IsHit)
		{
			m_StunTimer += DeltaTime;

			if (m_StunTimer >= m_HitStunDuration)
			{
				m_pPlayerController->EnableTextBox(true);
				m_StunTimer = 0;
				m_IsHit = false;
			}
		}
	}

	
}
