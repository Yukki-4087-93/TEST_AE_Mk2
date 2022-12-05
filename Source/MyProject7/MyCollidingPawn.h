// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawnMovementComponent.h"
#include "MyCollidingPawn.generated.h"

UCLASS()
class MYPROJECT7_API AMyCollidingPawn : public APawn
{
	GENERATED_BODY()
		

public:
	// Sets default values for this pawn's properties
	AMyCollidingPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnyehere)UMyPawnMovementComponent* OurMovementComponent;

	virtual UMyPawnMovementComponent* GetMovementComponent() const override;

	void MoveForward(float AxisVisal);
};
