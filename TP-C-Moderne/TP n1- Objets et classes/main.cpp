//
//  main.cpp
//  tp
//
//  Created by nasr on 08/09/2024.
//

//extrait du livre Programmer en C++ Moderne - Chapitre classe @ objets
//page 253/254
//ajout sur Git

#include <iostream>
using namespace std;

//----------Declaration de la classe point
class point
{
public:
    point(int,int);
    void deplace (int,int);
    void affiche();
    /Users/nasr/Documents/PremierProjet/Travaux C++/TP C++ moderne/Objet & classes/TP n 1/main.cpp
private:
    int x;
    int y;
};

//--------Definition des fonctions membre de la classe point

point::point (int abs,int ord)
{
    x=abs;y=ord;
}

void point::deplace(int dx,int dy)
{
    x=x+dx;y=y+dy;
}

void point::affiche()
{
    cout<<"Je suis en "<<x<<" "<<y<<"\n";
}

//----------Utilisation de la classe point

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
      Affiche
     Je suis en 5 2
     Je suis en 3 6
     Je suis en 1 -1
     Program ended with exit code: 0
     
     */
    
    //point a(5,2); //ou point a{5,2}
    point a{5,2};
    a.affiche();
    a.deplace(-2, 4);a.affiche();
    point b(1,-1);
    b.affiche();
    
}
