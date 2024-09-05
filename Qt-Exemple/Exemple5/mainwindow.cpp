#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Chapitre 5 - arret youtube Time:3:26

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
