// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor_Y.generated.h"

UCLASS()
class MYPROJECT7_API AMoveActor_Y : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMoveActor_Y();

	//staticMesh�R���|�[�l���g��錾
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="FloatingProperty")
	float fSpeed = 20.0f;
	float fRotSpeed = 20.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	/*
	EditAnywhere�@�G�f�B�^��Ńv���p�e�B�����J���A�ҏW���\�ɂ���
	
	BlueprintReadWrite�@�u���[�v�����g�ł̓ǂݎ��Ə������݂��\�ɂ���
	
	Category�@�G�f�B�^��Ɍ��J���ꂽ�v���p�e�B���J�e�S���[(�l�X�e�B���O)�ɕ�����
	*/
};
