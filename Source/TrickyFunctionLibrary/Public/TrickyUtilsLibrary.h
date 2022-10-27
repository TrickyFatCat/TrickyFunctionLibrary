// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TrickyUtilsLibrary.generated.h"

class UTimelineComponent;
class AActor;

/**
 * 
 */
UENUM(BlueprintType)
enum class ETimeFormat : uint8
{
	MM_SS_MsMs UMETA(DisplayName="MM:SS.MsMs"),
	MM_SS_Ms UMETA(DisplayName="MM:SS.Ms"),
	MM_SS UMETA(DisplayName="MM:SS"),
	SS_MsMs UMETA(DisplayName="SS.MsMs"),
	SS_Ms UMETA(DisplayName="SS.Ms"),
	SS UMETA(DisplayName="SS")
};

/**
 * 
 */
UCLASS()
class TRICKYFUNCTIONLIBRARY_API UTrickyUtilsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	/**
	 * Converts given time in seconds in different time formats.
	 */
	UFUNCTION(BlueprintPure, Category="TrickyFunctionLibrary")
	static FString ConvertTimeSeconds(const float TimeSeconds, const ETimeFormat TimeFormat);

	/**
	 * Sets timeline play rate to play as long as TargetTime.
	 */
	UFUNCTION(BlueprintCallable, Category="TrickyFunctionLibrary")
	static void SetTimelineRateToTime(UTimelineComponent* TimelineComponent,
	                                      const float TimelineLength = 1.f,
	                                      const float TargetTime = 1.f);

	/**
	 *
	 */
	UFUNCTION(BlueprintCallable, Category="TrickyFunctionLibrary")
	static bool GetPlayerCharacterViewPoint(AActor* CharacterActor, FVector& ViewLocation, FRotator& ViewRotation);
};
