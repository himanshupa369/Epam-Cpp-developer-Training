//Introduction...

//A function pointer in C++ is a pointer that stores the address of a function. 
//It allows calling functions dynamically and enables passing functions as arguments to other functions, making code more flexible and modular.

//Key Features of Function Pointers...

// Dynamic Function Invocation: Allows calling functions stored in a pointer.
// Passing Functions as Arguments: Useful for callback mechanisms.
// Enables Polymorphic Behavior: Can store different function implementations dynamically.
// Used in Callbacks and Event Handling: Common in GUI frameworks and system programming.

//Syntax of Function Pointers.. :- type (*pointer_name)(parameter_list);

//When to Use Function Pointers...

// When implementing callback functions (e.g., event-driven programming).
// When storing multiple function implementations dynamically.
// When designing plugin-based architectures.
// When simulating polymorphism in C (before C++ introduced virtual functions).

//When to Avoid Function Pointers...

// When function pointers add unnecessary complexity.
// When standard function objects (std::function) or lambda expressions provide a cleaner solution.

#include<iostream>
#include<vector>
using namespace std;

// Function returning an integer
int getNumber() {
	return 4;
}

// Static function to print a character multiple times
static void Print(int count, char ch) {
	for (int i = 0; i < count; i++) {
		cout << ch;
	}
	cout << endl;
}

// Function to return the sum of two numbers
int NumSum(int x, int y) {
	return x + y;
}

// Comparison functions for sorting
bool ascendingCompare(int a, int b) {
	return a < b;
}

bool descendingCompare(int a, int b) {
	return a > b;
}

// Sorting functions without function pointers (hardcoded comparison)
void sortAscending(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		int min = i;
		for (int j = i + 1; j < arr.size(); j++) {
			// Hardcoded ascending comparison
			if (ascendingCompare(arr[j], arr[min]))
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

void sortDescending(vector<int>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		int min = i;
		for (int j = i + 1; j < arr.size(); j++) {
			// Hardcoded descending comparison
			if (descendingCompare(arr[j], arr[min]))
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

// Generic selection sort function using function pointer for comparison
void selectionSort(vector<int>& arr, bool(*compareFunctionPtr)(int, int)) {
	for (int i = 0; i < arr.size(); i++) {
		int min = i;
		for (int j = i + 1; j < arr.size(); j++) {
			// Using function pointer for comparison
			if (compareFunctionPtr(arr[j], arr[min]))
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

// Function to print an array
void printNumbers(vector<int>& arr) {
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << ' ';
}

int main() {
	// Example 1: Function Pointer to a Static Function
	Print(5, '#');
	void (*fnptr)(int, char) = &Print; // Declaring a function pointer
	/* we can write this also == void (*fnptr)(int, char) = Print;*/
	(*fnptr)(5, '&'); // Calling function using pointer
	fnptr(5, '$'); // Another way to call function
	cout << "Function address:" << fnptr << endl;

	// Example 2: Function Pointer to Arithmetic Function
	int (*fn1ptr)(int, int) = NumSum;
	int ars = fn1ptr(3, 4);
	cout << "Sum is =" << ars << endl;

	// Example 3: Function Pointer to Function without Parameters
	cout << "Function Return value is: " << getNumber() << endl;
	cout << "Address of function: " << getNumber << endl;

	// Example 4: Sorting Using Function Pointer
	vector<int> arr = { 3,6,5,2,4,1 };
	//sortAscending(arr);
	//sortDescending(arr);

	// Assign function pointer to descending comparison function
	bool (*funcPtr1)(int, int) = descendingCompare;
	selectionSort(arr, funcPtr1); // Sorting in descending order
	printNumbers(arr);

	// Reassign function pointer to ascending comparison function
	funcPtr1 = ascendingCompare;
	cout << endl;
	selectionSort(arr, funcPtr1); // Sorting in ascending order
	printNumbers(arr);

	return 0;
}

//Array of Function Pointers...

// #include <iostream>
// using namespace std;

// int add(int a, int b) { return a + b; }
// int subtract(int a, int b) { return a - b; }

// int main() {
//     // Array of function pointers
//     int (*operations[2])(int, int) = {add, subtract};
    
//     cout << "Addition: " << operations[0](10, 5) << endl; // Output: 15
//     cout << "Subtraction: " << operations[1](10, 5) << endl; // Output: 5
    
//     return 0;
// }




