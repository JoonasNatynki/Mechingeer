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

    friend struct FAmpere;

private:
    double InternalValue = 0.0;
    double CachedScaleMultiplier = 1.0;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0", ClampMax = "9999.0"))
    float Voltages = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EUnitScale Scale = EUnitScale::Unit;

    double GetUnitValue() const;
    FVoltage operator+(const FVoltage& Other) const;
    FVoltage operator-(const FVoltage& Other) const;
    FWatt operator*(const FAmpere& Ampere) const;
    FWatt operator*=(const FAmpere& Ampere) const;
    void operator=(const double& InValue);

    FVoltage() = default;
    FVoltage(const double& InValue, const EUnitScale& InScale);
};

USTRUCT(BlueprintType)
struct FAmpere
{
    GENERATED_BODY()

    friend struct FVoltage;

private:
    double InternalValue = 0.0;
    double CachedScaleMultiplier = 1.0;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0", ClampMax = "9999.0"))
    float Amperes = 0.0f;
    
    double GetUnitValue() const;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EUnitScale Scale = EUnitScale::Unit;

    FAmpere operator+(const FAmpere& Other) const;
    struct FWatt operator*(const FVoltage& Other) const;
    FAmpere operator-(const FAmpere& Other) const;

    FAmpere() = default;
    FAmpere(const double& InValue, const EUnitScale& InScale);
};

USTRUCT(BlueprintType)
struct FWatt
{
    GENERATED_BODY()

private:
    double InternalValue = 0.0;
    double CachedScaleMultiplier = 1.0;

public:

    double GetUnitValue() const;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0", ClampMax = "9999.0"))
    float Watts = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EUnitScale Scale = EUnitScale::Unit;

    FWattHour operator*(const FWatt& Other) const;
    FWatt operator*(const double& Value) const;

    FWatt() = default;
    FWatt(const double& InWatts, const EUnitScale& InScale);
};

USTRUCT(BlueprintType)
struct FWattHour
{
    GENERATED_BODY()

private:
    double InternalValue = 0.0;
    double CachedScaleMultiplier = 1.0;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0", ClampMax = "9999.0"))
    float WattHours = 0.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    EUnitScale Scale = EUnitScale::Unit;

    FWattHour() = default;
    FWattHour(const double& InWattHours, const EUnitScale& InScale);

    FWattHour operator+(const FWattHour& Other) const;
};