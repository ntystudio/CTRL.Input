// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

#include "CTRLInputComponent.h"

#include "EnhancedInputSubsystems.h"
#include UE_INLINE_GENERATED_CPP_BY_NAME(CTRLInputComponent)

class UCTRLInputConfig;

UCTRLInputComponent::UCTRLInputComponent(FObjectInitializer const& ObjectInitializer)
{
}

void UCTRLInputComponent::AddInputMappings(UCTRLInputConfig const* InputConfig, UEnhancedInputLocalPlayerSubsystem const* InputSubsystem) const
{
	check(InputConfig);
	check(InputSubsystem);

	// Here you can handle any custom logic to add something from your input config if required
}

void UCTRLInputComponent::RemoveInputMappings(UCTRLInputConfig const* InputConfig, UEnhancedInputLocalPlayerSubsystem const* InputSubsystem) const
{
	check(InputConfig);
	check(InputSubsystem);

	// Here you can handle any custom logic to remove input mappings that you may have added above
}

void UCTRLInputComponent::RemoveBinds(TArray<uint32>& BindHandles)
{
	for (auto const Handle : BindHandles)
	{
		RemoveBindingByHandle(Handle);
	}
	BindHandles.Reset();
}
