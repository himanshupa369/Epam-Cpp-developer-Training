/* Recursive Template Instantiation */

//Introduction...

//Recursive template instantiation in C++ is a technique where templates call themselves with modified template parameters. 
//This is useful for implementing compile-time computations, type manipulations, and container operations.

//Key Features of Recursive Template Instantiation...

//Compile - time Computation : Enables calculations at compile time, reducing runtime overhead.
//Enables Metaprogramming : Useful in template metaprogramming techniques.
//Reduces Code Duplication : Avoids manual unrolling of loops and repetitive code.
//Base Case Requirement : Like recursive functions, recursive templates need a base case to stop instantiation.

//When to Use Recursive Template Instantiation...

//When performing compile - time computations(e.g., factorial, Fibonacci, power calculations).
//When implementing type transformations in template metaprogramming.
//When unrolling loops for performance optimizations.

//When to Avoid Recursive Templates...

//If the recursion depth is too large(can cause compiler recursion limit errors).
//When a runtime solution is more efficient(e.g., for large input values).

#include<iostream>
using namespace std;

//primary template (recursive case)
template<int N>
class Factorial {
public:
	static const int ans = N * Factorial<N - 1>::ans;
};

//Base case or termination case
template<>
class Factorial<0>{
public:
	static const int ans = 1;
};
template<>
class Factorial<1> {
public:
	static const int ans = 1;
};

int main() {
	static const int x=5;
	cout << "Factorial of Given Number: " << Factorial<x>::ans << endl;
}
