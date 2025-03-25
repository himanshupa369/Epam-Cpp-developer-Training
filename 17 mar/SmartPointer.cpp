#include <iostream>
#include <memory> // For smart pointers
#include<cstdio>
using namespace std;

class backend;
class frontend {
    weak_ptr<backend> bPtr;
public:
    frontend() {
        cout << "Frontend Constructor Invoked:" << endl;
    }
    ~frontend() {
        cout << "Inside Frontend use count: " << bPtr.use_count() << endl;
        cout << "Frontend destructor Invoked:" << endl;
    }
    void setBackEnd(shared_ptr<backend>& bPtr1) {
        bPtr = bPtr1;
        cout << "within function" << endl;
    }

};
class backend {
    shared_ptr<frontend> fPtr;
public:
    backend(shared_ptr<frontend> &fPtr1) {
        cout << "backend Constructor Invoked:" << endl;
        fPtr = fPtr1;
    }
    ~backend() {
        cout << "Inside backend use count: " << fPtr.use_count() << endl;
        cout << "backend destructor Invoked:" << endl;
    }
};

//Custom deleter...

// A custom deleter allows us to control how objects are destroyed.
//shared_ptr calls delete instead of delete[], which leads to undefined behavior when managing an array.
//❌ Incorrect usage:
//shared_ptr<int> sp(new int[10]);  // ❌ WRONG: Calls `delete` instead of `delete[]`
//✅ Solution : Use std::shared_ptr<int[]> or custom deleter.
//shared_ptr<int> sp(new int[10], [](int* p) { delete[] p; });  // ✅ Custom deleter

struct FileCustomDeleter{
    void operator()(FILE* file) {
        if (file) {
            fclose(file);
            cout << "File closed successfully.\n";
        }
    }
};


class Smartptr {
    int* intPtr;
public:
    Smartptr(int* ptrVal) {
        cout << "Creation of Smartptr:" << endl;
        intPtr = ptrVal;
    }
    ~Smartptr() {
        cout << "Deallocation of memory:" << endl;
        if(intPtr)
        delete intPtr;
    }
    int& operator*(){
        cout << "Inside operator*():" << endl;
        return *intPtr;
    }
    int* operator -> (){
        cout << "Inside operator->():" << endl;
        return intPtr;
    }
    void swaraj() {
        cout << "swaraj wants swarajya:" << endl;
    }
};

class Sample {
public:
    void func() {
        cout << "this is a function:" << endl;
    }
};
class A {
public:
    A() {
        cout << "Constructor invoked" << endl;
    }
    ~A() {
        cout << "Destructor invoked" << endl;
    }
};

int main() {
    // cycle redundancy problem 
    shared_ptr<frontend> fPtr1 = make_shared<frontend>();
    cout << "Frontend use count:" << fPtr1.use_count() << endl;
    //cout << "Backend use count:" << bPtr1.use_count() << endl;
    shared_ptr<backend> bPtr1 = make_shared<backend>(fPtr1);
    fPtr1->setBackEnd(bPtr1);
    cout << "Frontend use count:" << fPtr1.use_count() << endl;
    cout << "backend use count:" << bPtr1.use_count() << endl;
    cout << endl;

    FILE* filePtr = nullptr;
    if (fopen_s(&filePtr, "example.txt", "w") != 0) {  // fopen_s safer version
        cerr << "Failed to open file.\n";
        return 1;
    }

    shared_ptr<FILE> file(filePtr, FileCustomDeleter());  // `shared_ptr` manages FILE*

    //int a = 5;
    //int* p = &a;
    //Smartptr sm1(p);
    ////Smartptr *sm2 = new Smartptr(p);
    //unique_ptr<Smartptr> uuptr = make_unique<Smartptr>(p);
    int* ptr = new int(52);
    Smartptr sm(ptr);
    cout << *sm << endl;
    Smartptr* sm2 = new Smartptr(new int(23));
    sm2->swaraj();
    Sample* sm1 = new Sample();
    sm1->func();

    // UNIQUE POINTER DEMO
    /*...Since unique_ptr follows exclusive ownership, it does not allow copying.
    That means both the copy constructor and copy assignment operator are deleted...*/
    /*1️) unique_ptr(Exclusive Ownership)
     🟢 When to Use :
        When you own a resource and want sole ownership.
        To prevent accidental copies and ensure automatic deallocation.
        For RAII(Resource Acquisition Is Initialization).

    🚀 Example Use Cases :
        Managing heap - allocated objects in a function or class.
        Implementing custom memory management(e.g., linked lists).
        Optimizing performance by avoiding reference counting.*/
    cout << "\n--- Unique Pointer Demo ---" << endl;
    unique_ptr<int> uPtr1 = make_unique<int>(25); // Allocating memory for an integer with value 25

    // Move ownership from uPtr1 to uPtr2
    unique_ptr<int> uPtr2 = move(uPtr1);

    if (uPtr1 == nullptr) {
        cout << "uPtr1 is null (ownership transferred)" << endl;
    }

    // Reset uPtr1 to a new integer value
    uPtr1.reset(new int(5));
    cout << "uPtr1 now points to: " << *uPtr1 << endl;
    cout << "uPtr2 points to: " << *uPtr2 << endl;

    // Unique pointer with a class
    {
        unique_ptr<A> classPtr = make_unique<A>(); // Constructor called here
    } // Destructor called when classPtr goes out of scope

    unique_ptr<A> classPtr = make_unique<A>(); // Another instance of A

    // SHARED POINTER DEMO
    /*2️) shared_ptr(Shared Ownership)
    🟢 When to Use :
        When multiple parts of the code need access to the same resource.
        For dynamically allocated objects with shared lifetime.
        When copying should increase the reference count.
    🚀 Example Use Cases :
        Observer pattern(e.g., event listeners).
        Multithreading where multiple threads access shared data.
        Graph structures where multiple nodes share the same data.*/
    cout << "\n--- Shared Pointer Demo ---" << endl;
    shared_ptr<A> sPtr = make_shared<A>();
    cout << "Shared Count: " << sPtr.use_count() << endl;
    {
        shared_ptr<A> sPtr2 = sPtr; // Shared ownership
        cout << "Shared Count (inside block): " << sPtr.use_count() << endl;
    } // sPtr2 goes out of scope, decreasing the count
    cout << "Shared Count (after block): " << sPtr.use_count() << endl;

    // WEAK POINTER DEMO
    /*3)weak_ptr(Non - Owning Observer)
    🟢 When to Use :

        To break cyclic dependencies in shared_ptr.
        When an object needs to observe another without affecting its lifetime.
        In cache systems where objects should expire if not used.
    🚀 Example Use Cases :

        Parent - child relationships(e.g., GUI tree structures).
        Event listeners that shouldn't keep the subject alive.
        Avoiding memory leaks in shared_ptr cycles.*/
    cout << "\n--- Weak Pointer Demo ---" << endl;
    weak_ptr<int> wPtr;
    {
        shared_ptr<int> sPtr3 = make_shared<int>(6);
        wPtr = sPtr3; // weak_ptr references sPtr3 but does not increase the count
        cout << "Use count of shared_ptr: " << sPtr3.use_count() << endl;
        if (auto tempPtr = wPtr.lock()) { // Locking weak_ptr to get a shared_ptr
            cout << "Weak Pointer successfully locked: " << *tempPtr << endl;
        }
    } // sPtr3 goes out of scope here

    if (wPtr.expired()) {
        cout << "Weak pointer is expired, resource is deleted" << endl;
    }

    system("pause>null"); // Prevents console from closing immediately
}
