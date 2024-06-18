#include "Interfaces/ConnectionPortSurface.h"

#include "Interfaces/ConnectionPort.h"

TArray<TScriptInterface<IConnectionPort>> IConnectionPortSurface::GetFreePowerConnectionPorts_Implementation() const
{
	return GetConnectionPorts().FilterByPredicate([](const TScriptInterface<IConnectionPort>& Port)
	{
		const bool bIsPowerPort = Port->GetPortType() == EConnectionPortType::Power;
		const bool bIsPortUsed = Port->IsPortUsed();
		return bIsPowerPort && !bIsPortUsed;
	});
}
