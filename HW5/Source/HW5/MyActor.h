// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class HW5_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Move();
	float Distance(const FVector2D& first, const FVector2D& second) const;
	int32 Step() const;
	int32 CreateEvent() const;

	FVector2D start = FVector2D::ZeroVector;
	int32 evCnt = 0;
	float totDist = 0.0f;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
