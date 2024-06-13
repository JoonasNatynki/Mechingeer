#pragma once

#include "CoreMinimal.h"
#include "ElectricUnits.generated.h"

UENUM(BlueprintType)
enum class EUnitScale : uint8
{
    Unit,
    Micro,
    Milli,
    Kilo,
    Mega,
    Giga
};

class ElectricUnitHelper
{
public:
    static constexpr double GetScaleMultiplier(EUnitScale Scale)
    {
        switch (Scale)
        {
            case EUnitScale::Micro: return 0.000001;
            case EUnitScale::Milli: return 0.001;
            case EUnitScale::Kilo: return 1000.0;
            case EUnitScale::Mega: return 1000000.0;
            case EUnitScale::Giga: return 1000000000.0;
            default: return 1.0;
        }
    }
};

USTRUCT(BlueprintType)
struct FVoltage
{
    GENERATED_BODY()

private:
    double InternalValue = 0.0;
    double ScaleMultiplier = 1.0;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0", ClampMax = "9999.0"))
    float Value = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EUnitScale Scale = EUnitScale::Unit;

    double GetUnitValue() const;
    FVoltage operator+(const FVoltage& Other) const;
    FVoltage operator-(const FVoltage& Other) const;
    void operator=(const double InValue);

    FVoltage() = default;
    FVoltage(double InValue, EUnitScale InScale);
};

USTRUCT(BlueprintType)
struct FAmpere
{
    GENERATED_BODY()

private:
    double InternalValue = 0.0;
    double ScaleMultiplier = 1.0;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0", ClampMax = "9999.0"))
    float Value = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EUnitScale Scale = EUnitScale::Unit;

    void UpdateInternalValue()
    {
        InternalValue = Value * ElectricUnitHelper::GetScaleMultiplier(Scale);
    }

    float GetValueInBaseUnit() const
    {
        return static_cast<float>(InternalValue / ElectricUnitHelper::GetScaleMultiplier(Scale));
    }

    FAmpere operator+(const FAmpere& Other) const
    {
        double ResultValue = InternalValue + Other.InternalValue;
        return FAmpere{ static_cast<float>(ResultValue / ElectricUnitHelper::GetScaleMultiplier(Scale)), Scale };
    }

    FAmpere operator-(const FAmpere& Other) const
    {
        double ResultValue = InternalValue - Other.InternalValue;
        return FAmpere{ static_cast<float>(ResultValue / ElectricUnitHelper::GetScaleMultiplier(Scale)), Scale };
    }

    FAmpere operator*(float Scalar) const
    {
        double ResultValue = InternalValue * Scalar;
        return FAmpere{ static_cast<float>(ResultValue / ElectricUnitHelper::GetScaleMultiplier(Scale)), Scale };
    }

    FAmpere operator/(float Scalar) const
    {
        double ResultValue = InternalValue / Scalar;
        return FAmpere{ static_cast<float>(ResultValue / ElectricUnitHelper::GetScaleMultiplier(Scale)), Scale };
    }

    FAmpere() = default;
    FAmpere(double InValue, EUnitScale InScale);
};

USTRUCT(BlueprintType)
struct FWatt
{
    GENERATED_BODY()

private:
    double InternalValue = 0.0;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0", ClampMax = "9999.0"))
    float Value = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EUnitScale Scale = EUnitScale::Unit;

    void UpdateInternalValue()
    {
        InternalValue = Value * ElectricUnitHelper::GetScaleMultiplier(Scale);
    }

    float GetValueInBaseUnit() const
    {
        return static_cast<float>(InternalValue / ElectricUnitHelper::GetScaleMultiplier(Scale));
    }

    FWatt operator+(const FWatt& Other) const
    {
        double ResultValue = InternalValue + Other.InternalValue;
        return FWatt{ static_cast<float>(ResultValue / ElectricUnitHelper::GetScaleMultiplier(Scale)), Scale };
    }

    FWatt operator-(const FWatt& Other) const
    {
        double ResultValue = InternalValue - Other.InternalValue;
        return FWatt{ static_cast<float>(ResultValue / ElectricUnitHelper::GetScaleMultiplier(Scale)), Scale };
    }

    FWatt operator*(float Scalar) const
    {
        double ResultValue = InternalValue * Scalar;
        return FWatt{ static_cast<float>(ResultValue / ElectricUnitHelper::GetScaleMultiplier(Scale)), Scale };
    }

    FWatt operator/(float Scalar) const
    {
        double ResultValue = InternalValue / Scalar;
        return FWatt{ static_cast<float>(ResultValue / ElectricUnitHelper::GetScaleMultiplier(Scale)), Scale };
    }

    FWatt() = default;
    FWatt(float X, EUnitScale Scale);
};