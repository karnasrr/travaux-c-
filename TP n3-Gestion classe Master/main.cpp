#include <iostream>
#include "revision0.h"
#include <stdlib.h>

using namespace std;

int main()
{
    const int tailleTabClass = 25;
    CLASSE tabClass[tailleTabClass];
    int nbrClass = 0;

    
    const int tailleTabEcole = 25;
    ECOLE tabEcole[tailleTabEcole];
    int nbrEcole = 0;

    
    
    const int tailleTabEtu = 30;
    ETUDIANT tabEtu[tailleTabEtu];
    int nbrEtu = 0;

    
        menu1:
        switch(menu1()){
        case 1:
            system("cls");
            cout <<endl << "AJOUT DE ECOLE" <<endl <<endl;

            nbrEcole= ajouterEcole(tabEcole, nbrEcole, saisirEcole(nbrEcole));
            //system("pause");
            //system("cls");
            cout <<endl << "nbrEcole=" << nbrEcole<<endl <<endl;
            cout <<endl << "FIN AJOUT DE ECOLE" <<endl <<endl;
            goto menu1;
            break;
                
        case 2:
            system("cls");
            cout <<endl << "AFFICHAGE DES ECOLES" <<endl <<endl;

            afficheTabEcole(tabEcole, nbrEcole);

            //system("pause");
            //system("cls");
            goto menu1;
            break;
         
        case 3:
                system("cls");
                cout <<endl << "AJOUT DE CLASSE" <<endl <<endl;

                nbrClass= ajouterClasse(tabClass, nbrClass, saisirClasse(nbrClass));

                //system("pause");
                //system("cls");
                    
                cout <<endl << "nbrClass=" << nbrClass<<endl <<endl;
                cout <<endl << "FIN AJOUT DE CLASSE" <<endl <<endl;
                goto menu;
                break;
                
                
        case 4:
            system("cls");
            cout <<endl << "AJOUT D'ETUDIANT" <<endl <<endl;

            nbrEtu = ajouterEtudiant(tabEtu, nbrEtu, saisirEtudiant(nbrEtu, tabClass, nbrClass));

            //system("pause");
            //system("cls");
            goto menu1;
            break;
                
        case 5:
            system("cls");
            cout <<endl << "AFFICHAGE D'ETUDIANT PAR CLASSE" <<endl <<endl;


            afficherEtudiantParClasse(tabEtu, nbrEtu, tabClass, nbrClass);


            //system("pause");
            //system("cls");
            goto menu1;
            break;
                
        case 6:
            system("cls");
            cout <<endl << "AFFICHAGE CLASSE PAR ORDRE CROISSANT DU NOMBRE D'ETUDIANT" <<endl <<endl;

            afficheClasseCroissant( tabClass, nbrClass);


            //system("pause");
            //system("cls");
            goto menu1;
            break;
                
        case 7:
            //system("cls");
            //return 0;
            //goto menu;
            break;
        }


    menu:
    switch(menu2()){
    case 1:
        system("cls");
        cout <<endl << "AJOUT DE CLASSE" <<endl <<endl;

        nbrClass= ajouterClasse(tabClass, nbrClass, saisirClasse(nbrClass));

        //system("pause");
        //system("cls");
            
        cout <<endl << "nbrClass=" << nbrClass<<endl <<endl;
        cout <<endl << "FIN AJOUT DE CLASSE" <<endl <<endl;
        goto menu;
        break;
    case 2:
        system("cls");
        cout <<endl << "AFFICHAGE DES CLASSES" <<endl <<endl;

        afficheTabClasse(tabClass, nbrClass);

        //system("pause");
        //system("cls");
        goto menu;
        break;
    case 3:
        system("cls");
        cout <<endl << "AJOUT D'ETUDIANT" <<endl <<endl;

        nbrEtu = ajouterEtudiant(tabEtu, nbrEtu, saisirEtudiant(nbrEtu, tabClass, nbrClass));

        //system("pause");
        //system("cls");
        goto menu;
        break;
    case 4:
        system("cls");
        cout <<endl << "AFFICHAGE D'ETUDIANT PAR CLASSE" <<endl <<endl;


        afficherEtudiantParClasse(tabEtu, nbrEtu, tabClass, nbrClass);


        //system("pause");
        //system("cls");
        goto menu;
        break;
    case 5:
        system("cls");
        cout <<endl << "AFFICHAGE CLASSE PAR ORDRE CROISSANT DU NOMBRE D'ETUDIANT" <<endl <<endl;

        afficheClasseCroissant( tabClass, nbrClass);


        //system("pause");
        //system("cls");
        goto menu;
        break;
    case 6:
        //system("cls");
        return 0;
        break;
    }

    return 0;
}
