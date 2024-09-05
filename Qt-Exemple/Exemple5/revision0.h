#ifndef REVISION0_H_INCLUDED
#define REVISION0_H_INCLUDED
#include <string>
#include <vector>

using namespace std;

struct VILLE{
    int id;
    string libelle;
    string departement;
    int effectif;
};


struct ECOLE{
    int id;
    string libelle;
    int effectif;
};


struct CLASSE{
    int id;
    string libelle;
    int effectif;
};

struct ETUDIANT{
    int id;
    string nom;
    string prenom;
    int age;
    CLASSE cl;
    ECOLE c2;
};

//  prototypes
CLASSE saisirClasse(int);
ECOLE saisirEcole(int);
void saisirVille(int nbrVille);
int ajouterClasse(CLASSE tabClass[], int nbrClass, CLASSE);
int ajouterEcole(ECOLE tabEcole[],int nbrEcole,ECOLE);
void afficheClasse(CLASSE cl);
void afficheTabClasse(CLASSE tabClass[], int nbrClass);
void afficheTabEcole(ECOLE tabEcole[],int nbrEcole);
int menu2();
int menu1();
ETUDIANT saisirEtudiant(int nbrEtu, CLASSE tabClass[], int nbrClass);
int controleClasse(string, CLASSE tabClass[], int nbrClass);
CLASSE getClasseByName(string, CLASSE tabClass[], int nbrClass);
int ajouterEtudiant(ETUDIANT tabEtu[], int nbrEtu, ETUDIANT b);
void afficherEtudiantParClasse(ETUDIANT tabEtu[], int nbrEtu, CLASSE tabClass[], int nbrClass);

void afficheClasseCroissant(CLASSE tabClass[], int nbrClass);




#endif // REVISION0_H_INCLUDED

