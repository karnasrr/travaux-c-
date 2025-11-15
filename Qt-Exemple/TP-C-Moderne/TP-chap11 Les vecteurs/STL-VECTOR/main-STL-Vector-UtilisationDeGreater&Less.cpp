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
Transmission d'un vecteur par valeur (utilisation de Greater & less)
 Affiche
 Avant :
 23 5 -10 0 0 321 1 2 99 30
 Après :
 -10 0 0 1 2 5 23 30 99 321

*/

#include <iostream>

#include <algorithm>

#include <vector>

using namespace std;



int main()
{
  
    vector<int> vec { 23, 5, -10, 0, 0, 321, 1, 2, 99, 30 }; // -std=c++0x ou -std=c++11

    cout << "Avant : " << endl;

    for (int i = 0; i < vec.size(); ++i)

    {
    
        cout << vec[i] << " ";

        }

        cout << endl;

        // Tri décroissant :

        sort(vec.begin(), vec.end(), greater<int>());

        cout << "Après : " << endl;

        for (int i = 0; i < vec.size(); ++i)

        {

        cout << vec[i] << " ";

        }

        cout << endl;

        
    return 0;

}
