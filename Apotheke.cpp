#include "MyProject.h"
#include "FPSGM.h"
#include "Apotheke.h"

AApotheke::AApotheke(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Sphere = PCIP.CreateDefaultSubobject<USphereComponent>(this, "Sphere");
	Sphere->InitSphereRadius(100.0f);
	RootComponent = Sphere;
	Sphere->OnComponentBeginOverlap.AddDynamic(this, &AApotheke::OnBeginOverlap);
	
}


void AApotheke::OnBeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		TObjectIterator< APlayerController > ThePC;
		UWorld* TheWorld = ThePC->GetWorld();
		AFPSGM* MyGM = Cast<AFPSGM>(UGameplayStatics::GetGameMode(TheWorld));
		if (MyGM != NULL)
		{
			MyGM->Health += 50;
			if (MyGM->Health > MyGM->MaxHealth)
			{
				MyGM->Health = 100;
			}
		}
		Destroy();

	}
}
