// SPDX-FileCopyrightText: © 2025 NTY.studio
// SPDX-License-Identifier: MIT

#pragma once

#include "UserSettings/EnhancedInputUserSettings.h"

#include "CTRLPlayerMappableKeyProfile.generated.h"

UCLASS(DisplayName="Player Mappable Key Profile [CTRL]")
class CTRLINPUT_API UCTRLPlayerMappableKeyProfile : public UEnhancedPlayerMappableKeyProfile
{
	GENERATED_BODY()

protected:
	//~ Begin UEnhancedPlayerMappableKeyProfile interface
	virtual void EquipProfile() override;
	virtual void UnEquipProfile() override;
	//~ End UEnhancedPlayerMappableKeyProfile interface
};
