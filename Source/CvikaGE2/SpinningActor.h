#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "SpinningActor.generated.h"

UCLASS(Blueprintable)
class ASpinningActor : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly,
		meta=(AllowPrivateAccess="True", DisplayName="My name") )
	int NumberOfSpins;

	double LastYaw;
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(ExposeOnSpawn="True"))
	int Threshold;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *StaticMeshComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *SubStaticMeshComponent;

	UPROPERTY(EditAnywhere)
	URotatingMovementComponent *MovementComponent;

	ASpinningActor();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpin();

	UFUNCTION(BlueprintNativeEvent)
	void OnThresholdReached();
	
	UFUNCTION(BlueprintCallable)
	void ResetSpinning();

	UFUNCTION(BlueprintCallable)
	void SetDescription( UPARAM(ref) FString &descrition);
	
	UFUNCTION(BlueprintCallable)
	int GetNumberOfSpins();
};
