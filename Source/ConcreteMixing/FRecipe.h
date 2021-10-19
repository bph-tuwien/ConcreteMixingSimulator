#pragma once


#include "CoreMinimal.h"

#include "FRecipe.generated.h"

USTRUCT(BlueprintType)
struct FRecipe
{
	GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 id = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		bool ok = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		FString name = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		FString description = "";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 cementMin = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 cementMax = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 flyAshMin = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 flyAshMax = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 recycledConcreteMin = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 recycledConcreteMax = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 sandMin = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 sandMax = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 waterMin = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 waterMax = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 juteFibersMin = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
		int32 juteFibersMax = 0;



};