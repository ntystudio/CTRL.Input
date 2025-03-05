// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

#include "CTRLAimSensitivityData.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(CTRLAimSensitivityData)

UCTRLAimSensitivityData::UCTRLAimSensitivityData(FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SensitivityMap =
	{
		{ECTRLGamepadSensitivity::Slow, 0.5f},
		{ECTRLGamepadSensitivity::SlowPlus, 0.75f},
		{ECTRLGamepadSensitivity::SlowPlusPlus, 0.9f},
		{ECTRLGamepadSensitivity::Normal, 1.0f},
		{ECTRLGamepadSensitivity::NormalPlus, 1.1f},
		{ECTRLGamepadSensitivity::NormalPlusPlus, 1.25f},
		{ECTRLGamepadSensitivity::Fast, 1.5f},
		{ECTRLGamepadSensitivity::FastPlus, 1.75f},
		{ECTRLGamepadSensitivity::FastPlusPlus, 2.0f},
		{ECTRLGamepadSensitivity::Insane, 2.5f},
	};
}

float UCTRLAimSensitivityData::SensitivityEnumToFloat(ECTRLGamepadSensitivity const InSensitivity) const
{
	if (float const* Sens = SensitivityMap.Find(InSensitivity))
	{
		return *Sens;
	}

	return 1.0f;
}
