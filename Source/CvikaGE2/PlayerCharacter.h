// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class CVIKAGE2_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	UPROPERTY(EditAnywhere)
	int Damage = 1;

	bool bIsAttacking = false;

protected:
	float ForwardMovement = 0;
	float RightMovement = 0;

	const UCharacterMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* SwordMesh;

	UPROPERTY(EditAnywhere)
	class UAnimSequence* AttackAnimation;

	void MoveForward(float InputValue);

	void MoveRight(float InputValue);

	void Turn(float InputValue);

	void LookUp(float InputValue);

	void StartAttack();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
