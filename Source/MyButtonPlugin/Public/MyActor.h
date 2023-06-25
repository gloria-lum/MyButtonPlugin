// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"


UCLASS()
class MYBUTTONPLUGIN_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* CubeMeshComponent;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VisualMesh;


	UPROPERTY(EditAnywhere, Category = "Materials")
		UMaterialInstanceDynamic* DynamicMaterialInstance;

	FVector CubeLocation;
	FRotator CubeRotation;

	AMyActor();
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);
	virtual void CreateAndSetMaterialInstanceDynamic();
	virtual void Move();
	~AMyActor();
};
