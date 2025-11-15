//
//  main.cpp
//  Thread
//
//  Created by nasr on 13/09/2024.
//  extracted from
//  https://www.bogotobogo.com/cplusplus/C11/1_C11_creating_thread.php
//
/*
 Thread with Move Semantics
 What's the implication of passing a variable by value?

 When a function gets its parameter as by value, it does copy. Compiler knows how to copy it. If it's a user defined type, we may need to provide copy constructor, and may be assignment operator as well to be able to do a deep copy. However, copying is expensive.
*/

#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <cassert>
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



int main()
{
    //affiche
    //thread function: 2
    //1thread function: 3
    //0
    //Program ended with exit code: 0
    //Thread with Move Semantics
    /*
    What's the implication of passing a variable by value?

    When a function gets its parameter as by value, it does copy. Compiler knows how to copy it. If it's a user defined type, we may need to provide copy constructor, and may be assignment operator as well to be able to do a deep copy. However, copying is expensive.
     */
    //
    // vector container stores threads
    std::vector<std::thread> workers;
    for (int i = 0; i < 5; i++) {
        auto t = std::thread([i]()
        {
            std::cout << "thread function: " << i << "\n";
        });
        workers.push_back(std::move(t));
    }
    std::cout << "main thread\n";

    // Looping every thread via for_each
    // The 3rd argument assigns a task
    // It tells the compiler we're using lambda ([])
    // The lambda function takes its argument as a reference to a thread, t
    // Then, joins one by one, and this works like barrier
    std::for_each(workers.begin(), workers.end(), [](std:: thread &t)
    {
        assert(t.joinable());
        t.join();
    });

    return 0;
}
