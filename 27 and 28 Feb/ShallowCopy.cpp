/* Shallow copy */

//A shallow copy copies the memory address instead of the actual data.
//If one object modifies the dynamically allocated memory, the changes will be reflected in the other object as well.
//When the destructor is called, it deletes the same memory twice, causing undefined behavior or a segmentation fault.
//Shallow copy copies the pointer, deep copy copies the value and allocates new memory.

//When to Use Shallow Copy ?
//✔ When working with small objects that do not require deep copying.
//✔ When performance is a priority and copying large data is expensive.
//✔ When objects are read - only and do not need independent memory.
//✔ When working with shared data structures where multiple objects can safely reference the same data.

#include <iostream>
using namespace std;

class student {
private:
	string name;
	int* agePtr; // Pointer to dynamically allocated memory

public:
	// Default Constructor
	student() : agePtr(nullptr) {}

	// Parameterized Constructor
	student(string name, int age) {
		this->name = name;
		this->agePtr = new int(age); 
	}

	// Shallow Copy Constructor
	student(const student& obj) {
		this->name = obj.name;
		this->agePtr = obj.agePtr; // Copies the pointer, NOT the actual value (shallow copy)
	}

	void display() {
		cout << "Student name: " << name << endl;
		cout << "Student age address: " << agePtr << endl;
		if (agePtr)
			cout << "Student age: " << *agePtr << endl;
		else
			cout << "Student age not provided." << endl;
	}

	~student() {
		delete agePtr; // Problem in Shallow Copy: Both objects will try to delete the same memory
		cout << "Destructor called for " << name << endl;
	}
};

int main() {
	student s1("Swaraj", 22);
	s1.display();

	cout << "Creating a shallow copy of s1 into s2:"<<endl;
	student s2 = s1; // Calls shallow copy constructor
	s1.display();
	s2.display();

	return 0; 
}
