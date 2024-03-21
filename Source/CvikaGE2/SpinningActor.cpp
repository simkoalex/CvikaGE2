#include "SpinningActor.h"
#include "Kismet/KismetSystemLibrary.h"

ASpinningActor::ASpinningActor() :
	NumberOfSpins(0),
	LastYaw(0)
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMeshComponent);

	UStaticMesh *Sphere = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Sphere"));
	StaticMeshComponent->SetStaticMesh(Sphere);
	
	SubStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("SubStaticMeshComponent");
	SubStaticMeshComponent->SetupAttachment(StaticMeshComponent);
	SubStaticMeshComponent->SetRelativeLocation(FVector(0,0, 100));

	UStaticMesh *Cube = LoadObject<UStaticMesh>(nullptr, TEXT("/Engine/BasicShapes/Cube"));
	SubStaticMeshComponent->SetStaticMesh(Cube);

	MovementComponent = CreateDefaultSubobject<URotatingMovementComponent>(TEXT("MovementComponent"));

	PrimaryActorTick.bCanEverTick = true;
}

void ASpinningActor::BeginPlay()
{
	Super::BeginPlay();
	LastYaw = GetActorRotation().Yaw;
	UKismetSystemLibrary::PrintString(this, TEXT("ASpinningActor::BeginPlay()"));
}

void ASpinningActor::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	double const CurrentYaw = GetActorRotation().Yaw;
	if (CurrentYaw < LastYaw)
	{
		NumberOfSpins += 1;
		OnSpin();
		if (NumberOfSpins == Threshold)
		{
			OnThresholdReached();
		}
	}
	LastYaw = CurrentYaw;
}

// void ASpinningActor::OnSpin()
// {
// 	FString const Str = FString::FromInt(NumberOfSpins);
// 	UKismetSystemLibrary::PrintString(this, Str);
// }

void ASpinningActor::OnThresholdReached_Implementation()
{
	UKismetSystemLibrary::PrintString(this, TEXT("Threshold reached"));
}

void ASpinningActor::ResetSpinning()
{
	NumberOfSpins = 0;
	LastYaw = GetActorRotation().Yaw;
}

void ASpinningActor::SetDescription(FString &descrition)
{
	
}

int ASpinningActor::GetNumberOfSpins()
{
	return NumberOfSpins;
}

