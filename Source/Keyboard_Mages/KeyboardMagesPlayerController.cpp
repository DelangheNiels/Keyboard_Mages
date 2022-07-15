// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyboardMagesPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"

#include "Components/EditableTextBox.h"
#include "Internationalization/Text.h"

AKeyboardMagesPlayerController::AKeyboardMagesPlayerController()
{

}

void AKeyboardMagesPlayerController::BeginPlay()
{
	SetShowMouseCursor(false);
	
	m_InputMode.SetConsumeCaptureMouseDown(true);
	SetInputMode(m_InputMode);

	if (HUD)
	{
		// Create the widget and store it.
		m_HUD = CreateWidget<UUserWidget>(this, HUD);

		if (m_HUD)
		{
			m_HUD->AddToViewport();

			if (m_HUD->GetWidgetFromName("SpellText"))
			{
				m_SpellTextBox = Cast<UEditableTextBox>(m_HUD->GetWidgetFromName("SpellText"));

				if (m_SpellTextBox)
				{
					m_SpellTextBox->SetFocus();
				}

			}
			
		}

	}
}

FString AKeyboardMagesPlayerController::GetTextboxText() const
{
	return m_SpellTextBox->GetText().ToString();
}

void AKeyboardMagesPlayerController::ClearTextbox()
{
	m_SpellTextBox->SetText(FText::FromString(""));

}

void AKeyboardMagesPlayerController::EnableTextBox(bool enable)
{
	m_SpellTextBox->SetIsReadOnly(!enable);

	if (enable)
		m_SpellTextBox->SetFocus();
}
