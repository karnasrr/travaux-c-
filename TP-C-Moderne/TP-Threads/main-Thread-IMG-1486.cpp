//
//  main.cpp
//  heritage
//
//  Created by nasr on 11/09/2024.
//


//--------Programme sur utilisation des Thread depuis une fonction ou un objet fonction Thread fonction (IMG-1485 )

// Programme affiche
/*
 bonjourbonjourbonjourbonjourbonjourbonjourbonjourbonjourbonjourbonjourbonjourbonjour
 bonsoirbonsoirbonsoirbonsoirbonsoirbonsoirbonsoirbonsoir
*/

//------------------
#include <iostream>
#include <thread>
using namespace std;

void ecritBonjour()
{for (int i=0;i<12;i++) cout << "bonjour";}

void ecritBonsoir()
{for(int i=0;i<10;i++) cout << "bonsoir";}

void ecritLigne()
{for(int i=0;i<6;i++) cout << endl;}




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
    
    //vect u(3,2),v(4,1),w;
    //w=min(u,v);
    
    //int n=4,p=12;
    //float x=2.5,y=3.25;
    
    //w=min(u,v);
    //cout << "min (u,v)="; w.affiche();  //int min(int,int)
    //cout << "min (x,y)=" << minimum (x,y) << endl;  //float min(float,float)
    
    /*
     int t[5]={5,2,0,2,0};
     char c[6]={0,12,0,0,0,5};
     cout << "compte (t) = " <<compte (t,5)<< "\n";
     cout << "compte (C) = " <<compte (c,6)<< "\n";
     */
    
    //point a(5),b(3.15);
    //cout<< "a et b:"<<a.coincide(b)<<"ou"<<b.coincide(a)<<endl;
    //cout<<"b et c:"<<b.coincide(c)<<"ou"<<c.coincide(b)<<endl;
    //a.affiche();
    //b.affiche();
    //point b(5);
    
    //b.affiche("Point b -");
    //point c (3,12);
    
    //c.affiche("Hello -------");
    
    //cpte_obj::compte();
    //cpte_obj a;
    //cpte_obj::compte();
    //fct();
    //cpte_obj::compte();
    //cpte_obj b;
    //cpte_obj::compte();
    
    thread t1 (ecritBonjour);
    thread t2 (ecritBonsoir);
    thread t3 (ecritLigne);
    
    t1.join();t2.join();t3.join();
}

