//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from
//  http://genelaix.free.fr/IMG/pdf/threads_cours_tp.pdf
//
/*
resultat aleatoire
0,1A-B-C-D-E-F-,2,3,G-H-I-J-K-L-M-N-O-P-Q-R-S4,5,6,-T-U-V-W-X-Y-Z-
Fin du thread t2
7,8,9,
Fin du thread t1

les threads st termines
Program ended with exit code: 0
*/

#include <thread>
#include <iostream>



using namespace std;


void affN(int maxi) {
int i=0;
while(i<=maxi)
{
    cout << i++ << ","; // ici deux ecritures sur la console
}
    cout<<"\nFin du thread t1\n";
}

void affC(char debut,char fin)
{
    char c=debut;
    while(c<=fin)
    {
        cout << c++ << "-";
    }
    cout<<"\nFin du thread t2\n";
}


int main()
{
    thread t1(affN,9);
    thread t2(affC,'A','Z');
    
    t1.join();
    t2.join();
    cout<<endl<<"les threads st termines\n";
    return 0;
}
