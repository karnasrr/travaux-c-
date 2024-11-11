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
Utilisation d'un VECTOR
 Affiche
 Premier element : 10
 Dernier element : 10
 Tout est normal : tableau vide
 Nouvelle taille : 10
 Taille : 0
 Capacite : 50
 Nouvelle taille : 50
 Max : 49
 v[0] = 0    v[1] = 1    v[2] = 2    v[3] = 3    v[4] = 4
 at() a levé une exception std::out_of_range : vector
 4    3    2    1    0
 Somme : 200
 v est bien une copie conforme de v3
 Program ended with exit code: 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <stdexcept>
using namespace std;


int main()
{
  
    // créer un tableau d’entiers vide

    std::vector<int> v;

    // ajouter l’entier 10 à la fin

    v.push_back( 10 );

    // afficher le premier élément (10)

    cout << "Premier element : " << v.front() << "\n";

    // afficher le dernier élément (10)

    cout << "Dernier element : " << v.back() << "\n";

    // enlever le dernier élément

    v.pop_back(); // supprime ’10’

    // le tableau est vide

    if ( v.empty() )

    {

    cout << "Tout est normal : tableau vide\n";

    }
    
    
    // redimensionner le tableau

    // resize() initialise tous les nouveaux entiers à 0

    v.resize( 10 );

    // quelle est sa nouvelle taille ?

    cout << "Nouvelle taille : " << v.size() << "\n"; // affiche 10

    // sa taille est de 10 : on peut accéder directement aux

    // 10 premiers éléments

    v[ 9 ] = 5;

    // intitialiser tous les éléments à 100

    std::fill( v.begin(), v.end(), 100 );

    // vider le tableau

    v.clear(); // size() == 0

    // on va insérer 50 éléments

    // réserver (allouer) de la place pour au moins 50 éléments

    v.reserve( 50 );
    
    // vérifier que la taille n’a pas bougé (vide)

    cout << "Taille : " << v.size() << "\n";

    // capacité du tableau = nombre d’éléments qu’il peut stocker

    // sans devoir réallouer (modifié grâce à reserve())

    cout << "Capacite : " << v.capacity() << "\n"; // au moins 50, sûrement plus

    for ( int i = 0; i < 50; ++i )

    {

    // grâce à reserve() on économise de multiples réallocations

    // du fait que le tableau grossit au fur et à mesure

    v.push_back( i );

    }

    // afficher la nouvelle taille

    cout << "Nouvelle taille : " << v.size() << "\n"; // affiche 50

    // rechercher l’élément le plus grand (doit être 49)

    cout << "Max : " << *std::max_element( v.begin(), v.end() ) << "\n";

    // tronquer le tableau à 5 éléments

    v.resize( 5 );
    
    
    // les trier par ordre croissant

    std::sort( v.begin(), v.end() );

    // parcourir le tableau

    for ( size_t i = 0, size = v.size(); i < size; ++i )

    {

    // attention : utilisation de l’opérateur []

    // les accès ne sont pas vérifiés, on peut déborder !

    cout << "v[" << i << "] = " << v[ i ] << "\t";

    }

    cout << "\n";

    // utilisation de at() : les accès sont vérifiés

    try

    {

    v.at( v.size() ) = 10; // accès en dehors des limites !

    }

    catch ( const std::out_of_range &e )

    {

    cerr << "at() a levé une exception std::out_of_range : " << e.what() << endl;

    }
    
    
    // parcours avec un itérateur en inverse

    for ( std::vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i )

    {

    cout << *i << "\t";

    }

    cout << "\n";
    
    std::vector<int> v2( 10 );

    v2.at( 9 ) = 5; // correct, le tableau est de taille 10

    // on crée un tableau v3 de 10 éléments initialisés à 20

    std::vector<int> v3( 10, 20 );

    // faire la somme de tous les éléments de v3

    // on doit obtenir 200 (10 * 20)

    cout << "Somme : " << std::accumulate( v3.begin(), v3.end(), 0 ) << "\n";

    // on recopie v3 dans v

    v = v3;

    // on vérifie la recopie

    if ( std::equal( v.begin(), v.end(), v3.begin() ) )

    {

    cout << "v est bien une copie conforme de v3\n";

    }
    
    
    
    return 0;

}
