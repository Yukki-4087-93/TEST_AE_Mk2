// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawnMovementComponent.h"

void UMyPawnMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//i dou kanou ni natte iruka tyekku
	if (PawnOwner || UpdatedComponent || ShouldSkipUpdate(DeltaTime))
	{
		return;
	}

	//�ړ��x�N�g�����擾
	FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.0f;

	if (!DesiredMovementThisFrame.IsNearlyZero())
	{
		FHitResult Hit;

		SafeMoveUpdatedComponent(DesiredMovementThisFrame,
								 UpdatedComponent->GetComponentRotation(),
								 true,
								 Hit);

		//�����蔻�肪�N�����犊�炩�Ɉړ�
		if (Hit.IsValidBlockingHit())
		{
			SlideAlongSurface(DesiredMovementThisFrame,1.f - Hit.Time,Hit.Normal,Hit);
		}
	}
}


