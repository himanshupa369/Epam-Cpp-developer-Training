//Move Constructor and Move Copy Assignment...

#include <iostream>
using namespace std;

class A {
private:
   int* ptrArr;
public:
   A() : ptrArr(new int[5]) {
       for (int i = 0; i < 5; ++i) {
           ptrArr[i] = i + 1;  
       }
       cout << "default constructor called" << endl;
   }

   // Copy Constructor (Deep Copy)
   A(const A& other) : ptrArr(new int[5]) {
       cout << "copy constructor called" << endl;
       for (int i = 0; i < 5; ++i) {
           this->ptrArr[i] = other.ptrArr[i];
       }
   }

   // Move Constructor
   A(A&& other) noexcept : ptrArr(other.ptrArr) {
       cout << "move constructor called" << endl;
       other.ptrArr = nullptr; // Transfer ownership
   }

   // Copy Assignment Operator
   A& operator=(const A& other) {
       cout << "Copy Assignment Overload" << endl;
       if (this != &other) {
           delete[] ptrArr;
           this->ptrArr = new int[5];
           for (int i = 0; i < 5; ++i) {
               ptrArr[i] = other.ptrArr[i];
           }
       }
       return *this;
   }

   // Move Assignment Operator
   //noexcept defines that function can't throw error
   A& operator=(A&& other) noexcept{
       cout << "Move Assignment Overload" << endl;
       if (this != &other) {
           delete[] ptrArr;
           this->ptrArr = other.ptrArr;
           other.ptrArr = nullptr;
       }
       return *this;
   }

   void display() {
       cout << "print call" << endl;
       for (int i = 0; i < 5; ++i) {
           cout << ptrArr[i] << " ";
       }
       cout << endl;
       cout << endl;
   }

   virtual ~A() {
       delete[] ptrArr; 
       cout << "destructor is called" << endl;
   }
};

int main() {
   A a; 
   a.display();

  // Copy constructor
   A b = a; 
   b.display();

  // Move constructor
   A c = move(b); 
   c.display();
   //b.display();

   A d;
   //Copy Assignment
   d = a;
   d.display();

   A e;
   // Move copy assignment
   e = move(a);
   e.display();
}
