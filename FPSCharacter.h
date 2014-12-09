// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "FPSGM.h"
#include "FPSCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AFPSCharacter : public ACharacter
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "GM")
	class AFPSGM* GM;

	UPROPERTY()
		bool bPressedRoll;

	virtual void BeginPlay() override;
	
protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UFUNCTION()
		void MoveForward(float val);
	UFUNCTION()
		void MoveRight(float val);
	UFUNCTION()
		void OnStartJump();
	UFUNCTION()
		void OnStopJump();
	UFUNCTION()
		void OnStartRoll();
	UFUNCTION()
		void OnStopRoll();
	UFUNCTION()
		void GetMyHealth();
};
