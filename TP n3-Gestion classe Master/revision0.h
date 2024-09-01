#ifndef REVISION0_H_INCLUDED
#define REVISION0_H_INCLUDED
#include <string>
#include <vector>

using namespace std;

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
};

//  prototypes
CLASSE saisirClasse(int);
int ajouterClasse(CLASSE tabClass[], int nbrClass, CLASSE);
void afficheClasse(CLASSE cl);
void afficheTabClasse(CLASSE tabClass[], int nbrClass);
int menu();
ETUDIANT saisirEtudiant(int nbrEtu, CLASSE tabClass[], int nbrClass);
int controleClasse(string, CLASSE tabClass[], int nbrClass);
CLASSE getClasseByName(string, CLASSE tabClass[], int nbrClass);
int ajouterEtudiant(ETUDIANT tabEtu[], int nbrEtu, ETUDIANT b);
void afficherEtudiantParClasse(ETUDIANT tabEtu[], int nbrEtu, CLASSE tabClass[], int nbrClass);

void afficheClasseCroissant(CLASSE tabClass[], int nbrClass);




#endif // REVISION0_H_INCLUDED

