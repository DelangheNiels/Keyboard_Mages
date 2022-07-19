// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Incendio.h"
#include "BaseCharacter.h"

#include "Components/SphereComponent.h"


ASpell_Incendio::ASpell_Incendio()
{
	m_Name = "Incendio";

}

void ASpell_Incendio::BeginPlay()
{
	Super::BeginPlay();
		
}

void ASpell_Incendio::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

