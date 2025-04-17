// TOPIC: std::future and std::promise in threading.

// NOTES:
// 1. std::promise ( like setter )
//      a. Used to set values or exceptions.
// 2. std::future ( like getter)
//      a. Used to get values from promise.
//      b. Ask promise if the value is available.
//      c. Wait for the promise.


//📦 Analogy:
//Think of it like online food delivery :
//You place an order(the promise — "I’ll cook and send your food").
//You get a tracking link(the future — "I’ll wait until food arrives").
//You can wait for the food, check when it’s done, or get notified when it arrives.

// PROGRAM:
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <future>
using namespace std;
using namespace std::chrono;
typedef long int ull;

void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end) {
   ull OddSum = 0;
   for (ull i = start; i <= end; ++i) {
       if (i & 1) {
           OddSum += i;
       }
   }
   OddSumPromise.set_value(OddSum);
}

int main() {

   ull start = 0, end = 1900000000;

   std::promise<ull> OddSum;
   std::future<ull> OddFuture = OddSum.get_future(); // future connected to the promise

   cout << "Thread Created!!" << endl;
   std::thread t1(findOdd, std::move(OddSum), start, end);

   cout << "Waiting For Result!!" << endl;
   ull value = OddFuture.get();  // blocks until value is set
   cout << "OddSum : " << value<< endl;

   cout << "Completed!!" << endl;
   t1.join();
   return 0;
}
