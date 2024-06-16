#include "Interfaces/Battery.h"
#include "ElectricUnits.h"

void IBattery::ModifyCurrentCapacity_Implementation(const FWattHour& ModifyWith)
{
	SetCurrentCapacity(GetCurrentCapacity() + ModifyWith);
}
