// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterPlayerState.h"
#include "Blaster/Character/BlasterCharacter.h"
#include "Blaster/PlayerController/BlasterPlayerController.h"
#include "Net/UnrealNetWork.h"

void ABlasterPlayerState::OnRep_Score()
{
	Super::OnRep_Score();

	ABlasterCharacter* Character = Cast<ABlasterCharacter>(GetPawn());
	if (Character)
	{
		ABlasterPlayerController* Controller = Cast<ABlasterPlayerController>(Character->Controller);
		if (Controller)
		{
			Controller->SetHUDScore(GetScore());
		}
	}
}

void ABlasterPlayerState::AddToScore(float ScoreAmount)
{
	SetScore(GetScore() + ScoreAmount);
	ABlasterCharacter* Character = Cast<ABlasterCharacter>(GetPawn());
	if (Character)
	{
		ABlasterPlayerController* Controller = Cast<ABlasterPlayerController>(Character->Controller);
		if (Controller)
		{
			Controller->SetHUDScore(GetScore());
		}
	}
}


void ABlasterPlayerState::AddToDefeats(int32 DefeatsAmount)
{
	Defeats += DefeatsAmount;
	ABlasterCharacter* Character = Cast<ABlasterCharacter>(GetPawn());
	if (Character)
	{
		ABlasterPlayerController* Controller = Cast<ABlasterPlayerController>(Character->Controller);
		if (Controller)
		{
			Controller->SetHUDDefeats(Defeats);
		}
	}
}

void ABlasterPlayerState::OnRep_Defeats()
{
	ABlasterCharacter* Character = Cast<ABlasterCharacter>(GetPawn());
	if (Character)
	{
		ABlasterPlayerController* Controller = Cast<ABlasterPlayerController>(Character->Controller);
		if (Controller)
		{
			Controller->SetHUDDefeats(Defeats);
		}
	}
}

void ABlasterPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ABlasterPlayerState, Defeats);
}
