

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


#define LOCTEXT_NAMESPACE "FMyButtonPluginModule"
static const FName DummyNomadTab = TEXT("MyPluginTab");


void FMyButtonPluginModule::StartupModule()
{
	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->RegisterTabSpawner(DummyNomadTab, FOnSpawnTab::CreateRaw(this, &FMyButtonPluginModule::SpawnTab))
		.SetDisplayName(FText::FromString(TEXT("SuperPlugin")));
	tm->TryInvokeTab(DummyNomadTab);
}


bool  FMyButtonPluginModule::moveButtonPressed = false;
bool  FMyButtonPluginModule::colorButtonPressed = false;
bool  FMyButtonPluginModule::destroyButtonPressed = false;

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
				SAssignNew(buttonMove, SButton)
					.Text(FText::FromString(TEXT("Move")))
					.ContentPadding(3)
					.Visibility(EVisibility::Hidden)
					.OnClicked_Lambda([this]() -> FReply {
					 MoveInEditor();
				return FReply::Handled();
					})
					.OnPressed_Lambda([this]() {
						moveButtonPressed = true;

					})
					.OnReleased_Lambda([this]() {
						moveButtonPressed = false;
					})

			]
					+ SVerticalBox::Slot().AutoHeight().Padding(8, 8, 8, 8).HAlign(EHorizontalAlignment::HAlign_Center)[
						SAssignNew(buttonChange, SButton)
							.Text(FText::FromString(TEXT("change color")))
							.ContentPadding(3)
							.Visibility(EVisibility::Hidden)
							.OnClicked_Lambda([this]() -> FReply {
							ChangeColor();
						return FReply::Handled();
							})
							.OnPressed_Lambda([this]() {
								colorButtonPressed = true;

							})
							.OnReleased_Lambda([this]() {
								colorButtonPressed = false;
							})

					]
									+ SVerticalBox::Slot().AutoHeight().Padding(8, 8, 8, 8).HAlign(EHorizontalAlignment::HAlign_Center)[
										SAssignNew(buttonDestroyON, SButton)
											.Text(FText::FromString(TEXT("Destroy ON")))
											.ContentPadding(3)
											.Visibility(EVisibility::Hidden)
											.OnClicked_Lambda([this]() -> FReply {
											destroyButtonPressed = true;
										return FReply::Handled();
											})
									]
											+ SVerticalBox::Slot().AutoHeight().Padding(8, 8, 8, 8).HAlign(EHorizontalAlignment::HAlign_Center)[
												SAssignNew(buttonDestroyOFF, SButton)
													.Text(FText::FromString(TEXT("Destroy OFF, EDITOR")))
													.ContentPadding(3)
													.Visibility(EVisibility::Hidden)
													.OnClicked_Lambda([this]() -> FReply {
													destroyButtonPressed = false;
												DestroyObjectInEditor();
												return FReply::Handled();
													})

											]
	];
	return SpawnedTab;



}
FReply FMyButtonPluginModule::SpawnCube()
{
	UWorld* World = GEngine->GetWorldContexts()[0].World();

	if (World)
	{
		
		FVector CubeLocation(FMath::RandRange(100.f, 300.f), FMath::RandRange(100.f, 800.f), FMath::RandRange(100.f, 800.f));
		FRotator CubeRotation(0.f, 10.f, 0.f);
		FTransform CubeTransform(CubeRotation, CubeLocation);
		AMyActor* new_actor = World->SpawnActor<AMyActor>(AMyActor::StaticClass(), CubeLocation, FRotator::ZeroRotator);

		new_actor->SetActorTransform(CubeTransform);
		new_actor->SetActorHiddenInGame(false);
		new_actor->VisualMesh->SetHiddenInGame(false);
		new_actor->VisualMesh->SetVisibility(true);
		new_actor->SetActorTickEnabled(true);
	
	}

	return FReply::Handled();
}

FReply FMyButtonPluginModule::ChangeColor()
{
	UWorld* World = GEngine->GetWorldContexts()[0].World();

	for (TActorIterator<AMyActor> ActorItr(World->GetWorld()); ActorItr; ++ActorItr)
	{
		AMyActor* FoundActor = *ActorItr;

		FoundActor->CreateAndSetMaterialInstanceDynamic();

	}
	return FReply::Handled();
}
FReply FMyButtonPluginModule::UpdateButtonVisibility()
{
	buttonMove->SetVisibility(EVisibility::Visible);
	buttonChange->SetVisibility(EVisibility::Visible);
	buttonDestroyOFF->SetVisibility(EVisibility::Visible);
	buttonDestroyON->SetVisibility(EVisibility::Visible);
	return FReply::Handled();
}

FReply FMyButtonPluginModule::MoveInEditor()
{
	UWorld* World = GEngine->GetWorldContexts()[0].World();

	for (TActorIterator<AMyActor> ActorItr(World->GetWorld()); ActorItr; ++ActorItr)
	{
		AMyActor* FoundActor = *ActorItr;

		FoundActor->Move();

	}

	return FReply::Handled();
}

FReply FMyButtonPluginModule::DestroyObjectInEditor()
{
	UWorld* World = GEngine->GetWorldContexts()[0].World();

	for (TActorIterator<AMyActor> ActorItr(World->GetWorld()); ActorItr; ++ActorItr)
	{
		AMyActor* FoundActor = *ActorItr;

		FoundActor->Destroy();
		FoundActor->DestroyConstructedComponents();

		buttonChange->SetVisibility(EVisibility::Hidden);
		buttonDestroyON->SetVisibility(EVisibility::Hidden);
		buttonDestroyOFF->SetVisibility(EVisibility::Hidden);
		buttonMove->SetVisibility(EVisibility::Hidden);

	}
	return  FReply::Handled();
}
void FMyButtonPluginModule::ShutdownModule()
{
	TSharedRef<class FGlobalTabmanager> tm = FGlobalTabmanager::Get();
	tm->UnregisterTabSpawner(DummyNomadTab);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FMyButtonPluginModule, MyButtonPlugin)