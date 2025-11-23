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

from PySide6.QtWidgets import QApplication,QLabel, QWidget, QBoxLayout,QVBoxLayout,QTableView,QDialog,QLineEdit, QPushButton,QFormLayout,QDataWidgetMapper,QCheckBox,QComboBox

from PySide6.QtGui import QGuiApplication,QFont,QPalette,QColor,QBrush
from PySide6.QtCore import QCoreApplication,Qt
from PySide6.QtSql import QSqlDatabase,QSqlRelationalTableModel,QSqlRelation,QSqlRelationalDelegate
from PySide6.QtSql import QSqlTableModel


#premiere police
maFont = QFont('chalkduster',18,QFont.Weight.Bold)
maFont.setItalic(True)

#deuxieme police
maFont2 = QFont()
maFont2.setFamily('Futura')
maFont2.setPointSize(15)
maFont2.setCapitalization(QFont.Capitalization.Capitalize)
maFont2.setWeight(QFont.Weight.Medium)

class FenetreSimple(QWidget):
    def __init__(self):
        super().__init__()

        self.setGeometry(100,100,300,200 )
        self.setWindowTitle("utilisation deQ Brush")

        self.disposition = QFormLayout()

        #champ "NOM"
        self.nomLabel = QLabel ("Nom:")
        self.nom = QLineEdit()
        #self.disposition.addRow(self.nomLabel,self.nom)

        # champ "PRENOM"
        #self.prenomLabel = QLabel("PreNom:")
        #self.prenom = QLineEdit()
        #self.disposition.addRow(self.prenomLabel, self.prenom)

        # champ "loisir prefere"
        #self.loisirlabel = QLabel("loisir prefere:")
        #self.loisir = QComboBox()
        #self.loisir.addItems([
        #    "Pratique sportive",
        #    "Pratique artistique",
        #    "programmation informatique",
        #    "voyage"
        #])

        #self.disposition.addRow(self.loisirlabel,self.loisir)

        #checkbox "possede un velo"
        #self.veloLabel = QLabel("possede un vélo?")
        #self.velo = QCheckBox()
        #self.velo.setChecked(True)
        #self.disposition.addRow(self.veloLabel,self.velo)

        #bouton "envoyer" et "annuler"
        self.boutonEnvoyer = QPushButton("Envoyer")
        self.boutonAnnuler = QPushButton("Annuler")

        self.disposition.addRow(self.nomLabel,self.nom)
        self.disposition.addRow(self.boutonEnvoyer,self.boutonAnnuler)

        #definir la disposition
        self.setLayout(self.disposition)

        #appliquer les polices
        #self.nomLabel.setFont(maFont)
        #self.prenomLabel.setFont(maFont2)
        #self.loisirlabel.setFont(maFont2)
        #self.veloLabel.setFont(maFont2)

        #self.clickbouton = QPushButton("Click", clicked=self.creationDB)
        #self.disposition.addWidget(self.clickbouton)
        #self.setLayout(self.disposition)
        #self.execute()

        #QtGui.QWindow.__init__(self,parent)
        #self.resize(30, 30)
        #self.setFont(QtGui.QFont("Verdana"))
        #self.setWindowTitle("Bases de données")

  #      self.clickbouton = QPushButton("Click",clicked=self.creationDB)êêEE
  #     self.disposition.addWidget(self.clickbouton)
  #      self.setLayout(self.disposition)
  #      self.execute()

        #ajouter des widgets au layout
        #self.disposition.addRow(self.nomLabel,self.nom)
        #self.disposition.addRow(self.prenomLabel, self.prenom)
        #self.disposition.addRow(self.loisirlabel, self.loisir)
        #self.disposition.addRow(self.veloLabel, self.velo)
        #self.disposition.addRow(self.boutonEnvoyer, self.boutonAnnuler)

        self.setLayout(self.disposition)

       #definir un pinceau avec un motif pointille  rouge
        brush = QBrush(Qt.GlobalColor.red,Qt.BrushStyle.DiagCrossPattern)

       #definir la palette pour la couleur de fond de la fenetre
        #appliquer le pinceau a une palette pour l arriere plan de la fenetre
        palette = QPalette()
        #bleu clair
        palette.setBrush(QPalette.ColorGroup.Normal,QPalette.ColorRole.Window,brush)
        #palette.setColor(QPalette.ColorGroup.Normal,QPalette.ColorRole.Window,QColor(300,300,500))
        #associer la palette a la fenetre
        self.setPalette(palette)
        self.setAutoFillBackground(True)

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

def prec():
    print("Bouton précédent")
    mapping.toPrevious()
    id.repaint()
    sujet.repaint()

def suiv():
    print("Bouton suivant")
    mapping.toNext()
    id.repaint()
    sujet.repaint()

def joinDB():
        app = QtCore.QCoreApplication(sys.argv)

        db = QtSql.QSqlDatabase.addDatabase('QSQLITE')
        db.setDatabaseName('Baselivres.db')
        print("connexion base ok")

        if not db.open():
            print("la db ne peut s'ouvrir.")
            return False

        query = QtSql.QSqlQuery()



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

    fenetre = FenetreSimple()
    fenetre.show()

    # creation de la boite de dialogue
    #dialogue = QDialog()
    #disposition = QFormLayout()

    #champ d'édition
    #id = QLineEdit()
    #id.setReadOnly(True)
    #sujet = QLineEdit()

    #disposition.addRow("ID:",id)
    #disposition.addRow("Sujet:",sujet)

    #precedentBouton = QPushButton("Précedent")
    #suivantBouton = QPushButton("suivant")
    #disposition.addRow(precedentBouton,suivantBouton)

    #dialogue.setLayout(disposition)
    #dialogue.setWindowTitle("usage de QDATAwidgetMapper")

    #base = QtSql.QSqlDatabase.addDatabase('QSQLITE')
    #base.setDatabaseName('Baselivres.db')

    #definition du modele
    #modele = QtCore.QAbstractItemModel
    #modele = QSqlTableModel()
    #modele.setTable('SUJET')
    #modele.setEditStrategy(QSqlTableModel.EditStrategy.OnFieldChange)

    #modification immediate
    #modele.select()

    #mapping = QDataWidgetMapper()
    #mapping.setModel(modele)
    #mapping.addMapping(id, 0)
    #mapping.addMapping(sujet, 1)
    #mapping.toFirst()

    #precedentBouton.clicked.connect(prec)
    #suivantBouton.clicked.connect(suiv)

    #modele.select()

    #dialogue.show()

    # ...
    sys.exit(app.exec())



# See PyCharm help at https://www.jetbrains.com/help/pycharm/
