#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->label_order->setWordWrap(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_order_clicked()
{

    QString str="Thank you-your oredr items";

    if(ui->checkBox_Dinner->isChecked())
    {
        str+="Dinner";
    }

    if(ui->checkBox_Lunch->isChecked())
    {
        str+="Lunch";
    }

    str+="will be placed shortly";

    ui->label_order->setText(str);
}

