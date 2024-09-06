#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTabWidget>
#include <QFrame>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //extrait youtube
    //Tutoriel framework GUI Qt Français | Chapitre 4 | Gestion des onglets avec QTabWidget

    //arrete à COMPLET le 04/09/024 en dernier

    //creation New File & close File

    //exemple de programme pour utiliser widgets
    //affiche une barre en haut de l ecran avec menu et qd on clique sur file, il y a ajout de Untiltled
    //dans la fenêtre , affiche helloworld qd clicq sur untilted


    ui->setupUi(this);

    //fenêtre principal
    //QTabWidget *tabsWidget = new QTabWidget(this);


    //affiche tab1
    //tabsWidget->addTab(new QWidget,"Tab 1");

    //tabsWidget->addTab(new QWidget,"Tab 2");

    //tabsWidget->addTab(new QWidget,"Tab 3x");

    tabsWidget->setMovable(true);
    tabsWidget->setTabsClosable(true);

    setCentralWidget(tabsWidget);
    //tabsWidget->show();

    //ui->setupUi(this);

    //qd click sur icone fleche, on ferme la case
    connect(tabsWidget,SIGNAL(tabCloseRequested(int)),this,SLOT(closeTab(int)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionFile1_triggered()
 {
    QFrame *tabFrame = new QFrame(this);
    //QLabel *label = new QLabel(tabFrame);

    //affiche label Hello world qd clique sur bouton untiled
    //label->setText("Hello World");

    tabsWidget->addTab(tabFrame,"Untitled");
 }

 void MainWindow::on_actionClose_File_triggered()
 {
       //qd click sur icone fleche, on ferme la case
     tabsWidget->removeTab(tabsWidget->currentIndex());
 }


 void MainWindow::closeTab(int index)
{
         //qd click sur icone fleche, on ferme la case
     tabsWidget->removeTab(index);
}







