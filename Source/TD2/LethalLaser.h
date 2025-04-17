// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LethalLaser.generated.h"

UCLASS()
class TD2_API ALethalLaser : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALethalLaser();
	bool LaserOn;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Setup")
	UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void LaserAppear();

};
