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
	//デバック文字の表示
	GEngine->AddOnScreenDebugMessage(
		(uint64)-1,							//キー
		2.0f,								//開始する時間
		FLinearColor::Red.ToFColor(true),	//色の設定
		TEXT("HELLO,WORLD"));				//表示するテキスト内容
}

// Called when the game starts or when spawned
void AActorModel000::BeginPlay()
{
	Super::BeginPlay();
	
	//デバック文字の表示
	GEngine->AddOnScreenDebugMessage(
		(uint64)-1,							//キー
		2.0f,								//開始する時間
		FLinearColor::Red.ToFColor(true),	//色の設定
		TEXT("HELLO,WORLD"));				//表示するテキスト内容
}

// Called every frame
void AActorModel000::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

