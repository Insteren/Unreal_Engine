// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "FPSCharacter.h"
#include "FPSGM.h"


AFPSCharacter::AFPSCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	bPressedRoll = false;
}

void AFPSCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You're using FPSCharacter"));
	}
	
}

void AFPSCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	InputComponent->BindAxis("MoveForward", this, &AFPSCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AFPSCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &AFPSCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AFPSCharacter::AddControllerPitchInput);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AFPSCharacter::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &AFPSCharacter::OnStopJump);
	InputComponent->BindAction("Roll", IE_Pressed, this, &AFPSCharacter::OnStartRoll);
	InputComponent->BindAction("Roll", IE_Released, this, &AFPSCharacter::OnStopRoll);
	InputComponent->BindKey("F", IE_Released, this, &AFPSCharacter::GetMyHealth);
}

void AFPSCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (CharacterMovement->IsMovingOnGround() || CharacterMovement->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AFPSCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

// Jumping on Space Bar
void AFPSCharacter::OnStartJump()
{
	bPressedJump = true;
}

void AFPSCharacter::OnStopJump()
{
	bPressedJump = false;
}

// Rolling on CTRL
void AFPSCharacter::OnStartRoll()
{
	bPressedRoll = true;
}

void AFPSCharacter::OnStopRoll()
{
	bPressedRoll = false;
}

void AFPSCharacter::GetMyHealth()
{
	if (GEngine)
	{
		TObjectIterator< APlayerController > ThePC;
		UWorld* TheWorld = ThePC->GetWorld();
		AFPSGM* MyGM = Cast<AFPSGM>(UGameplayStatics::GetGameMode(TheWorld));
		if (MyGM != NULL)
		{
			GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, FString::FromInt(MyGM->Health));
		}
	}
}
