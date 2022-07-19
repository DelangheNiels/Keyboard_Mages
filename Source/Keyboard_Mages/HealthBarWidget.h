// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.generated.h"

/**
 * 
 */

class ABaseCharacter;

//Set abstract so it is not selectable in a drop down menu
UCLASS( abstract )
class KEYBOARD_MAGES_API UHealthBarWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void SetOwner(ABaseCharacter* character);

protected:

	void NativeTick(const FGeometry& myGeometry, float inDeltaTime) override;

	UPROPERTY(meta = (BindWidget))
		class UProgressBar* m_pHealthBar;

private:

	UPROPERTY()
		ABaseCharacter* m_pOwner;
	
};
