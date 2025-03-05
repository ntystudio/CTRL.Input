// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

#pragma once

#include "CoreMinimal.h"

#include "CTRLInput/CTRLInputConfig.h"

#include "Engine/DeveloperSettings.h"

#include "CTRLInputSettings.generated.h"

/**
 * 
 */
UCLASS(DefaultConfig, Config="Game", meta=(DisplayName="CTRL.Input"))
class CTRLINPUT_API UCTRLInputSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Config, EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UCTRLInputConfig> DefaultInputConfig;

public:
#if WITH_EDITORONLY_DATA
	virtual FName GetCategoryName() const override { return TEXT("CTRL"); }
	virtual FText GetSectionText() const override { return FText::FromString(TEXT("Input")); }
#endif
};
