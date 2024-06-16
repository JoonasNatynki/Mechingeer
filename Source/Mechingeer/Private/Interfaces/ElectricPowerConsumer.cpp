#include "Interfaces/ElectricPowerConsumer.h"
#include "ElectricUnits.h"

FVoltage IElectricPowerConsumer::GetVoltageNominalityDelta_Implementation() const
{
	return GetCurrentOperationalVoltage() - GetNominalVoltage();
}

FWatt IElectricPowerConsumer::GetCurrentPowerConsumption_Implementation() const
{
	return GetCurrentOperationalAmperage() * GetCurrentOperationalVoltage(); 
}
