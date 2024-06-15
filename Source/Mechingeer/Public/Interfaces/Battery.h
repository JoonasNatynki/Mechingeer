#pragma once

#include "CoreMinimal.h"
#include "ElectricUnits.h"
#include "UObject/Interface.h"
#include "Battery.generated.h"

struct FWattHour;

UINTERFACE(MinimalAPI)
class UBattery : public UInterface
{
	GENERATED_BODY()
};

class IBattery
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	FWattHour GetMaximumCapacity() const;
	
	UFUNCTION(BlueprintImplementableEvent)
	FWattHour GetCurrentCapacity() const;

	virtual void SetCurrentCapacity(const FWattHour& NewCapacity) = 0;
	void ModifyCurrentCapacity(const FWattHour& ModifyWith);
};
