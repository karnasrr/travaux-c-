
//  main.cpp
//  tp
//
//  Created by nasr on 09/09/2024.
//

//extrait du livre Programmer en C++ Moderne - Chapitre classe @ objets Construction et destruction
//page 318 (IMG-1753) constructeur temporaire d'objets (creation et destruction immediate apres
//ajout sur Git

//le programme affiche
//Affiche
//++constructeur point      0 0a l adresse0x7ff7bfeff2e8
//++constructeur point      1 2a l adresse0x7ff7bfeff2e0
//++destructeur  point      1 2a l adresse:0x7ff7bfeff2e0
//++constructeur point      3 5a l adresse0x7ff7bfeff2c8
//++destructeur  point      3 5a l adresse:0x7ff7bfeff2c8
//********Fin Main***********
//++destructeur  point      3 5a l adresse:0x7ff7bfeff2e8
//Program ended with exit code: 0

#include <iostream>
#include <vector>
using namespace std;


//----------Declaration de la classe vect

class point
{
public:
    point(int abs=0,int ord=0) : x(abs),y(ord)
    {cout << "++constructeur point      "<<x<<" "<<y<< "a l adresse"<<this<<endl;}
    
    ~point()
    {cout << "++destructeur  point      "<<x<<" "<<y<<"a l adresse:"<<this<<endl;}
    
private:
    int x,y;
};
    
//----------Utilisation de la classe point

/// <#Description#>
int main() {
    // insert code here...
    // cinstructeur de recopie
    //Affiche

    //cercle a(1,3,9);
    point a(0,0);
    a=point(1,2);
    a=point(3,5);
    
    cout <<"********Fin Main***********\n";
    
}

