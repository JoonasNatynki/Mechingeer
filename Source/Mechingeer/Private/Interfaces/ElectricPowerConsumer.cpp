#include "Interfaces/ElectricPowerConsumer.h"

FWattHour IElectricPowerConsumer::ConsumeElectricPower_Implementation(
	const float DeltaTime) const
{
	const FWatt Watts(GetCurrentOperationalVoltage() * GetCurrentOperationalAmperage());
	const FWattHour WattHours(Watts.GetUnitValue() * DeltaTime, EUnitScale::Unit);
	return WattHours;
}

FVoltage IElectricPowerConsumer::GetVoltageNominalityDelta_Implementation() const
{
	return GetCurrentOperationalVoltage() - GetNominalVoltage();
}

FWatt IElectricPowerConsumer::GetCurrentPowerConsumption_Implementation() const
{
	return GetCurrentOperationalAmperage() * GetCurrentOperationalVoltage(); 
}
