// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "S05__TestingGroundsHUD.generated.h"

UCLASS()
class AS05__TestingGroundsHUD : public AHUD
{
	GENERATED_BODY()

public:
	AS05__TestingGroundsHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

