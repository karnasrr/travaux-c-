#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtWidgets/QMessageBox>
#include <QSqlQueryModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connectToDatabase();
    ui->setupUi(this);
}


void MainWindow::connectToDatabase() {

    // make sure any query or model depending on the database connection is
            // out-of-scope/deleted, then

                // For a named connection
                //QSqlDatabase::removeDatabase("FunkyDBName");

    // For the default connection
    //QString connName;
    //{
    //    QSqlDatabase db = QSqlDatabase::database();
    //    connName = db.connectionName();
    //}
    //QSqlDatabase::removeDatabase(connName);
    //@





    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("contacts.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données");
        return;
    }

    // Création de la table si elle n'existe pas
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS contacts (id INTEGER PRIMARY KEY AUTOINCREMENT, nom TEXT, prenom TEXT, telephone TEXT, email TEXT)");
}


void MainWindow::ajouterContact() {
    // Récupération des données des QLineEdit
    QString nom = ui->lineEditNom->text();
    QString prenom = ui->lineEditPreNom->text();
    QString email = ui->lineEditEmail->text();


    QSqlQuery query;
    query.prepare("INSERT INTO contacts (nom, prenom, telephone, email) VALUES (:nom, :prenom, :telephone, :email)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":email",email);

    // ...
    query.exec();

    // Rafraîchissement de la table
    afficherContacts();
}


void MainWindow::afficherContacts() {
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM contacts");
    ui->tableView->setModel(model);
}


void MainWindow::supprimerContact() {

    // Récupération des donnees des QLineEdit


    /// make sure any query or model depending on the database connection is
            // out-of-scope/deleted, then

                // For a named connection
                //QSqlDatabase::removeDatabase("FunkyDBName");

    // For the default connection
    //QString connName;
    //{
    //    QSqlDatabase db = QSqlDatabase::database();
    //    connName = db.connectionName();
    //}
    //QSqlDatabase::removeDatabase(connName);
    //@

    QString nom = ui->lineEditNom->text();
    QString prenom = ui->lineEditPreNom->text();
    QString email = ui->lineEditEmail->text();

    QSqlQuery query;
    //query.prepare("DELETE * FROM contacts(nom,prenom,telephone,email) VALUES (:nom,:prenom,:telephone,:email)");
    //query.bindValue(":nom",nom);
    //query.bindValue(":prenom",prenom);
    //query.bindValue(":email",email);


    QString critere = ui->lineEditRecherche->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    //model->setQuery("DELETE * FROM contacts(nom,prenom,telephone,email) VALUES (:nom,:prenom,:telephone,:email)");
    //model->setQuery("DELETE FROM contacts WHERE nom LIKE '%karim%'"); -> cok

    //efface de la table contacts les noms dont ressemblant au critere saisi dans le champ recherche
    model->setQuery("DELETE FROM contacts WHERE nom LIKE '%" + critere +"%'");

    //DELETE FROM artists_backup
    //    WHERE name LIKE '%Santana%';


    ui->tableView->setModel(model);



    //query.exec();
    afficherContacts();

   //QSqlQueryModel *model = new QSqlQueryModel;
    //model->setQuery("SELECT * FROM contacts");
    //ui->tableView->setModel(model);
}




void MainWindow::rechercherContact() {
    QString critere = ui->lineEditRecherche->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM contacts WHERE nom LIKE '%" + critere + "%' OR prenom LIKE '%" + critere + "%'");
    ui->tableView->setModel(model);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAjouter_clicked()
{
    //connectToDatabase();
    ajouterContact();
}


void MainWindow::on_pushButtonSupprimer_clicked()
{
    //connectToDatabase();
    supprimerContact();
}


void MainWindow::on_pushButtonRechercher_clicked()
{
    //connectToDatabase();
    rechercherContact();
}

