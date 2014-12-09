#pragma once

#include "GameFramework/GameMode.h"
#include "FPSGM.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AFPSGM : public AGameMode
{
	GENERATED_UCLASS_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
		int32 Health;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameMode")
		int32 MaxHealth;

	virtual void BeginPlay() override;
	
};
