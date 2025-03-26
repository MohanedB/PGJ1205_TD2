// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerZone.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "TP_ThirdPerson/TP_ThirdPersonGameMode.h"

ATimerZone::ATimerZone()
{

}

void ATimerZone::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ATimerZone::OnOverLapBegin);
	OnActorEndOverlap.AddDynamic(this, &ATimerZone::OnOverLapEnd);


}

void ATimerZone::OnOverLapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && zoneType == TimeZoneType::End)
	{
		ATP_ThirdPersonCharacter* Character = Cast<ATP_ThirdPersonCharacter>(OtherActor);
		if (Character)
		{
			if (UWorld* World = GetWorld())
			{
				if (ATP_ThirdPersonGameMode* GameMode = Cast<ATP_ThirdPersonGameMode>(World->GetAuthGameMode()))
				{
					GameMode->EndTimer();
				}
			}
		}
	}
}

void ATimerZone::OnOverLapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && zoneType == TimeZoneType::Start)
	{
		ATP_ThirdPersonCharacter* Character = Cast<ATP_ThirdPersonCharacter>(OtherActor);
		if (Character)
		{
			if (UWorld* World = GetWorld())
			{
				if (ATP_ThirdPersonGameMode* GameMode = Cast<ATP_ThirdPersonGameMode>(World->GetAuthGameMode()))
				{
					GameMode->StartTimer();
				}
			}
		}
	}
}
