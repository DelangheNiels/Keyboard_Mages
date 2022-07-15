// Fill out your copyright notice in the Description page of Project Settings.


#include "MageCharacter.h"
#include "KeyboardMagesPlayerController.h"
#include "BaseSpell.h"

AMageCharacter::AMageCharacter()
{
	//m_AttackDuration = 2.3f;
}

void AMageCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMageCharacter::CastSpell()
{
	Super::CastSpell();
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Casting spell"));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, m_pPlayerController->GetTextboxText());

	FString spellLowercase = m_pPlayerController->GetTextboxText().ToLower();
	
	FVector spawnPoint = GetActorLocation();
	spawnPoint.Y += 200;



	GetWorld()->SpawnActor<AActor>(m_Spells[0], spawnPoint, FRotator(0, 0, 0));

	m_pPlayerController->ClearTextbox();
	m_pPlayerController->EnableTextBox(false);
}

void AMageCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_IsAttacking)
	{
		m_AttackTime += DeltaTime;
		if (m_AttackTime >= m_AttackDuration)
		{
			m_AttackTime = 0;
			m_IsAttacking = false;
			m_pPlayerController->EnableTextBox(true);
		}
	}
}
