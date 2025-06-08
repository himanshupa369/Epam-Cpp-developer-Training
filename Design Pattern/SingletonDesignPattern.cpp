/*
Singleton Design Pattern :- 

The Singleton method or Singleton Design pattern is one of the simplest design patterns.
It ensures a class only has one instance, and provides a global point of access to it.

Singleton Design Pattern Principles:-

Below are the principles of the Singleton Pattern:
A) Single Instance: Singleton ensures that only one instance of the class exists throughout the application.
B) Global Access: Provide a global point of access to that instance.
C) Lazy or Eager Initialization: Support creating the instance either when needed (lazy) or when the class is loaded (eager).
D) Thread Safety: Implement mechanisms to prevent multiple threads from creating separate instances simultaneously.
E) Private Constructor: Restrict direct instantiation by making the constructor private, forcing the use of the access point

Initialization Types of Singleton:-

A) Early initialization : In this method, class is initialized whether it is to be used or not.
B) Lazy initialization  : In this method, class in initialized only when it is required.

| Feature              | Eager Initialization      | Lazy Initialization            |
| -------------------- | ------------------------- | ------------------------------ |
| **When initialized** | Immediately               | On first use                   |
| **Performance**      | May waste resources early | More efficient for unused data |
| **Implementation**   | Simple                    | Slightly more complex          |
| **Thread Safety**    | Easier                    | Requires care in multithreaded |


*/

#include <iostream>
using namespace std;

class Singleton {
private:
   // Private constructor
   Singleton() {
       cout << "Singleton instance created\n";
   }

   // Delete copy constructor and assignment operator
   Singleton(const Singleton&) = delete;
   Singleton& operator=(const Singleton&) = delete;

   // Static instance pointer
   static Singleton* instance;

public:
   // Public method to get the instance
   static Singleton* getInstance() {
       if (instance == nullptr) {
           instance = new Singleton();
       }
       return instance;
   }

   void showMessage() {
       cout << "Hello from Singleton!" << endl;
   }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

// Usage
int main() {
   Singleton* s1 = Singleton::getInstance();
   s1->showMessage();

   Singleton* s2 = Singleton::getInstance();
   s2->showMessage();

   // Confirm both are same instance
   cout << "Same instance? " << (s1 == s2 ? "Yes" : "No") << endl;

   return 0;
}
