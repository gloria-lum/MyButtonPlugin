// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "MyButtonPlugin.h"


// Sets default values
AMyActor::AMyActor()
{
		
		PrimaryActorTick.bCanEverTick = true;
		bRunConstructionScriptOnDrag = true;
		VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
		//VisualMesh->SetupAttachment(RootComponent);
		SetRootComponent(VisualMesh);
		static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));//StaticMesh'/Engine/BasicShapes/Sphere.Sphere'

		if (CubeVisualAsset.Succeeded())
		{
			VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
			VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
			VisualMesh->SetVisibility(true);
			VisualMesh->SetHiddenInGame(false);
		}

		UWorld* World = GetWorld();

		if (World)
		{
			CubeLocation = FVector(0.f, 10.f, 0.f);
			CubeRotation = FRotator(0.f, 10.f, 0.f);
			FTransform CubeTransform(CubeRotation, CubeLocation);
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
	
	if (FMyButtonPluginModule::moveButtonPressed)
	{
		Move();
	}
	if (FMyButtonPluginModule::colorButtonPressed)
	{
		CreateAndSetMaterialInstanceDynamic();
	}
	if (FMyButtonPluginModule::destroyButtonPressed)
	{
		this->Destroy();
	}
}

void AMyActor::CreateAndSetMaterialInstanceDynamic()
{
	FLinearColor RandomColor = FLinearColor::MakeRandomColor();
	if (!DynamicMaterialInstance)
	{
		DynamicMaterialInstance = UMaterialInstanceDynamic::Create(VisualMesh->GetMaterial(0), this);
	}
	else
	{
		DynamicMaterialInstance = Cast<UMaterialInstanceDynamic>(VisualMesh->GetMaterial(0));
	}
	DynamicMaterialInstance->SetVectorParameterValue(TEXT("Color"), RandomColor);
	VisualMesh->SetMaterial(0, DynamicMaterialInstance);

}
void AMyActor::Move()
{
	int MinX = 100;
	int MaxX = 300;
	int MinY = 100;
	int MaxY = 800;
	int MaxZ = 800;
	int MinZ = 100;

	UWorld* World = GetWorld();

	if (World)
	{
		CubeLocation = FVector(FMath::RandRange(MinX, MaxX), FMath::RandRange(MinY, MaxY), FMath::RandRange(MinZ, MaxZ));
		SetActorLocation(CubeLocation);
	}
}

AMyActor::~AMyActor()
{

	this->DestroyConstructedComponents();
	Super::Destroy();
	
}