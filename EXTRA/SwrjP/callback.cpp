//What is a Callback Function?
/* A callback function is a function passed as an argument to
 another function. The receiving function has the ability to 
 "call back" (invoke) the callback function at a specific point 
 during its execution.\
*/



// Callback Function can be implemented using function pointers, functors,
//lamdda functions, std::function.


//1.   Using Function Pointers -> Function pointers store the address of a function
// and can be passed around to invoke the function indirectly.


//#include <iostream>
//using namespace std;

// Define a callback function

//void myCallback(int value) {
//    cout << "Callback with value: " << value << endl;
//}
//
//// Generic function accepting a callback
//void performOperation(void (*callback)(int), int data) {
//    cout << "Performing operation..." << endl;
//    callback(data);  // Invoke the callback
//}
//
//int main() {
//    performOperation(myCallback, 10); // Pass the callback function
//    return 0;
//}


// 2. Using Functors(FUnction Objects)
//    A functor (function object) in C++ is a class or struct that acts 
//    like a function because it overloads the () (function call) operator. 
//    This unique ability allows objects of that class to be invoked as if they were a function.

//    Functors are better than function pointers because they allow encapsulation
//    of state and provide greater flexibility.

/*
#include <iostream>
using namespace std;

// Define a functor (function object)
class MyFunctor {
public:
    void operator()(int a) const {
        cout << "Functor called with value: " << a << endl;
    }
};

void performCallback(MyFunctor callback, int value) {
    callback(value); // Use the functor
}

int main() {
    MyFunctor functor;
    performCallback(functor, 20);
    return 0;
}
*/

// 3. Using Lambda Functions -> Lambda functions provide an inline, anonymous function definition.


//#include <iostream>
//#include <functional> // Required to use std::function
//
//using namespace std;
//
//// 1. Function that accepts a callback (function) and a value
//void executeCallback(const function<void(int)>& callback, int value) {
//    cout << "Inside executeCallback function..." << endl;
//
//    // 2. Call the callback function with the value
//    callback(value);
//}
//
//// 3. Main function
//int main() {
//    // 4. Define and pass a lambda as the callback
//    executeCallback([](int x) {
//        cout << "Lambda callback executed with value: " << x << endl;
//        }, 42);  // 5. Pass lambda and value 42
//
//    return 0;
//}


//std::function is a versatile mechanism to store callable objects,
// including regular functions, lambdas, and functors.



// Why do we need Callback functions?
//1. Modularity and Flexibility
//2. Event-Driven Programming
//3. Asynchronous Operations
