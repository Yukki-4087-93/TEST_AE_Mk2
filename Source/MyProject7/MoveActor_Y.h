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

	//staticMeshコンポーネントを宣言
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
	EditAnywhere　エディタ上でプロパティを公開し、編集を可能にする
	
	BlueprintReadWrite　ブループリントでの読み取りと書き込みを可能にする
	
	Category　エディタ上に公開されたプロパティをカテゴリー(ネスティング)に分ける
	*/
};
