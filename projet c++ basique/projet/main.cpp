


#include <iostream>

template <typename T>
void afficher(const T& c)
{
    for(auto e:c)
        std::cout << e << "";
    std::cout << std::endl;
}


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
    
    
    
    
    return 0;
}




