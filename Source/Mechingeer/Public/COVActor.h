#pragma once

#include "CoreMinimal.h"
#include "ElectricUnits.h"
#include "GameFramework/Actor.h"
#include "COVActor.generated.h"

UCLASS()
class ACOVActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACOVActor();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	FVoltage PERSE;
};
