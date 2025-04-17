//Atomic Variable in C++.

//✅ What is an Atomic Variable ?
//An atomic variable ensures that operations on it(read / write / increment / etc.) 
//are indivisible — no other thread can interrupt it in the middle of an operation.

//🧠 Operations supported on std::atomic
//Load / Store
//++ / --
//fetch_add, fetch_sub
//Compare - and -swap(compare_exchange_weak, compare_exchange_strong)

//🚀 Use Cases
//
//Thread - safe counters
//Lock - free programming
//Spinlocks
//Flags and status indicators

#include<iostream>
#include<mutex>
#include<atomic>
#include<thread>
using namespace std;

std::atomic<int> counter;
int times = 1000000;
std::mutex m;

void run() {
    // to avoid race condition use mutex.
    //m.lock();
    for (int i = 0; i < times; ++i) {
        counter++;
    }
    //m.unlock();

}

int main() {
    std::thread t1(run);
    std::thread t2(run);

    t1.join();
    t2.join();

    cout << counter << endl;
    return 0;
}
