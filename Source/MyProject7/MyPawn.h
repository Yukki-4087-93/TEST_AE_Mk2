// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class MYPROJECT7_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

	//�\������I�u�W�F�N�g���Ǘ�����R���|�[�l���g
	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;

	void Move_YAxis(float faxsiValue);

	//���݂̑��x
	FVector CurrentVelocity;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

};
