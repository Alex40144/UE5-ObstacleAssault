// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	this->initialPosition = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->movePlatform(DeltaTime);

	this->rotatePlatform(DeltaTime);
	
}

void AMovingPlatform::movePlatform(float DeltaTime)
{
	FVector currentPosition = GetActorLocation();
	currentPosition += this->velocity * DeltaTime;

	SetActorLocation(currentPosition);

	distanceMoved = FVector::Dist(this->initialPosition, currentPosition);

	if (distanceMoved > maxDistance)
	{
		this->initialPosition = this->initialPosition + this->velocity.GetSafeNormal() * maxDistance;
		SetActorLocation(this->initialPosition);
		this->velocity = -this->velocity;
	}
}

void AMovingPlatform::rotatePlatform(float DeltaTime)
{
	FRotator currentRotation = GetActorRotation();
	currentRotation = currentRotation + rotationVelocity * DeltaTime;
	SetActorRotation(currentRotation);
}