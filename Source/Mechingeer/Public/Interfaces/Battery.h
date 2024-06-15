#pragma once

#include "CoreMinimal.h"
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
	virtual FWattHour GetMaximumCapacity() const = 0;
	virtual FWattHour GetCurrentCapacity() const = 0;

	virtual void SetCurrentCapacity(const FWattHour& NewCapacity) = 0;
	void ModifyCurrentCapacity(const FWattHour& ModifyWith);
};
