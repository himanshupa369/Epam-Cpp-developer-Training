//...Lambda Function...

// Lambda functions in C++ (introduced in C++11) are anonymous functions that can be defined inline.
// They allow you to write short function - like expressions without formally defining a separate function.

//Syntax of Lambda Functions in C++...
//[ capture_list ] ( parameter_list ) -> return_type { function_body }
//Components:
//Capture list([]) : Specifies which variables from the surrounding scope can be accessed.
//Parameter list(()) : Defines the function parameters.
//Return type(->type) : Specifies the return type(optional, deduced automatically if omitted).
//Function body({}) : Contains the logic.

//2. Capture List in Lambda Functions
//The capture list determines how variables from the surrounding scope are accessed inside the lambda.

// Capture Method	                         Syntax                	Description
// Capture by Value                           [x]	     Captures x by value(creates a copy).
// Capture by Reference                       [&x]	     Captures x by reference(modifies original).
// Capture All by Value                       [=]	     Captures all local variables by value.
// Capture All by Reference                   [&]	     Captures all local variables by reference.
// Mixed Capture                              [x, &y]	 Captures x by value and y by reference.

// Advantages of Lambda Functions...

//✅ Shorter Code – Avoids writing separate function definitions.
//✅ Improved Readability – More concise and easier to understand.
//✅ Encapsulation – Keeps logic closer to where it’s used.
//✅ Higher - Order Functions – Allows functions to be passed as arguments easily.
//✅ Better Performance – Inline lambdas avoid function call overhead.

// Disadvantages of Lambda Functions...

//❌ A lambda cannot return a reference to a local variable because the variable goes out of scope when the lambda exits.
//❌ Complexity in Debugging – Debugging can be harder for complex lambda expressions.
//❌ Limited Reusability – Unlike named functions, lambdas are harder to reuse.
//❌ Verbose Syntax – Can become confusing with complicated captures and return types.
/*auto lambda = [](bool flag) {
    if (flag)
        return 10;   // int
    else
        return 3.14; // double (Error!)
};

std::cout << lambda(true);
*/

/*auto lambda = [](bool flag) -> double {
    if (flag)
        return 10;   // Implicitly converted to double
    else
        return 3.14;
};
*/

//❌ Lambdas without a capture list ([]) can be converted to function pointers, but lambdas with captures ([x]) cannot.
//❌ Since lambdas are often short-lived, dynamically allocated memory inside a lambda must be properly released, or memory leaks will occur.
// ✅ Fix: Use delete or smart pointers (std::unique_ptr).
//❌ std:: function issues
//❌ mutable issues with lambda function
/*int x = 10;
wrong way...
auto lambda = [x]() { x = 20; };  // ❌ Compilation error
correct way...
auto lambda = [x]() mutable { x = 20; };*/


//  Use Cases of Lambda Functions...

//✅ 1. Sorting with Custom Comparator Eg.:- sort(nums.begin(), nums.end(), [](int a, int b) { return a > b; });
//✅ 2. Using Lambdas in std::for_each Eg.:- for_each(nums.begin(), nums.end(), [](int x) { std::cout << x * x << " "; });
//✅ 3. Callbacks in Multithreading (std::thread).
//✅ 4. Capturing External Variables.
/*#include <iostream>

int main() {
    int a = 5, b = 10;
    auto multiply = [a, b]() { return a * b; };
    std::cout << multiply() << std::endl; // 50
} */

//✅ 5. Filtering in STL Algorithms.

#include <iostream>
using namespace std;

int main() {
    int x = 10, y = 20;

    // Capture by value
    auto lambda1 = [=]() { return x + y; };

    // Capture by reference
    auto lambda2 = [&]() { x++; y += x; };
    lambda1();
    cout << "After Lambda_1 Call x: " << x <<" y: " <<y<< endl;
    lambda2();
    cout << "After Lambda_2 Call x: " << x << " y: " << y << endl;
    return 0;
}
