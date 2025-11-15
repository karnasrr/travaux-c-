//
//  main.cpp
//  tp
//
//  Created by nasr on 08/09/2024.
//

//extrait du livre Programmer en C++ Moderne - Chapitre classe @ objets Construction et destruction
//page 256
//ajout sur Git

#include <iostream>
using namespace std;

//----------Declaration de la classe test
class test
{
public:
    int num;
    test (int);
    ~test();
};

//-------definition de la classe test
test::test (int n):num(n)
{
    cout << "++ Appel constructeur -num=" << num <<endl;
}

test::~test ()
{
    cout << "++ Appel destructeur -num=" << num <<endl;
}

void fct (int);



//----------Utilisation de la classe point

int main(int argc, const char * argv[]) {
    // insert code here...
    
    /**
      Affiche
     ++ Appel constructeur -num=1
     ++ Appel constructeur -num=4
     ++ Appel destructeur -num=4
     ++ Appel constructeur -num=6
     ++ Appel destructeur -num=6
     ++ Appel constructeur -num=8
     ++ Appel destructeur -num=8
     ++ Appel destructeur -num=1
     Program ended with exit code: 0
       */
       
    test a(1);
    
    for(int i=2;i<=4;i++) fct(i);
}

void fct (int p)
{
    test x(2*p);
}
