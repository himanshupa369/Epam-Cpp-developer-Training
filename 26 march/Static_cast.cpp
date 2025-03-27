//... static cast ...

/* static_cast is a type of casting operator in C++ that is used for compile-time type conversion. 
It is safer and more explicit than C-style casting ((type)value).*/

// Key Features of static_cast:

//✔ Used for converting between related types(like int to float, double to int, pointer conversions, etc.).
//✔ Performed at compile time(does not involve runtime checks).
//✔ Safer than C - style casting but does not check for correctness at runtime.
//✔ Cannot be used for converting between completely unrelated types(e.g., int to std::string).

// When NOT to Use static_cast
//❌ Between unrelated types(e.g., int to std::string).
//❌ If you need runtime safety(use dynamic_cast for polymorphic types).
//❌ For casting away const (use const_cast).

#include <iostream>
using namespace std;

class Base {};
class Derived : public Base {};

enum Color { RED, GREEN, BLUE };

int main() {

   //Basic Type Conversion (Primitive Types)
   double pi = 3.14159;
   int intPi = static_cast<int>(pi); // Explicit conversion (float to int)
   cout << "Integer value: " << intPi << endl; // Output: 3


   // Pointer Type Conversion (Base to Derived and Vice Versa)
   Derived d;
   Base* basePtr = static_cast<Base*>(&d);  // Derived* → Base* 
   Derived* derivedPtr = static_cast<Derived*>(basePtr); // Base* → Derived* 


   //Enum to Integer Conversion

   Color c = GREEN;
   int colorValue = static_cast<int>(c); // Enum to int conversion
   cout << "Enum value: " << colorValue << endl; // Output: 1

   return 0;
}
