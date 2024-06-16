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
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FWattHour GetMaximumCapacity() const;
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FWattHour GetCurrentCapacity() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetCurrentCapacity(const FWattHour& NewCapacity);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ModifyCurrentCapacity(const FWattHour& ModifyWith);
	virtual void ModifyCurrentCapacity_Implementation(const FWattHour& ModifyWith);
};
