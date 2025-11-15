
//  main.cpp
//  tp
//
//  Created by nasr on 09/09/2024.
//

//extrait du livre Programmer en C++ Moderne - Chapitre classe @ objets Construction et destruction
//page 313 constructeur avec initialize list
//ajout sur Git

//le programme affiche
//Affiche
//constructeur int,int       0 0
//constructeur int,int       0 0
//Program ended with exit code: 9
//Program ended with exit code: 0

//programm bug affiche pas initializer_list (0) 2 2, s arrete apres
//voir extrait code page 313 (IMG-1744) du dossier constructeur.

#include <iostream>
using namespace std;


//----------Declaration de la classe vect

class point
{
public:
    point(int abs=0,int ord=0) : x(abs),y(ord)
    {cout << "constructeur int,int       "<<x<<" "<<y<<endl;}
    point(initializer_list<int> c) : x(0) , y(0)
    {
        unsigned int nb =  c.size();
        auto deb = c.begin();
        x=  * deb;
        
        if(nb==1) y=0;
        else{deb++;y= * deb;}
        cout << "constr initialize_list ("<< c.size()<<")"<<x<<""<<y<<endl;
        
    }
    
    
private:
    int x,y;
};
    
    


//----------Utilisation de la classe point

int main() {
    // insert code here...
    // cinstructeur de recopie
    //Affiche
    
    point p1;point p2{};point p3({});
    point q1(1);point q2{};
    point s1(1,2);point s2{2,4};
    
}

