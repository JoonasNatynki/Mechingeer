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

void FVoltage::operator=(const double InValue)
{
	InternalValue = InValue;
	Value = InternalValue;
}

FVoltage::FVoltage(double InValue, EUnitScale InScale)
{
	InternalValue = InValue;
	Value = InValue;
	Scale = InScale;
	ScaleMultiplier = ElectricUnitHelper::GetScaleMultiplier(InScale);
}

FAmpere::FAmpere(double InValue, EUnitScale InScale)
{
	InternalValue = InValue;
	Value = InValue;
	Scale = InScale;
	ScaleMultiplier = ElectricUnitHelper::GetScaleMultiplier(Scale);
}
