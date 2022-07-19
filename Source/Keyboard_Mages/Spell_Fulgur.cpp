// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Fulgur.h"
#include "BaseCharacter.h"

#include "Components/SphereComponent.h"

ASpell_Fulgur::ASpell_Fulgur()
{
	m_Name = "Fulgur";

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshVisualAsset(TEXT("StaticMesh'/Game/Blueprints/Spells/Meshes/StaticMesh_Lightning.StaticMesh_Lightning'"));

	if (StaticMeshVisualAsset.Succeeded())
	{
		m_pStaticMeshComponent->SetStaticMesh(StaticMeshVisualAsset.Object);
		m_pStaticMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

void ASpell_Fulgur::BeginPlay()
{
	Super::BeginPlay();
}

void ASpell_Fulgur::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
