// Example of Deadlock.

#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
std::mutex m1;
std::mutex m2;

void thread1(){
	m1.lock();
	//If you want to implement deadlock then use sleep_for.
	std::this_thread::sleep_for(std::chrono::seconds(1));
	m2.lock();
	std::cout << "critical section of thread one" << std::endl;
	m1.unlock();
	m2.unlock();
}

void thread2() {
	m2.lock();
	std::this_thread::sleep_for(std::chrono::seconds(1));
	m1.lock();
	std::cout << "critical section of thread two" << std::endl;
	m2.unlock();
	m1.unlock();
}

int main() {
	std::thread t1(thread1);
	std::thread t2(thread2);
	t1.join();
	t2.join();
	return 0;
}
