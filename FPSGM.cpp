#include "MyProject.h"
#include "FPSGM.h"
#include "FPSCharacter.h"


AFPSGM::AFPSGM(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Health = 50;
	MaxHealth = 100;
	static ConstructorHelpers::FObjectFinder<UBlueprint> PlayerPawnObject(TEXT("Blueprint'/Game/Blueprints/BP_FPSCharacter.BP_FPSCharacter'"));
	if (PlayerPawnObject.Object != NULL)
	{
		DefaultPawnClass = (UClass*)PlayerPawnObject.Object->GeneratedClass;
	}
}

void AFPSGM::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("You're using FPSGameMode"));
	}

}
