/* ...Move Semantic... */

//Introduction...

//In C++, move semantics is a feature introduced in C++11 that allows resources to be efficiently transferred from one object to another, instead of copying them.
//This is particularly useful for expensive operations like managing dynamic memory, file handles, or other system resources.
//Allow us to avoid unnecessary copy of objects when working with temporary object.

//Why Move Semantics?

//When an object is copied, a deep copy is typically performed, which means duplicating all resources.However,
//in some cases(like returning objects from functions), creating a copy is wasteful.Move semantics allows transferring ownership of resources instead of duplicating them.

//When are Move Semantics Used ?

//Returning objects from functions(avoid unnecessary copies).
//When passing temporary objects.
//Optimizing large data structures like vectors, strings, etc.

// lvalue...

// A value that resides in memory(heap/stack).
// lvalue is addressable.
// Can't be moved.But modifiable.
// int i=5; int* p1=&i (Possible) but int* p2=&5 (not possible).
// Simply any value left to the assignment operator ("=") is called lvalue.But not in every cases.

// rvalue...

// A value that's not a lvalue.
// It resides always to the right of assignment expression such as a literal or a temporary which is intended to be non modifiable.
// Can be move.  int i=5 (5 is rvalue.) : A a= A() ( A() is rvalue.).

// lvalue references...

// Normal / Old value reference.
// Can be bound to only  lvalues but not on rvalues.
// however we can bind an rvalues to a const  lvalue references.
// example:- int i=10; (correct)
//           int& x = i; (correct)
//           int &x1=10; (incorrect)
//           int ans=foo(10) (incorrect) if( foo(int& lr)  )
//           cont int& x2=10; (correct)

// rvalue references...

// Introduced in c++ 11 standard.
// Bind only to rvalues.
// represented by &&.
// An expression is an rvalue if it results in  a temporary object.
// example:- int a=10;(coorect)
//           int&& rr=10; (correct)
//           int&& rr1=foo(10) (correct) if( foo(int&& rr2)  )
//

#include<iostream>
using namespace std;

void fun(int& a) {
	cout << "lvalue called: a= " << a << endl;
}

void fun(int&& a1) {
	cout << "rvalue called: a1= " << a1 << endl;
}
void fun(const int& a2) {
	cout << "const lvalue: a2= " << a2 << endl;
}
int main() {
	int i = 10;
	fun(i);
	fun(10);
	fun(std::move(i)); //( "move()" convert lvalue into rvalue)
	fun(static_cast<int&&>(i));
	return 0;
}
