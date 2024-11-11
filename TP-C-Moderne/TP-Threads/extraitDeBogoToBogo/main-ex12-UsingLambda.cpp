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
    //We can replace the thread_function() with lambda function (anonymous function)
    //Note that we are writing inline code and passing into another function which is a thread constructor.

    //The lambda expression is a series of statements enclosed in braces, prefixed with [], called lambda introducer or capture specification which tells the compiler we're creating a lambda function, in our case, taking no argument. So, in essence, we're using [](){} as a task, and assigning it to our thread.
    //Program ended with exit code: 0
    //
    
    
       std::thread t([]()
        {
            std::cout << "thread function\n";
        }
        );
        std::cout << "main thread\n";
        t.join();     // main thread waits for t to finish
    
    //here number of threads
    std::cout << "Number of threads = "
                  <<  std::thread::hardware_concurrency() << std::endl;
     //t.join();
     return 0;
}
