// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "TP_ThirdPerson/TP_ThirdPersonGameMode.h"

// Sets default values
AItem::AItem()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserMesh"));
	RootComponent = Mesh;

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnOverLapBegin);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AItem::OnOverLapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Enter item"));
	if (OtherActor)
	{
		ATP_ThirdPersonCharacter* Character = Cast<ATP_ThirdPersonCharacter>(OtherActor);
		if (Character)
		{
			if (UWorld* World = GetWorld())
			{
				if (ATP_ThirdPersonGameMode* GameMode = Cast<ATP_ThirdPersonGameMode>(World->GetAuthGameMode()))
				{
					GameMode->IncrementScore();
					//Destroy();
					UE_LOG(LogTemp, Log, TEXT("Hide item"));
					SetActorHiddenInGame(true);
					SetActorEnableCollision(false);
				}
			}
		}
	}
}

void AItem::RespawnItem()
{
	UE_LOG(LogTemp, Log, TEXT("Respawn item"));

	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}

