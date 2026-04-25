//
//  main.cpp
//  STL
//
//  Created by nasr on 08/10/2024./Users/nasr/Documents/PremierProjet/Travaux C++/TP-C++Moderne/TP-chap11 Les vecteurs/STL-VECTOR/main-STL-Vector-UtilisationDeGreater&Less.cpp
//  extracted from C++ INSA Polycop MASTER SPECIALISE Nabila Benharkat
//
//
/*
 gestion de la table tri algorithm-utilisation de Find dans STL
 extrait https://www.bogotobogo.com/cplusplus/stl2_map.php#google_vignette
Utilisation d'un MAP
 On peut créer sa propre fonction de hachage avec un foncteur 1
 On peut utiliser unordered_map avec ses propres classes à condition de déﬁnir l’opérateur == :
 Affiche
 Size of populationMap: 5
 Brasil: 193 million
 China: 1339 million
 India: 1187 million
 Indonesia: 234 million
 Pakistan: 170 million
 Indonesia's populations is 234 million
 Program ended with exit code: 0

*/


#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

class Fabricant

{

private:

string nom;

public:
    
    Fabricant(string nom)

    {

    this->nom = nom;

    }

    string getNom() const

    {

    return nom;

    }

    bool operator==(const Fabricant &f) const

    {

    return nom == f.nom;

    }

};

class Modele

{

private:

string nom;

int annee;

public:

Modele(string nom, int annee)

{

this->nom = nom;

this->annee = annee;

}

string getNom() const

{

return nom;

}

int getAnnee() const

{

return annee;

}

bool operator==(const Modele &m) const

{

return (nom == m.nom && annee == m.annee);

}

};


class Hachage

{

public:

size_t operator()(const Modele &m) const

{

return hash<string>()(m.getNom()) ^ hash<int>()(m.getAnnee());

}

};


int main()
{
 
    typedef map<string, int> mapType;
        mapType populationMap;
     
        populationMap.insert(pair<string, int>("China", 1339));
        populationMap.insert(pair<string, int>("India", 1187));
        populationMap.insert(mapType::value_type("US", 310));
        populationMap.insert(mapType::value_type("Indonesia", 234));
        populationMap.insert(make_pair("Brasil", 193));
        populationMap.insert(make_pair("Pakistan", 170));

        // Erase the end element using the erase function
        // Because it's ordered map (by key),
        // map elements are not in the order of the entry
        // In this map it's US since it's ordered alphabetically.
        mapType::iterator iter = --populationMap.end();
        populationMap.erase(iter);
     
        // output the size of the map
        cout << "Size of populationMap: " << populationMap.size() << '\n';
     
        for (iter = populationMap.begin(); iter != populationMap.end(); ++iter) {
            cout << iter->first <<": "
                << iter->second << " million\n";
        }

        // find will return an iterator to the matching element if it is found
        // or to the end of the map if the key is not found
        string country("Indonesia");
        iter = populationMap.find(country);
        if( iter != populationMap.end() )
            cout << country <<"'s populations is "
                << iter->second << " million\n";
        else
            cout << "Key is not in populationMap" << '\n';
     
        // clear the entries in the map
        populationMap.clear();
    
    return 0;

}
