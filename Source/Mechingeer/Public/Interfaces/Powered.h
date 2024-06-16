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

	//	Means that the thing is actively consuming power...even at near zero idle states
	UFUNCTION(Category = "Powered", BlueprintImplementableEvent, BlueprintCallable)
	bool IsPoweredOn() const;
	
	UFUNCTION(Category = "Powered", BlueprintImplementableEvent, BlueprintCallable)
	void SetIsPoweredOn(const bool bNewPoweredState);
};
