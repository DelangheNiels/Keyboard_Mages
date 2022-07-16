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


	/*if (m_pSphereCollision)
		m_pSphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ASpell_Fulgur::OnOverlapBegin);*/
}

void ASpell_Fulgur::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//void ASpell_Fulgur::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor != m_pCaster)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("hitting something"));
//		Destroy();
//	}
//}
