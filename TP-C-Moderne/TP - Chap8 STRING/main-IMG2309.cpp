//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from C++ modern
//
//
/*
 Gestion de string
 Affiche
 quel est votre nom:nasr
 quel est votre prenom:kar
 bonjourkarnasr
 Program ended with exit code: 0
 
*/

#include <iostream>
using namespace std;

int main()
{
//Lecture et écriture de chaines
    
    cout << "quel est votre nom:";
    string nom; cin>>nom;
    cout << "quel est votre prenom:";
    string prenom;cin>>prenom;
    cout<<"bonjour"<<prenom<<""<<nom<<endl;
}
