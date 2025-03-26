// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RotatorBase2.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD2_API URotatorBase2 : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URotatorBase2();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation");
	float rotationSpeed = 30.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation");
	float rotationRange = 45.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation");
	FVector rotationAxis = FVector(0.0, 0.0, 1.0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation");
	bool bCanRotateBackAndForth = false;

private:
	float currentRotationAngle = 0.0f;
	float rotationDirection = 1.0f;

	void UpdateRotation(float DeltaTime);
};
