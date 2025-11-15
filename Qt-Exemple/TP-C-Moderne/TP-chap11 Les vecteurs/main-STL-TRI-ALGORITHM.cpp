//
//  main.cpp
//  STL
//
//  Created by nasr on 08/10/2024.
//  extracted from C++ INSA Polycop MASTER SPECIALISE Nabila Benharkat
//
//
/*
 gestion de la table tri algorithm STL
Transmission d'un vecteur par valeur
 Affiche
 Avant :
 23 5 -10 0 0 321 1 2 99 30
 Après :
 -10 0 0 1 2 5 23 30 99 321

*/

#include <iostream>

#include <algorithm>
using namespace std;



int main()
{
  

    int tableau[] = { 23, 5, -10, 0, 0, 321, 1, 2, 99, 30 };

    size_t taille = sizeof(tableau) / sizeof(tableau[0]);

    cout << "Avant : " << endl;

    for (size_t i = 0; i < taille; ++i)

    {

    cout << tableau[i] << " ";

    }

    cout << endl;

    // Tri :

    sort(tableau, tableau + taille);

    cout << "Après : " << endl;

    for (size_t i = 0; i < taille; ++i)

    {

    cout << tableau[i] << " ";

    }

    cout << endl;
    
    return 0;

}
