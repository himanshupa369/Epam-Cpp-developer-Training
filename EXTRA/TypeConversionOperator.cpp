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

✅ Two Main Ways to Convert User-Defined to User-Defined Types:-

    🔹 1. Conversion Constructor
    Defined in the target class, used to convert from another type.
    ******************************************************************************************************************
    class A {
public:
    int x;
    A(int val) : x(val) {}
};

class B {
public:
    int y;
    B(const A& a) { y = a.x; }  // Conversion constructor
};
   *********************************************************************************************************************
  usage:-
    A a(10);
    B b = a;  // A is converted to B using B's constructor
  ***********************************************************************************************************************
 🔹 2. Conversion Operator (Type Conversion Operator)
  Defined in the source class, used to convert to another type.
  ***********************************************************************************************************************
  class B;  // Forward declaration

class A {
public:
    int x;
    A(int val) : x(val) {}

    // Conversion operator to convert A → B
    operator B();
};

class B {
public:
    int y;
    B(int val) : y(val) {}
    void show() { cout << "B.y = " << y << endl; }
};

// Definition after B is fully declared
A::operator B() {
    return B(x);
}
***********************************************************************************************************************
Usage :-
A a(100);
B b = a;  // A is converted to B using A's conversion operator
b.show();

**********************************************************************************************************************

⚠️ Important Notes
-> For user-defined to user-defined:
  => You can either define a conversion constructor in the destination type or
  => A conversion operator in the source type.
-> If both are defined, the compiler picks the best match based on overload resolution.
-> Avoid circular conversions to prevent confusion or ambiguity.


