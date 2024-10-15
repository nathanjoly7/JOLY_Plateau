// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UParentState.generated.h"

/**
 * 
 */
UCLASS()
class CPP_53_API UUParentState : public UObject
{
	GENERATED_BODY()
	virtual void EnterState();
	virtual void Comportement();
	virtual void ExitState();
};
