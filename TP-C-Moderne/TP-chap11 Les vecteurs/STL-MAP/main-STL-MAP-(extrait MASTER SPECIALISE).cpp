//
//  main.cpp
//  STL
//
//  Created by nasr on 07/10/2024.
//  extracted from C++ INSA Polycop MASTER SPECIALISE Nabila Benharkat
//
//
/*
 gestion de la MAP STL
Transmission d'un vecteur par valeur
 Affiche
 Juin->30
 Precedent dans l'ordre alphabetique estJuillet
 Suivant dans l'ordre alphabetique estMai

 Program ended with exit code: 0
*/

#include <iostream>
#include <map>

using namespace std;

struct CompareChaineC {
    
    bool operator()(const char* s1,const char* s2)const
    {
        return strcmp (s1,s2)<0;
    }
    
};


int main()
{
  
    map<const char *,int,CompareChaineC>mois;
    
    mois["Janvier"]=31; mois["Fevrier"]=28;mois["Mars"]=31;
    
    mois["Avril"]=30; mois["Mai"]=31;mois["Juin"]=30;
    
    
    mois["Juillet"]=31; mois["Aout"]=31;mois["Septembre"]=30;
    
    
    mois["Octobre"]=31; mois["Novembre"]=30;mois["Decembre"]=31;
    
    typedef map<const char *,int,CompareChaineC>associations;
    
    cout<<"Juin->"<<mois["Juin"]<<endl;
    
    associations::iterator cur = mois.find("Juin");
    associations::iterator prev = cur;
    associations::iterator next = cur;
    
    ++next;
    --prev;
    
    cout << "Precedent dans l'ordre alphabetique est"<<(*prev).first<<endl; //pre->first
    cout << "Suivant dans l'ordre alphabetique est" <<next->first<<endl;
    
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
