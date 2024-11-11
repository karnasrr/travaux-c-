
//  main.cpp
//  tp
//
//  Created by nasr on 09/09/2024.
//

//extrait du livre Programmer en C++ Moderne - Chapitre classe @ objets Construction et destruction
//page 313 constructeur avec 2 CLASSES imbriquées point et cercle
//ajout sur Git

//le programme affiche
//Affiche
//constructeur point      1 3
//constr . cercle9
//Program ended with exit code: 0



#include <iostream>
using namespace std;


//----------Declaration de la classe vect

class point
{
public:
    point(int abs=0,int ord=0) : x(abs),y(ord)
    {cout << "constructeur point      "<<x<<" "<<y<<endl;}
    
private:
    int x,y;
};
    
class cercle
{
public:
    cercle(int,int,int);
private:
    point centre;
    int rayon;
};

cercle::cercle(int abs,int ord,int ray):centre(abs,ord),rayon(ray)
{
    cout << "constr . cercle" << rayon << endl;
}


//----------Utilisation de la classe point

int main() {
    // insert code here...
    // cinstructeur de recopie
    //Affiche
    //constructeur point      1 3
    //constr . cercle9
    //Program ended with exit code: 0
    cercle a(1,3,9);
    
}

