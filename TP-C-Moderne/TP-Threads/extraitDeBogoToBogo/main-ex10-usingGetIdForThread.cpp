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

void thread_function()
{
    std::cout << "thread function ";
    //std::cout << "message is = " << s << std::endl;
    //s="Justin Beaver";
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
    //main thread
    //thread function Program ended with exit code: 0
    //We can get id information using this_thread::get_id()
    //main thread message = Kathy Perry
    //main thread id = 0x7ff84a7047c0
    //thread function message is = Kathy Perry
    //main thread message =
    //main thread id = 1208
    //child thread id = 5224
    //Program ended with exit code: 0
    //
    
    
     std::string s = "Kathy Perry";
     //std::thread t(&thread_function, std::move(s));
     std::cout << "main thread message = " << s << std::endl;

     std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;
     //std::cout << "child thread id = " << t.get_id() << std::endl;

     //t.join();
     return 0;
}
