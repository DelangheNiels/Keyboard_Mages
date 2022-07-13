// Fill out your copyright notice in the Description page of Project Settings.


#include "MageCharacter.h"

AMageCharacter::AMageCharacter()
{

}

void AMageCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void AMageCharacter::CastSpell()
{
	Super::CastSpell();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Casting spell"));
}

void AMageCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
