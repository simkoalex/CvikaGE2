// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackNotify.h"

#include "PlayerCharacter.h"

void UAttackNotify::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime,
                               const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (APlayerCharacter *PlayerCharacter = Cast<APlayerCharacter>(MeshComp->GetOwner()); IsValid(PlayerCharacter))
	{
		PlayerCharacter->LineTrace();
	}
}
