// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	FVector startPos = FVector(0.0f, 0.0f, 0.0f);
	SetActorLocation(startPos);
	start = FVector2D(startPos);
	for (int i = 0; i < 10; i++)
	{
		Move();
	}
	UE_LOG(LogTemp, Log, TEXT("Total Distance :: %f / Event Count :: %d"), totDist, evCnt);
}

void AMyActor::Move()
{
	FVector pos = GetActorLocation();
	FVector newPos = { pos.X + Step(), pos.Y + Step(), pos.Z };
	SetActorLocation(newPos);
	float distance = Distance(FVector2D(pos), FVector2D(newPos));
	UE_LOG(LogTemp, Log, TEXT("Location :: %s / Moved Distance :: %f"), *newPos.ToString(), distance);
	totDist += distance;
	evCnt += CreateEvent();
}

float AMyActor::Distance(const FVector2D& first, const FVector2D& second) const
{
	float x = second.X - first.X;
	float y = second.Y - first.Y;
	return sqrt(x * x + y * y);
}

int32 AMyActor::Step() const
{
	return FMath::RandRange(0, 1);
}

int32 AMyActor::CreateEvent() const
{
	int32 rand = FMath::RandRange(0, 1);
	if (rand == 1)
	{
		UE_LOG(LogTemp, Warning, TEXT("New Event!!"));
	}
	return rand;
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

