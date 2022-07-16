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

	if (m_pSphereCollision)
	{
		m_pSphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ASpell_Incendio::OnOverlapBegin);
	}
		
		
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));
	}
}

void ASpell_Incendio::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector newLocation = GetActorLocation();
	newLocation.Y += m_MovementSpeed * DeltaTime;

	SetActorLocation(newLocation);
}

void ASpell_Incendio::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != m_pCaster)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("hitting something"));
		Destroy();
	}
	
}
