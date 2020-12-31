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
    QString fluidNameQString = ui->listWidget_quickList->currentItem()->text();


    QString a = ui->listWidget_quickList->currentItem()->text();
    double internalEnergy = CoolProp::PropsSI("T","P",101325,"Q",0,"Water");
    std::string internalEnergyString = std::to_string(internalEnergy);
    QString internalEnergyQString = QString::fromStdString(internalEnergyString);
    ui->lineEdit->setText(a);
    ui->lineEdit_3->setText(internalEnergyQString);
}

