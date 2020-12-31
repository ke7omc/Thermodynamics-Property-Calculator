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
