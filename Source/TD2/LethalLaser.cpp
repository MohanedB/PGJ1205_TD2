// Fill out your copyright notice in the Description page of Project Settings.


#include "LethalLaser.h"
#include "TP_ThirdPerson/TP_ThirdPersonGameMode.h"
#include <Kismet/GameplayStatics.h>
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"


// Sets default values
ALethalLaser::ALethalLaser()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ALethalLaser::BeginPlay()
{
	Super::BeginPlay();
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);
    LaserOn = false;

}

// Called every frame
void ALethalLaser::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	LaserAppear();
}

void ALethalLaser::LaserAppear()
{
    // 1) On récupère le GameMode et son timer
    auto GM = Cast<ATP_ThirdPersonGameMode>(UGameplayStatics::GetGameMode(this));
    if (!GM)
        return;

    float t = GM->time;

    bool bShouldBeOn = (t >= 1.0f) && (FMath::Fmod(t - 1.0f, 3.0f) < 2.0f);

    // 3) Si l’état désiré diffère de l’état actuel, on bascule une fois
    if (bShouldBeOn && !LaserOn)
    {
        LaserOn = true;
        SetActorHiddenInGame(false);
        SetActorEnableCollision(true);
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(0, 2.0f, FColor::Red, TEXT("🔥 Laser ON"));
    }
    else if (!bShouldBeOn && LaserOn)
    {
        LaserOn = false;
        SetActorHiddenInGame(true);
        SetActorEnableCollision(false);
        if (GEngine)
            GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Blue, TEXT("💤 Laser OFF"));
    }
}
