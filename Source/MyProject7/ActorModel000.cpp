// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorModel000.h"

// Sets default values
AActorModel000::AActorModel000()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AActorModel000::OnConstruction(const FTransform& transform)
{
	//�f�o�b�N�����̕\��
	GEngine->AddOnScreenDebugMessage(
		(uint64)-1,							//�L�[
		2.0f,								//�J�n���鎞��
		FLinearColor::Red.ToFColor(true),	//�F�̐ݒ�
		TEXT("HELLO,WORLD"));				//�\������e�L�X�g���e
}

// Called when the game starts or when spawned
void AActorModel000::BeginPlay()
{
	Super::BeginPlay();
	
	//�f�o�b�N�����̕\��
	GEngine->AddOnScreenDebugMessage(
		(uint64)-1,							//�L�[
		2.0f,								//�J�n���鎞��
		FLinearColor::Red.ToFColor(true),	//�F�̐ݒ�
		TEXT("HELLO,WORLD"));				//�\������e�L�X�g���e
}

// Called every frame
void AActorModel000::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

