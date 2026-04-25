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
 Program ended with exit code: 0
*/

#include <thread>
#include <iostream>

#include <mutex>
using namespace std;

mutex monmutex; // un mutex

void thread_function()
{
    std::cout << "thread function\n";
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

    //In the previous examples, we used regular function for the thread task. However, we can use any callable object such as lambda functions as described in the next section or functor (function objects
    //Here, we created an function object and assign it to a thread task
    //
    
     MyFunctor fnctor;
     std::thread t(fnctor);
     std::cout << "main thread\n";
     t.join();
     return 0;
}
