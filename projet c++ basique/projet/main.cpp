//26 avril 026
//EXTRAIT DU LIVRE C++ Programmer en C++  ALAIN GIBAUB
//test les algorithmes de la STL
//ce programme affiche
/*
3 8 5 15 17 17 9
3 8 5 15 17 17 9
notes >=10  15 17 17
3 prem notes=3 8 5
notes copiés à la fin=  0 0 0 0 0 3 8 5 15 17 17 9
noms=
noms1 déplacés=  louis paul emma
notes augmentees de 4pts=  7 12 9 19 20 20 13
fib=  0 1 1 2 3 5 8 13 21 34 55 89 144 233 377
fib impairs =  1 1 3 5 13 21 55 89 233 377
fib impairs >=10 =  -1 -1 -1 -1 13 21 55 89 233 377
idem à l envers=  377 233 89 55 21 13 -1 -1 -1 -1
les 24anagrammes possibles de elio sont :
elio eloi eiol eilo eoli eoil lioe lieo loei loie leio leoi ioel iole ielo ieol iloe ileo oeli oeil olie olei oiel oile
Program ended with exit code: 0
 */

#include <iostream>
#include <list>

template <typename T>
void afficher(const T& c)
{
    for(auto e:c)
        std::cout << e << " ";
    std::cout << std::endl;
}

class FiboGenerator
{
    int a,b;
    
public:
    FiboGenerator(): a(0),b(1){}
    int operator()()
    {
        int r=a,t=a+b;
        a =b;b=t;
        return r;
    }
    
    
};

void calculerAnagrammes(std::string& s,int from,std::vector<std::string>& r)
{
    int k = s.size() -from;
    if(k==1)
        r.push_back(s);
    else
    {
        while(k--)
        {
            calculerAnagrammes(s, from +1, r);
            auto i1 = s.begin()+from;
            rotate(i1,i1+1,s.end());
        }
    }
};

int main()
{
    std:: vector<double> notes = { 3, 8, 5, 15, 17, 17, 9} ;
    auto d= notes.begin(),f=notes.end();
    afficher(notes);
    
    //copy
    std:: vector<double> notes1;
    std::copy(d, f, std::back_inserter(notes1));
    afficher(notes1);
    
    //copy if
    std:: vector<double> notes2;
    std::copy_if(d, f, std::back_inserter(notes2), [](double n){return n>=10;});
    std::cout << "notes >=10  ";
    afficher(notes2);
    
    
    // copy n
    std::deque<double> notes3;
    std::copy_n(d, 3, back_inserter(notes3)),std::cout <<"3 prem notes=";afficher(notes3);
    
    // copy backward
    std::vector<double>notes4(notes1.size()+5);
    std::copy_backward(d, f, notes4.end());
    std::cout << "notes copiés à la fin=  ";
    afficher(notes4);
    
    
    //move
    std::list <std::string> noms={"louis","paul","emma"};
    std::list <std::string> noms1(noms.size());
    std::move(noms.begin(), noms.end(), noms1.begin());
    std::cout << "noms=  ";afficher(noms);
    std::cout << "noms1 déplacés=  ";afficher(noms1);
    
    std::vector<double>notesplus;
    auto add4 =[](double n)
    {
        double nplus = n+4;if (nplus >20)nplus=20;return nplus;
    };
    
    std::transform(d, f, std::back_inserter(notesplus), add4);
    std::cout << "notes augmentees de 4pts=  ";afficher(notesplus);
    
    //generate
    FiboGenerator generator;
    std::vector<int>fib(15);
    std::generate(fib.begin(),fib.end(),generator);
    std::cout << "fib=  ";afficher(fib);
    
    //remove if
    auto logend =std::remove_if(fib.begin(), fib.end(), [](int k){return k%2 ==0;});
    fib.erase(logend,fib.end());
    std::cout << "fib impairs =  ";afficher(fib);
    
    //replace if
    std::replace_if(fib.begin(), fib.end(), [](double x){return x <10;}, -1.0);
    std::cout << "fib impairs >=10 =  ";afficher(fib);
    
    //reverse
    std::reverse(fib.begin(), fib.end());
    std::cout << "idem à l envers=  ";afficher(fib);
    
    //rotate
    std::string s="elio";
    std::vector<std::string>r;
    calculerAnagrammes(s, 0, r);
    std::cout << "les " << r.size()  <<"anagrammes possibles de " <<s <<" sont : "<< std::endl ;afficher(r);
    
    
    return 0;
}




