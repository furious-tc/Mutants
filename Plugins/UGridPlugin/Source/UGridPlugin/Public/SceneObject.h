// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "SceneObject.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct UGRIDPLUGIN_API FSceneObject : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="SceneObject")
	FName objectName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="SceneObject")
	FVector location;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="SceneObject")
	FRotator rotation;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="SceneObject")
	FVector scale;
};
