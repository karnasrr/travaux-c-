//
//  main.cpp
//  STL
//
//  Created by nasr on 07/10/2024.
//  extracted from C++ INSA Polycop MASTER SPECIALISE Nabila Benharkat
//
//
/*
 gestion de la Deque STL
Transmission d'un vecteur par valeur
 Affiche
 0 1 2 3
 1 2 3
 Program ended with exit code: 0
*/

#include <iostream>
#include <deque>
#include <algorithm>
//#include "libpq-fe.h"
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
  
    deque<int>Q;
    Q.push_back(3);
    Q.push_front(1);
    Q.push_front(1);
    Q.insert(Q.begin()+2,2);
    Q[0]=0;
    deque<int>::iterator iQ;
    for(iQ=Q.begin();iQ!=Q.end();iQ++){cout<<*iQ<<" ";}
    cout<<endl;
    Q.pop_front();
    
    copy(Q.begin(),Q.end(),ostream_iterator<int>(cout," "));
    
    cout<<endl;
    
    
    return 0;
    
  /*
    PGconn *conn = PQconnectdb("postgresql://localhost");
    if (PQstatus(conn) == CONNECTION_OK) {
        PGresult *result = PQexec(conn, "SELECT datname FROM pg_database");
        for (int i = 0; i < PQntuples(result); i++) {
            char *value = PQgetvalue(result, i, 0);
            if (value) printf("%s\n", value);
        }
        PQclear(result);
    }
    PQfinish(conn);
      */
    /*
    std::vector < std::string > vecOfStr;
        vecOfStr.push_back("first");
        vecOfStr.push_back("sec");
        vecOfStr.push_back("third");
        // Vector with other string object
        std::vector < std::string > vecOfStr3(vecOfStr);

    // Array of string objects
    std::string arr[] = {
        "first",
        "sec",
        "third",
        "fourth"
    };
    */
    // Vector with a string array
    //std::vector < std::string > vecOfStr(arr,
    //    arr +
    //    sizeof(arr) / sizeof(std::string));
    //for (std::string str: vecOfStr)
    //    std::cout << str << std::endl;


    
    /*
    // soit trois vecteurs
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    // v1 remplacé par 10 int à 50
    v1.assign(10, 50);
    // v2 remplacé par six éléments au centre de v1
    vector<int>::iterator it;
    it = v1.begin() + 2;
    v2.assign(it, v1.end() - 2);
    // v3 remplacé par les éléments du tableau tab
    int tab[] = { 10, 20, 30 };
    v3.assign(tab, tab + 3);
    // affichage des tailles des vecteurs
    cout << int(v1.size()) << '\n';
    cout << int(v2.size()) << '\n';
    cout << int(v3.size()) << '\n';
    
    
    
    
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
