// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCollidingPawn.h"
#include "Components/SphereComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyCollidingPawn::AMyCollidingPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//RootComponent�𓖂��蔻��p��SphereComponent�ɐݒ�
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));

	//���a�̐ݒ�
	RootComponent = SphereComponent;

	//�q���[�W�����v���t�@�C���̐ݒ�
	SphereComponent->SetCollisionProfileName(TEXT("Pown"));

	//���B�W���A�����b�V���̐ݒ�
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));

	SphereVisual->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		SphereVisual->SetWorldScale3D(FVector(0.8f));
	}

	//�X�v�����O�A�[���ɂ��J�����̐ݒ�
	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttacmentArm"));

	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	//�J�����𐶐��A�X�v�����O�A�[���ɐe�q�t��
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamere"));

	Camera->SetupAttachment(SpringArm,USpringArmComponent::SocketName);

	//���̓v���C���[�̐ݒ�
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	OurMovementComponent = CreateDefaultSubobject<UMyPawnMovementComponent>(TEXT("CustamMovementComponent"));

	OurMovementComponent->UpdatedComponent = RootComponent;
}

// Called when the game starts or when spawned
void AMyCollidingPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCollidingPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCollidingPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//MoveForward�̓��͒l��MoveForward�֐��փo�C���h����
	InputComponent->BindAxis("MoveForward", this, &AMyCollidingPawn::MoveForward);
}

UMyPawnMovementComponent* AMyCollidingPawn::GetMovementComponent() const
{
	return OurMovementComponent;
}

void AMyCollidingPawn::MoveForward(float AxisVisal)
{
	if (OurMovementComponent && OurMovementComponent->UpdatedComponent == RootComponent)
	{
		OurMovementComponent->AddInputVector(GetActorForwardVector() * AxisVisal);
	}
}
