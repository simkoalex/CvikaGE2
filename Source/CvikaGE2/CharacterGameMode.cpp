// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterGameMode.h"

ACharacterGameMode::ACharacterGameMode()
{
	ConstructorHelpers::FClassFinder<APawn> BPCharClass (TEXT("/Game/Character/BPPlayerCharacter"));

	if (BPCharClass.Class != nullptr)
	{
		DefaultPawnClass = BPCharClass.Class;
	}
	
}

void ACharacterGameMode::MyMethod()
{
	ConstructorHelpers::FClassFinder<APawn> BPCharClass (TEXT("/Game/Character/BPPlayerCharacter"));
}
