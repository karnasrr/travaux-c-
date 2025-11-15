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

    std::thread t(&thread_function);   // t starts running
    std::cout << "main thread\n";
    //t.join();   // main thread waits for the thread t to finish
    t.detach();
    if(t.joinable())
    t.join();   // Error main thread
    //thread function
    //We can keep the code from crashing by checking using joinable(). Because it's not joinable, the join() function won't be called, and the program runs without crash.
    
    return 0;
}
