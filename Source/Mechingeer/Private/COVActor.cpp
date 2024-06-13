#include "COVActor.h"

ACOVActor::ACOVActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACOVActor::BeginPlay()
{
	Super::BeginPlay();
	
	FVoltage Volt1(1.0, EUnitScale::Giga);
	FVoltage Volt2(1.5, EUnitScale::Micro);

	PERSE = Volt1 - Volt2;
}

