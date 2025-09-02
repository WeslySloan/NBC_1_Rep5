
#include "MyActor.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	start = FVector2D(0.0f, 0.0f);
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	start = FVector2D(0.0f, 0.0f);

	move();
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 AMyActor::step()
{
	return UKismetMathLibrary::RandomIntegerInRange(0, 1);
}

void AMyActor::move()
{
	for (int i = 0; i < 10; ++i)
	{
		int32 stepX = step();
		int32 stepY = step();

		start.X += stepX;
		start.Y += stepY;

		UE_LOG(LogTemp, Warning, TEXT("Current Location: (X=%f, Y=%f)"), start.X, start.Y);
	}
}