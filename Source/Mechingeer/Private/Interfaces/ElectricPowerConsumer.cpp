#include "Interfaces/ElectricPowerConsumer.h"

FWattHour IElectricPowerConsumer::ConsumeElectricPower_Implementation(
	const float DeltaTime)
{
	const FWatt Watts(GetCurrentOperatingVoltage() * GetCurrentOperatingAmperage());
	const FWattHour WattHours(Watts.GetUnitValue() * DeltaTime, EUnitScale::Unit);
	return WattHours;
}

FVoltage IElectricPowerConsumer::GetVoltageNominalityDelta_Implementation() const
{
	return GetCurrentOperatingVoltage() - GetNominalVoltage();
}

FWatt IElectricPowerConsumer::GetCurrentPowerConsumption_Implementation() const
{
	return GetCurrentOperatingAmperage() * GetCurrentOperatingVoltage(); 
}
