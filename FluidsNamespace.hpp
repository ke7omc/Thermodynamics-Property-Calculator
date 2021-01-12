#ifndef FLUIDSNAMESPACE_HPP
#define FLUIDSNAMESPACE_HPP

#include <QString>

namespace FluidsNamespace
{
    QString fluidName = "Water";
    QString firstPropertyVariable = "T";
    double firstPropertyValue = 274;
    QString secondPropertyVariable = "P";
    double secondPropertyValue = 101325;

    double resultantInternalEnergy(0);
    double resultantEnthalpy(0);
    double resultantTemperature(0);
    double resultantPressure(0);
    double resultantEntropy(0);
    double resultantSpecificVolume(0);
    double resultantQuality(0);
    double resultantDensity(0);
    double saturatedLiquidDensity(0);
    double saturatedVaporDensity(0);
    double resultantConstantPressureSpecificHeat(0);
    double resultantConstantVolumeSpecificHeat(0);
    double resultantDynamicViscosity(0);
    double resultantKinematicViscosity(0);
    double resultantThermalConductivity(0);
    double resultantThermalDiffusivity(0);
    double resultantSpeedOfSound(0);
    double resultantPrandtlNumber(0);
    double resultantSurfaceTension(0);
    double resultantGibbsFunction(0);
    double resultantAccentricFactor(0);

}
#endif // FLUIDSNAMESPACE_HPP
