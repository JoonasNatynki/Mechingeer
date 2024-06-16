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

FWattHour FWattHour::operator+(const FWattHour& Other) const
{
	return {InternalValue + Other.InternalValue, EUnitScale::Unit};
}

FVoltage FVoltage::operator-(const FVoltage& Other) const
{
	const double ResultValue = InternalValue - ((Other.InternalValue * ElectricUnitHelper::GetScaleMultiplier(Other.Scale)) / ElectricUnitHelper::GetScaleMultiplier(Scale));
	return FVoltage{ResultValue, EUnitScale::Unit};
}

FWatt FVoltage::operator*(const FAmpere& Other) const
{
	const double ResultValue = InternalValue - ((Other.InternalValue * ElectricUnitHelper::GetScaleMultiplier(Other.Scale)) / ElectricUnitHelper::GetScaleMultiplier(Scale));
	return FWatt{ResultValue, EUnitScale::Unit};
}

FWatt FAmpere::operator*(const FVoltage& Other) const
{
	const double ResultValue = InternalValue - ((Other.InternalValue * ElectricUnitHelper::GetScaleMultiplier(Other.Scale)) / ElectricUnitHelper::GetScaleMultiplier(Scale));
	return FWatt{ResultValue, EUnitScale::Unit};
}

FWattHour FWatt::operator*(const FWatt& Other) const
{
	const double ResultValue = InternalValue - ((Other.InternalValue * ElectricUnitHelper::GetScaleMultiplier(Other.Scale)) / ElectricUnitHelper::GetScaleMultiplier(Scale));
	return FWattHour{ResultValue, EUnitScale::Unit};
}

FWatt FWatt::operator*(const double& Value) const
{
	return {InternalValue * Value, Scale};
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
	CachedScaleMultiplier = ElectricUnitHelper::GetScaleMultiplier(InScale);
}

double FAmpere::GetUnitValue() const
{
	return InternalValue * ElectricUnitHelper::GetScaleMultiplier(Scale);
}

double FWatt::GetUnitValue() const
{
	return InternalValue * ElectricUnitHelper::GetScaleMultiplier(Scale);
}

FAmpere::FAmpere(const double& InValue, const EUnitScale& InScale)
{
	InternalValue = InValue;
	Amperes = InValue;
	Scale = InScale;
	CachedScaleMultiplier = ElectricUnitHelper::GetScaleMultiplier(Scale);
}

FWatt::FWatt(const double& InWatts, const EUnitScale& InScale)
{
	Watts = InWatts;
	InternalValue = InWatts;
	Scale = InScale;
	CachedScaleMultiplier = ElectricUnitHelper::GetScaleMultiplier(Scale);
}

FWattHour::FWattHour(const double& InWattHours, const EUnitScale& InScale)
{
	InternalValue = InWattHours;
	WattHours = InternalValue;
	Scale = InScale;
	CachedScaleMultiplier = ElectricUnitHelper::GetScaleMultiplier(Scale);
}
