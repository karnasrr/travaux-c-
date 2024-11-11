#include "mainwindow.h"

#include <QApplication>

#include <QVBoxLayout>

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QPushButton>
#include <QComboBox>
#include <QStringList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QWidget *fen;

    //QVBoxLayout *outerLayout = new QVBoxLayout(this);
    //QHBoxLayout *topLayout = new QHBoxLayout();
    //topLayout ->addWidget(new QLabel("Printer"));

    //QLayout layout = new QLayout();

    //QWidget* rien = new QWidget;
    //rien->setLayout(layout);
    //setCentralWidget(rien);


    QStringList *qstring = new QStringList();
    //qstring->contains(1);
    //qstring->insert(1,"toto");

    QWidget *maPage = new QWidget(); /* Création de la page qui contiendra le layout */

    /* Création des boutons */
    QPushButton *bouton1 = new QPushButton("Wiki");
    QPushButton *bouton2 = new QPushButton("Books");

    QHBoxLayout *monLayout = new QHBoxLayout(); /* Création du layout */
    /* Ajout des widgets dans le layout */
    monLayout->addWidget(bouton1);
    monLayout->addWidget(bouton2);

    QWidget *window = new QWidget;
    QWidget *window1 = new QWidget;

    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    QComboBox *combo = new QComboBox();

    //void	setCurrentText(const QString &text)
    //setEditText
    //configuration of combobox
    combo->setCurrentText("exemple");
    combo->setEditText("exercice");
    combo->addItem("Peugeot");
    combo->addItem("Citroën");
    combo->addItem("REN");



    combo->setEnabled(1);

    //combo->addItems(qstring);

    //combo->insertItems(1,"action1");


    QHBoxLayout *layout = new QHBoxLayout(window);

    QHBoxLayout *topLayout = new QHBoxLayout(window1);
    topLayout ->addWidget(new QLabel("Printer"));
    topLayout ->addWidget(combo);


    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);

    window->show();
    window1->show();


    //maPage->setLayout(monLayout); /* Le layout appartient désormais à l'objet maPage */

    //fen->setLayout(monLayout);
    //fen->show();
    //w->setLayout(monLayout);

    w.windowTitle();
    w.setCentralWidget(fen);
    w.show();
    return a.exec();
}
