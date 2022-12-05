// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorModel000.generated.h"

UCLASS()
class MYPROJECT7_API AActorModel000 : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AActorModel000();
	virtual void OnConstruction(const FTransform& transform);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
