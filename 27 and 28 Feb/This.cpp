/* this Pointer */

//The this pointer is an implicit pointer available in all non - static member functions.
//It points to the calling object of the member function.
//It is used to differentiate between instance variables and parameters when they have the same name.

//Why this pointer is not used on static variables ?

//Static variables belong to the class, not to any specific object.
//The this pointer is associated with an instance of the class, whereas static members exist independently of any instance.
//Thus, this pointer cannot be used with static members.

//The this pointer facilitates method chaining by allowing member functions to return a reference to the current object(*this),
//enabling the calling of multiple methods on the same object in a single statement.

#include <iostream>
using namespace std;

class This{
private:
   int x;

public:
   This(int x) {
       // `this->x` refers to the class member, `x` refers to the constructor argument
       this->x = x;
   }

   void Display() {
       cout << "Value of x: " << this->x << endl;
   }
   void Del() {
       cout << "object is deleted" << endl;
       delete this;
   }
};

int main() {
   This obj(10);
   obj.Display();
   //obj.Del();
   return 0;
}
