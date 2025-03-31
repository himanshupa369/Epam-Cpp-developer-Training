/*...C++ ARRAY...*/
#include<iostream>
#include<array>
using namespace std;

//Feature	                           C Array	                          C++ Array(std::array)
//Size Handling	                       sizeof() (manual)	              size() (built - in)
//Bound Checking	                   ❌ No	                          ✅ at() with exception
//Dynamic Allocation	               malloc() / free()	              std::vector(safer)
//Initialization                       {}(partial allowed)                {} (safe, full initialization)
//Passing to Functions	               Passed as pointer	              Pass by reference
//Multi - dimensional                  Support Yes	                      std::vector(dynamic size)
//Operations	                       Manual loops	                      Iterators, range - based loops

//arr.data() is a member function of std::array and std::vector in C++.
//It returns a pointer to the first element of the container, providing direct access to the underlying array.

//✅ Why use arr.data() ?

//Provides direct access to internal array memory.
//Safer than & arr[0] for empty containers.
//Useful for interfacing with C functions.
//Enables pointer - based operations efficiently.

//  Arrays are passed as pointers, and size must be passed separately.
void printArray(int* arr, int size) {
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	cout << endl;
}

int main() {
	array<int, 5> arr = {1, 2, 3, 4, 5};
	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;

	int* ptr = arr.data();  // Get pointer to first element
	for (int i = 0; i < 5; ++i) {
		cout << *(ptr + i) << " ";
	}cout << endl;

	for (int x : arr)  // Range-based for loop
		cout << x << " ";
	cout << endl;

	//arr.at(index) performs bound checking and throws an exception if out of range.
	cout << arr.at(1) << endl;
	//cout << arr.at(7) << endl;

	int arry[5] = { 11, 12, 13, 14, 15 };
	printArray(arry, 5);  // Pass pointer


	cout << "Array empty element:" << endl;
	array<int, 5> arr1 = { 1,2,3 };
	for (int i = 0; i < 5; ++i) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	const int size = 4;
	//int arr2[size];
	int arr2[size]{};

	cout << "Uninitialized array elements: "<<endl;
	for (int i = 0; i < size; ++i) {
		cout << "arr2[" << i << "]: " << arr2[i] << endl;
	}
	cout << "size of arr: " << sizeof(arr) << endl; //in byte
	cout << "size of arr: " << arr.size() << endl;
	cout << "size of arr: " << sizeof(arr)/sizeof(arr[0]) << endl;
	cout << "size of arr1: " << sizeof(arr1) << endl;
	cout << "size of arr2: " << sizeof(arr2) << endl;
}
