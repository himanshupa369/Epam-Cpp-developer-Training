// TOPIC: Use Of join(), detach() and joinable() In Thread In C++ (C++11)

// JOIN NOTES
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object.
// 1. Double join will result into program termination.
// 2. If needed we should check thread is joinable before joining. ( using joinable() function)
// 3.It block thread call.


// DETACH NOTES
// 0. This is used to detach newly created thread from the parent thread.
// 1. Always check before detaching a thread that it is joinable otherwise we may end up double detaching and 
//    double detach() will result into program termination.
// 2. If we have detached thread and main function is returning then the detached thread execution is suspended.

// NOTES:
// Either join() or detach() should be called on thred object, otherwise during thread object�s destructor it will 
// terminate the program. Because inside destructor it checks if thread is still joinable? if yes then it terminates the program.


//#include <iostream>
//#include <chrono>
//#include <thread>
//using namespace std;
//
//void run(int count) {
//	while (count-- > 0) {
//		cout << count << " CppNuts" << endl;
//	}
//	//here process wait for 5 second.
//	//std::this_thread::sleep_for(chrono::seconds(5));
//
//	cout << "thread finished" << endl;
//}
// 
//int main() {
//	/*std::thread t1(run, 10);*/
//	//*******join()*********
//	/*cout << "main()" << endl;
//	t1.join();*/
//	// showng error
//	//t1.join();
//	//it can't give error.
//	// use of joinable()...
//	/*if (t1.joinable())
//		t1.join();*/
//	/*cout << "main() after" << endl;*/
//
//	//*********detach()*******
//	std::thread t1(run, 10); 
//	cout << "main()" << endl;
//
//	t1.detach();
//	if(t1.joinable())
//		t1.detach();
//
//	cout << "main() after" << endl;
//
//	// after completing entire statements OS wait for 5 second to terminate the code.
//	// check difference by commenting below statement.
//	std::this_thread::sleep_for(chrono::seconds(5));
//	return 0;
//}
