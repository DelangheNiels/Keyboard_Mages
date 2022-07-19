// Fill out your copyright notice in the Description page of Project Settings.


#include "Spell_Protego.h"
#include "BaseCharacter.h"

#include "Components/SphereComponent.h"

ASpell_Protego::ASpell_Protego()
{
	m_Name = "Protego";

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshVisualAsset(TEXT("StaticMesh'/Game/Blueprints/Spells/Meshes/StaticMesh_HalfSphere.StaticMesh_HalfSphere'"));

	if (StaticMeshVisualAsset.Succeeded())
	{
		m_pStaticMeshComponent->SetStaticMesh(StaticMeshVisualAsset.Object);
		m_pStaticMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

void ASpell_Protego::BeginPlay()
{
	Super::BeginPlay();

	m_pStaticMeshComponent->SetWorldScale3D(m_MeshScale);
	m_pStaticMeshComponent->AddLocalRotation(FRotator(0, 180, 0));
}

void ASpell_Protego::Tick(float DeltaTime)
{
	m_AliveTimer += DeltaTime;

	if (m_AliveTimer >= m_TimeToDissapear)
	{
		Destroy();
	}
}

