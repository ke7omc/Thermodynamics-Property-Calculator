#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "CoolProp.h"
#include "FluidsNamespace.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listWidget_quickList_itemSelectionChanged()
{
    FluidsNamespace::fluidName = ui->listWidget_quickList->currentItem()->text();
    ui->lineEdit_chosenFluid->setText(FluidsNamespace::fluidName);
}


void MainWindow::on_listWidget_allFluids_itemSelectionChanged()
{
    FluidsNamespace::fluidName = ui->listWidget_allFluids->currentItem()->text();
    ui->lineEdit_chosenFluid->setText(FluidsNamespace::fluidName);
}

void MainWindow::on_comboBox_firstProperty_currentIndexChanged(const QString &firstPropertyName)
{
    ui->lineEdit_firstPropertyValue->clear();
    ui->lineEdit_secondPropertyValue->clear();

    if (firstPropertyName == "Temperature")
    {
        FluidsNamespace::firstPropertyVariable = "T";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Pressure");
        ui->comboBox_secondProperty->addItem("Density");
        ui->comboBox_secondProperty->addItem("Quality");
        ui->comboBox_secondProperty->addItem("Entropy");
    }
    else if (firstPropertyName == "Pressure")
    {
        FluidsNamespace::firstPropertyVariable = "P";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Density");
        ui->comboBox_secondProperty->addItem("Quality");
    }
    else if (firstPropertyName == "Enthalpy")
    {
        FluidsNamespace::firstPropertyVariable = "H";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Pressure");
    }
    else if (firstPropertyName == "Entropy")
    {
        FluidsNamespace::firstPropertyVariable = "S";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Pressure");
        ui->comboBox_secondProperty->addItem("Enthalpy");
    }
    else if (firstPropertyName == "Quality")
    {
        FluidsNamespace::firstPropertyVariable = "Q";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Temperature");
        ui->comboBox_secondProperty->addItem("Pressure");
    }
    else if (firstPropertyName == "Density")
    {
        FluidsNamespace::firstPropertyVariable = "D";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Temperature");
        ui->comboBox_secondProperty->addItem("Pressure");
    }
//    else if (firstPropertyName == "Specifc Volume")
//    {
//        FluidsNamespace::firstPropertyVariable = "Specific Volume";
//        ui->comboBox_secondProperty->clear();
//        ui->comboBox_secondProperty->addItem("Temperature");
//        ui->comboBox_secondProperty->addItem("Pressure");
//    }

}

void MainWindow::on_comboBox_secondProperty_currentIndexChanged(const QString &secondPropertyName)
{
    ui->lineEdit_secondPropertyValue->clear();

    if (secondPropertyName == "Pressure")
    {
        FluidsNamespace::secondPropertyVariable = "P";
    }
    else if (secondPropertyName == "Enthalpy")
    {
        FluidsNamespace::secondPropertyVariable = "H";
    }
    else if (secondPropertyName == "Entropy")
    {
        FluidsNamespace::secondPropertyVariable = "S";
    }
    else if (secondPropertyName == "Quality")
    {
        FluidsNamespace::secondPropertyVariable = "Q";
    }
    else if (secondPropertyName == "Density")
    {
        FluidsNamespace::secondPropertyVariable = "D";
    }

}

void MainWindow::on_lineEdit_firstPropertyValue_textEdited(const QString &firstPropertyValueQString)
{
    FluidsNamespace::firstPropertyValue = firstPropertyValueQString.toDouble();
}

void MainWindow::on_lineEdit_secondPropertyValue_textEdited(const QString &secondPropertyValueQString)
{
    FluidsNamespace::secondPropertyValue = secondPropertyValueQString.toDouble();
}



void MainWindow::on_pushButton_calculate_clicked()
{
    FluidsNamespace::resultantInternalEnergy = CoolProp::PropsSI("U",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantEnthalpy = CoolProp::PropsSI("H",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantTemperature = CoolProp::PropsSI("T",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantPressure = CoolProp::PropsSI("P",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantEntropy = CoolProp::PropsSI("S",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
//    FluidsNamespace::resultantSpecificVolume = CoolProp::PropsSI("U",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantQuality = CoolProp::PropsSI("Q",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantDensity = CoolProp::PropsSI("D",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantConstantPressureSpecificHeat = CoolProp::PropsSI("C0",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantConstantVolumeSpecificHeat = CoolProp::PropsSI("C",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
//    FluidsNamespace::resultantDynamicViscosity = CoolProp::PropsSI("U",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
//    FluidsNamespace::resultantKinematicViscosity = CoolProp::PropsSI("U",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantThermalConductivity = CoolProp::PropsSI("L",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
//    FluidsNamespace::resultantThermalDiffusivity = CoolProp::PropsSI("U",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantSpeedOfSound = CoolProp::PropsSI("A",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
//    FluidsNamespace::resultantPrandtlNumber = CoolProp::PropsSI("U",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantSurfaceTension = CoolProp::PropsSI("I",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantGibbsFunction = CoolProp::PropsSI("G",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());
    FluidsNamespace::resultantAccentricFactor = CoolProp::PropsSI("w",FluidsNamespace::firstPropertyVariable.toStdString(),FluidsNamespace::firstPropertyValue,FluidsNamespace::secondPropertyVariable.toStdString(),FluidsNamespace::secondPropertyValue,FluidsNamespace::fluidName.toStdString());


    std::string resultantInternalEnergyString = std::to_string(FluidsNamespace::resultantInternalEnergy);
    std::string resultantEnthalpyString = std::to_string(FluidsNamespace::resultantEnthalpy);
    std::string resultantTemperatureString = std::to_string(FluidsNamespace::resultantTemperature);
    std::string resultantPressureString = std::to_string(FluidsNamespace::resultantPressure);
    std::string resultantEntropyString = std::to_string(FluidsNamespace::resultantEntropy);
    std::string resultantSpecificVolumeString = std::to_string(FluidsNamespace::resultantSpecificVolume);
    std::string resultantQualityString = std::to_string(FluidsNamespace::resultantQuality);
    std::string resultantDensityString = std::to_string(FluidsNamespace::resultantDensity);
    std::string resultantConstantPressureSpecificHeatString = std::to_string(FluidsNamespace::resultantConstantPressureSpecificHeat);
    std::string resultantConstantVolumeSpecificHeatString = std::to_string(FluidsNamespace::resultantConstantVolumeSpecificHeat);
    std::string resultantDynamicViscosityString = std::to_string(FluidsNamespace::resultantDynamicViscosity);
    std::string resultantKinematicViscosityString = std::to_string(FluidsNamespace::resultantKinematicViscosity);
    std::string resultantThermalConductivityString = std::to_string(FluidsNamespace::resultantThermalConductivity);
    std::string resultantThermalDiffusivityString = std::to_string(FluidsNamespace::resultantThermalDiffusivity);
    std::string resultantSpeedOfSound = std::to_string(FluidsNamespace::resultantSpeedOfSound);
    std::string resultantPrandtlNumber = std::to_string(FluidsNamespace::resultantPrandtlNumber);
    std::string resultantSurfaceTension = std::to_string(FluidsNamespace::resultantSurfaceTension);
    std::string resultantGibbsFunction = std::to_string(FluidsNamespace::resultantGibbsFunction);
    std::string resultantAccentricFactor = std::to_string(FluidsNamespace::resultantAccentricFactor);


    QString resultantInternalEnergyQString = QString::fromStdString(resultantInternalEnergyString);
    QString resultantEnthalpyQString = QString::fromStdString(resultantEnthalpyString);
    QString resultantTemperatureQString = QString::fromStdString(resultantTemperatureString);
    QString resultantPressureQString = QString::fromStdString(resultantPressureString);
    QString resultantEntropyQString = QString::fromStdString(resultantEntropyString);
    QString resutantSpecificVolumeQString = QString::fromStdString(resultantSpecificVolumeString);
    QString resultantQualityQString = QString::toStdString(resultantQualityString);
    QString resultantDensityQString = ;
    ui->lineEdit_internalEnergy->setText(resultantInternalEnergyQString);
}
