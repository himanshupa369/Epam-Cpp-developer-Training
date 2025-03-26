#include <iostream>
using namespace std;

/*
PIMPL (Pointer to IMPLementation) is a design pattern used to hide implementation details from the interface.
This reduces compilation dependencies and improves encapsulation.
Here, we use a forward-declared class and a unique pointer to manage the implementation.
*/

class SampleImpl;  // Forward declaration

class Sample {
private:
    SampleImpl* impl;  // Pointer to implementation

public:
    Sample();  // Constructor
    ~Sample(); // Destructor
    void func(); // Public function
};

// Implementation class (hidden from interface)
class SampleImpl {
public:
    void func() {
        cout << "This is a function:" << endl;
    }
};

// Implementation of Sample class methods
Sample::Sample() : impl(new SampleImpl()) {
    cout << "Sample instance created using PIMPL." << endl;
}

Sample::~Sample() {
    delete impl;
    cout << "Sample instance destroyed." << endl;
}

void Sample::func() {
    impl->func();
}

class Smartptr {
    Sample* intPtr;
public:
    Smartptr(Sample* ptrVal) {
        cout << "Creation of Smartptr:" << endl;
        intPtr = ptrVal;
    }
    ~Smartptr() {
        cout << "Deallocation of memory:" << endl;
        if (intPtr)
            delete intPtr;
    }
    Sample& operator*() {
        cout << "Inside operator*():" << endl;
        return *intPtr;
    }
    Sample* operator->() {
        cout << "Inside operator->():" << endl;
        return intPtr;
    }
    void swaraj() {
        cout << "Swaraj wants swarajya:" << endl;
    }
};

int main() {
    Smartptr sm1(new Sample());
    sm1->func();
    return 0;
}
