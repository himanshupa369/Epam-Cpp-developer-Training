/*
============================================
Explanation:
============================================

Without thread_local:
- Both threads share the same 'counter' variable.
- The output will be inconsistent and interleaved due to race conditions.
- Multiple threads may update 'counter' at the same time.

With thread_local:
- Uncomment `thread_local int counter = 0;` to give each thread its own instance.
- Each thread will maintain a separate counter that starts at 0.
- No data races will occur.

============================================
✅ What is the use of thread_local?
============================================
- 'thread_local' is a storage specifier in C++.
- It ensures each thread gets its own copy of the variable.
- Syntax: `thread_local int counter = 0;`
- Helps to avoid data races without using mutexes.
- Useful when you want to store data per-thread, especially in logging, caching, etc.
*/

#include <iostream>
#include <thread>
#include<mutex>
// Uncomment this to give each thread its own counter

//thread_local int counter = 0;
int counter = 0; // Shared counter (race condition)
std::mutex m;

void threadFunction(int threadId) {
    for (int i = 0; i < 5; ++i) {
        ++counter;
        std::cout << "Thread " << threadId << " - Counter: " << counter << std::endl;
    }
}

int main() {
    std::thread t1(threadFunction, 1);
    std::thread t2(threadFunction, 2);

    t1.join();
    t2.join();

    return 0;
}
