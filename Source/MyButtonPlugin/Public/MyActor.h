
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
		UStaticMeshComponent* visual_mesh;


	UPROPERTY(EditAnywhere, Category = "Materials")
		UMaterialInstanceDynamic* dynamic_material_instance;

	FVector cube_location;
	FRotator cube_rotation;

	AMyActor();
	virtual void BeginPlay();
	virtual void Tick(float DeltaTime);
	virtual void CreateAndSetMaterialInstanceDynamic();
	virtual void Move();
	~AMyActor();
};