#include "Interfaces/Battery.h"
#include "ElectricUnits.h"

void IBattery::ModifyCurrentCapacity(const FWattHour& ModifyWith)
{
	SetCurrentCapacity(GetCurrentCapacity() + ModifyWith);
}
