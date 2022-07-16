// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Incendio.h"
#include "BaseCharacter.h"

#include "Components/SphereComponent.h"


ASpell_Incendio::ASpell_Incendio()
{
	m_Name = "Incendio";
	m_pStaticMeshComponent->SetSimulatePhysics(false);

}

void ASpell_Incendio::BeginPlay()
{
	Super::BeginPlay();

	/*if (m_pSphereCollision)
		m_pSphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ASpell_Incendio::OnOverlapBegin);*/
		
		
}

void ASpell_Incendio::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

