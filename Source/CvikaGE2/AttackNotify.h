// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "AttackNotify.generated.h"

/**
 * 
 */
UCLASS()
class CVIKAGE2_API UAttackNotify : public UAnimNotifyState
{
	GENERATED_BODY()

	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;
};
