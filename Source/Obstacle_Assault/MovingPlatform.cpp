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
	
	startposition=GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	movePlatform(DeltaTime);
	rotatePlatform(DeltaTime);
}

void AMovingPlatform::movePlatform(float deltatime){

	if(Ismove)
	{
		if(shouldPlatformReturn()){
			FVector moveDrirection=velocity.GetSafeNormal();
			startposition=startposition+(moveDrirection * GetDistance());
			SetActorLocation(startposition);
			velocity=-velocity;
		}else{
			FVector currentLocation=GetActorLocation();
			currentLocation=currentLocation+(velocity*deltatime);
			SetActorLocation(currentLocation);
		}
	}
	
}

void AMovingPlatform::rotatePlatform(float deltatime)
{
	if(Isrotate){
		FRotator currentRot=GetActorRotation();
		SetActorRotation(currentRot+(Rotvelocity*deltatime));
	}
}

float AMovingPlatform::GetDistance() const
{
	FVector currentLocation=GetActorLocation();
	return FVector::Dist(startposition,currentLocation);
}

bool AMovingPlatform::shouldPlatformReturn() const
{
	return GetDistance() > MoveDistance;
}


