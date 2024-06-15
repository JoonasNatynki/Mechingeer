#include "ElectricUnits.h"
#include "Interfaces/Battery.h"

void IBattery::ModifyCurrentCapacity(const FWattHour& ModifyWith)
{
	SetCurrentCapacity(GetCurrentCapacity() + ModifyWith);
}
