// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"

#include "HealthComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;

	SwordMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SwordMesh"));
	SwordMesh->SetupAttachment(GetMesh(), FName("SwordSocket"));
}

void APlayerCharacter::MoveForward(float InputValue)
{
	if (bIsAttacking) return;
	ForwardMovement = InputValue;
	const FVector ForwardDirection = GetActorForwardVector();
	AddMovementInput(ForwardDirection, ForwardMovement);
}

void APlayerCharacter::MoveRight(float InputValue)
{
	if (bIsAttacking) return;
	RightMovement = InputValue;
	const FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, RightMovement);
}

void APlayerCharacter::Turn(float InputValue)
{
	AddControllerYawInput(InputValue);
}

void APlayerCharacter::LookUp(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

void APlayerCharacter::StartAttack()
{
	if (AttackAnimation && !bIsAttacking)
	{
		GetMesh()->PlayAnimation(AttackAnimation, false);
		bIsAttacking = true;
	}
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsAttacking) return;

	if (IdleAnimation && ForwardMovement == 0 && RightMovement == 0 && CurrentAnimation != Idle)
	{
		GetMesh()->PlayAnimation(IdleAnimation, true);
		CurrentAnimation = Idle;
	}

	if (RightAnimation && ForwardMovement == 0 && RightMovement > 0 && CurrentAnimation != Right)
	{
		GetMesh()->PlayAnimation(RightAnimation, true);
		CurrentAnimation = Right;
	}

	if (RightAnimation && ForwardMovement == 0 && RightMovement < 0 && CurrentAnimation != Left)
	{
		GetMesh()->PlayAnimation(LeftAnimation, true);
		CurrentAnimation = Left;
	}

	if (RunAnimation && ForwardMovement > 0 && CurrentAnimation != Run)
	{
		GetMesh()->PlayAnimation(RunAnimation, true);
		CurrentAnimation = Run;
	}
	
	if (BackAnimation && ForwardMovement < 0 && CurrentAnimation != Backward)
	{
		GetMesh()->PlayAnimation(BackAnimation, true);
		CurrentAnimation = Backward;
	}
}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	MovementComponent = FindComponentByClass<UCharacterMovementComponent>();
	if (!IsValid(MovementComponent)) return;

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &APlayerCharacter::StartAttack);
}

void APlayerCharacter::LineTrace() const
{
	FVector StartLocation = SwordMesh->GetSocketLocation(FName("Start"));
	FVector EndLocation = SwordMesh->GetSocketLocation(FName("End"));

	FHitResult HitResult;
	FCollisionQueryParams TraceParams;
	TraceParams.AddIgnoredActor(this);

	GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECC_Visibility, TraceParams);

	DrawDebugLine(GetWorld(), StartLocation, EndLocation, FColor::Red, false, 1, 0, 1);

	if (HitResult.bBlockingHit)
	{
		AActor * ActorHit = HitResult.GetActor();
		UHealthComponent * HealthComponent = ActorHit->FindComponentByClass<UHealthComponent>();

		if (IsValid(HealthComponent))
		{
			HealthComponent->TakeDamage(Damage, GetUniqueID());
		}
		//HitResult.GetActor()->Destroy();
	}
}

