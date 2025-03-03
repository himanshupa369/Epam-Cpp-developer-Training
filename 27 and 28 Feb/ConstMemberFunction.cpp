/* const Member Function */

// A const function cannot modify any member variables of the class (except mutable members).
// It ensures that the function is read - only.
// but we can change static member and function within const function.
// Calling a const function on a non - const object is allowed,But A const object can only call const member functions.
// Const Obj :- A const object is an instance of a class that cannot be modified after initialization.

//Why can’t we call non - const functions using a const object ?

//A const object ensures that no modifications occur, while a non - const function might modify the object.
//Calling a non - const function from a const object would violate the purpose of const.

//Why can we change static variables inside a const member function ?
//Static variables are shared across all objects and belong to the class, not an individual instance.
//Since static variables are not tied to any specific object, a const function can modify them.

Example:-
class D{
   static int cnt;
public:
   void display() const {
       cnt++; // Allowed because count is static
   }
};

//Initialization of Non - const and const Variables

// Non - const private members: Cannot be initialized at the time of declaration.
// const private members : Must be initialized at the time of declaration or via an initialization list.

// Example:-
class Test {
   int x = 10;  // ❌ Not allowed
   const int y = 20;  // ✅ Allowed
};

// const_cast :- const_cast is used to remove or add const to a variable.
// const_cast is mainly used when dealing with legacy code or APIs that require non-const arguments.

// Example:-
#include <iostream>
using namespace std;

void modify(const int* p) {
   int* q = const_cast<int*>(p); // Removes const
   *q = 100; // Now we can modify the value
}

int main() {
   int x = 10;
   modify(&x);
   cout << "Modified x: " << x << endl; // Output: Modified x: 100
   return 0;
}

//const function

#include <iostream>
using namespace std;

class Example {
private:
   int x;
   static int cnt;
public:
   Example(int x) : x(x) {}

   void show() const { // `const` function
       cnt++;
       cout << "Value of cnt : " << cnt << endl;
       cout << "Value of x : " << x << endl;
   }
};
int Example::cnt = 5;

int main() {
   Example obj(10);
   obj.show(); // Output: Value: 10
   return 0;
}
