// Fill out your copyright notice in the Description page of Project Settings.

//include file
#include "MyPawn.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	//�e�q�t���\�ȃ_�~�[�R���|�[�l���g���쐬
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//�J�����I�u�W�F�N�g�𐶐�
	UCameraComponent * OurCamara = CreateDefaultSubobject<UCameraComponent>(TEXT("OurComponent"));

	//���I�u�W�F�N�g(���b�V��)���쐬
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	//RootComponent�ɃJ������e�q�t��
	OurCamara->SetupAttachment(RootComponent);

	//�J�������f���Ώۂ̈ʒu�Ɉˑ�����悤�ɔz�u
	OurCamara->SetRelativeLocation(FVector(-250.0f,0.0f,250.0f));
	OurCamara->SetRelativeRotation(FRotator(-45.0f,0.0f,0.0f));

	//RootComponent�ɉ��I�u�W�F�N�g(���b�V��)��e�q�t��
	OurVisibleComponent->SetupAttachment(RootComponent);
}

void AMyPawn::Move_YAxis(float faxsiValue)
{
	CurrentVelocity.Y = FMath::Clamp(faxsiValue,-1.0f,1.0f) * 100.0f;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//�ړ��ʂ������Location���X�V
	if (CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//MoveY�̓��͒l��Move_YAxis�֐����o�C���h����
	InputComponent->BindAxis("MoveY",this,&AMyPawn::Move_YAxis);
}

