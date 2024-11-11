//
//  main.cpp
//  heritage
//
//  Created by nasr on 14/09/2024.
//


//--------Programme sur utilisation des Thread et sa mise en exception (IMG-1489 )

// Programme affiche
/*

 Lancement exception int depuis ft
 catch exception dans ft - on positionne err
 Dans main err est non null
 catch exception int dans main - valeur =5
 Program ended with exit code: 0
 
*/

//------------------
#include <iostream>
#include <thread>
#include <memory>
using namespace std;
/*
void ecritBonjour()
{for (int i=0;i<12;i++) cout << "bonjour";}

void ecritBonsoir()
{for(int i=0;i<10;i++) cout << "bonsoir";}

void ecritLigne()
{for(int i=0;i<6;i++) cout << endl;}

void ecrit (string ch,int n,int ms)
{
    for (int i=0;i<n;i++)
    {
        cout <<ch;
        this_thread::sleep_for(chrono::microseconds(ms));
    }
}
*/

void ft(exception_ptr *err)
{
    cout << "Lancement exception int depuis ft \n";
    try
    {
        throw(5);
    }
    catch(int n)
    {
        cout<< "catch exception dans ft - on positionne err\n";
        *err =current_exception();
    }
    
}

int main() {
    
    try{
        
        exception_ptr err = nullptr;
        
        thread t1 (ft,&err);
        t1.join();
        if(err){
            cout << "Dans main err est non null \n";
            rethrow_exception(err);
        }
        
    }
    catch(int n)
    {
        cout << "catch exception int dans main - valeur =" << n << endl;
    }

}

