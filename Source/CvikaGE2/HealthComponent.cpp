
#include "HealthComponent.h"


void UHealthComponent::TakeDamage(int Damage, uint32 ActorID)
{
	if (!TakenDamageFrom.Contains(ActorID))
	{
		Health -= Damage;
		TakenDamageFrom.Add(ActorID);

		GEngine->AddOnScreenDebugMessage(
			-1, 15, FColor::Yellow, FString::Printf(TEXT("%d"), Health));

		FTimerHandle DamageDelayHandle;
		FTimerDelegate DamageDelegate = FTimerDelegate::CreateUObject(
		this, &UHealthComponent::AllowTakeDamage, ActorID );

		GetWorld()->GetTimerManager().SetTimer(DamageDelayHandle, DamageDelegate,
		0.5f, false);
		
		if (Health <= 0) {
			Die();
		}
	}
}

void UHealthComponent::Die()
{
	GetOwner()->Destroy();
}

void UHealthComponent::AllowTakeDamage(uint32 ActorID)
{
	TakenDamageFrom.Remove(ActorID);
}
