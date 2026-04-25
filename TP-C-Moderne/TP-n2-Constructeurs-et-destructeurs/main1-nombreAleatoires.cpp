//
//  main.cpp
//  tp
//
//  Created by nasr on 08/09/2024.
//

//extrait du livre Programmer en C++ Moderne - Chapitre classe @ objets Construction et destruction
//page 257 construcyeur Hazard
//ajout sur Git

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib> // pour rand
using namespace std;


//----------Declaration de la classe test
class test
{
public:
    int num;
    test (int);
    ~test();
};

class hasard
{
public:
    hasard(int,int);
    void affiche ();
private:
    int nb;            //nombre de valeurs entieres
    int max;           //entre 0 et max
    vector<int> val;   //pour les valeurs
};


hasard::hasard (int n,int m) : nb(n),max(m)
{
    if (nb <= 0) nb =1; if(max<1) max=1;
    val = vector<int>(nb);
    for (int i=0;i<nb;i++) val[i] = double (rand()) / RAND_MAX * max;
    
}

void hasard::affiche()
{

    for (int i=0;i<nb;i++) cout<< val[i] <<" ";
    cout << " ";

}


//----------Utilisation de la classe point

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
     Affiche code aleatoire
     0 0 3 2 2 1 0 3 3 4 1 2 4 0 0  4 6 0 3 0 3 6 5 8 7 4 0 5 3 6 8 6 2 0 6  0
     */
    
    hasard suite1(15,5); suite1.affiche();
    hasard suite2(20,9); suite2.affiche();
    hasard suite3(-2,0); suite3.affiche();
    
}
