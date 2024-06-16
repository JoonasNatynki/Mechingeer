#include "ElectricUnits.h"

double FVoltage::GetUnitValue() const
{
	return InternalValue * ElectricUnitHelper::GetScaleMultiplier(Scale);
}

FVoltage FVoltage::operator+(const FVoltage& Other) const
{
	const double ResultValue = InternalValue + ((Other.InternalValue * ElectricUnitHelper::GetScaleMultiplier(Other.Scale)) / ElectricUnitHelper::GetScaleMultiplier(Scale));
	return FVoltage{ResultValue, EUnitScale::Unit};
}

FVoltage FVoltage::operator-(const FVoltage& Other) const
{
	const double ResultValue = InternalValue - ((Other.InternalValue * ElectricUnitHelper::GetScaleMultiplier(Other.Scale)) / ElectricUnitHelper::GetScaleMultiplier(Scale));
	return FVoltage{ResultValue, EUnitScale::Unit};
}

FWatt FAmpere::operator*(const FVoltage& Other) const
{
	const double ResultValue = InternalValue - ((Other.InternalValue * ElectricUnitHelper::GetScaleMultiplier(Other.Scale)) / ElectricUnitHelper::GetScaleMultiplier(Scale));
	return FWatt{ResultValue, EUnitScale::Unit};
}

FAmpere FAmpere::operator-(const FAmpere& Other) const
{
	const double ResultValue = InternalValue - ((Other.InternalValue * ElectricUnitHelper::GetScaleMultiplier(Other.Scale)) / ElectricUnitHelper::GetScaleMultiplier(Scale));
	return FAmpere{ResultValue, EUnitScale::Unit};
}

FWatt FVoltage::operator*=(const FAmpere& Ampere) const
{
	return {GetUnitValue() * Ampere.GetUnitValue(), EUnitScale::Unit};
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

double FAmpere::GetUnitValue() const
{
	return InternalValue * ElectricUnitHelper::GetScaleMultiplier(Scale);
}

FAmpere::FAmpere(const double& InValue, const EUnitScale& InScale)
{
	InternalValue = InValue;
	Amperes = InValue;
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