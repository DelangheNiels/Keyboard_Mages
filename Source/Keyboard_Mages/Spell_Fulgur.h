// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSpell.h"
#include "Spell_Fulgur.generated.h"

/**
 * 
 */
UCLASS()
class KEYBOARD_MAGES_API ASpell_Fulgur : public ABaseSpell
{
	GENERATED_BODY()

public:

	ASpell_Fulgur();

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

private:

	/*UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);*/
	
};
