#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ConnectionPortSurface.generated.h"

class IConnectionPort;

UINTERFACE(MinimalAPI)
class UConnectionPortSurface : public UInterface
{
	GENERATED_BODY()
};

class IConnectionPortSurface
{
	GENERATED_BODY()

public:

	UFUNCTION(Category = "ConnectionPortSurface", BlueprintImplementableEvent, BlueprintCallable)
	TArray<TScriptInterface<IConnectionPort>> GetConnectionPorts() const;

	UFUNCTION(Category = "ConnectionPortSurface", BlueprintImplementableEvent, BlueprintCallable)
	TArray<TScriptInterface<IConnectionPort>> GetPowerConnectionPorts() const;

	UFUNCTION(Category = "ConnectionPortSurface", NotBlueprintable)
	virtual TArray<TScriptInterface<IConnectionPort>> GetFreePowerConnectionPorts() const;
	virtual TArray<TScriptInterface<IConnectionPort>> GetFreePowerConnectionPorts_Implementation() const;
};
