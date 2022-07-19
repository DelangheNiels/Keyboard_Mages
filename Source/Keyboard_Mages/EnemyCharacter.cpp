// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"
#include "BaseSpell.h"

AEnemyCharacter::AEnemyCharacter()
{

}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AEnemyCharacter::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	if (m_IsAttacking)
	{
		m_AttackTime += DeltaTime;
		if (m_AttackTime >= m_AttackDuration)
		{
			m_AttackTime = 0;
			m_IsAttacking = false;
			m_HasCastSpell = false;
		}

		if (m_AttackTime >= m_AttackDuration * 0.55 && !m_HasCastSpell)
		{
			CastSpell();

			if (m_pCastedSpell)
			{
				m_pCastedSpell->InverseYawRotation();
				m_pCastedSpell->InverseMovement();

				auto currentLocation = m_pCastedSpell->GetActorLocation();
				currentLocation.X = -52;
				m_pCastedSpell->SetActorLocation(currentLocation);
			}
				
		}
	}

	else
	{
		m_AttackTimer += DeltaTime;
		if (m_AttackTimer >= m_TimeToAttack)
		{
			m_AttackTimer = 0;
			StartCasting();
		}
	}

	if (m_IsHit)
	{
		m_StunTimer += DeltaTime;

		if (m_StunTimer >= m_HitStunDuration)
		{
			m_IsHit = false;
			m_StunTimer = 0;
		}
	}
}

void AEnemyCharacter::StartCasting()
{
	m_SpellIndex = FMath::RandRange(0, m_Spells.Num()-1);
	m_IsAttacking = true;
}

void AEnemyCharacter::TakeDamage(float damage)
{
	m_CurrentHealth -= damage;

	if (m_CurrentHealth > 0)
	{
		m_IsHit = true;
	}

	else
	{
		m_IsDead = true;
	}
}
