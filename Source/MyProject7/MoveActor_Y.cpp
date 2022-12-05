// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActor_Y.h"

// Sets default values
AMoveActor_Y::AMoveActor_Y()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//���b�V���̍쐬
	VisualMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	//�A�Z�b�g�̐ݒ�
	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	//�쐬�ɐ�������������
	if (CubeVisualAsset.Succeeded())
	{
		//�p�����[�^�[�ݒ�
		VisualMesh->SetStaticMesh(CubeVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	}
}

// Called when the game starts or when spawned
void AMoveActor_Y::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMoveActor_Y::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//�A�N�^�̈ʒu���擾
	FVector NewLocation = GetActorLocation();

	//���݂̍������Z�o
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = ((FMath::Sin(RunningTime + DeltaTime)) - FMath::Sin(RunningTime));

	//Z�����̐ݒ�
	NewLocation.Z += DeltaHeight * 20.0f;

	//�A�N�^�̈ʒu�֐ݒ�
	SetActorLocation(NewLocation);
}
