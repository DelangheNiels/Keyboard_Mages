// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"

#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
ACamera::ACamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACamera::BeginPlay()
{
	Super::BeginPlay();

	m_pPlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (m_pPlayerController)
		m_pPlayerController->SetViewTargetWithBlend(this);
	
}

// Called every frame
void ACamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

