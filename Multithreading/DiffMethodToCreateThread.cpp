// Topic: types of thread creation in c++ 11.
// There are 5 different types we can create threads in c++11 using callable objecys.

//Note:-
//If we create multiple threads at the same time it does not guarantee which one will start first.


//#include <iostream>
//#include <thread>
//#include <algorithm>
//#include <chrono>
//#include<mutex>
//using namespace std;
//using namespace std::chrono;
//std::mutex mt;

// 1. Function Pointer
// this is the very basic form of thread creation. 

//✅ Where ?
//Simple and quick thread tasks.
//When threading logic doesn’t need object state or context.

//✅ Why ?
//Minimal overhead.
//Easy to understand for beginners or simple utilities.

//🧠 Use case: Bootstrapping a basic loader, network listener, etc.

//void fun(int x) {
//	mt.lock();
//	while (x-- > 0) {
//		std::cout << x << std::endl;
//	}
//	mt.unlock();
//}

//int main() {
//	std::thread t1(fun, 11);
//	//std::thread t2(fun, 10);
//	t1.join();
//	//t2.join();
//
//	return 0;
//}

// 2. Lambda Function

//✅ Where ?
//When you want to define behavior inline.
//When the thread logic is short, non - reusable, or uses local variables.

//✅ Why ?
//No need to create a named function.
//Great for encapsulating logic near where it's used.
//Supports capturing variables.

//🧠 Use case: GUI callbacks, task dispatchers, unit tests, throwaway tasks.



// Example:

//int main() {
//	// we can directly inject lambda at thread creation time.
//
//	/*auto fun = [](int x) {
//		while (x-- > 0) {
//			cout << x << endl;
//		}
//		};*/
//
//	std::thread t([](int x) {
//		while (x-- > 0) {
//			cout << x << endl;
//		}
//		}, 10);
//
//	t.join();
//	return 0;
//}

// 3. Functor (Function Object)

//✅ Where ?
//When the thread logic needs state(data stored in the object).
//When you're building a reusable thread task, like in a thread pool.

//✅ Why ?
//Allows encapsulation of data and logic.
//Objects can be copied and customized.

//🧠 Use case: Background workers, encapsulated jobs (like Task or Job objects), thread pool jobs.

//class Base {
//public:
//	void operator ()(int x) {
//		while (x-- > 0) {
//			cout << x << endl;
//		}
//	}
//};
//
//int main() {
//	std::thread t((Base()), 10);
//	t.join();
//	return 0;
//}


// 4. Non-static member function

//✅ Where ?
//When threads must access non - static class members.
//Used in OOP - style apps where the logic belongs to a class.

//✅ Why ?
//You need to use this pointer to access instance data.
//Keeps the logic encapsulated and maintainable.

//🧠 Use case: Server-client models, game engines, real-time simulations, class-based architecture.

//class Base
//{
//public:
//	void run(int x) {
//		while (x-- > 0) {
//			cout << x << endl;
//		}
//	}
//};
//
//int main() {
//  // In this case of thread we  need object.
//	Base b;
//	std::thread t(&Base::run, &b, 10);
//	t.join();
//	return 0;
//}

// 5. Static member function

//✅ Where ?
//When the method doesn't need object state (this).
//For utility - style threading within a class.

//✅ Why ?
//No object needed.
//Easier to use than non - static if no class data is needed.

//🧠 Use case: Logger, task scheduler, timers, helper threads.
 

//class Base
//{
//public:
//	static void run(int x) {
//		while (x-- > 0) {
//			cout << x << endl;
//		}
//	}
//};
//
//int main() {
//	// In this case of thread we don't need any kind of object.
//	std::thread t(&Base::run, 10);
//	t.join();
//	return 0;
//}
