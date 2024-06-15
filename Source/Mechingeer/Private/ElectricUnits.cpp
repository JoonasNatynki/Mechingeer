#include "ElectricUnits.h"

double FVoltage::GetUnitValue() const
{
	return InternalValue * ElectricUnitHelper::GetScaleMultiplier(Scale);
}

FVoltage FVoltage::operator+(const FVoltage& Other) const
{
	const double ResultValue = InternalValue + ((Other.InternalValue * ElectricUnitHelper::GetScaleMultiplier(Other.Scale)) / ElectricUnitHelper::GetScaleMultiplier(Scale));
	return FVoltage{ResultValue, Scale};
}

FVoltage FVoltage::operator-(const FVoltage& Other) const
{
	const double ResultValue = InternalValue - ((Other.InternalValue * ElectricUnitHelper::GetScaleMultiplier(Other.Scale)) / ElectricUnitHelper::GetScaleMultiplier(Scale));
	return FVoltage{ResultValue, Scale};
}

void FVoltage::operator=(const double& InValue)
{
	InternalValue = InValue;
	Voltages = InternalValue;
}

FVoltage::FVoltage(const double& InValue, const EUnitScale& InScale)
{
	InternalValue = InValue;
	Voltages = InValue;
	Scale = InScale;
	ScaleMultiplier = ElectricUnitHelper::GetScaleMultiplier(InScale);
}

FAmpere::FAmpere(const double& InValue, const EUnitScale& InScale)
{
	InternalValue = InValue;
	Value = InValue;
	Scale = InScale;
	ScaleMultiplier = ElectricUnitHelper::GetScaleMultiplier(Scale);
}

FWatt::FWatt(const double InWatts, const EUnitScale& InScale)
{
	Watts = InWatts;
	InternalValue = InWatts;
	Scale = InScale;
	ScaleMultiplier = ElectricUnitHelper::GetScaleMultiplier(Scale);
}

FWattHour::FWattHour(const float& InWattHours)
{
	WattHours = InWattHours;
}

FWattHour FWattHour::operator+(const FWattHour& Other) const
{
	return {WattHours + Other.WattHours};
}