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

	//親子付け可能なダミーコンポーネントを作成
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	//カメラオブジェクトを生成
	UCameraComponent * OurCamara = CreateDefaultSubobject<UCameraComponent>(TEXT("OurComponent"));

	//可視オブジェクト(メッシュ)を作成
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	//RootComponentにカメラを親子付け
	OurCamara->SetupAttachment(RootComponent);

	//カメラが映す対象の位置に依存するように配置
	OurCamara->SetRelativeLocation(FVector(-250.0f,0.0f,250.0f));
	OurCamara->SetRelativeRotation(FRotator(-45.0f,0.0f,0.0f));

	//RootComponentに可視オブジェクト(メッシュ)を親子付け
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

	//移動量があればLocationを更新
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

	//MoveYの入力値をMove_YAxis関数をバインドする
	InputComponent->BindAxis("MoveY",this,&AMyPawn::Move_YAxis);
}

