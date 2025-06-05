// Why Move Semantics?
/* 
=> Eliminate unnecessary copying in c++ to boost speed and efficiency.
=> Improve Performance especially when handling large and complex objects by enabling the transfer of resources rather than costly duplication.

=>this all achieved through Lvalue ,Rvalue ,Rvalue Reference and the utility function std::move.


//Introduction...

//In C++, move semantics is a feature introduced in C++11 that allows resources to be efficiently transferred from one object to another, instead of copying them.
//This is particularly useful for expensive operations like managing dynamic memory, file handles, or other system resources.
//Allow us to avoid unnecessary copy of objects when working with temporary object.

//Why Move Semantics?

//When an object is copied, a deep copy is typically performed, which means duplicating all resources.However,
//in some cases(like returning objects from functions), creating a copy is wasteful.Move semantics allows transferring ownership of resources instead of duplicating them.

//When are Move Semantics Used ?

//Returning objects from functions(avoid unnecessary copies).
//When passing temporary objects.
//Optimizing large data structures like vectors, strings, etc.


Copy & Move Semantics : -

*Copy is implemented through copy constructor
* Copy of the object state is created
* Wasteful in case copy is created from a temporary
* Instead, the state can be moved from the source object
* Implemented through move semantics

Resource Management :-
   * Some classes own a resource
   * This resource may be a pointer, file handle, socket, etc.
   * Such resources may be acquired in the constructor
   * Subsequently, you have to decide the action in case objects of such classes are copied, moved or destroyed
   * E.g. on destruction, the resource must be released to avoid leaks
   * Similarly, on copy or move the resource must be handled accordingly
*/

//Move Constructor and Move Copy Assignment...

//#include <iostream>
//using namespace std;
//
//class A {
//private:
//    int* ptrArr;
//public:
//    A() : ptrArr(new int[5]) {
//        for (int i = 0; i < 5; ++i) {
//            ptrArr[i] = i + 1;
//        }
//        cout << "default constructor called" << endl;
//    }
//
//    // Copy Constructor (Deep Copy)
//    A(const A& other) : ptrArr(new int[5]) {
//        cout << "copy constructor called" << endl;
//        for (int i = 0; i < 5; ++i) {
//            this->ptrArr[i] = other.ptrArr[i];
//        }
//    }
//
//    // Move Copy Constructor
//    A(A&& other) noexcept : ptrArr(other.ptrArr) {
//        cout << "move constructor called" << endl;
//        other.ptrArr = nullptr; // Transfer ownership
//    }
//
//    // Copy Assignment Operator
//    A& operator=(const A& other) {
//        cout << "Copy Assignment Overload" << endl;
//        if (this != &other) {
//            delete[] ptrArr;
//            this->ptrArr = new int[5];
//            for (int i = 0; i < 5; ++i) {
//                ptrArr[i] = other.ptrArr[i];
//            }
//        }
//        return *this;
//    }
//
//    // Move Assignment Operator
//    //noexcept defines that function can't throw error
//    A& operator=(A&& other) noexcept {
//        cout << "Move Assignment Overload" << endl;
//        if (this != &other) {
//            delete[] ptrArr;
//            this->ptrArr = other.ptrArr;
//            other.ptrArr = nullptr;
//        }
//        return *this;
//    }
//
//    void display() {
//        cout << "print call" << endl;
//        for (int i = 0; i < 5; ++i) {
//            cout << ptrArr[i] << " ";
//        }
//        cout << endl;
//        cout << endl;
//    }
//
//    virtual ~A() {
//        delete[] ptrArr;
//        cout << "destructor is called" << endl;
//    }
//};
//
//int main() {
//    A a;
//    a.display();
//
//    // Copy constructor
//    A b = a;
//    b.display();
//
//    // Move constructor
//    A c = std::move(b);
//    c.display();
//    //b.display();
//
//    A d;
//    //Copy Assignment
//    d = a;
//    d.display();
//
//    A e;
//    // Move copy assignment
//    e = std::move(a);
//    e.display();
//}



//move constructor with vector reallocation or resizing. 

//#include <iostream>
//#include <vector>
//
//class MyClass {
//public:
//    int* data;
//
//    MyClass(int val) {
//        data = new int(val);
//        std::cout << "Constructor: " << *data << std::endl;
//    }
//
//    // Copy constructor
//    MyClass(const MyClass& other) {
//        if(other.data!=nullptr) //********************
//        data = new int(*other.data); 
//        std::cout << "Copy Constructor: " << *data << std::endl;
//    }
//
//    // Move constructor
//    MyClass(MyClass&& other) noexcept {
//        data = other.data;
//        other.data = nullptr;
//        std::cout << "Move Constructor\n";
//    }
//
//    ~MyClass() {
//        if (data) {
//            std::cout << "Destructor: " << *data << std::endl;
//            delete data;
//        }
//    }
//};
//
//int main() {
//    std::vector<MyClass> vec;
//
//    vec.reserve(2);  // Avoid reallocation for first 2
//    vec.push_back(MyClass(1));
//    vec.push_back(MyClass(2));
//
//    std::cout << "--- Triggering Reallocation ---\n";
//    vec.push_back(MyClass(3)); // Causes reallocation, moves/copies objects
//
//    return 0;
//}
//// If we did not use noexcept in our move constructor then we can see that order of destructors are not deallocating in reverse order of object creation due to vector implementation and it varies compiler to compiler.


