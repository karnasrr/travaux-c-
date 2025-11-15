//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from C++ modern
//
//
/*
 Gestion de vecteurs-IMG 2195-96
 Transmission d'une variable de type string en argument d'une fonction
 Affiche
 Donnez le nombre de notes:10
 Donnez la note numero:1:7
 Donnez la note numero:2:8
 Donnez la note numero:3:9
 Donnez la note numero:4:11
 Donnez la note numero:5:4
 Donnez la note numero:6:8
 Donnez la note numero:7:12
 Donnez la note numero:8:12
 Donnez la note numero:9:13
 Donnez la note numero:10:12
 Moyenne de la classe:9.6
 5eleves ont plus de cette moyenne
 Program ended with exit code: 0
 Program ended with exit code: 0
 
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    unsigned int nb;
    cout << "Donnez le nombre de notes:"; cin>>nb;
    vector<float>notes (nb);
    for (unsigned int i=0;i<nb;i++)
    {
        cout << "Donnez la note numero:"<<i+1<<":"; cin>>notes[i];
    }
    
    float som =0;
    for(unsigned int i=0;i<nb;i++) som+=notes[i];
    float moy = som/nb;
    cout << "Moyenne de la classe:"<<moy<<endl;
    
    int nbm=0;
    for(unsigned int i=0;i<nb;i++) if(notes[i]>moy) nbm++;
    cout<<nbm<<"eleves ont plus de cette moyenne"<<endl;
}
