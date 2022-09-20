// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"




UCLASS()
class OBSTACLE_ASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	
	UPROPERTY(EditAnywhere, Category="Moving Velocity")
	FVector velocity=FVector(100,0,0);
	UPROPERTY(EditAnywhere, Category="Moving Velocity")	
	double MoveDistance=100;
	UPROPERTY(VisibleAnywhere, Category="Moving Velocity")
	FVector startposition;
	UPROPERTY(EditAnywhere, Category="Moving Velocity")	
	bool Ismove;

	UPROPERTY(EditAnywhere, Category="Moving Rotation")	
	FRotator Rotvelocity=FRotator(0,0,100);	
	UPROPERTY(EditAnywhere, Category="Moving Rotation")	
	bool Isrotate;

	void movePlatform(float DeltaTime);
	void rotatePlatform(float DeltaTime);

	bool shouldPlatformReturn() const;
	float GetDistance() const; 
	

};
