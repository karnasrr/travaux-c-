
//  main.cpp
//  tp
//
//  Created by nasr on 08/09/2024.
//

//extrait du livre Programmer en C++ Moderne - Chapitre classe @ objets Construction et destruction
//page 257 construcyeur avec les pointeurs intelligents (c++11)
//ajout sur Git

//le programme affiche
//Je suis en12
//Je suis en47
//Je suis en00
//Je suis en25
//Je suis en67
//Je suis en00
//Program ended with exit code: 0



#include <iostream>
#include <memory>
using namespace std;


//----------Declaration de la classe point



class point
{
public:
    point (int abs=0,int ord=0) : x(abs),y(ord){}
    void deplace (int dx,int dy) {x+=dx ;y +=dy;}
    void affiche()
    {cout << "Je suis en" <<x<<""<<y<<endl;}
private:
    
    int x,y;
    };

//----------Utilisation de la classe point

int main(int argc, const char * argv[]) {
    // insert code here...
    //gestion dynamique d un point avec pointeurs natifs
    
    point *adp1 = new point (1,2);
    adp1 ->affiche();adp1->deplace(3,5);adp1->affiche();
    
    point *adp2 = new point ();
    adp2->affiche();
    
    delete adp1;delete adp2;
    
    //gestion dynamique d un point avec un unique_ptr
    unique_ptr <point> up1 = make_unique<point>(2,5);
    up1->affiche(); up1->deplace(4,2);up1->affiche();
    
    unique_ptr <point> up2 (new point());
    up2->affiche();
    
}

