//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from
//  http://genelaix.free.fr/IMG/pdf/threads_cours_tp.pdf
//
/*
resultat
 6Program ended with exit code: 0
 sans mutex
 0 3 6 9 12 15 18 21 24 27 0 3 6 9 12 15 18 21 24 27 0 3 6 9 12 15 18 21 24 27 Program ended with exit code: 0
 avec mutex
 0 3 6 9 12 15 18 21 24 27 0 3 6 9 12 15 18 21 24 27 0 3 6 9 12 15 18 21 24 27 Program ended with exit code: 0
*/

#include <thread>
#include <iostream>
#include <mutex>
using namespace std;

mutex monmutex; // un mutex

int main() {

    monmutex.lock();
    thread t1([]() {
        //monmutex.lock();
        for (int i = 0; i < 10; ++i)
        {
            cout << (i * 3) << " ";
            
        }
        //monmutex.unlock();
    });
    monmutex.unlock();
    
    monmutex.lock();
    thread t2([]() {
        //monmutex.lock();
        for (int i = 0; i < 10; ++i)
        {
            cout << (i * 3) << " ";
            
        }
        //monmutex.unlock();
    });
    monmutex.unlock();
    
    monmutex.lock();
    thread t3([]() {
        //monmutex.lock();
        for (int i = 0; i < 10; ++i)
        {
            cout << (i * 3) << " ";
            
        }
        //monmutex.unlock();
    });
    monmutex.unlock();
    
    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}
