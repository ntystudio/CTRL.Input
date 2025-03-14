﻿// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

#include "CTRLInputSetupComponent.h"

#include "AbilitySystemGlobals.h"
#include "EnhancedInputSubsystems.h"

#include "CTRLGas/CTRLAbilitySystemComponent.h"

#include "CTRLInput/CTRLInput.h"
#include "CTRLInput/CTRLInputComponent.h"
#include "CTRLInput/CTRLInputSettings.h"

#include "Components/InputComponent.h"

#include "Engine/LocalPlayer.h"

#include "GameFramework/Pawn.h"

UCTRLInputSetupComponent::UCTRLInputSetupComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCTRLInputSetupComponent::SetupInputComponent(APlayerController* PlayerController, UInputComponent* PlayerInputComponent)
{
	// Add Input Mapping Context
    if (auto const* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
    {
        auto const Settings = GetDefault<UCTRLInputSettings>();
        auto const InputConfigSoft = Settings->DefaultInputConfig;
        if (InputConfigSoft.IsNull())
        {
            CTRL_INPUT_LOG(Error, TEXT("%s InputConfig is null"), *GetNameSafe(this));
            return;
        }
        else
        {
            if (auto const InputConfig = InputConfigSoft.LoadSynchronous())
            {
                auto const CTRLInputComponent = Cast<UCTRLInputComponent>(PlayerInputComponent);
                if (ensureMsgf(
                    CTRLInputComponent,
                    TEXT("Unexpected Input Component class! The Gameplay Abilities will not be bound to their inputs. Change the input component to UCTRLInputComponent or a subclass of it.")
                ))
                {
                    // Add the key mappings that may have been set by the player
                    CTRLInputComponent->AddInputMappings(InputConfig, Subsystem);

                    // This is where we actually bind and input action to a gameplay tag, which means that Gameplay Ability Blueprints will
                    // be triggered directly by these input actions Triggered events. 
                    CTRLInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::OnInput_AbilityInputTagPressed, &ThisClass::OnInput_AbilityInputTagReleased, /*out*/ BindHandles);
                }
            }
            else
            {
                CTRL_INPUT_LOG(Error, TEXT("%s InputConfig is null"), *GetNameSafe(this));
            }
        }
	}
}

// ReSharper disable once CppMemberFunctionMayBeConst
void UCTRLInputSetupComponent::OnInput_AbilityInputTagPressed(FGameplayTag const InputTag)
{
	if (auto const ASC = UCTRLAbilitySystemComponent::GetASC(GetOwner()))
	{
		ASC->OnAbilityInputTagPressed(InputTag);
	}
}

// ReSharper disable once CppMemberFunctionMayBeConst
void UCTRLInputSetupComponent::OnInput_AbilityInputTagReleased(FGameplayTag const InputTag)
{
	if (auto const ASC = UCTRLAbilitySystemComponent::GetASC(GetOwner()))
	{
		ASC->OnAbilityInputTagReleased(InputTag);
	}
}
