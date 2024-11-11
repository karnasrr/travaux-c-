//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from C++ modern
//
//
/*
 Gestion de string-IMG 2313
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
//illustration de différentes façons d'accéder aux carcatères d'une chaine
//--Caractère de rang 0=b
//    --Liste de tous les caractères de ch:
//    bonjour
//    --Liste de caractères de rang pair de ch:
//    bnor
//    --En A - ch contient maintenant:banjour
//    --En B - ch contient maintenant:banlour
//    --En C - ch[25]=x
//    --En D - ch contient maintenant:banlour
//    --En E - ch[8]= 
//    Program ended with exit code: 0
//
    string ch="bonjour";
    cout<<"--Caractère de rang 0="<<ch[0]<<endl;
    cout<<"--Liste de tous les caractères de ch:"<<endl;
    for(unsigned int i=0;i<ch.size();i++) cout<<ch[i]<<"";
    cout<<endl;
    cout<<"--Liste de caractères de rang pair de ch:"<<endl;
    for(unsigned int i=0;i<ch.size();i+=2) cout<<ch[i]<<"";
    cout<<endl;
    ch[1]='a';
    cout<<"--En A - ch contient maintenant:"<<ch<<endl;
    ch[3]+=2; //remplace j par m
    cout<<"--En B - ch contient maintenant:"<<ch<<endl;
    ch[25]='x'; //a eviter
    cout<<"--En C - ch[25]="<<ch[25]<<endl; //malgre les apparence
    cout<<"--En D - ch contient maintenant:"<<ch<<endl;
    cout<<"--En E - ch[8]="<<ch[-3]<<endl; //semble ok mais...
    //ch1[3]='' ; rejeté car ch1 type const char *

}
