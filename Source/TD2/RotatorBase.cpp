// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatorBase.h"

// Sets default values for this component's properties
URotatorBase::URotatorBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URotatorBase::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URotatorBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (AActor* owner = GetOwner())
	{
		FRotator newRotation = owner->GetActorRotation();

		if (bRotateX)
		{
			newRotation.Roll += speed * DeltaTime;
		}

		if (bRotateY)
		{
			newRotation.Pitch += speed * DeltaTime;
		}

		if (bRotateZ)
		{
			newRotation.Yaw += speed * DeltaTime;
		}

		owner->SetActorRotation(newRotation);
	}
}

