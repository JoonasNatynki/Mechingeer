#include "Interfaces/ConnectionPort.h"

bool IConnectionPort::IsPortUsed_Implementation() const
{
	return GetPortConnection().GetInterface() != nullptr;
}
