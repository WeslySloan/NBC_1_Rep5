#include "MyActor.h"
#include "Kismet/KismetMathLibrary.h"

AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;

	start = FVector2D(0.0f, 0.0f);

	TotalEventCount = 0;
	TotalDistance = 0.0f;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	start = FVector2D(0.0f, 0.0f);

	TotalEventCount = 0;
	TotalDistance = 0.0f;

	move();
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 AMyActor::step()
{
	return UKismetMathLibrary::RandomIntegerInRange(0, 1);
}

float AMyActor::distance(FVector2D first, FVector2D second)
{
	return FVector2D::Distance(first, second);
}

int32 AMyActor::createEvent()
{
	return UKismetMathLibrary::RandomBool() ? 1 : 0;
}

void AMyActor::move()
{
	for (int i = 0; i < 10; i++)
	{
		FVector2D prevLocation = start;

		int32 stepX = step();
		int32 stepY = step();

		start.X += stepX;
		start.Y += stepY;

		float currentStepDist = distance(prevLocation, start);

		TotalDistance += currentStepDist;

		bool bEventOccurred = (createEvent() == 1);
		if (bEventOccurred)
		{
			TotalEventCount++;
		}

		UE_LOG(LogTemp, Warning, TEXT("Step %d: Location(X=%f, Y=%f), Distance: %f, Event: %s"),
			i + 1, start.X, start.Y, currentStepDist, bEventOccurred ? TEXT("Active") : TEXT("None"));
	}

	UE_LOG(LogTemp, Warning, TEXT("Result: Total Distance: %f, Total Events: %d"), TotalDistance, TotalEventCount);
}