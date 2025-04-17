//Debug the code to understand the concepts behind semaphor.

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

class BinarySemaphore {
public:
   BinarySemaphore() : flag(true) {} // flag = true means available

   void down() {
       std::unique_lock<std::mutex> lock(mtx);
       cv.wait(lock, [this]() { return flag; });
       flag = false; // lock acquired
   }

   void up() {
       std::unique_lock<std::mutex> lock(mtx);
       flag = true;
       cv.notify_one();
   }

private:
   std::mutex mtx;
   std::condition_variable cv;
   bool flag; // acts like a binary flag (0 or 1)
};

BinarySemaphore sem;

void worker(int id) {
   sem.down();
   std::cout << "Thread " << id << " entered critical section.\n";
   std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
   std::cout << "Thread " << id << " leaving critical section.\n";
   sem.up();
}

int main() {
   std::vector<std::thread> threads;
   for (int i = 0; i < 5; ++i) {
       threads.emplace_back(worker, i);
   }
   for (auto& t : threads) {
       t.join();
   }
   return 0;
}

