#include<iostream>
using namespace std;

//is a relation
class Animal {};
class Dog : public Animal {};  // Dog IS an Animal

//has a relation
class Engine {};
class Car {
	Engine engine;  // Car HAS an Engine
};


class A {
	int val;
public:
	int data;
	//The explicit keyword in C++ is used to prevent implicit type conversions that would otherwise happen automatically.
	/*A() : val(0), data(0) {} this is called constructor initialization list*/
	explicit A() :val(0), data(0) {}
	explicit A(int x, int datav) :val(x), data(datav) {}

	//explicit copy constructor :-An explicit copy constructor is one where you prevent implicit copying of objects.
	//The copy constructor in C++ creates a new object as a copy of an existing object.
	// If you don't define a copy constructor, the compiler provides a default one.
	// The explicit ensures that copy-construction only happens explicitly, not implicitly.
	// Explicit copy constructor
	explicit A(const A& obj) {
		val = obj.val;
		data = obj.data;
	}

	// Custom Copy Assignment Operator (Explicit Deep Copy)
	// An assignment operator can't be explicit 
	A& operator = (const A& obj1) {
		if (this != &obj1) {
			data = obj1.data;
			val = obj1.val;
		}
		return *this;
	}
	void print() {
		cout << "val = " << val << endl;
		cout << "data =" << data << endl;
	}
	~A() {
		cout << "destructor call" << endl;
	}
};

int main() {
	int p = 10;
	//p is implicitly converted from into double
	double q = p;  // Implicit conversion from int to double
	/*A a = 5;*/ // Error if constructor is explicit
	/*A a(5,3);*/
	A a(5, 3);
	a.print();
	A b(6, 2);
	b.print();
	/*A c = a; is an implicitly copying object*/
	A c(a); // Explicit copy constructor
	c.print();
	b = a; // assignment copy constructor
	b.print();
	return 0;
}