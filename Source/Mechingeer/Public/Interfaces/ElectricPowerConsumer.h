#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ElectricPowerConsumer.generated.h"

struct FWatt;
struct FAmpere;
struct FVoltage;

UINTERFACE(MinimalAPI)
class UElectricPowerConsumer : public UInterface
{
	GENERATED_BODY()
};

class IElectricPowerConsumer
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	FVoltage GetCurrentOperationalVoltage();
	
	UFUNCTION(BlueprintImplementableEvent)
	FAmpere GetCurrentOperationalAmperage();

	UFUNCTION(BlueprintImplementableEvent)
	FWatt GetCurrentPowerConsumption();
	FWatt GetCurrentPowerConsumption_Implementation();
};
