// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

#pragma once

#include "Engine/DataAsset.h"

#include "CTRLAimSensitivityData.generated.h"

UENUM(BlueprintType)
enum class ECTRLGamepadSensitivity : uint8
{
	Invalid = 0 UMETA(Hidden),

	Slow UMETA(DisplayName = "01 - Slow"),
	SlowPlus UMETA(DisplayName = "02 - Slow+"),
	SlowPlusPlus UMETA(DisplayName = "03 - Slow++"),
	Normal UMETA(DisplayName = "04 - Normal"),
	NormalPlus UMETA(DisplayName = "05 - Normal+"),
	NormalPlusPlus UMETA(DisplayName = "06 - Normal++"),
	Fast UMETA(DisplayName = "07 - Fast"),
	FastPlus UMETA(DisplayName = "08 - Fast+"),
	FastPlusPlus UMETA(DisplayName = "09 - Fast++"),
	Insane UMETA(DisplayName = "10 - Insane"),

	MAX UMETA(Hidden),
};

class UObject;

/** Defines a set of gamepad sensitivity to a float value. */
UCLASS(BlueprintType, Const, Meta = (DisplayName = "Aim Sensitivity Data [CTRL]", ShortTooltip = "Data asset used to define a map of Gamepad Sensitivty to a float value."))
class CTRLINPUT_API UCTRLAimSensitivityData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UCTRLAimSensitivityData(FObjectInitializer const& ObjectInitializer);

	float SensitivityEnumToFloat(ECTRLGamepadSensitivity const InSensitivity) const;

protected:
	/** Map of SensitivityMap settings to their corresponding float */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<ECTRLGamepadSensitivity, float> SensitivityMap;
};
