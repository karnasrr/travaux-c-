//
//  main.cpp
//  Thread avec mutex
//
//  Created by nasr on 13/09/2024.
//  extracted from
//  http://genelaix.free.fr/IMG/pdf/threads_cours_tp.pdf
//
/*
resultat
 0,1,2,3,4,5,6,7,8,9,
 Fin du thread t1
 A-B-C-D-E-F-G-H-I-J-K-L-M-N-O-P-Q-R-S-T-U-V-W-X-Y-Z-
 Fin du thread t2

 les threads st termines
 Program ended with exit code: 0
*/

#include <thread>
#include <iostream>
#include <mutex>


using namespace std;

mutex monmutex;
void affN(int maxi) {
monmutex.lock();
int i=0;
while(i<=maxi)
{
    cout << i++ << ","; // ici deux ecritures sur la console
}
    cout<<"\nFin du thread t1\n";
    monmutex.unlock();
}

void affC(char debut,char fin)
{
    monmutex.lock();
    char c=debut;
    while(c<=fin)
    {
        cout << c++ << "-";
    }
    cout<<"\nFin du thread t2\n";
    monmutex.unlock();
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
