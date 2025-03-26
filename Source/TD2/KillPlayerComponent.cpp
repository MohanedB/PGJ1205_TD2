// Fill out your copyright notice in the Description page of Project Settings.


#include "KillPlayerComponent.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"

// Sets default values for this component's properties
UKillPlayerComponent::UKillPlayerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UKillPlayerComponent::BeginPlay()
{
	Super::BeginPlay();


	AActor* Owner = GetOwner();
	if (Owner)
	{
		Mesh = Owner->FindComponentByClass<UStaticMeshComponent>();

		if (Mesh)
		{
			Mesh->OnComponentHit.AddDynamic(this, &UKillPlayerComponent::OnHit);
		}

	}
}

void UKillPlayerComponent::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor)
	{
		ATP_ThirdPersonCharacter* Character = Cast<ATP_ThirdPersonCharacter>(OtherActor);
		if (Character)
		{
			Character->CallRestartPlayer();
		}
	}
}

