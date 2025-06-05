//L value and R value
/*
| **Feature * *        | **L - value  Locator* *                                    | **R - value * *                                 |
| ------------------ - | ------------------------------------------------ - | -------------------------------------------- -  |
| **Name * *           | Has a name                                         | Does not have a name                            |
| **Variable Type * *  | All variables are L - values                       | R - value is a temporary value                  |
| **Assignment * *     | Can be assigned values                             | Cannot be assigned values                       |
| **Expressions * *    | Some expressions return L - values                 | Some expressions return R - values              |
| **Persistence * *    | Persists beyond the expression                     | Does not persist beyond the expression          |
| **Function Return * *| Functions that return by reference return L - value| Functions that return by value return R - value |
| **Reference Type * * | Reference to L - value(L - value reference)        | Reference to R - value(R - value reference)     |

//R- value reference

| **Feature**                | **Description**                               |
| -------------------------- | --------------------------------------------- |
| **Definition**             | A reference created to a temporary            |
| **Represents**             | A temporary value                             |
| **Syntax**                 | Created with `&&` operator                    |
| **Can Bind To**            | Only R-values (temporaries)                   |
| **Cannot Bind To**         | L-values                                      |
| **Binding Rule**           | R-value references always bind to temporaries |
| **L-value Reference Rule** | L-value references (&) always bind to L-values    |

int&& ref=5+3
int& ref1=x;
*/

//#include <iostream>
//
//// Returns r-value
//int Add(int x, int y) {
//    return x + y;
//}
//
//// Returns l-value
//int& Transform(int& x) {
//    x *= x;
//    return x;
//}
//
//// Print accepts l-value reference
//void Print(int& x) {
//    std::cout << "Lvalue : Print(int&)" << std::endl;
//}
//
//// Print accepts const l-value reference
//void Print(const int& x) {
//    std::cout << "Const Lvalue: Print(const int&)" << std::endl;
//}
//
// //Print accepts r-value reference
//void Print(int&& x) {
//    std::cout << "Rvalue : Print(int&&)" << std::endl;
//}
//
//int main() {
//    // x is an l-value
//    int x = 10;
//    int y=x;
//    int z=5+3;
//    // ref is an l-value reference
//    int& ref = x;
//
//    // Transform returns an l-value
//    int& ref2 = Transform(x);
//
//    // rv is an r-value reference
//    int&& rv = 8;
//
//    // Add returns a temporary (r-value)
//    int&& rv2 = Add(3, 5);
//
//    // The following lines would cause an error because an l-value cannot bind to an r-value reference
//     /*int var = 0;
//     int &&r1 = var;*/
//
//    // But an l-value can bind to a const l-value reference
//    const int& r2 = 3;
//
//    // Function call demonstrations
//    int i = 10;
//    Print(i);                        // L-value
//    Print(10);                       // R-value
//    Print(std::move(i));            // move() converts l-value into r-value
//    Print(static_cast<int&&>(i));   // Explicit cast to r-value reference
//    //Note:- static_cast and move both perform same operation ,
//    //But we use it most of the time as move just avoid ambiguity and increase readability.
// 
//
//    return 0;
//}