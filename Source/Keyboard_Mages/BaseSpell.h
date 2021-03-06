// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSpell.generated.h"

class UStaticMeshComponent;
class ABaseCharacter;

UCLASS()
class KEYBOARD_MAGES_API ABaseSpell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseSpell();

protected:

	UPROPERTY(EditAnywhere, Category = "Spell")
		float m_MovementSpeed;

	UPROPERTY(EditAnywhere, Category = "Spell")
		float m_Damage;

	UPROPERTY(EditAnywhere, Category = "Spell")
		float m_CollisionSphereRadius;

	UPROPERTY()
		class USphereComponent* m_pSphereCollision;

	FString m_Name;

	UPROPERTY()
	UStaticMeshComponent* m_pStaticMeshComponent;

	UPROPERTY()
	ABaseCharacter* m_pCaster;


private:

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
		virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString GetSpellName();

	void SetCaster(ABaseCharacter* caster);

	void InverseMovement();

	void InverseYawRotation();


private:
};
