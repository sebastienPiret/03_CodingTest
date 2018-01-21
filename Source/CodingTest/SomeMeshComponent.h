// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/MeshComponent.h"
#include "PrimitiveSceneProxy.h"
#include "SomeMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=Experimental,meta=(BlueprintSpawnableComponent))
class CODINGTEST_API USomeMeshComponent : public UMeshComponent
{
	GENERATED_BODY()
	
public:
	// Begin UPrimitiveComponent interface
	/*virtual FPrimitiveSceneProxy* CreateSceneProxy() override;

	TArray<int32> indices;
	TArray<FVector> vertices;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Materials)
		UMaterial* theMaterial;
	
	USomeMeshComponent();*/
	
};
