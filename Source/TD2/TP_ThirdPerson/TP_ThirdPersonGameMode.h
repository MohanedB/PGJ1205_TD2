// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TP_ThirdPersonGameMode.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerDiedSignature, ACharacter*, Character);

UCLASS(minimalapi)
class ATP_ThirdPersonGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ATP_ThirdPersonGameMode();

	const FOnPlayerDiedSignature& GetOnPlayerDied() const { return OnPlayerDied; }

	virtual void RestartPlayer(AController* NewPlayer) override;

	void StartTimer();

	void EndTimer();

	void ResetTimer();

	void IncrementScore();

	void ResetScore();

	UPROPERTY(VisibleAnywhere, Category = "Timer")
	float time;

	UPROPERTY(VisibleAnywhere, Category = "Timer")
	float besttime=0.0;

	UPROPERTY(VisibleAnywhere, Category = "Timer")
	bool bTimerIsRunning;

	UPROPERTY(VisibleAnywhere, Category = "Score")
	float score;

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	virtual void PlayerDied(ACharacter* Character);

	UPROPERTY()
	FOnPlayerDiedSignature OnPlayerDied;


};



