// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyActor.h"

void AMyGameModeBase::BeginPlay()
{
    Super::BeginPlay();

    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    FVector Location(0.0f, 0.0f, 0.0f);
    FRotator Rotation(0.0f, 0.0f, 0.0f);

    AMyActor* MySpawnedActor = GetWorld()->SpawnActor<AMyActor>(Location, Rotation, SpawnParams);

    if (MySpawnedActor)
    {
        /*UE_LOG(LogTemp, Warning, TEXT("AMyActor has been spawned successfully!"));*/ // 스폰체크용
    }
}