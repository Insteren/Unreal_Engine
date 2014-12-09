#pragma once

#include "GameFramework/Actor.h"
#include "Apotheke.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AApotheke : public AActor
{
	GENERATED_UCLASS_BODY()


	UPROPERTY()
	TSubobjectPtr<USphereComponent> Sphere;

	UFUNCTION()
	void OnBeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
};
