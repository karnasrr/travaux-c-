//
//  main.cpp
//  Thread et fonction lambda
//
//  Created by nasr on 13/09/2024.
//  extracted from
//  http://genelaix.free.fr/IMG/pdf/threads_cours_tp.pdf
//
/*
resultat
 6Program ended with exit code: 0
*/

#include <iostream>
using namespace std;


int main() {
    int a = 1;
    auto p = [a](int b,int c) {
        int d;
        d=a+b+c;
        return d;
    };
    cout<<p(2,3); //appel de la fonction
    return 0;
}
