// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerFSM.h"
#include "UParentState.generated.h"

/**
 * 
 */
UCLASS()
class CPP_53_API UUParentState : public UObject
{
	GENERATED_BODY()
protected :
	virtual void EnterState(PlayerFSM stateMachine);
	virtual void Comportement(PlayerFSM stateMachine);
	virtual void ExitState(PlayerFSM stateMachine);
};
