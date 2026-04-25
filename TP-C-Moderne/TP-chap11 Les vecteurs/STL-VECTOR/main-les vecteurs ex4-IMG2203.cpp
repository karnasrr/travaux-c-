//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from C++ modern
//
//
/*
 Gestion de vecteurs-IMG 2203
Transmission d'un vecteur par valeur
 Affiche
 En A,    v=135
 En 1 de f,v=135
 En 2 de f,v=246
 En B,       v=135
 Program ended with exit code: 0
 
*/

#include <iostream>
#include <vector>
using namespace std;

void f(vector<int>v);

void f(vector<int>v)
{
    cout<<"En 1 de f,v=";
    for(auto n:v) cout<<n<<"";cout<<endl;
    for(auto &n:v) n++;
    cout<<"En 2 de f,v=";
    for(auto n:v) cout <<n<<"";cout<<endl;
}

int main()
{
    
    vector<int> v1{1,3,5};
    //vector<int> v2{2,4,6,8};
    
    cout<<"En A,    v=";
    for(auto n:v1) cout << n<<"";cout<<endl;
    f(v1);
    cout<<"En B,       v=";
    for(auto n:v1) cout<<n<<"";cout<<endl;
    
    //cout << "En A,les"<< v1.size()<<"valeurs de v1 sont:";
    //for(auto v:v1)cout<<v<<"";cout<<endl;
    
    //cout << "En A,les"<< v2.size()<<"valeurs de v2 sont:";
    //for(auto v:v2)cout<<v<<"";cout<<endl;
    
    /*
    v1=v2;
    cout<<"En B,les"<<v1.size()<<"valeurs de v1 sont:";
    for(auto v:v1) cout<<v<<"";cout<<endl;
    cout<<"En B,les "<<v2.size()<<"valeurs de v2 sont:";
    for(auto v:v2) cout <<v<<"";cout<<endl;
    */
    /*
    for(unsigned int i=0;i<v.size();i++) v[i]++;
    cout<<"En B,v=";
    for(auto e:v) cout <<e<<"";cout<<endl;
    cout <<"En C,v=";
    for(auto e:v)cout<<e<<"";cout<<endl;
    for(auto & e:v)e++;
    cout<<"En D,v=";
    for(int e:v)cout<<e<<"";cout<<endl;
    */

}
