// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "BaseSpell.h"
#include "KeyboardMagesPlayerController.h"
#include "HealthBarWidget.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "Components/WidgetComponent.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_MaxHealth = 100.0f;
	m_CurrentHealth = m_MaxHealth;

	m_IsAttacking = false;
	m_IsHit = false;
	m_HasCastSpell = false;

	m_SpellIndex = -1;

	GetMesh()->SetGenerateOverlapEvents(true);
	GetMesh()->SetSimulatePhysics(false);

	m_pHealthBarWidgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBar"), false);
	m_pHealthBarWidgetComp->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	m_MontagePercentageToReleaseSpell = 0.0f;
}

float ABaseCharacter::GetCurrentHealth() const
{
	return m_CurrentHealth;
}

float ABaseCharacter::GetHealthPercentage() const
{
	return m_CurrentHealth / m_MaxHealth;
}

bool ABaseCharacter::GetIsAttacking() const
{
	return m_IsAttacking;
}

bool ABaseCharacter::GetIsHit() const
{
	return m_IsHit;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	m_pPlayerController = Cast<AKeyboardMagesPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

	if (m_pPlayerController && Camera)
	{
		m_pPlayerController->SetViewTargetWithBlend(Camera);
	}

	if(m_pAttackingMontage)
		m_AttackDuration = m_pAttackingMontage->CalculateSequenceLength();

	if (m_pHitReactionMontage)
		m_HitStunDuration = m_pHitReactionMontage->CalculateSequenceLength();

	UHealthBarWidget* pHealthBar = Cast<UHealthBarWidget>(m_pHealthBarWidgetComp->GetUserWidgetObject());
	pHealthBar->SetOwner(this);
		
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::CastSpell()
{
	FVector handLoc = GetMesh()->GetBoneLocation(m_BonenameToSpawnSpell);
	auto spell = GetWorld()->SpawnActor<AActor>(m_Spells[m_SpellIndex], handLoc, FRotator(0, 0, 0));

	m_pCastedSpell = Cast<ABaseSpell>(spell);
	m_pCastedSpell->SetCaster(this);

	m_SpellIndex = -1;
	m_HasCastSpell = true;
}

