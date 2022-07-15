// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSpell.generated.h"

class UStaticMeshComponent;

UCLASS()
class KEYBOARD_MAGES_API ABaseSpell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseSpell();

	UPROPERTY(EditAnywhere, Category = "Spell")
		float m_MovementSpeed;

	UPROPERTY(EditAnywhere, Category = "Spell")
		float m_Damage;

	UPROPERTY(EditAnywhere, Category = "Spell")
		float m_CollisionSphereRadius;

protected:

	FString m_Name;

	UPROPERTY()
		class USphereComponent* m_pSphereCollision;

	UPROPERTY()
	UStaticMeshComponent* m_pStaticMeshComponent;

	AActor* m_pCaster;


private:

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void CastSpell();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FString GetName();

	void Cast();

	UFUNCTION()
		void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


private:

};
