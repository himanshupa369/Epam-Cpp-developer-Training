// A variadic template is a template that accepts a variable number of arguments. 
// It allows defining functions or classes that can operate on multiple arguments without specifying their exact number.

// Key Concepts:
// Introduced in C++11.
// Uses ... (ellipsis) to represent parameter packs.
// Works for both functions and classes.
// Uses recursion or fold expressions for processing arguments.

// 1.Function Variadic Template
// A function variadic template allows a function to accept an arbitrary number of parameters.
// #include <iostream>
// using namespace std;

// // Base Case: End of recursion
// void print() {
//     cout << "No more arguments\n";
// }

// // Variadic template function
// template<typename T, typename... Args>
// void print(T first, Args... rest) {
//     cout << first << " ";  // Print first argument
//     print(rest...);        // Recursively call with remaining arguments
// }

// int main() {
//     print(1, "hello", 3.14, 'A');
//     return 0;
// }



// 2. Class Variadic Template...
//A class variadic template allows a class to accept multiple template parameters.
// #include <iostream>
// using namespace std;

// // Variadic template class
// template<typename... Args>
// class MyClass;

// // Specialization for handling the first type
// template<typename First, typename... Rest>
// class MyClass<First, Rest...> {
// public:
//     First value;
//     MyClass<Rest...> next;  // Recursively instantiate the rest

//     MyClass(First v, Rest... rest) : value(v), next(rest...) {}

//     void print() {
//         cout << value << " ";
//         next.print();
//     }
// };

// // Base Case: Empty class specialization
// template<>
// class MyClass<> {
// public:
//     void print() {} // Base case does nothing
// };

// int main() {
//     MyClass<int, string, double> obj(10, "hello", 3.14);
//     obj.print();
//     return 0;
// }


// 3. Using Fold Expressions (C++17)
// Instead of recursion, C++17 introduced fold expressions to simplify variadic template processing.

// #include <iostream>
// using namespace std;

// template<typename... Args>
// auto sum(Args... args) {
//     return (args + ...);  // Fold expression
// }

// int main() {
//     cout << sum(1, 2, 3, 4, 5) << endl;  // Output: 15
//     return 0;
// }

    
#include <iostream>
// Variadic class template
template <typename... Types>
class DataHolder {};

// Specialization for at least one argument
template <typename FirstType, typename... OtherTypes>
class DataHolder<FirstType, OtherTypes...> {
public:
    FirstType value;
    DataHolder<OtherTypes...> next;

    DataHolder(FirstType val, OtherTypes... rest) : value(val), next(rest...) {}

    void display() {
        std::cout << value << " ";
        next.display();
    }
};

// Base case specialization
template <>
class DataHolder<> {
public:
    void display() {}
};

int main() {
    DataHolder<std::string, float, int> dh("Hello", 3.14, 42);
    dh.display();  // Output: Hello 3.14 42
    return 0;
}
