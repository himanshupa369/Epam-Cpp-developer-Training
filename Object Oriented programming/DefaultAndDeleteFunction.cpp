#include <iostream>
using namespace std;

// 👇 Class representing an integer wrapper
class Int {
private:
    int value;  // Holds the integer value

public:
    // ✅ Default constructor initializes value to 0
    Int() : value(0) {
        cout << "Int() - Default constructor called" << endl;
    }

    // ✅ Parameterized constructor
    Int(int a) : value(a) {
        cout << "Int(int a) - Parameterized constructor called" << endl;
    }

    // ✅ Default copy constructor
    // The compiler will generate the default copy constructor behavior
    Int(const Int&) = default;

    /*
    ❌ If we uncomment the line below, copy constructor is deleted,
       which will cause a compile-time error when copying is attempted.

    Int(const Int&) = delete;
    */

    // ✅ Sets value from an integer
    void SetVal(int x) {
        value = x;
    }

    /*
    ❌ If we uncomment the line below, it deletes the function overload 
       for float input — prevents implicit conversion from float to int.

    void SetVal(float fv) = delete;
    */

    // ✅ Displays the value
    void ShowVal() {
        cout << "value: " << value << endl;
    }
};

int main() {
    Int i1;             // Calls default constructor
    i1.SetVal(3);       // Sets integer value
    i1.ShowVal();       // Prints: value: 3

    i1.SetVal(3.3);     // Implicitly converts float to int (3), unless SetVal(float)=delete is used
    i1.ShowVal();       // Prints: value: 3

    Int i2(i1);         // Copy constructor is called — OK because it's defaulted
    return 0;
}
