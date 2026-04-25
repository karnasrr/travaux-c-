//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from
//  https://www.bogotobogo.com/cplusplus/C11/1_C11_creating_thread.php
//
/*
resultat
 main thread
 Passing Parameters to a thread
 Here is an example of passing parameter to a thread. In this case, we're just passing a string:
 
 main thread message = Kathy Perry
 thread function message is = Kathy Perry
 Program ended with exit code: 0
*/

#include <thread>
#include <iostream>

#include <mutex>
using namespace std;

mutex monmutex; // un mutex

void thread_function(std::string s)
{
    std::cout << "thread function ";
    std::cout << "message is = " << s << std::endl;
}

class MyFunctor
{
public:
    void operator()() {
        std::cout << "functor\n";
    }
};

/*
void appA(void) {
    char c;
    while(1)
    {
        //c<<cin;
    }
    
}

void appZ(void) {
    char c;
    while(1)
    {
    }
    
}
*/


int main() {

    //Here is an example of passing parameter to a thread. In this case, we're just passing a string:
    //main thread message = Kathy Perry
    //thread function message is = Kathy Perry
    //Program ended with exit code: 0
    //
    
    std::string s = "Kathy Perry";
    std::thread t(&thread_function, s);
    std::cout << "main thread message = " << s << std::endl;
    t.join();
    return 0;
}
