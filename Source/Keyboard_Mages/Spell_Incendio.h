// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSpell.h"
#include "Spell_Incendio.generated.h"

/**
 * 
 */
UCLASS()
class KEYBOARD_MAGES_API ASpell_Incendio : public ABaseSpell
{
	GENERATED_BODY()

public:

	ASpell_Incendio();

protected:

	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	
};
