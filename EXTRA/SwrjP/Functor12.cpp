//What is functor
// A functor (function object) in C++ is a class or struct that acts like
// a function because it overloads the () (function call) operator. 
// This unique ability allows objects of that class to be invoked as if they were a function.


// Why do we need functors
//1. Encapsulation
//2. Maintainability
//3. Reusability
//4. Type Safety
//5. INtegration with c++ Standard Libraries(STL)


//1.Simple Functor Example

//#include<iostream>
//using namespace std;
//
//class FunctorClass {
//public:
//	void operator()(int x)const {
//		cout << "My Functor Called with " << x << endl;
//	}
//};
//
//int main() {
//	FunctorClass f1;
//	f1(10);
//	return 0;
//}

//2. Functor Holding state -> Fucntor can hold internal state, which make 
// them more powerful than plain function

//#include <iostream>
//using namespace std;
//
//class MultiplyBy {
//private:
//    int multiplier;      // State stored in the functor
//public:
//    MultiplyBy(int factor) : multiplier(factor) {}  // Constructor to initialize state
//
//    int operator()(int x) const {
//        return x * multiplier;  // Use the stored state for calculations
//    }
//};
//
//int main() {
//    MultiplyBy timesThree(3);   // Functor to multiply by 3
//    cout << timesThree(5) << endl;  // Output: 15
//    return 0;
//}


//3. functors with STL algorithms -> FUnctors works seamlessly with STL function
// like sort and transform

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//class Compare {
//public:
//	bool operator()(int a, int b)const {
//		return a > b;
//	}
//};
//
//int main() {
//	vector<int> v1{ 1,6,2,8 };
//	sort(v1.begin(), v1.end(), Compare());
//	for (auto& it : v1) {
//		cout << it << " ";
//	}
//	return 0;
//}


// Key differences between Function Pointers and Functors(Function object)

// Function pointers							Functors
// 1. cannot store state						1. can store state using class member variables
// 2. Harder to reuse across complex systems	2. Highly usauble with STL and other algorithms
// 3. Lightweight and simple					3. Minor overhead but offers richer functionality
// 4. Prone to type mismatches or incorrect     4. More type safe and integrated with C++ frameworks
//    casts

// Advantages of Functors

//1. State Management 

//2. Readable Code 

//3. STL Compatibility 

//4. Extensibility 

//5. Efficiency



// What is type Safe 
// Type Safe means -> You are ensuring that only correct and expected data types 
// are used with your code, and any type mismatch is caught at compile time rather than causing runtime bugs.


// Example to understand type safety
//#include <iostream>
//#include <type_traits>
//using namespace std;

// Type-safe functor
//template <typename T>
//class SafeMultiplier {
//    static_assert(std::is_arithmetic<T>::value, "SafeMultiplier requires an arithmetic type.");
//private:
//    T multiplier;
//public:
//    SafeMultiplier(T factor) : multiplier(factor) {}
//
//    T operator()(T x) const {
//        return x * multiplier;
//    }
//};
//
//int main() {
//    SafeMultiplier<int> timesTwo(2);
//    cout << "2 * 5 = " << timesTwo(5) << endl;
//
//    SafeMultiplier<double> timesPi(3.14);
//    cout << "3.14 * 2.5 = " << timesPi(2.5) << endl;
//
//    // SafeMultiplier<string> badType("abc"); // ❌ Compile-time error: not arithmetic
//    return 0;
//}

// static assert(..) -> this ensures type safety at compile time
// std::is_arithmetic<T>::value checks if T is an arithmetic type (int, float, double, etc.).
// IF not , the program won't compile and fives a clear error message 

//Why this matters -> Prevents bugs at compile time , not at runtime
