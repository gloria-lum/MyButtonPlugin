// Copyright Epic Games, Inc. All Rights Reserved.


#include "MyButtonPlugin.h"
#include "MyActor.h"
#include "EngineUtils.h"
#include "UObject/UObjectGlobals.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Widgets/Docking/SDockTab.h"
#include <Kismet/GameplayStatics.h>
#include "Runtime/Engine/Classes/Engine/World.h"
#include <IMaterialBakingAdapter.h>
#include <StaticMeshComponentAdapter.h>
#include <StaticMeshAdapter.h>
#include <stdbool.h>
#include "Components/Button.h"
#include <Editor.h>
#include "Engine/GameEngine.h"


#define LOCTEXT_NAMESPACE "FMyButtonPluginModule"
static const FName dummy_nomad_tab = TEXT("MyPluginTab");



void FMyButtonPluginModule::StartupModule()
{
	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->RegisterTabSpawner(dummy_nomad_tab, FOnSpawnTab::CreateRaw(this, &FMyButtonPluginModule::SpawnTab))
		.SetDisplayName(FText::FromString(TEXT("SuperPlugin")));
	tm->TryInvokeTab(dummy_nomad_tab);


}

bool  FMyButtonPluginModule::move_button_pressed = false;
bool  FMyButtonPluginModule::color_button_pressed = false;
bool  FMyButtonPluginModule::destroy_button_pressed = false;

TSharedRef<SDockTab>FMyButtonPluginModule::SpawnTab(const FSpawnTabArgs& TabSpawnArgs)
{

	TSharedRef<SDockTab> SpawnedTab = SNew(SDockTab)[
		SNew(SVerticalBox)
			+ SVerticalBox::Slot().AutoHeight().Padding(2).HAlign(EHorizontalAlignment::HAlign_Center)[
				SNew(SButton)
					.Text(FText::FromString(TEXT("Create Cube")))
					.ContentPadding(3)
					.OnClicked_Lambda([this]() -> FReply {
					SpawnCube();
				UpdateButtonVisibility();
				return FReply::Handled();})
			]

			+ SVerticalBox::Slot().AutoHeight().Padding(4).HAlign(EHorizontalAlignment::HAlign_Center)[
				SAssignNew(button_move, SButton)
					.Text(FText::FromString(TEXT("Move")))
					.ContentPadding(3)
					.Visibility(EVisibility::Hidden)
					.OnClicked_Lambda([this]() -> FReply {
					MoveInEditor();
				return FReply::Handled();
					})
					.OnPressed_Lambda([this]() {
						move_button_pressed = true;

					})
					.OnReleased_Lambda([this]() {
						move_button_pressed = false;
					})

			]
					+ SVerticalBox::Slot().AutoHeight().Padding(8, 8, 8, 8).HAlign(EHorizontalAlignment::HAlign_Center)[
						SAssignNew(button_change, SButton)
							.Text(FText::FromString(TEXT("change color")))
							.ContentPadding(3)
							.Visibility(EVisibility::Hidden)
							.OnClicked_Lambda([this]() -> FReply {
							ChangeColor();
						return FReply::Handled();
							})
							.OnPressed_Lambda([this]() {
								color_button_pressed = true;

							})
							.OnReleased_Lambda([this]() {
									color_button_pressed = false;
							})

					]
									+ SVerticalBox::Slot().AutoHeight().Padding(8, 8, 8, 8).HAlign(EHorizontalAlignment::HAlign_Center)[
										SAssignNew(button_destroy_on, SButton)
											.Text(FText::FromString(TEXT("Destroy ON")))
											.ContentPadding(3)
											.Visibility(EVisibility::Hidden)
											.OnClicked_Lambda([this]() -> FReply {
											destroy_button_pressed = true;
										return FReply::Handled();
											})
									]
											+ SVerticalBox::Slot().AutoHeight().Padding(8, 8, 8, 8).HAlign(EHorizontalAlignment::HAlign_Center)[
												SAssignNew(button_destroy_off, SButton)
													.Text(FText::FromString(TEXT("Destroy OFF, EDITOR")))
													.ContentPadding(3)
													.Visibility(EVisibility::Hidden)
													.OnClicked_Lambda([this]() -> FReply {
													destroy_button_pressed = false;
												DestroyObjectInEditor();
												return FReply::Handled();
													})

											]
	];
	return SpawnedTab;


}


FReply FMyButtonPluginModule::SpawnCube()
{

	UWorld* world = nullptr;
	const TIndirectArray<FWorldContext>& world_contexts = GEngine->GetWorldContexts();

	for (const FWorldContext& Context : world_contexts)
	{
		world = Context.World();
		FVector cube_location(FMath::RandRange(100.f, 300.f), FMath::RandRange(100.f, 800.f), FMath::RandRange(100.f, 800.f));
		FRotator cube_rotation(0.f, 10.f, 0.f);
		FTransform CubeTransform(cube_rotation, cube_location);

		AMyActor* new_actor = world->SpawnActor<AMyActor>(AMyActor::StaticClass(), cube_location, FRotator::ZeroRotator);

		new_actor->SetActorTransform(CubeTransform);
		new_actor->SetActorHiddenInGame(false);
		new_actor->visual_mesh->SetHiddenInGame(false);
		new_actor->visual_mesh->SetVisibility(true);
		new_actor->SetActorTickEnabled(true);

	}

	return FReply::Handled();
}

FReply FMyButtonPluginModule::ChangeColor()
{
	UWorld* world = GEngine->GetWorldContexts()[0].World();

	for (TActorIterator<AMyActor> actor_itr(world->GetWorld()); actor_itr; ++actor_itr)
	{
		AMyActor* found_actor = *actor_itr;

		found_actor->CreateAndSetMaterialInstanceDynamic();

	}
	return FReply::Handled();

}

FReply FMyButtonPluginModule::UpdateButtonVisibility()
{
	button_move->SetVisibility(EVisibility::Visible);
	button_change->SetVisibility(EVisibility::Visible);
	button_destroy_on->SetVisibility(EVisibility::Visible);
	button_destroy_off->SetVisibility(EVisibility::Visible);
	return FReply::Handled();
}

FReply FMyButtonPluginModule::MoveInEditor()
{
	UWorld* world = GEngine->GetWorldContexts()[0].World();

	for (TActorIterator<AMyActor> actor_itr(world->GetWorld()); actor_itr; ++actor_itr)
	{
		AMyActor* found_actor = *actor_itr;

		found_actor->Move();

	}


	return FReply::Handled();
}

FReply FMyButtonPluginModule::DestroyObjectInEditor()
{
	UWorld* world = GEngine->GetWorldContexts()[0].World();

	for (TActorIterator<AMyActor> actor_itr(world->GetWorld()); actor_itr; ++actor_itr)
	{
		AMyActor* found_actor = *actor_itr;

		found_actor->Destroy();
		found_actor->DestroyConstructedComponents();

		button_change->SetVisibility(EVisibility::Hidden);
		button_destroy_on->SetVisibility(EVisibility::Hidden);
		button_destroy_off->SetVisibility(EVisibility::Hidden);
		button_move->SetVisibility(EVisibility::Hidden);

	}
	return  FReply::Handled();
}


void FMyButtonPluginModule::ShutdownModule()
{
	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->UnregisterTabSpawner(dummy_nomad_tab);
}


#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMyButtonPluginModule, MyButtonPlugin)