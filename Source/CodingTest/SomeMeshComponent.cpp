// Fill out your copyright notice in the Description page of Project Settings.

#include "SomeMeshcomponent.h"
//#include "DynamicMeshBuilder.h"
//#include <VertexFactory.h>
//#include "MaterialShared.h"
//#include "UObject/ConstructorHelpers.h"
//#include "PrimitiveSceneProxy.h"
//
//class FMyVertexBuffer : public FVertexBuffer
//{
//public:
//	TArray<FVector> vertices;
//
//	virtual void InitRHI() override
//	{
//		FRHIResourceCreateInfo CreateInfo;
//		VertexBufferRHI = RHICreateVertexBuffer(vertices.Num() * sizeof(FVector), BUF_Static, CreateInfo);
//
//		// Copy the vertex data into the vertex buffer.
//		void* VertexBufferData = RHILockVertexBuffer(VertexBufferRHI, 0, vertices.Num() * sizeof(FVector), RLM_WriteOnly);
//		FMemory::Memcpy(VertexBufferData, vertices.GetData(), vertices.Num() * sizeof(FVector));
//		RHIUnlockVertexBuffer(VertexBufferRHI);
//	}
//};
//
//class FMyIndexBuffer : public FIndexBuffer
//{
//public:
//	TArray<int32> indices;
//
//
//	virtual void InitRHI() override
//	{
//		FRHIResourceCreateInfo CreateInfo;
//		IndexBufferRHI = RHICreateIndexBuffer(sizeof(int32), indices.Num() * sizeof(int32), BUF_Static, CreateInfo);
//
//		// Write the indices to the index buffer.
//		void* Buffer = RHILockIndexBuffer(IndexBufferRHI, 0, indices.Num() * sizeof(int32), RLM_WriteOnly);
//		FMemory::Memcpy(Buffer, indices.GetData(), indices.Num() * sizeof(int32));
//		RHIUnlockIndexBuffer(IndexBufferRHI);
//	}
//
//};
//
//
//
//
//class FMySceneProxy : public FPrimitiveSceneProxy
//{
//public:
//	FMySceneProxy(USomeMeshComponent* component)
//		:FPrimitiveSceneProxy(component),
//		indices(component->indices),
//		theMaterial(component->theMaterial)
//	{
//		//Need to copy the FDynamicMeshVertex and index buffers from the component
//
//		VertexBuffer = FMyVertexBuffer();
//		IndexBuffer = FMyIndexBuffer();
//
//		for (FVector Vertex : component->vertices)
//		{
//			vertices.Add(FDynamicMeshVertex(component->GetComponentLocation() + Vertex));
//		}
//
//	};
//
//	UPROPERTY()
//		UMaterial* theMaterial;
//
//	virtual FPrimitiveViewRelevance GetViewRelevance(const FSceneView* View)  const override
//	{
//		FPrimitiveViewRelevance Result;
//		Result.bDynamicRelevance = true;
//		Result.bDrawRelevance = true;
//		Result.bNormalTranslucencyRelevance = true;
//		return Result;
//	}
//
//	virtual void GetDynamicMeshElements(const TArray<const FSceneView*>& Views, const FSceneViewFamily& ViewFamily, uint32 VisibilityMap, FMeshElementCollector& Collector) const override
//	{
//		for (int32 ViewIndex = 0; ViewIndex < Views.Num(); ViewIndex++)
//		{
//
//			FDynamicMeshBuilder MeshBuilder;
//			if (vertices.Num() == 0)
//			{
//				return;
//			}
//			MeshBuilder.AddVertices(vertices);
//			MeshBuilder.AddTriangles(indices);
//
//			MeshBuilder.GetMesh(FMatrix::Identity, new FColoredMaterialRenderProxy(theMaterial->GetRenderProxy(false), FLinearColor::Gray), GetDepthPriorityGroup(Views[ViewIndex]), true, true, ViewIndex, Collector);
//
//		}
//	}
//
//	void FMySceneProxy::OnActorPositionChanged() override
//	{
//		VertexBuffer.ReleaseResource();
//		IndexBuffer.ReleaseResource();
//	}
//
//
//	uint32 FMySceneProxy::GetMemoryFootprint(void) const override
//	{
//		return sizeof(*this);
//		//this also needs to return the size of the arrays I'm thinking
//	}
//	virtual ~FMySceneProxy() {};
//private:
//	TArray<FDynamicMeshVertex> vertices;
//	TArray<int32> indices;
//	FMyVertexBuffer VertexBuffer;
//	FMyIndexBuffer IndexBuffer;
//};
//
//
//
//
//
//
//FPrimitiveSceneProxy* USomeMeshComponent::CreateSceneProxy()
//{
//	FPrimitiveSceneProxy* Proxy = NULL;
//	Proxy = new FMySceneProxy(this);
//	return Proxy;
//}
//
//USomeMeshComponent::USomeMeshComponent()
//{
//	static ConstructorHelpers::FObjectFinder<UMaterial>Material(TEXT("Material'/Engine/BasicShapes/BasicShapeMaterial'"));
//
//	if (Material.Object != NULL)
//	{
//		theMaterial = (UMaterial*)Material.Object;
//	}
//
//
//
//	vertices.Add(FVector(10, 0, 0));
//	vertices.Add(FVector(0, 10, 0));
//	vertices.Add(FVector(0, 0, 10));
//	indices.Add(0);
//	indices.Add(1);
//	indices.Add(2);
//}



