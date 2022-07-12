// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyboardMagesPlayerController.h"

AKeyboardMagesPlayerController::AKeyboardMagesPlayerController()
{

}

void AKeyboardMagesPlayerController::BeginPlay()
{
	m_InputMode.SetHideCursorDuringCapture(true);
	SetInputMode(m_InputMode);
}
