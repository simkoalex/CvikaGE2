// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "EndAttack.generated.h"

/**
 * 
 */
UCLASS()
class CVIKAGE2_API UEndAttack : public UAnimNotify
{
	GENERATED_BODY()

	void virtual Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
