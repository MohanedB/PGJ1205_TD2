// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TimerZone.generated.h"


UENUM(BlueprintType)
enum class TimeZoneType : uint8
{
	Start	UMETA(DisplayName = "Start"),
	End		UMETA(DisplayName = "End")
};


UCLASS()
class TD2_API ATimerZone : public ATriggerBox
{
	GENERATED_BODY()

	ATimerZone();

protected:

	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void OnOverLapBegin(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnOverLapEnd(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere, Category = "Settings")
	TimeZoneType zoneType;

};
