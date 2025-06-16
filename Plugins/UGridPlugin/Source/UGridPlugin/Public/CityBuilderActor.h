// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SceneObject.h"
#include "Engine/ObjectLibrary.h"
#include "GameFramework/Actor.h"
#include "CityBuilderActor.generated.h"

UENUM(BlueprintType)
enum class EAssetLoadingPolicy : uint8
{
	FromProject UMETA(DisplayName="Load meshes from project assets"),
	FromLevel UMETA(DisplayName="Load meshes from level"),
};


UCLASS()
class UGRIDPLUGIN_API ACityBuilderActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACityBuilderActor();

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Asset Loading Settings")
	EAssetLoadingPolicy AssetLoadingPolicy;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Asset Loading Settings", meta=(RelativePath, EditCondition="AssetLoadingPolicy == EAssetLoadingPolicy::FromProject", EditConditionHides))
	TArray<FDirectoryPath> Paths;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="CityBuilder|Mesh Loading")
	void GetMeshes(TArray<UStaticMesh*>& OutMeshes);

	UFUNCTION(BlueprintCallable, Category="CityBuilder|MeshUtils")
	void SetMeshName(const FString& Name, AActor* Actor);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="CityBuilder|Mesh Loading")
	void GetAllObjectsFromDT(UDataTable* SourceDT, TArray<FSceneObject>& OutSceneObjects);
	
	UFUNCTION(BlueprintCallable, BlueprintPure, Category="CityBuilder|Mesh Loading")
	void LoadAllMeshesFromDirectory(const TArray<FString>& Path, TArray<UStaticMesh*>& OutMeshes);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="CityBuilder|Mesh Loading")
	void LoadMeshesFromLevel(TArray<UStaticMesh*>& OutMeshes);

private:
	UPROPERTY()
	UObjectLibrary* ObjectLibrary;

	TArray<FString> ConvertAbsolutePathToRelative(const TArray<FDirectoryPath>& Directories);
};
