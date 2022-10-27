// MIT License Copyright (c) 2022 Artyom "Tricky Fat Cat" Volkov


#include "TrickyUtilsLibrary.h"

#include "Components/TimelineComponent.h"
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
