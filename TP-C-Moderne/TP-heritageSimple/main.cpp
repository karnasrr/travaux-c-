//
//  main.cpp
//  heritage
//
//  Created by nasr on 10/09/2024.
//


//--------Programme sur heritage somple (IMG-1604 p452)
// Programme affiche
/*
Je suis un point
 mes coordonees sont : 3 5
Je suis un point colore
mes coordonnees sont:86 et ma couleur est:  2
-------------------
Je suis un point
 mes coordonees sont : 8 6
Je suis un point colore
mes coordonnees sont:86 et ma couleur est:  2
Program ended with exit code: 0
*/


//-------------------




#include <iostream>
using namespace std;


class point
{
public:
    
    point(int abs=0,int ord=0) : x(abs), y(ord){}
    void affiche () const
    {
        cout << "Je suis un point \n";
        cout << " mes coordonees sont : " <<x<<" "<<y<<endl;
    }
    
protected:
    int x,y;
};

class pointcol: public point
{
    public:
    pointcol (int abs=0,int ord=0,short c1=1):point(abs,ord),couleur(c1){}
    void affiche() const
    {
        cout << "Je suis un point colore \n";
        cout << "mes coordonnees sont:"<<x<<""<<y;
        cout << " et ma couleur est:  "<< couleur<<endl;
    }
    
    //void colore (short c1){couleur=c1;}
    private:
    short couleur;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    //pointcol p;
    //p.initialise(10,20);p.colore(5);
    //p.affiche();
    //p.deplace(2, 4);
    //p.affiche();
    
    //std::cout << "Hello, World!\n";
    //return 0;
    
    point p(3,5); point *adp =&p;
    pointcol pc (8,6,2);pointcol * adpc = &pc;
    adp->affiche();adpc->affiche();
    cout << "-------------------\n";
    adp=adpc;
    adp->affiche(); adpc->affiche();
    
}


