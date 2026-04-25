//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from C++ modern
//
//
/*
 Gestion de string-IMG 2316
 Transmission d'une variable de type string en argument d'une fonction
 Affiche
 --avant appel f1,ch1=bonjour
 --Entree dans f1, ch=bonjour
 --Sortie de f1, ch=bonsoir
 --apres appel f1,ch1=bonjour
 --Entree dans f2, ch=bonjour
 --Sortie de f2, ch=au revoir
 --apres appel f2,ch1=au revoir
 Program ended with exit code: 0
 
*/

#include <iostream>
using namespace std;

void f1(string ch)
{
    cout<<"--Entree dans f1, ch="<<ch<<endl;
    ch="bonsoir";
    cout<<"--Sortie de f1, ch="<<ch<<endl;
}

void f2(string & ch)
{
    cout<<"--Entree dans f2, ch="<<ch<<endl;
    ch="au revoir";
    cout<<"--Sortie de f2, ch="<<ch<<endl;
}



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

    
    string ch1="bonjour"; cout<<"--avant appel f1,ch1="<<ch1<<endl;
    f1(ch1);cout<<"--apres appel f1,ch1="<<ch1<<endl;
    f2(ch1);cout<<"--apres appel f2,ch1="<<ch1<<endl;
    //cout<<"--En A - caractères de ch";
    //for(auto c:ch) cout <<c <<"";
    //cout <<endl;
    //cout <<"En B-ch=";
    //for(auto & c:ch) c='x';
    //cout << ch <<endl;
    //cout <<"En C-ch=";
    //for(auto c : ch) c='y';
    //cout<<ch<<endl;
}
