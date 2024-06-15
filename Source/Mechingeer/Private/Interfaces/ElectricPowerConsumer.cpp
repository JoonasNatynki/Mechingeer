#include "Interfaces/ElectricPowerConsumer.h"
#include "ElectricUnits.h"

FWatt IElectricPowerConsumer::GetCurrentPowerConsumption_Implementation()
{
	return GetCurrentOperationalAmperage() * GetCurrentOperationalVoltage(); 
}
