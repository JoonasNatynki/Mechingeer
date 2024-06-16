#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PowerConnector.generated.h"

UINTERFACE(MinimalAPI)
class UPowerConnector : public UInterface
{
	GENERATED_BODY()
};

class IPowerConnector
{
	GENERATED_BODY()

public:

	UFUNCTION(Category = "PowerConnector", BlueprintImplementableEvent, BlueprintCallable)
	FVoltage GetCurrentConnectorVoltage() const;

	UFUNCTION(Category = "PowerConnector", BlueprintImplementableEvent, BlueprintCallable)
	FAmpere GetCurrentConnectorAmpere() const;

	UFUNCTION(Category = "PowerConnector", BlueprintImplementableEvent, BlueprintCallable)
	void SetCurrentVoltage(const FVoltage& NewVoltage);

	UFUNCTION(Category = "PowerConnector", BlueprintImplementableEvent, BlueprintCallable)
	void SetCurrentAmpere(const FAmpere& NewAmpere);
};
