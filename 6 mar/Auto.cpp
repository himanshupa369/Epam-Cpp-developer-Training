#include <iostream>
#include <vector>
#include <typeinfo>
//above header file is used for "typeid" to get a type information of a variable like int ,float etc // 
using namespace std;

//.....auto keyword....//

//Introduction

//The auto keyword in C++ was introduced in C++11 and allows automatic type deduction.
// The compiler determines the variable's type based on the assigned value.

//Rules for auto

//auto requires an initializer for type deduction. auto var; ->>error
//It cannot be used for function parameters(use template or decltype instead).
//When used with pointers or references, the type is deduced accordingly.
//When used with const, auto deduces the type while preserving the constant nature.

//When to Use auto?

//When dealing with complex types like iterators, lambdas, and templates.
//To improve code readability and reduce redundancy.
//When the exact type is not necessary to specify explicitly.

//When Not to Use auto

//When explicit type information improves code clarity.
//When initialization is not possible.
//When it makes debugging harder due to unknown inferred types.



int main() {
   auto x = 10;    
   auto y = 3.14;     
   auto z = "Hello";  // const char*

   cout << "Type of x: " << typeid(x).name() << endl;
   cout << "Type of y: " << typeid(y).name() << endl;
   cout << "Type of z: " << typeid(z).name() << endl;

   // Using auto with references
   int a = 42;
   auto& ref = a; // ref is int&
   ref = 50;
   cout << "Type of ref: " << typeid(ref).name() << endl;

   // Using auto with const
   const int b = 100;
   auto c = b;  // c is int (const is discarded)
   const auto d = b; // d remains const int

   cout << "Type of c: " << typeid(c).name() << endl;
   cout << "Type of d: " << typeid(d).name() << endl;

   // Using auto with pointers
   auto p = &a; // p is int*

   cout << "Type of p: " << typeid(p).name() << endl;

   // Using auto with STL containers
   vector<int> vec = { 1, 2, 3, 4, 5 };
   for (auto it = vec.begin(); it != vec.end(); ++it) {
       cout << *it << " ";
   }
   cout << endl;

   //Using auto with lambda expressions //
   auto lambda = [](int n) { return n * n; };
   cout << "Lambda output: " << lambda(5) << endl;

   //Using auto for function return type (C++14)//
   auto add = [](auto x, auto y) { return x + y; };
   cout << "Addition: " << add(5, 3.2) << endl;

   //Using auto for range-based for loop//
   for (auto i : vec) {
       cout << i << " ";
   }

   return 0;
}
