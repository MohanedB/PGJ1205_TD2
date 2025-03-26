// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementBase.h"

// Sets default values for this component's properties
UMovementBase::UMovementBase()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMovementBase::BeginPlay()
{
	Super::BeginPlay();

	if (AActor* Owner = GetOwner())
	{
		startPosition = Owner->GetActorLocation();
	}
	
}


// Called every frame
void UMovementBase::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UpdateMouvement(DeltaTime);
}

void UMovementBase::UpdateMouvement(float DeltaTime)
{
	if (!GetOwner()) {	return;	}

	FVector normalizedDirection = movementDirection.GetSafeNormal();
	FVector offset = normalizedDirection * speed * DeltaTime;

	FVector newPosition = GetOwner()->GetActorLocation() + offset;

	if (bCanMoveBackAndForth)
	{
		if (FVector::Dist(startPosition, newPosition) >= movementRange)
		{
			movementDirection = -movementDirection;
			newPosition = GetOwner()->GetActorLocation() + movementDirection.GetSafeNormal() * speed * DeltaTime;
		}
	}

	GetOwner()->SetActorLocation(newPosition);
}