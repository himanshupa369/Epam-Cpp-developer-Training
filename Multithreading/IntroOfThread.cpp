//**********************************************************************************************************//

// TOPIC: Introduction to thread in c++ (c++11)

// QUESTIONS
// 1. What do you understand by thread and give one example in C++?

// ANSWER
// 0. In evey application there is a default thread which is main(), in side this we create other threads.
// 1. A thread is also known as lightweight process. Idea is achieve parallelism by dividing a process into multiple threads.
//    For example:
//    (a) The browser has multiple tabs that can be different threads.
//    (b) MS Word must be using multiple threads, one thread to format the text, another thread to process inputs (spell checker)
//    (c) Visual Studio code editor would be using threading for auto completing the code. (Intellicence)

// WAYS TO CREATE THREADS IN C++11
// 1. Function Pointers
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static Member functions

// REQUIREMENT
// Find the addition of all odd number from 1 to 1900000000 and all even number from 1 to 1900000000


#include <iostream>
#include <thread>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

void funcEven(ull start, ull end) {
   ull sumEven = 0;
   for (ull i = start; i <= end; ++i) {
       if ((i & 1) == 0) { // even
           sumEven += i;
       }
   }
   std::cout << "Sum of even: " << sumEven << std::endl;
}

void funcOdd(ull start, ull end) {
   ull sumOdd = 0;
   for (ull i = start; i <= end; ++i) {
       if ((i & 1) == 1) { // odd
           sumOdd += i;
       }
   }
   std::cout << "Sum of odd: " << sumOdd << std::endl;
}

int main() {
   ull start = 0, end = 1900000000;
   auto startTime = high_resolution_clock::now();
   // WITH THREAD
    std::thread t1(funcEven, start, end);
    std::thread t2(funcOdd, start, end);
    t1.join();
    t2.join();
   ////WITHOUT THREAD
   //funcEven(start, end);
   //funcOdd(start, end);
   auto stopTime = high_resolution_clock::now();
   auto duration = duration_cast<microseconds>(stopTime - startTime);
   cout << "Sec: " << duration.count() / 1000000 << endl;
   return 0;
}
