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

void thread_function(std::string &s)
{
    std::cout << "thread function ";
    std::cout << "message is = " << s << std::endl;
    s="Justin Beaver";
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
    //mmain thread message = Justin Beaver
    //thread function message is = Kathy Perry
    //Program ended with exit code: 0
    //Program ended with exit code: 0
    //There is another way of passing the parameter without copying and not sharing memory between the threads. We can use move()
    //thread function message is = Kathy Perry
    //main thread message =
    //Bug:But do not compile
    //
    
    std::string s1 = "Kathy Perry";
    //std::string s = "Justin Beaver";
    std::thread t(&thread_function, std::move(s1));
    std::cout << "main thread message = " << s1 << std::endl;
    t.join();
    return 0;
}
