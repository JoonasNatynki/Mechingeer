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

FWatt FWatt::operator*(const FVoltage& Voltage, const FAmpere& Amps)
{
	FVoltage Voltage1(Voltage);
	return Voltage1 *= Amps;
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