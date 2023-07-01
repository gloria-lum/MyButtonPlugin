// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "Math/Color.h"
#include "MyButtonPlugin.h"


AMyActor::AMyActor()
{

	PrimaryActorTick.bCanEverTick = true;
	bRunConstructionScriptOnDrag = true;
	visual_mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//VisualMesh->SetupAttachment(RootComponent);
	SetRootComponent(visual_mesh);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));//StaticMesh'/Engine/BasicShapes/Sphere.Sphere'

	if (CubeVisualAsset.Succeeded())
	{
		visual_mesh->SetStaticMesh(CubeVisualAsset.Object);
		visual_mesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		visual_mesh->SetVisibility(true);
		visual_mesh->SetHiddenInGame(false);
	}

	UWorld* world = GetWorld();

	if (world)
	{
		cube_location = FVector(0.f, 10.f, 0.f);
		cube_rotation = FRotator(0.f, 10.f, 0.f);
		FTransform CubeTransform(cube_rotation, cube_location);
		PrimaryActorTick.bCanEverTick = true;
		SetActorHiddenInGame(false);
	}


}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{

	Super::BeginPlay();

}


// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (FMyButtonPluginModule::move_button_pressed)
	{
		Move();
	}
	if (FMyButtonPluginModule::color_button_pressed)
	{
		CreateAndSetMaterialInstanceDynamic();
	}
	if (FMyButtonPluginModule::destroy_button_pressed)
	{
		this->Destroy();
	}
}

void AMyActor::CreateAndSetMaterialInstanceDynamic()
{
	FLinearColor RandomColor = FLinearColor::MakeRandomColor();
	if (!dynamic_material_instance)
	{
		dynamic_material_instance = UMaterialInstanceDynamic::Create(visual_mesh->GetMaterial(0), this);
	}
	else
	{
		dynamic_material_instance = Cast<UMaterialInstanceDynamic>(visual_mesh->GetMaterial(0));
	}
	dynamic_material_instance->SetVectorParameterValue(TEXT("Color"), RandomColor);
	visual_mesh->SetMaterial(0, dynamic_material_instance);

}
void AMyActor::Move()
{
	int min_x = 100;
	int max_x = 300;
	int min_y = 100;
	int max_y = 800;
	int max_z = 800;
	int min_z = 100;

	UWorld* World = GetWorld();

	if (World)
	{
		cube_location = FVector(FMath::RandRange(min_x, max_x), FMath::RandRange(min_y, max_y), FMath::RandRange(min_z, max_z));
		SetActorLocation(cube_location);
	}
}

AMyActor::~AMyActor()
{

	this->DestroyConstructedComponents();
	Super::Destroy();

}