#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ElectricUnits.h"
#include "ElectricPowerConsumer.generated.h"

UINTERFACE(MinimalAPI)
class UElectricPowerConsumer : public UInterface
{
	GENERATED_BODY()
};

class IElectricPowerConsumer
{
	GENERATED_BODY()

public:

	/**
	*	Consume the amount of electric power based on the current operational voltages and amperages
	*	@param	DeltaTime	In what kind of time spawn the amount of wattage is consumed
	*	@return				How much energy was consumed in WattHours
	*/
	UFUNCTION(Category = "ElectricPowerConsumer", BlueprintNativeEvent, BlueprintCallable)
	FWattHour ConsumerElectricPower(const float DeltaTime) const;
	FWattHour ConsumeElectricPower_Implementation(const float DeltaTime) const;
	
	// The actual voltage actively being used by this thing
	UFUNCTION(Category = "ElectricPowerConsumer", BlueprintImplementableEvent, BlueprintCallable)
	FVoltage GetCurrentOperationalVoltage() const;

	// The actual amperage being consumed by this thing
	UFUNCTION(Category = "ElectricPowerConsumer", BlueprintImplementableEvent, BlueprintCallable)
	FAmpere GetCurrentOperationalAmperage() const;

	// The voltage needed for proper function
	UFUNCTION(Category = "ElectricPowerConsumer", BlueprintImplementableEvent, BlueprintCallable)
	FVoltage GetNominalVoltage() const;

	// The voltage needed for proper function
	UFUNCTION(Category = "ElectricPowerConsumer", BlueprintImplementableEvent, BlueprintCallable)
	FAmpere GetNominalAmperage() const;

	// The difference between nominal voltage and supplied voltage. Positive values mean overvoltage
	UFUNCTION(Category = "ElectricPowerConsumer", BlueprintNativeEvent, BlueprintCallable)
	FVoltage GetVoltageNominalityDelta() const;
	virtual FVoltage GetVoltageNominalityDelta_Implementation() const;

	UFUNCTION(Category = "ElectricPowerConsumer", BlueprintNativeEvent, BlueprintCallable)
	FWatt GetCurrentPowerConsumption() const;
	virtual FWatt GetCurrentPowerConsumption_Implementation() const;
};
