//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from C++ modern
//
//
/*
 Gestion de vecteurs-IMG 2200
Differentes facons de parcourir les éléments d'un vecteur
 Affiche
 En A,v=135
 En B,v=246
 En C,v=246
 En D,v=357
 Program ended with exit code: 0
 
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    vector<int> v{1,3,5};
    cout << "En A,v=";
    for(auto e:v)cout<<e<<"";cout<<endl;
    for(unsigned int i=0;i<v.size();i++) v[i]++;
    cout<<"En B,v=";
    for(auto e:v) cout <<e<<"";cout<<endl;
    cout <<"En C,v=";
    for(auto e:v)cout<<e<<"";cout<<endl;
    for(auto & e:v)e++;
    cout<<"En D,v=";
    for(int e:v)cout<<e<<"";cout<<endl;
    
    
    /*
    const int N=10;
    vector<int>t[N];
    //t[12]=5;
    
    //cout<< "t[12]= "<<t[12]<<endl;
    //cout<<"t[100]="<<t[100]<<endl;
    cout<<"t[5]="<< t[5] << endl;
    
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
     */
}
