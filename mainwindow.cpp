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
        FluidsNamespace::firstPropertyName = "Temperature";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Pressure");
        ui->comboBox_secondProperty->addItem("Density");
        ui->comboBox_secondProperty->addItem("Quality");
        ui->comboBox_secondProperty->addItem("Entropy");
    }
    else if (firstPropertyName == "Pressure")
    {
        FluidsNamespace::firstPropertyName = "Pressure";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Density");
        ui->comboBox_secondProperty->addItem("Quality");
    }
    else if (firstPropertyName == "Enthalpy")
    {
        FluidsNamespace::firstPropertyName = "Enthalpy";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Pressure");
    }
    else if (firstPropertyName == "Entropy")
    {
        FluidsNamespace::firstPropertyName = "Entropy";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Pressure");
        ui->comboBox_secondProperty->addItem("Enthalpy");
    }
    else if (firstPropertyName == "Quality")
    {
        FluidsNamespace::firstPropertyName = "Quality";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Temperature");
        ui->comboBox_secondProperty->addItem("Pressure");
    }
    else if (firstPropertyName == "Density")
    {
        FluidsNamespace::firstPropertyName = "Density";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Temperature");
        ui->comboBox_secondProperty->addItem("Pressure");
    }
    else if (firstPropertyName == "Specifc Volume")
    {
        FluidsNamespace::firstPropertyName = "Specific Volume";
        ui->comboBox_secondProperty->clear();
        ui->comboBox_secondProperty->addItem("Temperature");
        ui->comboBox_secondProperty->addItem("Pressure");
    }

}

void MainWindow::on_comboBox_secondProperty_currentIndexChanged(const QString &secondPropertyName)
{
    ui->lineEdit_secondPropertyValue->clear();

    if (secondPropertyName == "Pressure")
    {
        FluidsNamespace::secondPropertyName = "Pressure";
    }
    else if (secondPropertyName == "Enthalpy")
    {
        FluidsNamespace::secondPropertyName = "Enthalpy";
    }
    else if (secondPropertyName == "Entropy")
    {
        FluidsNamespace::secondPropertyName = "Entropy";
    }
    else if (secondPropertyName == "Quality")
    {
        FluidsNamespace::secondPropertyName = "Quality";
    }
    else if (secondPropertyName == "Density")
    {
        FluidsNamespace::secondPropertyName = "Density";
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
    double resultantInternalEnergy = CoolProp::PropsSI("U","T",274,"P",101325,"Water");
    std::string resultantInternalEnergyString = std::to_string(FluidsNamespace::resultantInternalEnergy);
    QString abc = QString::fromStdString(resultantInternalEnergyString);
    ui->lineEdit_internalEnergy->setText(abc);
}
