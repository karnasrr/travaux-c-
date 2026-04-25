//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from C++ modern
//
//
/*
 Gestion de string-IMG 2315
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
//illustration  d'accéder aux carcatères d'une chaine (global)
//--Caractère de rang 0=b
//    --Liste de tous les caractères de ch:
//    bonjour
//    --Liste de caractères de rang pair de ch:
//    --En A - caractères de chbonjour
//    En B-ch=xxxxxxx
//    En C-ch=xxxxxxx
//    Program ended with exit code: 0

    
    string ch="bonjour";

    cout<<"--En A - caractères de ch";
    for(auto c:ch) cout <<c <<"";
    cout <<endl;
    cout <<"En B-ch=";
    for(auto & c:ch) c='x';
    cout << ch <<endl;
    cout <<"En C-ch=";
    for(auto c : ch) c='y';
    cout<<ch<<endl;
}
