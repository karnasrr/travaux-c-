# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.

import sys
import os
import PyQt6
import time
import timeit

from PyQt6.QtSql import *
from PyQt6.QtCore import *
from PyQt6.QtGui import *
from PyQt6 import QtWidgets
from PyQt6.QtCore import QTime
from PyQt6.QtWidgets import *
from PyQt6.QtCore import QTimer

from statemachine import StateMachine, State


class TestClass(QObject):
    def __init__(self):
        print("object TestClass is instancied")
        super(TestClass, self).__init__()

        self.messagesLeft = 0
        self.messagesLeft1 = 0
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.doSomething)

        self.timer1 = QTimer(self)
        self.timer1.timeout.connect(self.doSomething1)

    def startDoingSomething(self):
        self.messagesLeft = 20
        self.timer.start(2000)


    def startDoingSomething1(self):
        self.messagesLeft1 = 20
        self.timer1.start(2000)



    def doSomething(self):
        if self.messagesLeft > 0:
            print("test %d\n" % self.messagesLeft)
            self.messagesLeft -= 1
        else:
            print("timer stop")
            print("timer1 start")
            self.messagesLeft1 = 20
            self.timer1.start(2000)
            self.fenetre = FenetreSimple()
            self.fenetre1 = FenetreSimple()
            self.fenetre.show()
            #self.fenetre1.show()
            self.timer.stop()


    def doSomething1(self):
        if self.messagesLeft1 > 0:
            print("test %d\n" % self.messagesLeft1)
            self.messagesLeft1 -= 1
            if self.messagesLeft1 == 10:
                self.fenetre1.show()
            if self.messagesLeft1 == 5:
                self.fenetre1.close()

        else:
            print("timer stop")
            print("timer1 start")
            #self.messagesLeft = 20
            #self.timer1.start(2000)
            #self.messagesLeft1 = 20
            self.timer1.stop()
            self.fenetre.close()

class View(QMainWindow):
    def __init__(self):
        super().__init__()
        self.resize(300, 80)

        self.label = QLabel('Hi, I am a label')
        self.label.setStyleSheet('border: 1px solid black;')
        self.label.setMaximumHeight(25)
        self.label.setMinimumHeight(25)

        self.label2 = QLabel()
        self.label2.setStyleSheet('border: 1px solid black; background-color: lightyellow')
        self.label2.setMaximumHeight(25)
        self.label2.setMinimumHeight(25)
        self.label2.hide()

        self.button = QPushButton('Click Me')

        layout = QGridLayout()
        layout.addWidget(self.label, 0, 0, 1, 1)
        layout.addWidget(self.label2, 1, 0, 1, 1)
        layout.addWidget(self.button, 2, 0, 1, 1)

        widget = QWidget()
        widget.setLayout(layout)
        self.setCentralWidget(widget)


class Controller:
    def __init__(self, view):
        self.view = view
        self.duration = 5

        self.view.button.pressed.connect(self.show_msg)

    def show_msg(self):
        self.view.label2.setText(f'I am going to close in {self.duration} seconds.')
        self.view.label2.show()
        self.timer = QTimer()
        self.timer.timeout.connect(self.update)
        self.timer.start(1000)

        self.msg = QMessageBox()
        self.msg.setText(f'I am going to close in {self.duration} seconds.')
        self.msg.setIcon(QMessageBox.Icon.Information)
        self.msg.exec()

    def update(self):
        self.view.label2.setText(f'I am going to close in {self.duration} seconds.')
        self.msg.setText(f'I am going to close in {self.duration - 2} seconds.')
        self.duration -= 1

        box_dur = self.duration - 2
        if box_dur < 0:
            self.msg.close()

        if self.duration < 0:
            self.timer.stop()
            self.view.label2.hide()
            self.duration = 5

    def hideit(self, arg):
        arg.hide()

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
        self.setWindowTitle("signaux et slots")
        self.resize(250,300)
        self.move(50,500)

        self.disposition = QVBoxLayout()

        #creation bouton fermer
        self.fermer = QPushButton("Fermer")
        self.disposition.addWidget(self.fermer)

        #connexion du signal clicked au slot exemple_slot
        #self.fermer.clicked.connect(self.exemple_slot)

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

    #def showTime(self):
    #    current_time = QDateTime.currentDateTime()
    #    formatted_time = current_time.toString('yyyy-MM-dd hh:mm:ss dddd')
    #    self.label.setText(formatted_time)
    #    print (current_time)
    #    self.timer.startTimer(3000)

class TrafficLightMachine(StateMachine):
    """A traffic light machine"""
    print("traffic light machine")
    green = State(initial=True)
    yellow = State()
    red = State()

    cycle = (
        green.to(yellow)
        | yellow.to(red)
        | red.to(green)
    )

    def before_cycle(self, event: str, source: State, target: State, message: str = ""):
        message = "." + message if message else ""
        return print(f"Running {event} from {source.id} to {target.id}{message}")

    def on_enter_red(self):
        print("Don't move.")

    def on_exit_red(self):
        print("Go ahead")

def print_hi(name):
         # Use a breakpoint in the code line below to debug your script.
         print(f'Hi, {name}')  # Press ⌘F8 to toggle the breakpoint.

def showTime():
        print("lancement de showtime")
        current_time = QDateTime.currentDateTime()
        formatted_time = current_time.toString('yyyy-MM-dd hh:mm:ss dddd')
        #self.label.setText(formatted_time)
        print(current_time)
        timer.startTimer(3)
        time.sleep(30)

# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    print_hi('PyCharm')

    #QTimer *timer = new QTimer()

    #self.timer = QTimer()

    #sm = TrafficLightMachine()

    app = QApplication(sys.argv)

    #print("start timer")
    #timer = QTimer()
    #timer.timeout.connect(showTime)
    #timer.startTimer(3)

    #showTime()
    #time.sleep(0)
    #print("end of sleep")
    #showTime()

    #current_time = QDateTime.currentDateTime()
    #formatted_time = current_time.toString('yyyy-MM-dd hh:mm:ss dddd')
    #print(formatted_time)
    #print(current_time)

    #fenetre = FenetreSimple()
    #fenetre.show()
    #controller = Controller(View())
    #controller.view.show()

    #timer = QTimer()
    #timer.timeout.connect(showTime)

    #print(sm.current_state.id)
    #sm.send("cycle",message="please, first cycle")
    #print(sm.current_state.id)
    #sm.send("cycle")
    #print(sm.current_state.id)
    #fenetre.close()
    #controller.view.close()
    #sm.send("cycle",message="please, now slowdown")
    #print(sm.current_state.id)
    #print(sm.green.is_active)
    #print(sm.red.is_active)
    #print([s.id for s in sm.states])
    # sm.send("go")
    #fenetre = FenetreSimple()

    #controller = Controller(View())
    #controller.view.show()

    #fenetre.show()
    #timer.startTimer(3000)

    print("lancement de x-TestClass")
    x = TestClass()
    x.startDoingSomething()

    #time.sleep(30)
    #print("end of sleep")

    #print("lancement de y-TestClass")
    #y = TestClass()
    #y.startDoingSomething()

    #fenetre = FenetreSimple()
    #fenetre.show()

    #y.startDoingSomething()
    #fenetre.close()

    #fenetre_1 = FenetreSimple()
    #y.startDoingSomething()
    #fenetre_1.show()

    #showTime()
    #time.sleep(10)
    #print("end of sleep")
    #showTime()

    #current_time = QDateTime.currentDateTime()
    #formatted_time = current_time.toString('yyyy-MM-dd hh:mm:ss dddd')
    #print(formatted_time)
    #print(current_time)

    #timer.stop()

    sys.exit(app.exec())

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
