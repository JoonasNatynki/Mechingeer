#pragma once

#include "CoreMinimal.h"
#include "PortConnection.h"
#include "UObject/Interface.h"
#include "ConnectionPort.generated.h"

class IPortConnection;

UINTERFACE(MinimalAPI, BlueprintType)
class UConnectionPort : public UInterface
{
	GENERATED_BODY()
};

class IConnectionPort
{
	GENERATED_BODY()

public:

	UFUNCTION(Category = "ConnectionPort", BlueprintImplementableEvent, BlueprintCallable)
	bool AttachPortConnection(const TScriptInterface<IPortConnection>& PortConnection);
	
	UFUNCTION(Category = "ConnectionPort", BlueprintImplementableEvent, BlueprintCallable)
	bool DetachPortConnection();

	UFUNCTION(Category = "ConnectionPort", BlueprintImplementableEvent, BlueprintCallable)
	TScriptInterface<IPortConnection> GetPortConnection() const;
};