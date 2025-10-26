#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

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

    int sum_int=0;
    QString str="Thank you-your oredr items \n";

    QString sum="bill";

    if(ui->checkBox_Dinner->isChecked())
    {
        str+=" Dinner \n";
        sum_int+=10;
    }

    if(ui->checkBox_Lunch->isChecked())
    {
        str+=" Lunch \n";
        sum_int+=10;
    }

    if(ui->checkBox_Breakfast->isChecked())
    {
        str+=" Breakfast \n";
        sum_int+=5;
    }


    if(ui->checkBox_Others->isChecked())
    {
        str+=" Others \n";
        sum_int+=2;
    }


    str+="will be placed shortly";

    ui->label_order->setText(str);

    sum += std::to_string(sum_int);

    ui->label->setText(sum);
    ui->lcdNumber->screen();
    ui->lcdNumber->display(sum_int);

}


void MainWindow::on_dialObject_valueChanged(int value)
{
    ui->lcdNumber->display(ui->dialObject->value());
}

