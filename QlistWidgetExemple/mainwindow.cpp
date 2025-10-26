#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_clicked()
{
    QString str= ui->lineEdit->text();

    if(str=="") return;

    ui->listWidget->addItem(str);
}


void MainWindow::on_pushButton_2_clicked()
{

}


void MainWindow::on_pushButtonDel_clicked()
{

    if(mnSelected !=-1)
    {
        QListWidgetItem *it =  ui->listWidget->takeItem(mnSelected);
        delete it;
        ui->listWidget->setCurrentRow(-1);
    }


}


void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    mnSelected = currentRow;
}

