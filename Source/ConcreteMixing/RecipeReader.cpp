// Fill out your copyright notice in the Description page of Project Settings.


#include "RecipeReader.h"
#include <Runtime/Core/Public/Misc/Paths.h>
#include <Runtime/Core/Public/HAL/PlatformFilemanager.h>
#include <ConcreteMixing/FRecipe.h>


FString URecipeReader::EvaluateMixture(int cement, int flyAsh, int recycledConcrete,
									   int sand, int water, int juteFibers,
									   int& id, bool& ok, FString& name, FString& description)
{
	FString result;

	TArray<FRecipe>recipes;

	
	// #################
	// Loading JSON data
	// #################

	FString jsonFileName = "recipesConfig.json";
	FString FullPath = FPaths::ProjectContentDir() + jsonFileName;
	FString JsonStr;

	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*FullPath))
	{
		FFileHelper::LoadFileToString(JsonStr, *FullPath);

		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonStr);
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
		FJsonSerializer::Deserialize(JsonReader, JsonObject);


		TArray<TSharedPtr<FJsonValue>> jsonRecipes;
		jsonRecipes = JsonObject->GetArrayField("recipes");


		FRecipe recipe;
		for (int32 i = 0; i < jsonRecipes.Num(); i++)
		{
			recipe.id = jsonRecipes[i]->AsObject()->GetIntegerField("id");
			recipe.ok = jsonRecipes[i]->AsObject()->GetBoolField("ok");
			recipe.name = jsonRecipes[i]->AsObject()->GetStringField("name");
			recipe.description = jsonRecipes[i]->AsObject()->GetStringField("description");

			recipe.cementMin = jsonRecipes[i]->AsObject()->GetIntegerField("cementMin");
			recipe.cementMax = jsonRecipes[i]->AsObject()->GetIntegerField("cementMax");

			recipe.flyAshMin = jsonRecipes[i]->AsObject()->GetIntegerField("flyAshMin");
			recipe.flyAshMax = jsonRecipes[i]->AsObject()->GetIntegerField("flyAshMax");

			recipe.recycledConcreteMin = jsonRecipes[i]->AsObject()->GetIntegerField("recycledConcreteMin");
			recipe.recycledConcreteMax = jsonRecipes[i]->AsObject()->GetIntegerField("recycledConcreteMax");

			recipe.sandMin = jsonRecipes[i]->AsObject()->GetIntegerField("sandMin");
			recipe.sandMax = jsonRecipes[i]->AsObject()->GetIntegerField("sandMax");

			recipe.waterMin = jsonRecipes[i]->AsObject()->GetIntegerField("waterMin");
			recipe.waterMax = jsonRecipes[i]->AsObject()->GetIntegerField("waterMax");

			recipe.juteFibersMin = jsonRecipes[i]->AsObject()->GetIntegerField("juteFibersMin");
			recipe.juteFibersMax = jsonRecipes[i]->AsObject()->GetIntegerField("juteFibersMax");

			recipes.Add(recipe);
		}

	}

	// ##################
	// Evaluating mixture
	// ##################

	int32 matchingRecipeIndex = -1;

	for (int32 i = 0; i < recipes.Num(); i++)
	{

		if (!(recipes[i].cementMin <= cement && cement <= recipes[i].cementMax))
		{
			continue;
		}

		if (!(recipes[i].flyAshMin <= flyAsh && flyAsh <= recipes[i].flyAshMax))
		{
			continue;
		}

		if (!(recipes[i].recycledConcreteMin <= recycledConcrete && recycledConcrete <= recipes[i].recycledConcreteMax))
		{
			continue;
		}

		if (!(recipes[i].sandMin <= sand && sand <= recipes[i].sandMax))
		{
			continue;
		}

		if (!(recipes[i].waterMin <= water && water <= recipes[i].waterMax))
		{
			continue;
		}

		if (!(recipes[i].juteFibersMin <= juteFibers && juteFibers <= recipes[i].juteFibersMax))
		{
			continue;
		}

		matchingRecipeIndex = i;
		break;
	}


	id = matchingRecipeIndex;
	ok = recipes[id].ok;
	name = recipes[id].name;
	description = recipes[id].description;


	return FString::FromInt(matchingRecipeIndex);
}
