// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_ThirdPersonGameMode.h"
#include "TP_ThirdPersonCharacter.h"
#include "../Item.h"
#include "UObject/ConstructorHelpers.h"
#include "EngineUtils.h"

ATP_ThirdPersonGameMode::ATP_ThirdPersonGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	PrimaryActorTick.bCanEverTick = true;
}

void ATP_ThirdPersonGameMode::RestartPlayer(AController* NewPlayer)
{
	Super::RestartPlayer(NewPlayer);

	ResetTimer();
	ResetScore();

	for (TActorIterator<AItem> It(GetWorld()); It; ++It)
	{
		(*It)->RespawnItem();
	}
}

void ATP_ThirdPersonGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (!OnPlayerDied.IsBound())
	{
		OnPlayerDied.AddDynamic(this, &ATP_ThirdPersonGameMode::PlayerDied);
	}
}

void ATP_ThirdPersonGameMode::PlayerDied(ACharacter* Character)
{
	AController* CharacterController = Character->GetController();
	RestartPlayer(CharacterController);
}

void ATP_ThirdPersonGameMode::Tick(float DeltaTime)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 1.f, FColor::Red, FString::Printf(TEXT("Time : %f"), time));		
		GEngine->AddOnScreenDebugMessage(3, 1.f, FColor::Green, FString::Printf(TEXT("Score : %f"), score));
		GEngine->AddOnScreenDebugMessage(4, 1.f, FColor::Green, FString::Printf(TEXT("BestTime : %f"), besttime));

	}
	if (bTimerIsRunning)
	{
		time += DeltaTime;
	}
}

void ATP_ThirdPersonGameMode::StartTimer()
{
	bTimerIsRunning = true;
	time = 0;
}

void ATP_ThirdPersonGameMode::EndTimer()
{
	bTimerIsRunning = false;

	if (time > 0.0f && time > besttime)
	{
		besttime = time;
	}
}

void ATP_ThirdPersonGameMode::ResetTimer()
{
	bTimerIsRunning = false;
	time = 0;
}

void ATP_ThirdPersonGameMode::IncrementScore()
{
	score++;
}

void ATP_ThirdPersonGameMode::ResetScore()
{
	score = 0;
}


