#include "Car.h"
#include <iostream>
#include <cstring>
using namespace std;

class Myclass {
private:
    int intvar;
    float floatvar;
    string strvar;

public:
    // Constructor with different types of variables
    Myclass(int i, float f, string s) : intvar(i), floatvar(f), strvar(s) {}

    // Constructor with default values
    Myclass() : intvar(0), floatvar(0.0f), strvar("default") {}

    // Constructor with pointer resource handling (now using std::string)
    Myclass(const char* str) {
        strvar = str; 
        cout << "Constructor with pointer-based resource allocation" << endl;
    }

    // Copy Constructor
    Myclass(const Myclass& other) {
        intvar = other.intvar;
        floatvar = other.floatvar;
        strvar = other.strvar;  // String copying is handled automatically
        cout << "Copy constructor called" << endl;
    }

    // Destructor with pointer resource handling
    ~Myclass() {
        cout << "Destructor: Memory deallocated" << endl;
    }

    // Display method
    void display() {
        cout << "Integer: " << intvar << ", Float: " << floatvar << ", String: " << strvar << endl;
    }

    // Display method with overloaded function (Different parameter type)
    void display(string additionalText) {
        cout << "Additional Info: " << additionalText << endl;
    }

    // Explicit constructor (prevents implicit type conversions)
    explicit Myclass(float f) {
        floatvar = f;
        intvar = 0;
        strvar = "Explicit Constructor";
    }
};

// Array of objects
class ArrClass {
private:
    int value;

public:
    ArrClass(int val) : value(val) {}

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    // Constructor with different types of variables
    Myclass obj1(10, 5.5f, "Hello");

    // Constructor overloading
    Myclass obj2(42); // Only integer constructor
    Myclass obj3;     // Default constructor

    // Constructor with pointer resource handling
    Myclass obj4("PointerResource");

    // Copy Constructor (Copying obj1 to obj5)
    Myclass obj5 = obj1; // This will invoke the copy constructor

    // Display the objects
    obj1.display();
    obj2.display();
    obj3.display();
    obj4.display();
    obj5.display();  // Displaying the copied object

    // Display using overloaded function
    obj1.display("Extra Information");

    // Array of objects with default values
    ArrClass arr[3] = { ArrClass(1), ArrClass(2), ArrClass(3) };

    cout << "Array of objects display:" << endl;
    for (int i = 0; i < 3; ++i) {
        arr[i].display();
    }

    // Significance of explicit keyword: prevents implicit conversion
    // Uncommenting this will give a compilation error, because we can't convert float to MyClass implicitly
    // Myclass obj5 = 5.5f;


    // Creating an object dynamically using new
    Myclass* dynamicObj = new Myclass(100, 200.5f, "Dynamically Created");
    dynamicObj->display();

    Car cr(4);
    //cr.FillFuel(6);
    cr.Accelarate();
    cr.Accelarate();
    cr.Accelarate();
    cr.Accelarate();
    cr.DashBoard();

    // Deleting dynamically allocated object
    delete dynamicObj;
    return 0;
}
