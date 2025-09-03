// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class NBC_1_REP5_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	FVector2D start;

	UPROPERTY()
	int32 TotalEventCount;

	UPROPERTY()
	float TotalDistance;

	void move();
	int32 step();

	float distance(FVector2D first, FVector2D second);

	int32 createEvent();
};


