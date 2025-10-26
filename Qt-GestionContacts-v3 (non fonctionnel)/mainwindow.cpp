#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtWidgets/QMessageBox>
#include <QSqlQueryModel>
#include <QStandardItem>
#include <QWidget>
#include <QSQlerror>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connectToDatabase();
    ui->setupUi(this);

    connect(ui->comboBoxCategories, SIGNAL(currentIndexChanged(int)),
            this, SLOT(on_comboBoxCategories_currentIndexChanged(int)));
}


void MainWindow::connectToDatabase() {

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("contacts.db");
    //db.setDatabaseName("categories.db");

    if (!db.open()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données");
        return;
    }

    // Création de la table si elle n'existe pas
    QSqlQuery query;
    QSqlQuery queryCategories;

    queryCategories.exec("CREATE TABLE IF NOT EXISTS categories (id INTEGER PRIMARY KEY AUTOINCREMENT,nom TEXT)");
    if(!queryCategories.exec()){

        qDebug() << "Erreur lors de creation categories :" << queryCategories.lastError().text();
    }


    //query.exec("CREATE TABLE IF NOT EXISTS contacts (id INTEGER PRIMARY KEY AUTOINCREMENT , categorie_id INTEGER,nom TEXT, prenom TEXT, telephone TEXT, email TEXT,FOREIGN KEY(categorie_id))");
    query.exec("CREATE TABLE IF NOT EXISTS contacts (id INTEGER PRIMARY KEY AUTOINCREMENT , nom TEXT, prenom TEXT, telephone TEXT, email TEXT, categorie_id INTEGER DEFAULT 0);");
    if(!query.exec()){

        qDebug() << "Erreur lors de creation contacts :" << query.lastError().text();
    }

    //query.exec("CREATE TABLE IF NOT EXISTS contacts (id INTEGER PRIMARY KEY AUTOINCREMENT , nom TEXT, prenom TEXT, telephone TEXT, email TEXT)");
    //queryCategories.exec("CREATE TABLE IF NOT EXISTS categories (id INTEGER PRIMARY KEY AUTOINCREMENT,nom TEXT)");

    //supprimerContact();
}


void MainWindow::ajouterContact() {
    // Récupération des données des QLineEdit
    int16_t id = ui->lineEditId->text().toUInt();
    int16_t categorieId = ui->lineEditCategorieId->text().toInt();
    //int16_t categorie_id;

    QString nom = ui->lineEditNom->text();
    QString prenom = ui->lineEditPreNom->text();
    QString email = ui->lineEditEmail->text();
    QString telephone = ui->lineEditTelephone->text();

    QString idCat;
    QString nomCat;
    //QString numberOfContacts = ui->lineEditNumberOfContacts->text();

    QSqlQuery query;

    QSqlQuery queryCategories;
    queryCategories.prepare("INSERT INTO categories (nom ) VALUES ('ouvriers')");
    queryCategories.prepare("INSERT INTO categories (nom ) VALUES ('cadre')");
    queryCategories.prepare("INSERT INTO categories (nom ) VALUES ('administratif')");

    //queryCategories.bindValue(":id",idCat);
    queryCategories.bindValue(":nom",'administratif');

    queryCategories.exec();

    if(!queryCategories.exec()){

        qDebug() << "Erreur lors de l'insertion dans categories :" << queryCategories.lastError().text();
    }

   //query.prepare("INSERT INTO contacts (id,nom, prenom, telephone, email) VALUES (:id,:nom, :prenom, :telephone, :email)");

    qDebug() << " ID acquise IHM:" << id;
    qDebug() << "Categorie acquise IHM:" << categorieId;
    qDebug() << " nom acquise IHM:" << nom;
    qDebug() << " prenom acquise IHM:" << prenom;
    qDebug() << " email acquise IHM:" << email;
    qDebug() << " telephone acquise IHM:" << telephone;

    //query.clear();
    //query.prepare("INSERT INTO contacts (id,categorie_id,nom, prenom, telephone, email) VALUES ('3',:categorieId,:nom,:prenom,:telephone,:email)");
    //query.bindValue(":categorie_id",1);
    //query.bindValue(":nom", nom);
    //query.bindValue(":prenom", prenom);
    //query.bindValue(":telephone",telephone);
    //query.bindValue(":email",email);

    // Vérification de categorieId
    if (categorieId <= 0) {
        qDebug() << "categorie_id est invalide !";
        categorieId = 1; // Valeur par défaut
    }


    query.prepare("ALTER TABLE contacts ADD COLUMN categorie_id integer NOT NULL DEFAULT 0 REFERENCES  categories(id);");
    query.prepare("INSERT INTO contacts(id,nom,prenom,telephone,email,categorie_id) VALUES(:id,:nom,:prenom,:telephone,:email,:categorieId);");
    //query.prepare("ALTER TABLE contacts ADD COLUMN categorie_id integer NOT NULL DEFAULT 0 REFERENCES categories(id);");
    query.bindValue(":id",id);
    //query.bindValue(":categorie_id",categorieId);
    query.bindValue(":categorie_id", ui->comboBoxCategories->currentText().toInt());
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":telephone",telephone);
    query.bindValue(":email",email);

    // Vérification de categorieId
    //if (categorieId <= 0) {
    //    qDebug() << "categorie_id est invalide !";
    //    categorieId = 1; // Valeur par défaut
    //}

    qDebug() << "Bound values:" << query.boundValues();
    query.exec();
    // ...

    //qDebug() << "Categorie acquise IHM:" << categorieId;
    //qDebug() << "Bound values:" << query.boundValues();
    qDebug() << "Erreur lors de l'insertion dans contacts :" << query.lastError().text();


    if (query.exec("PRAGMA table_info(contacts);")) {
        while (query.next()) {
            QString columnName = query.value(1).toString();  // Nom de la colonne
            QString columnType = query.value(2).toString(); // Type de la colonne
            bool isNotNull = query.value(3).toBool();       // NOT NULL
            qDebug() << "Colonne :" << columnName << ", Type :" << columnType << ", NOT NULL :" << isNotNull;
        }
    } else {
        qDebug() << "Erreur PRAGMA:" << query.lastError().text();
    }

    // Rafraîchissement de la table
    afficherContacts();
    //remplir combo box
    remplirComboBoxCategories();
}

void MainWindow::filtrerParCategorie(){

    // ajouter code pour filtrer par categories

    if(ui->comboBoxCategories->currentText().toStdString()=="4-cadre")
    {
        // categorie 4-cadre
        std::string text=ui->comboBoxCategories->currentText().toStdString();
        qDebug() << "Categorie sélectionné:" << text;

        //filtre categorie 4

    }
    else if(ui->comboBoxCategories->currentText().toStdString()=="3-ouvrier")
    {
        // categorie 3-ouvrier
        std::string text=ui->comboBoxCategories->currentText().toStdString();
        qDebug() << "Categorie sélectionné:" << text;

        //filtre categorie 3
    }
    else
    {
        std::string text=ui->comboBoxCategories->currentText().toStdString();
        qDebug() << "Categorie sélectionné:" << text;

        //filtre desactive
    }


}

void MainWindow::remplirComboBoxCategories() {

    // Vider le ComboBox avant de le remplir
    ui->comboBoxCategories->clearEditText();

    QSqlQuery query("SELECT id,nom FROM categories");
    while (query.next()) {

        // Vider le ComboBox avant de le remplir
        //ui->comboBoxCategories->clear();

        QString id = query.value(0).toString();
        QString nom = query.value(1).toString();
        QString valeurCombinaison = id + "-" + nom;
        ui->comboBoxCategories->addItem(valeurCombinaison);
        //ui->comboBoxCategories->addItem(query.value(1).toString(),query.value(0).toString());
    }

    //QVB
    //QVBoxLayout *layout() = new QVBoxLayout(this);
    //layout->addWigget(comboBoxCategories);

    //QSqlQuery modelquery;

    //modelquery.exec("SELECT nom,email FROM contacts");
    //QSqlQueryModel *model = new QSqlQueryModel;
    //model->setQuery(modelquery);
    //model->setHeaderData(0, Qt::Horizontal, "UserName");
    //model->setHeaderData(1, Qt::Horizontal, "email");
    //model->setHeaderData(2, Qt::Horizontal, "File Location");
    //model->setHeaderData(3, Qt::Horizontal, "Size");
    //model->setHeaderData(4, Qt::Horizontal, "Finished");

    //ui->comboBoxCategories->setModel(model);


    // Requête SQL pour sélectionner les colonnes souhaitées
    // exemple
    /*
    QSqlQuery query("SELECT Nom, Prix FROM Produits");

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête :" << query.lastError();
        return;
    }

    // Créer un objet QComboBox
    QComboBox *comboBox = new QComboBox(this);

    // Ajouter les données à la combobox
    while (query.next()) {
        QString nom = query.value(0).toString();
        double prix = query.value(1).toDouble();
        QString valeurCombinaison = nom + " - " + QString::number(prix) + "€";
        comboBox->addItem(valeurCombinaison);
    }

    // Affichage de la combobox
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(comboBox);
    */
    //fin exemple


    //QStandardItem *col0 = new QStandardItem("UserName");
    //QStandardItem *col1 = new QStandardItem("email");

    //model->setItemData((const QModelIndex)0, col0);
    //model->setItemData((const QModelIndex)1, col1);

    //ui->comboBoxCategories->setModel(&model);

    /*
    QStandardItemModel model(5, 3);
    for(int i = 0; i < model.rowCount(); i++)
    {
        QStandardItem *col0 = new QStandardItem(QString("foobar%1").arg(i));
        QStandardItem *col1 = new QStandardItem(QString("foo%1").arg(i));
        QStandardItem *col2 = new QStandardItem(QString("bar%1").arg(i));

        model.setItem(i, 0, col0);
        model.setItem(i, 1, col1);
        model.setItem(i, 2, col2);
    }

    ui->comboBox->setModel(&model);
    QTreeView *treeView = new QTreeView(ui->comboBox);
    ui->comboBox->setView(treeView);

    treeView->setColumnHidden(0, true);im
    treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
    treeView->setAllColumnsShowFocus(true);
    treeView->setRootIsDecorated(false);
    treeView->header()->hide();

    */


    //QComboBox *myCmb= new QComboBox;
    //myCmb->addItem("one");
    //myCmb->addItem("two");
    //myCmb->addItem("three");
    //myCmb->addItem("four");

    //ui->comboBoxCategories->addItem(query.value(1).toString());
    //ui->comboBoxCategories->addItem(query.value(1).toString());
    //ui->comboBoxCategories->addItem("three");
    //ui->comboBoxCategories->addItem("four");
    //ui->comboBoxCategories->addItem("five");
}


void MainWindow::afficherContacts() {
    QSqlQueryModel *model = new QSqlQueryModel;
    QSqlQueryModel *modelContacts = new QSqlQueryModel;
    QString numberOfContacts;

    //SELECT COUNT(*) FROM contacts

    model->setQuery("SELECT * FROM contacts");
    ui->tableView->setModel(model);

    modelContacts->setQuery("SELECT COUNT(*) FROM contacts");
    ui->tableViewNumberOfContacts->setModel(modelContacts);
    //ui->lineEditNumberOfContacts->text()=numberOfContacts;
}


void MainWindow::supprimerContact() {


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

    afficherContacts();

}


void MainWindow::rechercherContact() {
    QString critere = ui->lineEditRecherche->text();
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM contacts WHERE nom LIKE '%" + critere + "%' OR prenom LIKE '%" + critere + "%'");
    ui->tableView->setModel(model);
}

void MainWindow::updateContact() {

    QString critere = ui->lineEditRecherche->text();
    QSqlQueryModel *model = new QSqlQueryModel;

    QString nom = ui->lineEditNom->text();
    QString prenom = ui->lineEditPreNom->text();
    QString email = ui->lineEditEmail->text();
    QString telephone = ui->lineEditTelephone->text();


    model->setQuery("SELECT * FROM contacts WHERE nom LIKE '%"+critere+"%'");


    //UPDATE employees
    //    SET lastname = 'Smith'
    //    WHERE employeeid = 3;

    model->setQuery("UPDATE contacts SET NOM = '"+nom+"' WHERE nom LIKE '%"+critere+"%'");
    model->setQuery("UPDATE contacts SET PRENOM = '"+prenom+"' WHERE nom LIKE '%"+critere+"%'");
    model->setQuery("UPDATE contacts SET EMAIL = '"+email+"' WHERE nom LIKE '%"+critere+"%'");
    model->setQuery("UPDATE contacts SET TELEPHONE = '"+telephone+"' WHERE nom LIKE '%"+critere+"%'");

    ui->tableView->setModel(model);
    //REPLACE INTO positions (title, min_salary)
    //VALUES('Full Stack Developer', 140000);

     afficherContacts();
     remplirComboBoxCategories();
     filtrerParCategorie();

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


void MainWindow::on_Update_clicked()
{
    updateContact();
}


void MainWindow::on_comboBoxCategories_currentIndexChanged(int index)
{
    //remplirComboBoxCategories();


    // Récupérer l'ID du produit sélectionné
    //int selectedId = ui->comboBoxCategories->currentData().toInt();

    std::string text=ui->comboBoxCategories->currentText().toStdString();



    qDebug() << "Categorie sélectionné avec l'ID:" << text;

}


void MainWindow::on_comboBoxCategories_textActivated(const QString &arg1)
{
    //remplirComboBoxCategories();
}


void MainWindow::on_comboBoxCategories_customContextMenuRequested(const QPoint &pos)
{
    //remplirComboBoxCategories();
}

