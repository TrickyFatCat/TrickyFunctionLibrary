// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "TrickyUtilsLibrary.h"

#include "Components/TimelineComponent.h"
#include "GameFramework/Character.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/KismetMathLibrary.h"

FString UTrickyUtilsLibrary::ConvertTimeSeconds(const float TimeSeconds, const ETimeFormat TimeFormat)
{
	const FTimespan Timespan = UKismetMathLibrary::FromSeconds(TimeSeconds);

	FString Result = "";

	const int32 TotalMinutes = static_cast<int32>(Timespan.GetTotalMinutes());
	const int32 Seconds = Timespan.GetSeconds();
	const int32 TotalSeconds = static_cast<int32>(Timespan.GetTotalSeconds());
	const int32 Milliseconds = Timespan.GetFractionMilli();

	auto ConvertMilliseconds = [&Milliseconds](const float Fraction) -> int32
	{
		return static_cast<int32>(Milliseconds * Fraction);
	};

	switch (TimeFormat)
	{
	case ETimeFormat::MM_SS_MsMs:
		Result = FString::Printf(TEXT("%02d:%02d.%02d"),
		                         TotalMinutes,
		                         Seconds,
		                         ConvertMilliseconds(0.1f));
		break;

	case ETimeFormat::MM_SS_Ms:
		Result = FString::Printf(TEXT("%02d:%02d.%d"),
		                         TotalMinutes,
		                         Seconds,
		                         ConvertMilliseconds(0.01f));
		break;

	case ETimeFormat::MM_SS:
		Result = FString::Printf(TEXT("%02d:%02d"), TotalMinutes, Seconds);
		break;

	case ETimeFormat::SS_MsMs:
		Result = FString::Printf(TEXT("%02d.%02d"), TotalSeconds, ConvertMilliseconds(0.1f));
		break;

	case ETimeFormat::SS_Ms:
		Result = FString::Printf(TEXT("%02d.%d"), TotalSeconds, ConvertMilliseconds(0.01f));
		break;

	case ETimeFormat::SS:
		Result = FString::Printf(TEXT("%02d"), TotalSeconds);
		break;
	}

	return Result;
}

void UTrickyUtilsLibrary::SetTimelineRateToTime(UTimelineComponent* TimelineComponent,
                                                    const float TimelineLength,
                                                    const float TargetTime)
{
	
	if (!TimelineComponent || TargetTime <= 0.f || TimelineLength <= 0.f) return;

	TimelineComponent->SetPlayRate(TimelineLength / TargetTime);
}

bool UTrickyUtilsLibrary::GetPlayerCharacterViewPoint(AActor* CharacterActor, FVector& ViewLocation, FRotator& ViewRotation)
{
	const ACharacter* Character = Cast<ACharacter>(CharacterActor);

	if (!Character)
	{
		return false;
	}

	if (Character->IsPlayerControlled())
	{
		const APlayerController* Controller = Character->GetController<APlayerController>();

		if (!Controller)
		{
			return false;
		}
		
		Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);
	}

	return true;
}

void UTrickyUtilsLibrary::ApproachInt32(int32& CurrentValue, const int32 TargetValue, const int32 DeltaValue)
{
	Approach(CurrentValue, TargetValue, DeltaValue);
}

void UTrickyUtilsLibrary::ApproachFloat(float& CurrentValue, const float TargetValue, const float DeltaValue)
{
	Approach(CurrentValue, TargetValue, DeltaValue);
}

void UTrickyUtilsLibrary::ApproachVector(FVector& CurrentValue, const FVector TargetValue, const FVector DeltaValue)
{
	Approach(CurrentValue.X, TargetValue.X, DeltaValue.X);
	Approach(CurrentValue.Y, TargetValue.Y, DeltaValue.Y);
	Approach(CurrentValue.Z, TargetValue.Z, DeltaValue.Z);
}
