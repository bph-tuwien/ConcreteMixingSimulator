// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <Runtime/Core/Public/Misc/FileHelper.h>
#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"


#include "RecipeReader.generated.h"


/**
 * 
 */
UCLASS()
class CONCRETEMIXING_API URecipeReader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "File I/O")
		static FString EvaluateMixture(int cement, int flyAsh, int recycledConcrete,
									   int sand, int water, int juteFibers,
									   int &id, bool &ok, FString &name, FString& description);
	
};
