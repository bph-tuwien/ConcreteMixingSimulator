// Fill out your copyright notice in the Description page of Project Settings.


#include "RecipeReader.h"
#include <Runtime/Core/Public/Misc/Paths.h>
#include <Runtime/Core/Public/HAL/PlatformFilemanager.h>


FString URecipeReader::EvaluateMixture(FString Filename)
{
	FString result;



	bool bOk = true;

	FString jsonFileName = "recipesConfig.json";

	FString FullPath = FPaths::ProjectContentDir() + jsonFileName;

	FString JsonStr;

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FullPath))
	{
		bOk = false;
	}

	if (bOk)
	{
		FFileHelper::LoadFileToString(JsonStr, *FullPath);

		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonStr);
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
		FJsonSerializer::Deserialize(JsonReader, JsonObject);


		TArray<TSharedPtr<FJsonValue>> recipes;
		recipes = JsonObject->GetArrayField("recipes");

		//FPlayerInventoryStruct item;
		for (int32 i = 0; i < recipes.Num(); i++)
		{
			/*item.id = aInventory[i]->AsObject()->GetIntegerField("id");
			item.name = aInventory[i]->AsObject()->GetStringField("Name");
			item.count = aInventory[i]->AsObject()->GetIntegerField("count");

			this->playerStruct.aInventory.Add(item);*/

			result = recipes[i]->AsObject()->GetStringField("name");

		}

	}




	return result;
}
