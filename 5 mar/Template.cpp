#include<iostream>
using namespace  std;

//...templates...

//Introduction...

//Templates in C++ allow writing generic and reusable code that works with any data type. 
// They enable the creation of functions and classes that operate on different types without rewriting the code.

//Key Features of Templates...

//Code Reusability: Enables writing a single function or class to handle multiple data types.
//Type Independence : Allows functions and classes to work with any data type.
//Compile - time Type Checking : Ensures type safety while allowing flexibility.
//Supports Function and Class Templates : Templates can be used for functions and entire class structures.
//Template Specialization : Allows defining custom behavior for specific data types.

//When to Use Templates...

//When writing functions or classes that should work with multiple data types.
//When avoiding redundant code for similar operations on different types.
//In generic programming, such as implementing containers(vector, map, etc.).

//When Not to Use Templates...

//When specific type handling is required.
//When code clarity is more important than flexibility.
//When dealing with complex inheritance hierarchies.

//Note:- we can't use template <string str> before c++ 20 versions but we can use it from version c++ 20.
//From C++20, string_view can be used as a non-type template parameter: with header #include<string_view>
//template <const char* str> we can use this before c++ 20 version behalf of string ///
//function template
template <typename T>
T sum(T x, T y) {
    return (x+y);
}

//class template
template <typename T>
class Example{
private:
    T a;
public:
    Example(T v) : a(v) {}
    void display() {
        cout << "a=  " << a << endl;
    }
};

//...template specialization...

//Template specialization in C++ allows customizing template behavior for specific types.
//It provides a mechanism to define an alternative implementation of a template when a particular type or set of types is used.

//When to Use Template Specialization...

//When a specific type requires different behavior than the generic template.
//When optimizing performance for certain types.
//When integrating with third - party libraries that require different implementations for different types.

//Types of Template Specialization...

//Full Specialization : Provides a completely customized implementation for a specific type.
//Partial Specialization : Allows customizing a subset of template parameters while keeping others generic.

//Full Specialization...

//In full specialization, a completely new definition of the template is provided for a specific type.


// Generic template
template <typename T>
class FullSpecialization{
public:
    void show(){
        cout << "generic template" << endl;
    }
};

// Full specialization for `int`
template <>
class FullSpecialization<int>{
public:
    void show(){
        cout << "specialized template for int" << endl;
    }
};

//Partial Specialization...

//Partial specialization allows customizing a subset of template parameters while keeping others generic.

// Generic template
template <typename T1, typename T2>
class PartialSpecialization{
public:
    void show(){
        cout << "generic template" << endl;
    }
};

// Partial specialization where the first type is `int`
template <typename T2>
class PartialSpecialization<int, T2>{
public:
    void show() {
        cout << "partial specialization where first type is int" << endl;
    }
};


int main() {
    cout << "sum of integers: " << sum(5, 10) << endl;
    cout << "sum of doubles: " << sum(3.5, 2.7) << endl;

    Example<int> e1(10);
    Example<double> e2(15.32);

    e1.display();
    e2.display();

    //Full specialization
    FullSpecialization<double> ex1;
    ex1.show(); // Calls generic template
    FullSpecialization<int> ex2;
    ex2.show(); // Calls specialized template for int

    //Partial specialization
    PartialSpecialization<double, char> exam1;
    exam1.show(); // Calls generic template
    PartialSpecialization<int, char> exam2;
    exam2.show(); // Calls partially specialized template

    return 0;
}
