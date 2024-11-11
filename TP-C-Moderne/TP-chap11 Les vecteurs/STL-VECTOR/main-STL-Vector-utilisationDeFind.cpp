//
//  main.cpp
//  STL
//
//  Created by nasr on 08/10/2024.
//  extracted from C++ INSA Polycop MASTER SPECIALISE Nabila Benharkat
//
//
/*
 gestion de la table tri algorithm-utilisation de Find dans STL
Transmission d'un vecteur par valeur (utilisation de Greater & less)
 Affiche
 Element trouvé : 30
 Element trouvé : 20
 Element non trouvé !
 Program ended with exit code: 0

*/

#include <iostream>

#include <algorithm>

#include <vector>

#include <list>

using namespace std;



int main()
{
  
    int tableau[] = { 10, 20, 30, 40 };

    size_t taille = sizeof(tableau) / sizeof(tableau[0]);

    int *p;

    p = find(tableau, tableau + taille, 30);

    if (p != (tableau + taille))

    cout << "Element trouvé : " << *p << "\n";

    else

    cout << "Element non trouvé !\n";

    vector<int> vec { 10, 20, 30, 40 };

    vector<int>::iterator itV;

    itV = find(vec.begin(), vec.end(), 20);

    if (itV != vec.end())

    cout << "Element trouvé : " << *itV << "\n";

    else

    cout << "Element non trouvé !\n";

    list<int> l { 10, 20, 30, 40 };

    list<int>::iterator itL;

    itL = find(l.begin(), l.end(), 50);

    if (itL != l.end())

    cout << "Element trouvé : " << *itL << "\n";

    else

    cout << "Element non trouvé !\n";
        
    return 0;

}
