#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Powered.generated.h"

UINTERFACE(MinimalAPI)
class UPowered : public UInterface
{
	GENERATED_BODY()
};

class IPowered
{
	GENERATED_BODY()

public:

	UFUNCTION(Category = "Powered", BlueprintImplementableEvent)
	bool IsPowered();
	
	UFUNCTION(Category = "Powered", BlueprintImplementableEvent)
	void SetIsPowered(const bool bNewPoweredState);
};
