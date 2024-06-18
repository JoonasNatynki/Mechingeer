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
	UFUNCTION(Category = "Battery", BlueprintImplementableEvent, BlueprintCallable)
	FWattHour GetMaximumCapacity() const;
	
	UFUNCTION(Category = "Battery", BlueprintImplementableEvent, BlueprintCallable)
	FWattHour GetCurrentCapacity() const;

	UFUNCTION(Category = "Battery", BlueprintImplementableEvent, BlueprintCallable)
	void SetCurrentCapacity(const FWattHour& NewCapacity);

	UFUNCTION(Category = "Battery", NotBlueprintable)
	virtual void ModifyCurrentCapacity(const FWattHour& ModifyWith);
	virtual void ModifyCurrentCapacity_Implementation(const FWattHour& ModifyWith);
};
