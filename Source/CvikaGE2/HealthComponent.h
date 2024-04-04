// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CVIKAGE2_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	int Health = 2;

	void TakeDamage(int Damage, uint32 ActorID);
	
protected:

	TArray<uint32> TakenDamageFrom;

	void Die();

	void AllowTakeDamage(uint32 ActorID);

};
