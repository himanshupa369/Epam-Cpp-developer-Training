// Pitfalls/Limitation of lambdas

// 1.Limited Readability for Complex Lambdas
//  when a lambda implements complex logic or spans multiple lines, 
// its inline definition can hurt readability

//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main() {
//    std::vector<int> numbers = { 10, 5, 3, 8, 15 };
//
//    // Complex lambda with multiple conditions inside
//    auto complexLambda = [](int a, int b) {
//        if (a % 2 == b % 2) {  // Same parity (both even or both odd)
//            return a < b;      // Sort in ascending order
//        }
//        else {
//            return (a % 2 == 0);  // Place even numbers before odd ones
//        }
//        };
//
//    std::sort(numbers.begin(), numbers.end(), complexLambda);
//
//    for (int num : numbers) {
//        std::cout << num << " ";
//    }
//    // Output: 8 10 3 5 15 (even numbers first, sorted, then odd numbers)
//    return 0;
//}

//->  the lambda’s complexity negatively impacts readability. 
// Solution -> we can use regular logic for complex logic


//2. Implicit Capture ([=] and [&]) Can Cause Bugs

// 1. [=](Capture by Value) : Copies variables.Changes to these variables inside the 
// lambda won't affect the original variables (and vice versa).
// 2. [&](Capture by Reference) : Modifies the original variables since they 
// are captured by reference.However, dangling references can occur if the lambda outlives the captured variables.


//Problem 1
//#include <iostream>

//int main() {
//    int x = 5;
//
//    // Capture x by value
//    auto lambdaByValue = [=]() mutable {
//        x += 10;  // Modifies the local copy inside the lambda, NOT the original x
//        std::cout << "Inside lambda (value): " << x << std::endl;  // Outputs 15
//        };
//
//    lambdaByValue();
//    std::cout << "Outside lambda: " << x << std::endl;  // Outputs 5 (unmodified original x)
//    return 0;
//}

//What is mutable?
//By default, when a lambda captures variables by value(e.g.[=]), 
// the captured variables are read - only inside the lambda body.
// If we want to modify the captured-by-value copy inside the lambda, 
// we must mark the lambda as mutable.

// Problem 2

//#include <iostream>
//#include <functional>
//
//std::function<void()> createLambda() {
//    int x = 100;
//    return [&]() {  // Captured by reference
//        std::cout << x << std::endl;
//        };  // `x` goes out of scope here, leading to dangling reference
//}
//
//int main() {
//    auto badLambda = createLambda();
//    badLambda();  // Undefined behavior (dangling reference)
//    return 0;
//}

// std::function<void()> is a type-erased wrapper that can store:
//A lambda(with or without captures)
//A function pointer
//A functor
//Any callable object that matches the signature

//Diagram of Memory
// Before return from createLambda()
/*
createLambda Stack Frame :
[x = 100]          ← Lambda refers to this
[lambda object]    ← Holds reference to x

main Stack Frame :
[badLambda ← copy of lambda]
*/

//After createLambda() returns
/*
createLambda Stack Frame : (gone)
[x = 100]   ❌ destroyed
[lambda]    ❌ invalid reference

main Stack Frame :
[badLambda ← lambda pointing to dead memory]
*/


//3. Cannot Be Forward Declared
// Solution -> Use std::function if you need a forward-declarable, 
// reusable callable object.

//#include <iostream>
//#include <functional>
//
//std::function<int(int, int)> someLambda;  // Allowed with std::function
//
//int main() {
//    someLambda = [](int a, int b) { return a + b; };
//    std::cout << "Sum: " << someLambda(3, 4) << std::endl;  // Output: Sum: 7
//    return 0;
//}


// 4. Copying Large State by Value

//#include <iostream>
//#include <vector>
//
//int main() {
//    std::vector<int> largeData(1000000, 42);  // Large vector
//
//    // Capturing by value creates a copy of largeData
//    auto inefficientLambda = [largeData]() {
//        std::cout << "Size of captured data: " << largeData.size() << std::endl;
//        };
//
//    inefficientLambda();  // Will create a large copy, wasting memory
//    return 0;
//}


//solution->
// auto efficientLambda = [&largeData]() {
//std::cout << "Size of captured data: " << largeData.size() << std::endl;
//};

// 5. No recursion

// This won't work for recursion:
//auto fibonacci = [](int n) {
//    if (n <= 1) return n;
//    return fibonacci(n - 1) + fibonacci(n - 2);  // ERROR: Can't refer to itself
//    };

//solution -> use regular function
