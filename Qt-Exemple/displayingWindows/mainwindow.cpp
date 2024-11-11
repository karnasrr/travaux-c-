#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //extrait youtube de
    //
    //Displaying Windows

    //        VoidRealms
    // creation d'un nouveau formulaire de dialog dans formulaire et le fichier dialog.h
    // modification de mainwindow.h pour intégrer Dialog *mDialog;
    // quand appui sur file on a possibilité d'afficher plusieurs dialog

    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Window_triggered()
{
    //Dialog mDialog;
    //mDialog.setModal(false);
    //mDialog.exec();
    //Dialog.show();

    mDialog = new Dialog(this);
    mDialog->show();

}

