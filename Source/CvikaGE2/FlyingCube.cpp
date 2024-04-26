
#include "FlyingCube.h"


AFlyingCube::AFlyingCube()
{
	PrimaryActorTick.bCanEverTick = true;
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Flying Mesh"));
	MeshComp->SetupAttachment(RootComponent);
}

void AFlyingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsFlying)
		MeshComp->AddForce(MeshComp->GetUpVector() * ForceStrength);
}

void AFlyingCube::Ignite()
{
	bIsFlying = true;
}

