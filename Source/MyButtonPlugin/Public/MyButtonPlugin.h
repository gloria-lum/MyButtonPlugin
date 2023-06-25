// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FMyButtonPluginModule : public IModuleInterface
{
public:
	TSharedPtr<SButton> buttonMove;
	TSharedPtr<SButton> buttonChange;
	TSharedPtr<SButton> buttonDestroyON;
	TSharedPtr<SButton> buttonDestroyOFF;

	static bool moveButtonPressed;
	static bool colorButtonPressed;
	static bool destroyButtonPressed;

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
