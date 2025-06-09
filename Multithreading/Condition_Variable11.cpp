// TOPIC: Condition Variable In C++ Threading

//Important Point:: CV are used for two purpose
// A. Notify other threads
// B. Waiting for some condotions.

// NOTES:
// 1. Condition variables allow us to synchronize threads via notifications.
//    a. notify_one();
//    b. notify_all();
// 2. You need mutex to use condition variable
// 3. Condition variable is used to synchronize two or more threads.
// 4. Best use case of condition variable is Producer/Consumer problem.
// 5. Condition variables can be used for two purposes:
//     a. Notify other threads
//     b. Wait for some condition
// 6. If some thread want to wait on some condition then it has to do these things:
//    a.Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);.
//    b.Execute wait,wait_for, or wait_until.The wait operations atomatically release the mutex
//      and suspend the execution of the thread.
//    c. When the condition variable is notified, the thread is awakened, and the mutex is atomically reacquired.
//       The thread should then check the condition and resume waiting if the wake uo was spurious.


#include <iostream>
#include <thread>
#include <mutex>
#include<chrono>
#include<condition_variable>
using namespace std;
using namespace std::chrono;

std::condition_variable cv;
int myAmount = 0;
std::mutex m;
long balance = 0;

void addMoney(int money) {
	std::lock_guard<mutex> lg(m);
	balance += money;
	cout << "Amount Added Current Balance: " << balance << endl;
	cv.notify_one();
}

void withdrowMoney(int money) {
	std::unique_lock<mutex> ul(m);
	cv.wait(ul, []() {return (balance != 0) ? true : false;  });
	if (balance >= money) {
		balance -= money;
		cout << "Amount Deducted: " << money << endl;
	}
	else {
		cout << "Amount can not be deducted,Current Balance is less Than " << money << endl;
	}
	cout << "Current Balance is : " << balance << endl;
}



void addMoney() {
	m.lock();
	++myAmount;
	m.unlock();
}

int main() {
	std::thread t2(withdrowMoney,500);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::thread t1(addMoney, 1000);

	t1.join();
	t2.join();
	return 0;
}
