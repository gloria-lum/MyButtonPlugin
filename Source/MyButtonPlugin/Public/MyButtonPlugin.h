// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FMyButtonPluginModule : public IModuleInterface
{
public:

	TSharedPtr<SButton> button_move;
	TSharedPtr<SButton> button_change;
	TSharedPtr<SButton> button_destroy_on;
	TSharedPtr<SButton> button_destroy_off;

	static bool move_button_pressed;
	static bool color_button_pressed;
	static bool destroy_button_pressed;

	FReply UpdateButtonVisibility();
	FReply ChangeColor();
	TSharedRef<SDockTab> SpawnTab(const FSpawnTabArgs& TabSpawnArgs);
	FReply SpawnCube();
	FReply DestroyObjectInEditor();
	FReply MoveInEditor();

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

};
