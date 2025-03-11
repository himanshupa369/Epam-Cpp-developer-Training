//Stack Unwinding...

	//Stack unwinding is the process by which destructors of automatic (local) objects are called in reverse order when an exception is thrown and not caught in the current function.
	//It ensures that resources are properly released as the function call stack is "unwound" to find an appropriate catch block.

//How Stack Unwinding Works...

	//An exception is thrown using throw.
	//The runtime searches for a matching catch block.
	//If no matching catch is found in the current function, the function exits, and its local objects are destroyed(destructors are called).
	//The process repeats for each function in the call stack until a matching catch is found.
	//If no catch is found, the program terminates.
	
// To protect our system from memory leak we use below concepts...

//Resource Acquisition Is Initialization (RAII)...

//RAII is a programming technique in which a resource(like memory, file handles, locks, or network connections) is tied to the lifetime of an object.
// This means that when an object is created, it acquires the resource, and when it goes out of scope, it automatically releases the resource.

//Key Concept...

//Resources should be wrapped inside a class.
//The constructor acquires(allocates) the resource.
//The destructor releases(deallocates) the resource automatically.
//This prevents memory leaks and ensures exception safety.

//Why is RAII Important ?

//✅ Automatic Resource Management
//No need to manually free resources.
//No memory leaks or dangling pointers.

//✅ Exception Safety
//If an exception occurs, the destructor still runs, ensuring proper cleanup.

//✅ Used in Standard Library(STL)
//std::unique_ptr and std::shared_ptr for smart memory management.
//std::lock_guard for thread synchronization.

#include<iostream>
#include<limits>
#include<memory> //for smart pointer //
using namespace std;

class Test {
public:
	Test() {
		cout << "File opened: " << endl;
	}
	~Test() {
		cout << "File closed: " << endl;
	}
};

int ProcessStatus(int count) {
	//Create object on stack. //
	//Test t1;
  
	//Now create opject on heap.//
	//Test* t2=new Test();
  
	//use of smart pointer.//
	unique_ptr<Test> t(new Test());

	cout << "Throwing an error:" << endl;
	if (count < 10) {
		throw out_of_range("process size must be more than ten;");
	}
	int* p = new int[count];
	int* ptrArr = (int*)malloc(count * sizeof(int));
	// 	if (p == nullptr)
	// 		throw bad_alloc("bad length of array");
	if (ptrArr == nullptr) {
		throw runtime_error("Failed To Allocate Memory");
		return -1;
	}
	for (int i = 0; i < count; ++i) {
		ptrArr[i] = i;
	}
	free(ptrArr);
	delete[] p;
	//delete t2;
	return 0;
}

int main() {
	try {
		//ProcessStatus(numeric_limits<int>::max());
		ProcessStatus(5);
	}
	catch (runtime_error& e) {
		cout << "error is:" << e.what() << endl;
	}
	catch (out_of_range& e) {
		cout << "error is:" << e.what() << endl;
	}
	catch (bad_alloc& e) {
		cout << "error is: " << e.what() << endl;
	}
	return 0;
}
