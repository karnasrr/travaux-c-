# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.


# This Python file uses the following encoding: utf-8
import sys
import os
import PyQt6

from PyQt6 import QtSql
from PyQt6 import QtCore
from PyQt6 import QtGui

from PyQt6.QtSql import *
from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6 import QtWidgets
from PyQt6.QtWidgets import *
#from PyQt6 import QtWidget


from PySide6.QtWidgets import QApplication,QLabel, QWidget, QBoxLayout,QVBoxLayout,QTableView,QDialog, QPushButton

from PySide6.QtGui import QGuiApplication
from PySide6.QtCore import QCoreApplication,Qt
from PySide6.QtSql import QSqlDatabase,QSqlRelationalTableModel,QSqlRelation,QSqlRelationalDelegate
from PySide6.QtSql import QSqlTableModel


class FenetreSimple(QWidget):
    def __init__(self):
        super().__init__()

        self.disposition = QVBoxLayout()
        self.clickbouton = QPushButton("Click", clicked=self.creationDB)
        self.disposition.addWidget(self.clickbouton)
        self.setLayout(self.disposition)
        self.execute()

        #QtGui.QWindow.__init__(self,parent)
        self.resize(30, 30)
        #self.setFont(QtGui.QFont("Verdana"))
        self.setWindowTitle("Bases de données")

  #      self.clickbouton = QPushButton("Click",clicked=self.creationDB)
  #     self.disposition.addWidget(self.clickbouton)
        self.setLayout(self.disposition)
  #      self.execute()

    def creationDB(self):


        self.db = QtSql.QSqlDatabase.addDatabase('QSQLITE')
        self.db.setDatabaseName('Baselivres.db')
        print ("Creation base ok")
        if not self.db.open():
            print ("la Db ne peut pas s'ouvrir.")
            return False

        query = QtSql.QSqlQuery()

        print(query.exec("SELECT COUNT(*) FROM PERSONNE"))
        while query.next():
            print(query.value(0))
            query.exec("INSERT INTO PERSONNE('NOM','PRENOM') VALUES('Prieur','Benoit')")
            query.exec("INSERT INTO PERSONNE('NOM','PRENOM') VALUES('Mocq','François')")
            query.exec("INSERT INTO PERSONNE('NOM','PRENOM') VALUES('Lacaze','Sarah')")

            print(query.exec("SELECT COUNT(*) FROM PERSONNE"))
            while query.next():
                print(query.value(0))

        print(query.exec("SELECT COUNT(*) FROM SUJET"))
        while query.next():
            print(query.value(0))
            query.exec("INSERT INTO SUJET('SUJET') VALUES('Csharp')")
            query.exec("INSERT INTO SUJET('SUJET') VALUES('Rasperry pi')")
            query.exec("INSERT INTO SUJET('SUJET') VALUES('Scratch')")

            print(query.exec("SELECT COUNT(*) FROM SUJET"))
            while query.next():
                print(query.value(0))

        print(query.exec("SELECT COUNT(*) FROM LIVRE"))
        while query.next():
            print(query.value(0))
            query.exec("INSERT INTO LIVRE('TITRE','ANNEE','sujet_id','id') VALUES('programmation en C-preparation aux certifications MCSA-examen 70-483',2018,1,1)")
            query.exec("INSERT INTO LIVRE('TITRE','ANNEE','sujet_id','id') VALUES('WPF-developper des applications structurees',2017,1,2)")
            query.exec("INSERT INTO LIVRE('TITRE','ANNEE','sujet_id','id') VALUES('Rasperry PI 4',2019,2,3)")
            query.exec("INSERT INTO LIVRE('TITRE','ANNEE','sujet_id','id') VALUES('Arduino',2019,1,4)")

            print(query.exec("SELECT COUNT(*) FROM LIVRE"))
            while query.next():
                print(query.value(0))

        query = QtSql.QSqlQuery()
        query.exec("UPDATE SUJET SET SUJET = 'MICROSOFT C#' WHERE id =2")

        query.exec("SELECT COUNT(*) FROM SUJET")
        while query.next():
            print(query.value(0))

        query.exec("SELECT SUJET FROM SUJET WHERE id = 2")
        while query.next():
            print(query.value(0))


        self.db.commit()
        self.db.close()
    #Creation des requêtes SQL
        creationTableLivre = """create table LIVRE(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            TITRE TEXT NOT NULL,
            ANNEE int,
            sujet_id INTEGER REFERENCES SUJET(id)
            );"""

        creationTableSujet = """create table SUJET(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            SUJET TEXT NOT NULL
            );"""
        creationTablePersonne = """create table PERSONNE(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            NOM TEXT NOT NULL,
            PRENOM TEXT NOT NULL
        );"""

    #Execution des requetes SQL
        self.db.open()
        query = QtSql.QSqlQuery()
        #self.db.close()

        if query.exec(creationTableLivre):
            print("creation table LIVRE ok")

        if query.exec(creationTableSujet):
            print("creation table SUJET ok")

        if query.exec(creationTablePersonne):
            print("creation table Personne ok")

        self.db.close()


    def execute (self):
        self.resize(250, 300)
        self.move(50, 500)
        self.setWindowTitle("chapitre 8 - insertion de donnees")
        self.show()

def joinDB():
        app = QtCore.QCoreApplication(sys.argv)

        db = QtSql.QSqlDatabase.addDatabase('QSQLITE')
        db.setDatabaseName('Baselivres.db')
        print("connexion base ok")

        if not db.open():
            print("la db ne peut s'ouvrir.")
            return False

        query = QtSql.QSqlQuery()

        #query.exec(
        #    "INSERT INTO LIVRE('TITRE','ANNEE','sujet_id','id') VALUES('programmation en C-preparation aux certifications MCSA-examen 70-483',2018,1,1)")
        #query.exec(
        #    "INSERT INTO LIVRE('TITRE','ANNEE','sujet_id','id') VALUES('WPF-developper des applications structurees',2017,1,2)")
        #query.exec("INSERT INTO LIVRE('TITRE','ANNEE','sujet_id','id') VALUES('Rasperry PI 4',2019,2,3)")
        #query.exec("INSERT INTO LIVRE('TITRE','ANNEE','sujet_id','id') VALUES('Arduino',2019,1,4)")

        #query.exec("""
        #    SELECT PERSONNE.PRENOM, PERSONNE.NOM
        #    FROM PERSONNE, LIVRE, SUJET
        #    WHERE PERSONNE.id = LIVRE.id
        #    AND SUJET.id = LIVRE.id
        #    AND SUJET.SUJET = 'Arduino'
        #    AND LIVRE.ANNEE = 2019
        #""")

        #affiche jointure
        #connexion
        #base ok
        #Benoit Prieur
        #François Mocq
        #Sarah Lacaze

        sujet = 'Scratch'
        annee = 2019

        requete="""
            SELECT PERSONNE.PRENOM, PERSONNE.NOM
            FROM PERSONNE, LIVRE, SUJET
            WHERE PERSONNE.id = LIVRE.id
            AND SUJET.id = LIVRE.id
                """

        query.prepare(requete)
        query.bindValue(":sujet",sujet)
        query.bindValue(":annee",annee)

        if query.exec():
            while query.next():
                print(query.value(0),query.value(1))
        else:
            print("erreur dans l execution de la requete:",query.lastError().text())

        query.exec("""
            SELECT PERSONNE.PRENOM, PERSONNE.NOM
            FROM PERSONNE, LIVRE, SUJET
            WHERE PERSONNE.id = LIVRE.id
            AND SUJET.id = LIVRE.id
              """)

        while query.next():
            print(query.value(0),query.value(1))

def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    # affiche jointure
    # connexion
    # base ok
    # Benoit Prieur
    # François Mocq
    # Sarah Lacaze
    #joinDB()
    #Application.instance()
    app = QApplication(sys.argv)

    base = QtSql.QSqlDatabase.addDatabase('QSQLITE')
    base.setDatabaseName('Baselivres.db')

    #definition du modele
    #modele = QtCore.QAbstractItemModel
    modele = QSqlRelationalTableModel()
    modele.setTable('LIVRE')
    modele.setEditStrategy(QSqlRelationalTableModel.EditStrategy.OnFieldChange)

    modele.setRelation(3,QSqlRelation("SUJET","id","SUJET"))
    modele.setRelation(4, QSqlRelation("PERSONNE", "id", "PRENOM"))

    #modification immediate
    #modele.select()
    modele.setHeaderData(3,Qt.Horizontal,"SUJET")
    modele.setHeaderData(3, Qt.Horizontal, "PRENOM")
    #modele.setHeaderData(3, QtCore.Qt.Orientation.Horizontal, "SUJET")
    #modele.setHeaderData(4,QtCore.Qt.Orientation.Horizontal,"PRENOM")
    modele.select()

    #creation de la vue et association au modele
    vue = QTableView()
    vue.setModel(modele)
    vue.setItemDelegate(QSqlRelationalDelegate(vue))

    #dialogue = QDialog()
    #disposition = QVBoxLayout()
    #disposition.addWidget(vue)

    #fenetre = QtWidgets.QWidget()

    #fenetre.QTableView().setModel(QtSql.QSqlTableModel())
    #vue.setItemDelegate(QSqlRelationalDelegate(vue))

    #creation de la boite de dialogue
    dialogue = QDialog()
    disposition = QVBoxLayout()
    disposition.addWidget(vue)

    #bouton d ajout
    bouton_ajout = QPushButton("ajouter un livre")
    bouton_ajout.clicked.connect(lambda :modele.insertRows(modele.rowCount(),1))
    disposition.addWidget(bouton_ajout)

    #bouton de suppression
    bouton_suppression = QPushButton("supprimer un livre")
    bouton_suppression.clicked.connect(lambda : modele.removeRow(vue.currentIndex().row()))
    disposition.addWidget(bouton_suppression)

    #finalisation de l interface
    dialogue.setLayout(disposition)
    dialogue.setWindowTitle("usage de QsqRelationalModele")
    dialogue.show()


    #app = QtCore.QCoreApplication(sys.argv)

    #app = QtCore.QCoreApplication(sys.argv)
    #app = QtGui.QGuiApplication(sys.argv)
    #app = QtCore.QCoreApplication(sys.argv)

    #app= QtCore.QCoreApplication.arguments()


    # ...
    sys.exit(app.exec())

    #fenetre = FenetreSimple()
    #sys.exit(app.exec())

    #print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
