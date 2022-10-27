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
	 * Converts given time in seconds to different time formats.
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
	 * Returns player characters viewport location and rotation. 
	 */
	UFUNCTION(BlueprintCallable, Category="TrickyFunctionLibrary")
	static bool GetPlayerCharacterViewPoint(AActor* CharacterActor, FVector& ViewLocation, FRotator& ViewRotation);
	
	template <typename T>
	static void Approach(T& CurrentValue, const T TargetValue, const T DeltaValue)
	{
		CurrentValue = TargetValue > CurrentValue
			               ? FMath::Min(CurrentValue + DeltaValue, TargetValue)
			               : FMath::Max(CurrentValue - DeltaValue, TargetValue);
	}
	
	/**
	 * Changes the given int32 variable by a given delta value up to a target value.
	 * If CurrentValue > TargetValue, it will be decreased, else increased.
	 */
	UFUNCTION(BlueprintCallable, Category="TrickyFunctionLibrary")
	static void ApproachInt32(UPARAM(ref) int32& CurrentValue, const int32 TargetValue, const int32 DeltaValue);

	/**
	 * Changes the given float variable by a given delta value up to a target value.
	 * If CurrentValue > TargetValue, it will be decreased, else increased.
	 */
	UFUNCTION(BlueprintCallable, Category="TrickyFunctionLibrary")
	static void ApproachFloat(UPARAM(ref) float& CurrentValue, const float TargetValue, const float DeltaValue);

	/**
	 * Changes the given vector variable by a given delta value up to a target value.
	 * If CurrentValue > TargetValue, it will be decreased, else increased.
	 */
	UFUNCTION(BlueprintCallable, Category="TrickyFunctionLibrary")
	static void ApproachVector(UPARAM(ref) FVector& CurrentValue, const FVector TargetValue, const FVector DeltaValue);
};
