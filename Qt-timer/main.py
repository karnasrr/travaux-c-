# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.


#def print_hi(name):
    # Use a breakpoint in the code line below to debug your script.
    #print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint.


# Press the green button in the gutter to run the script.
#if __name__ == '__main__':
#    print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/

import sys

from PyQt6.QtSql import *
from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6 import QtWidgets
from PyQt6.QtCore import QTime
from PyQt6.QtWidgets import *
from PyQt6.QtCore import QTimer


from PyQt6.QtWidgets import QWidget,QPushButton,QApplication,QListWidget,QGridLayout,QLabel
from PyQt6.QtCore import QTimer,QDateTime


class Fenetre(QWidget):
    def __init__(self):
        super().__init__()

        #QTimer *timer = QTimer()

        #connect(timer,SIGNAL(timeout(),widget,SLOT(doSomething())))
        #timer.start(1000)

        #self.timer = QTimer(self)
        #self.timer.timeout.connect(self.showTime)
        #self.timer = QTimer()

        #self.setGeometry(100,100,300,200 )
        self.setWindowTitle("Deuxieme fenetre")
        self.resize(250,300)
        self.move(50,500)

        self.disposition = QVBoxLayout()

        #creation bouton fermer
        self.fermer = QPushButton("Fermer")
        self.disposition.addWidget(self.fermer)

        #connexion du signal clicked au slot exemple_slot
        self.fermer.clicked.connect(self.exemple_slot)

        self.setLayout(self.disposition)
        #self.show()

        #self.timer.startTimer(3000)

        #self.close()
        #timer.stop()

        #champ "NOM"
        #self.nomLabel = QLabel ("Nom:")
        #self.nom = QLineEdit()
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
        #self.boutonEnvoyer = QPushButton("Envoyer")
        #self.boutonAnnuler = QPushButton("Annuler")

        #self.disposition.addRow(self.nomLabel,self.nom)
        #self.disposition.addRow(self.prenomLabel, self.prenom)
        #self.disposition.addRow(self.loisirlabel, self.loisir)
        #self.disposition.addRow(self.veloLabel, self.velo)



        #self.disposition.addRow(self.boutonEnvoyer,self.boutonAnnuler)

        #definir la disposition
        #self.setLayout(self.disposition)

        #feuille de style QSS
        feuille_de_style = """
        QWidget{
            background-color: lightblue; /*fond bleu clair*/
          }
        QLabel {
            color: darkblue; /*couleur texte des labels*/
            font-weight: bold;
        } 
        QPushButton {
            background-color: lightgreen; /*fond des boutons*/
            border: 1px solid green;
            border-radius: 5px
        }
        QPushButton:hover {
            background-color: yellow; /*fond en survol*/
        }
        """
        self.setStyleSheet(feuille_de_style)


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

    def exemple_slot(self):
        print("fermeture de la fenetre...")

        #self.fenetre1 = FenetreSimple()
        #self.fenetre1.show()

        self.close()

    #def showTime(self):
    #    current_time = QDateTime.currentDateTime()
    #    formatted_time = current_time.toString('yyyy-MM-dd hh:mm:ss dddd')
    #    self.label.setText(formatted_time)
    #    print (current_time)
    #    self.timer.startTimer(3000)


class FenetreSimple(QWidget):
    def __init__(self):
        super().__init__()

        #QTimer *timer = QTimer()

        #connect(timer,SIGNAL(timeout(),widget,SLOT(doSomething())))
        #timer.start(1000)

        #self.timer = QTimer(self)
        #self.timer.timeout.connect(self.showTime)
        #self.timer = QTimer()

        #self.setGeometry(100,100,300,200 )
        self.setWindowTitle("premiere fenetre")
        self.resize(250,300)
        self.move(50,500)

        self.disposition = QVBoxLayout()

        #creation bouton fermer
        self.fermer = QPushButton("Fermer")
        self.disposition.addWidget(self.fermer)

        #connexion du signal clicked au slot exemple_slot
        self.fermer.clicked.connect(self.exemple_slot)

        self.setLayout(self.disposition)

        self.fenetre1 = Fenetre()

        #self.show()

        #self.timer.startTimer(3000)

        #self.close()
        #timer.stop()

        #champ "NOM"
        #self.nomLabel = QLabel ("Nom:")
        #self.nom = QLineEdit()
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
        #self.boutonEnvoyer = QPushButton("Envoyer")
        #self.boutonAnnuler = QPushButton("Annuler")

        #self.disposition.addRow(self.nomLabel,self.nom)
        #self.disposition.addRow(self.prenomLabel, self.prenom)
        #self.disposition.addRow(self.loisirlabel, self.loisir)
        #self.disposition.addRow(self.veloLabel, self.velo)



        #self.disposition.addRow(self.boutonEnvoyer,self.boutonAnnuler)

        #definir la disposition
        #self.setLayout(self.disposition)

        #feuille de style QSS
        feuille_de_style = """
        QWidget{
            background-color: lightblue; /*fond bleu clair*/
          }
        QLabel {
            color: darkblue; /*couleur texte des labels*/
            font-weight: bold;
        } 
        QPushButton {
            background-color: lightgreen; /*fond des boutons*/
            border: 1px solid green;
            border-radius: 5px
        }
        QPushButton:hover {
            background-color: yellow; /*fond en survol*/
        }
        """
        self.setStyleSheet(feuille_de_style)


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

    def exemple_slot(self):
        print("fermeture de la fenetre...")

        #self.fenetre1 = Fenetre()
        self.fenetre1.move(200,200)
        self.fenetre1.show()

        #self.close()

    #def showTime(self):
    #    current_time = QDateTime.currentDateTime()
    #    formatted_time = current_time.toString('yyyy-MM-dd hh:mm:ss dddd')
    #    self.label.setText(formatted_time)
    #    print (current_time)
    #    self.timer.startTimer(3000)



class WinForm(QWidget):
    def __init__(self,parent=None):
        super(WinForm, self).__init__(parent)
        self.setWindowTitle('QTimer demonstration')

        self.listFile=QListWidget()
        self.label=QLabel('Label')
        self.startBtn=QPushButton('Start')
        self.endBtn=QPushButton('Stop')

        layout=QGridLayout()

        self.timer=QTimer()
        self.timer.timeout.connect(self.showTime)

        layout.addWidget(self.label,0,0,1,2)
        layout.addWidget(self.startBtn,1,0)
        layout.addWidget(self.endBtn,1,1)

        self.startBtn.clicked.connect(self.startTimer)
        self.endBtn.clicked.connect(self.endTimer)

        self.setLayout(layout)

    def showTime(self):
        print("timer timeout")
        #self.fenetre.fenetre1.show()
        current_time=QDateTime.currentDateTime()
        formatted_time=current_time.toString('yyyy-MM-dd hh:mm:ss dddd')
        self.label.setText(formatted_time)

        self.fenetre = FenetreSimple()
        self.fenetre.show()
        self.fenetre.fenetre1.show()
        self.fenetre.fenetre1.move(500, 500)


    def startTimer(self):
        self.timer.start(60000)
        self.startBtn.setEnabled(False)
        self.endBtn.setEnabled(True)

    def endTimer(self):
        #self.fenetre.fenetre1.show()
        print("end timer")
        self.timer.stop()
        self.startBtn.setEnabled(True)
        self.endBtn.setEnabled(False)
        #self.fenetre.close()
        #self.fenetre.fenetre1.show()


if __name__ == '__main__':
    app=QApplication(sys.argv)
    form=WinForm()
    form.show()
    sys.exit(app.exec())
