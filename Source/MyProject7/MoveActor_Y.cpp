// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveActor_Y.h"

// Sets default values
AMoveActor_Y::AMoveActor_Y()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//メッシュの作成
	VisualMesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	//アセットの設定
	static ConstructorHelpers::FObjectFinder<UStaticMesh>CubeVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	//作成に成功したか判定
	if (CubeVisualAsset.Succeeded())
	{
		//パラメーター設定
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

	//アクタの位置を取得
	FVector NewLocation = GetActorLocation();

	//現在の高さを算出
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = ((FMath::Sin(RunningTime + DeltaTime)) - FMath::Sin(RunningTime));

	//Z高さの設定
	NewLocation.Z += DeltaHeight * 20.0f;

	//アクタの位置へ設定
	SetActorLocation(NewLocation);
}

