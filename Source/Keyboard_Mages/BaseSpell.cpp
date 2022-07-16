// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSpell.h"
#include "BaseCharacter.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseSpell::ABaseSpell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_Name = "";
	m_pCaster = nullptr;

	FAttachmentTransformRules rules = FAttachmentTransformRules{ EAttachmentRule{ } , false };
	m_pStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	m_pStaticMeshComponent->SetSimulatePhysics(false);
	m_pStaticMeshComponent->AttachToComponent(RootComponent,rules);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshVisualAsset(TEXT("StaticMesh'/Game/Blueprints/Spells/Meshes/StaticMesh_Sphere.StaticMesh_Sphere'"));

	if (StaticMeshVisualAsset.Succeeded())
	{
		m_pStaticMeshComponent->SetStaticMesh(StaticMeshVisualAsset.Object);
		m_pStaticMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}

	m_pSphereCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	m_pSphereCollision->SetCollisionProfileName("Trigger");
	m_pSphereCollision->SetHiddenInGame(false);
	m_pSphereCollision->SetVisibility(true);
	m_pSphereCollision->AttachTo(m_pStaticMeshComponent);

}

// Called when the game starts or when spawned
void ABaseSpell::BeginPlay()
{
	Super::BeginPlay();
	m_pSphereCollision->SetSphereRadius(m_CollisionSphereRadius);
	//m_pSphereCollision->OnComponentBeginOverlap.AddDynamic(this, &ABaseSpell::OnOverlapBegin);
}

// Called every frame
void ABaseSpell::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FString ABaseSpell::GetSpellName()
{
	return m_Name;
}

void ABaseSpell::SetCaster(ABaseCharacter* caster)
{
	m_pCaster = caster;
}

//void ABaseSpell::OnOverlapBegin(UPrimitiveComponent* overlappedComponent, AActor* otherActor, UPrimitiveComponent* otherComp, int32 otherBodyIndex, bool bFromSweep, const FHitResult& sweepResult)
//{
//	/*if (otherActor != m_pCaster && m_pCaster != nullptr)
//	{
//		Destroy();
//	}*/
//}


