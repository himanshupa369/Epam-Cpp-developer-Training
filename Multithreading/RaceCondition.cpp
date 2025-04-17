//===== Realtime Race Condition =====//

// Result should be 2M but it's not why? due to race condition.

#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

int counter;
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
