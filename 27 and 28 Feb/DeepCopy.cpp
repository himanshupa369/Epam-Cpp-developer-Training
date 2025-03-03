//A deep copy allocates new memory and copies the actual data, not just the pointer.
//This ensures that each object has its own copy of the data, preventing unintended modifications.
//There is no double deletion issue, as each object handles its own memory independently.

// Advantages of Deep Copy :
//✔ Each object gets its own memory allocation.
//✔ No double deletion issue.
//✔ Modifications in one object do not affect another.

#include<iostream>
using namespace std;

class student {
private:
	string name;
	int* agePtr;
public:
	student():agePtr(nullptr){}
	student(string name, int age) {
		this->name = name;
		this->agePtr = new int(age);
	}
 // Deep Copy constructor
	student(const student& obj) {
		this->name = obj.name;
		if (obj.agePtr) {
			this->agePtr = new int(*(obj.agePtr)); // Allocate memory and copy value
		}
		else {
			this->agePtr = nullptr;
		}
	}
	void display() {
		cout << "Student name: " << name << endl;
		cout << "student agePtr address: " << agePtr << endl;
     cout<<"student age: "<<*agePtr<<endl;
	}
	~student() {
		delete agePtr;
		cout << "destructor called" << endl;
	}
};
int main() {
	student s1("Himanshu",22);
	/*student s2("swaraj", nullptr);*/
	s1.display();
	cout << endl;
	/*s2.display();*/
	student s2=s1;
	//Default copy constructor and Assignment constructor overloading not allowed for userdefine datatypes//
	s1.display();
	cout << endl;
	s2.display();
	return 0;
}
