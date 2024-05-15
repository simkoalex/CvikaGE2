// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

enum EAnimation
{
	No = -1,
	Idle = 0,
	Run = 1,
	Backward = 2,
	Right = 3,
	Left = 4,
	Attack = 5,
	Swim = 6
};

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
	EAnimation CurrentAnimation = EAnimation::No;
	
	float ForwardMovement = 0;
	float RightMovement = 0;
	int InteractionDistance = 1000;
	int ImpulseMultiplier = 1000;
	int RadialRadius = 200;
	int RadialMultiplier = 1000;

	const UCharacterMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* SwordMesh;

	UPROPERTY(EditAnywhere)
	class UAnimSequence* AttackAnimation;
	UPROPERTY(EditAnywhere)
	class UAnimSequence* RunAnimation;
	UPROPERTY(EditAnywhere)
	class UAnimSequence* SwimAnimation;
	UPROPERTY(EditAnywhere)
	class UAnimSequence* RightAnimation;
	UPROPERTY(EditAnywhere)
	class UAnimSequence* LeftAnimation;
	UPROPERTY(EditAnywhere)
	class UAnimSequence* BackAnimation;
	UPROPERTY(EditAnywhere)
	class UAnimSequence* IdleAnimation;
	
	UFUNCTION(BlueprintCallable)
	void MoveForward(float InputValue);

    UFUNCTION(BlueprintCallable)
	void MoveRight(float InputValue);

	void Turn(float InputValue);

	void LookUp(float InputValue);

	void StartAttack();

	FHitResult Interact();
	
	void Impulse();
	
	void Radial();
	
	void Force();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void LineTrace() const;
};
