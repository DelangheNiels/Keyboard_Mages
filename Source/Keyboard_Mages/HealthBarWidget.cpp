// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthBarWidget.h"
#include "BaseCharacter.h"

#include "Components/ProgressBar.h"

void UHealthBarWidget::SetOwner(ABaseCharacter* character)
{
	m_pOwner = character;
}

void UHealthBarWidget::NativeTick(const FGeometry& myGeometry, float inDeltaTime)
{
	//Super::NativeTick(myGeometry, inDeltaTime);

	if (m_pOwner)
	{
		m_pHealthBar->SetPercent(m_pOwner->GetHealthPercentage());
	}
}
