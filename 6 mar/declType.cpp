#include <iostream>
#include <vector>
#include <typeinfo>
//above header file is used for "typeid" to get a type information of a variable like int ,float etc // 
using namespace std;

//...declType...

//Introduction...

//The decltype keyword in C++ is used for type deduction at compile time.
// Unlike auto, decltype does not evaluate an expression but instead inspects its type.

//Key Features of decltype....

//Deduces the Exact Type : decltype extracts the exact type of an expression without evaluating it.
//Works Without Initialization : Unlike auto, decltype does not require an initializer.
//Useful in Templates and Return Types : Often used in function return types to deduce types dynamically.
//Preserves References and Qualifiers : Keeps const, volatile, and reference qualifiers.


//Rules for decltype

//decltype(expression) returns the exact type of the expression.
//If used with an identifier, it gives the declared type of the identifier.
//If used with an expression involving functions or operators, it returns the resulting type.
//If used with a reference expression, it preserves the reference type.

int main() {
   int a = 42;
   double b = 3.14;
   const int c = 100;

   //Basic decltype usage
   decltype(a) x; // x is int
   decltype(b) y; // y is double
   decltype(c) z = c; // z is const int // auto preserve only type int

   //decltype with expressions
   decltype(a + b) sum; //sum is double (type of a + b)

   // decltype with references
   int m = 10;
   int& s = m;
   decltype(s) newRef = m; // newRef is int&

   // decltype with function calls
   auto func = [](int x, double y) -> decltype(x * y) { return x * y; };
   cout << "Function return value: " << func(2, 3.5) << endl;

   cout << "Type of result: " << typeid(sum).name() << endl;
   cout << "Type of newRef: " << typeid(newRef).name() << endl;

   return 0;
}
