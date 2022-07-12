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
	m_InputMode.SetHideCursorDuringCapture(true);
	SetInputMode(m_InputMode);

	if (HUD)
	{
		// Create the widget and store it.
		m_HUD = CreateWidget<UUserWidget>(this, HUD);

		if (m_HUD)
		{
			m_HUD->AddToViewport();

			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), WidgetChildren.Num()));
			if (m_HUD->GetWidgetFromName("SpellText"))
			{
				m_SpellTextBox = Cast<UEditableTextBox>(m_HUD->GetWidgetFromName("SpellText"));

				if (m_SpellTextBox)
				{
					//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("found"));
					//m_SpellTextBox->SetText(FText::FromString(TEXT("your text")));
				}

			}
			
		}

	}
}
