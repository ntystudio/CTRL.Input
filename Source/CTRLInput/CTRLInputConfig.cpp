// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

#include "CTRLInputConfig.h"

#include "CTRLInput/CTRLInput.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CTRLInputConfig)

// ReSharper disable once CppEnforceCVQualifiersPlacement
const UInputAction* UCTRLInputConfig::FindNativeInputActionForTag(FGameplayTag const& FindInputTag, bool const bLogNotFound) const
{
	for (auto const& [InputAction, InputTag] : NativeInputActions)
	{
		if (InputAction && InputTag == FindInputTag)
		{
			return InputAction.Get();
		}
	}

	if (bLogNotFound)
	{
		CTRL_INPUT_LOG(Error, TEXT("Can't find NativeInputAction for InputTag [%s] on InputConfig [%s]."), *FindInputTag.ToString(), *GetNameSafe(this));
	}

	return nullptr;
}

// ReSharper disable once CppEnforceCVQualifiersPlacement
const UInputAction* UCTRLInputConfig::FindAbilityInputActionForTag(FGameplayTag const& FindInputTag, bool const bLogNotFound) const
{
	for (auto const& [InputAction, InputTag] : AbilityInputActions)
	{
		if (InputAction && InputTag == FindInputTag)
		{
			return InputAction.Get();
		}
	}

	if (bLogNotFound)
	{
		CTRL_INPUT_LOG(Error, TEXT("Can't find AbilityInputAction for InputTag [%s] on InputConfig [%s]."), *FindInputTag.ToString(), *GetNameSafe(this));
	}

	return nullptr;
}
