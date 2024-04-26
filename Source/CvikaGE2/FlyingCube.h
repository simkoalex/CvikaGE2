// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FlyingCube.generated.h"

UCLASS()
class CVIKAGE2_API AFlyingCube : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* MeshComp;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	bool bIsFlying = false;
	
	int ForceStrength = 100000;
public:
	AFlyingCube();
	virtual void Tick(float DeltaTime) override;
	
	void Ignite();
};
