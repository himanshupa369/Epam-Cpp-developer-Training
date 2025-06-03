🔄 Type Conversion Operator in C++
The type conversion operator in C++ is a special operator function that allows you to convert an object of a user-defined class
to a basic (primitive) type or another user-defined type.

There is no argument and no return type.

🧱 Syntax
operator typename() const;

typename: The target type you want to convert to (e.g., int, float, etc.).
const: Optional but recommended if the conversion doesn't modify the object.

//Example :- 

#include <iostream>
using namespace std;

class Distance {
    int meters;

public:
    Distance(int m) : meters(m) {}

    // Conversion operator
    operator int() const {
        return meters;
    }
};

int main() {
    Distance d(10);
    int x = d;  // Conversion operator called here
    cout << "Distance in meters: " << x << endl;
    return 0;
}


🔄 Overloading for Other Types

You can create multiple conversion operators in the same class for different types:
class MyClass {
public:
    operator int() const { return 5; }
    operator float() const { return 5.5f; }
};
# Note: Only one implicit conversion is applied at a time in any expression.


⚠️ Best Practices & Warnings

=> Avoid overusing conversion operators—they can lead to unexpected conversions and bugs.
=> Prefer explicit operator (C++11 onwards) if you want to avoid implicit conversion:
   explicit operator int() const;
   and if you use explicit so it must to write your conversion :-
   int x=static_cast<int>(object); 
