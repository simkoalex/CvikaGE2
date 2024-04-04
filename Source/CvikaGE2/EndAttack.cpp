// Fill out your copyright notice in the Description page of Project Settings.


#include "EndAttack.h"

#include "PlayerCharacter.h"

void UEndAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation,
                        const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (APlayerCharacter *PlayerCharacter = Cast<APlayerCharacter>(MeshComp->GetOwner()); IsValid(PlayerCharacter))
	{
		PlayerCharacter->bIsAttacking = false;
	}
}
