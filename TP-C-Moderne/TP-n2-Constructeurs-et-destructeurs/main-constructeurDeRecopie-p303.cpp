
//  main.cpp
//  tp
//
//  Created by nasr on 09/09/2024.
//

//extrait du livre Programmer en C++ Moderne - Chapitre classe @ objets Construction et destruction
//page 257 construcyeur de recopie (c++11)
//ajout sur Git

//le programme affiche
//Affiche
//++ const. usuel - adr objet : 0x7ff7bfeff2d0 - adr vecteur : 0x600000c04690
//**** appel de fct *****
//-- Destr. objet - adr objet : 0x7ff7bfeff2c0- adr vecteur:0x600000c04690
//-- Destr. objet - adr objet : 0x7ff7bfeff2d0- adr vecteur:0x600000c04690

//Program ended with exit code: 0



#include <iostream>
using namespace std;


//----------Declaration de la classe vect



class vect
{
public:
    vect(int n): nelem(n), adr(new double[n])
    {
        cout << "++ const. usuel - adr objet : " << this
        << " - adr vecteur : "<< adr << endl;
    }
    
    ~vect ()
    {
        cout << "-- Destr. objet - adr objet : "
        << this << "- adr vecteur:"<< adr << endl;
        delete[] adr;
    }
        
        
    
private:
    
    int nelem;
    double *adr;
};

void fct (vect b)
{cout << "**** appel de fct *****\n";}




//----------Utilisation de la classe point

int main(int argc, const char * argv[]) {
    // insert code here...
    // cinstructeur de recopie
    //Affiche
    //++ const. usuel - adr objet : 0x7ff7bfeff2d0 - adr vecteur : 0x600000c04690
    //**** appel de fct *****
    //-- Destr. objet - adr objet : 0x7ff7bfeff2c0- adr vecteur:0x600000c04690
    //-- Destr. objet - adr objet : 0x7ff7bfeff2d0- adr vecteur:0x600000c04690

    vect a(5);
    fct(a);
}

