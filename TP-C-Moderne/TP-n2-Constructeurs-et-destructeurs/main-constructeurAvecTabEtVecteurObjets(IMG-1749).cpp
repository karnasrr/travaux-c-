
//  main.cpp
//  tp
//
//  Created by nasr on 09/09/2024.
//

//extrait du livre Programmer en C++ Moderne - Chapitre classe @ objets Construction et destruction
//page 318 (IMG-1749) constructeur avec tableaux et vecteurs d objets
//ajout sur Git

//le programme affiche
//Affiche
//++constructeur point      1 1
//++constructeur point      2 0
//++constructeur point      3 3
//++constructeur point      1 2
//++constructeur copie point      1 2
//++constructeur point      5 5
//++constructeur copie point      1 2
//++constructeur point      2 2
//++constructeur point      3 0
//++constructeur copie point      1 2
//++constructeur copie point      2 2
//++constructeur copie point      3 0
//Program ended with exit code: 0



#include <iostream>
#include <vector>
using namespace std;


//----------Declaration de la classe vect

class point
{
public:
    point(int abs=0,int ord=0) : x(abs),y(ord)
    {cout << "++constructeur point      "<<x<<" "<<y<<endl;}
    
    point(const point & p) : x(p.x),y(p.y)
    {cout << "++constructeur copie point      "<<x<<" "<<y<<endl;}
    
private:
    int x,y;
};
    
//----------Utilisation de la classe point

int main() {
    // insert code here...
    // cinstructeur de recopie
    //Affiche

    //cercle a(1,3,9);
    
    point courbe1[3] {{1,1},2,{3,3}};
    point p1(1,2);
    point courbe2[2] {p1,{5,5}};
    
    vector<point> courbe3 {p1,{2,2},3};
    
}

