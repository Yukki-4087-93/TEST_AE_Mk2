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

	//RootComponentを当たり判定用のSphereComponentに設定
	USphereComponent* SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));

	//半径の設定
	RootComponent = SphereComponent;

	//子りゅージョンプロファイルの設定
	SphereComponent->SetCollisionProfileName(TEXT("Pown"));

	//ヴィジュアルメッシュの設定
	UStaticMeshComponent* SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));

	SphereVisual->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh>SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));

	if (SphereVisualAsset.Succeeded())
	{
		SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
		SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		SphereVisual->SetWorldScale3D(FVector(0.8f));
	}

	//スプリングアームによるカメラの設定
	USpringArmComponent* SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttacmentArm"));

	SpringArm->SetupAttachment(RootComponent);
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->bEnableCameraLag = true;
	SpringArm->CameraLagSpeed = 3.0f;

	//カメラを生成、スプリングアームに親子付け
	UCameraComponent* Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("ActualCamere"));

	Camera->SetupAttachment(SpringArm,USpringArmComponent::SocketName);

	//入力プレイヤーの設定
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

	//MoveForwardの入力値をMoveForward関数へバインドする
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
