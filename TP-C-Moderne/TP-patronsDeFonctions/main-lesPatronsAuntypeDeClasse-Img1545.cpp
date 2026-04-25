//
//  main.cpp
//  heritage
//
//  Created by nasr on 11/09/2024.
//


//--------Programme sur utilisation de patrons de fonctions à un type classe (IMG-1545 )
// Programme affiche
/*
 min (u,v)=32Program ended with exit code: 0
*/


//------------------
#include <iostream>
using namespace std;

//creation de patrons de fonctions

template <typename T> T minimum(T a,T b)
{
    if(a<b) return a;
    else return b;
}


class vect
{
public:
    
    vect(int abs=0,int ord=0) : x(abs), y(ord){}
    void affiche ()
    {
        cout << x <<""<<y;
    }
        friend int operator < (vect,vect);
        //cout << " mes coordonees sont : " <<x<<" "<<y<<endl;
    
    
private:
    int x,y;
};

int operator < (vect a,vect b)
{ return a.x*a.x + a.y*a.y < b.x*b.x+ b.y*b.y;
}



/*
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
*/

int main() {
    // insert code here...
    
    //pointcol p;
    //p.initialise(10,20);p.colore(5);
    //p.affiche();
    //p.deplace(2, 4);
    //p.affiche();
    
    //std::cout << "Hello, World!\n";
    //return 0;
    
    //point p(3,5); point *adp =&p;
    //pointcol pc (8,6,2);pointcol * adpc = &pc;
    //adp->affiche();adpc->affiche();
    //cout << "-------------------\n";
    //adp=adpc;
    //adp->affiche(); adpc->affiche();
    
    vect u(3,2),v(4,1),w;
    w=min(u,v);
    
    //int n=4,p=12;
    //float x=2.5,y=3.25;
    
    //w=min(u,v);
    cout << "min (u,v)="; w.affiche();  //int min(int,int)
    //cout << "min (x,y)=" << minimum (x,y) << endl;  //float min(float,float)
    
}


