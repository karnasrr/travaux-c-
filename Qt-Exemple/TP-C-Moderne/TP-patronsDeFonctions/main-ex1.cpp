//
//  main.cpp
//  heritage
//
//  Created by nasr on 11/09/2024.
//


//--------Programme sur utilisation de patrons de fonctions (IMG-1543 )
// Programme affiche
/*
 min (n,p)=4
 min (x,y)=2.5
 Program ended with exit code: 0
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

int main(int argc, const char * argv[]) {
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
    
    int n=4,p=12;
    float x=2.5,y=3.25;
    
    
    cout << "min (n,p)=" << minimum (n,p) << endl;  //int min(int,int)
    cout << "min (x,y)=" << minimum (x,y) << endl;  //float min(float,float)
    
}


