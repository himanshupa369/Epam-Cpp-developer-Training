#include <iostream>
#include "add.h"
using namespace std;
namespace Avg {
    float calculate(float x, float y) {
        return (x + y) / 2;
    }
}
namespace Summ {
    float calculate(float x, float y) {
        return x + y;
    }
}
static void Print(int count, char ch) {
    for (int i = 0; i < count; i++) {
        cout << ch;
    }
    cout << endl;
}
int NumSum(int x, int y) {
    return x + y;
}
inline int Square(int x) {
    return x * x;
}
// macros
//#define Square(x) x*x
void greet(string name, string message = "Hello") {
    cout << message << ", " << name << "!" << endl;
}
void display(int x, int y = 10, int z = 20) {
    cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
}
int main()
{
    int a, b;
    cout << "Enter a and b" << endl;
    cin >> a >> b;
    //by using pointer
    cout << Add(&a, &b) << endl;
    int result = 0;
    AddVal(&a, &b, &result);
    Swap(&a, &b);
    int fact = 1;
    Factorial(&a, &fact);
    // by using reference variable
    Add(a, b, result);
    Swap(a, b);
    Factorial(a, result);


    //Range based for loop
    int arr[] = { 1,2,3,4,5,6 };
    /*int* start = &arr[0];
    int* endd = &arr[5];
    while (start != endd) {
        cout << *start <<" ";
        start++;
    }*/
    auto range = arr; //if you write auto &&range = arr then write range at place of arr in below lines
    auto start = begin(arr);
    auto endd = end(arr);
    while (start != endd) {
        auto it = *start;
        cout << it << endl;
        start++;
    }



    //default function arguments//
    greet("Alice");            // Output: Hello, Alice!
    greet("Bob", "Goodbye");   // Output: Goodbye, Bob!
    display(5);             // Output: x: 5, y: 10, z: 20
    display(5, 15);         // Output: x: 5, y: 15, z: 20
    display(5, 15, 25);
    int squr = Square(5+1);
    //note for square(val+2) macros does not work properly
    cout <<"square is = " << squr << endl;



    //function pointer
    //example 1
    Print(5, '#');
    void (*fnptr)(int, char) = &Print;
    /* we can write this also == void (*fnptr)(int, char) = Print;*/
    (*fnptr)(5, '&');
    fnptr(5, '$');
    cout << "Function address:" << fnptr << endl;
    //example 2
    int (*fn1ptr)(int, int) = NumSum;
    int ars = fn1ptr(3, 4);
    cout << "sum is ="<<ars << endl;

    // use of namepsace 
    float f=Avg::calculate(5.3, 6.7);
    float fl=Summ::calculate(5.3, 6.7);
    cout << "f=" << f << endl;
    cout << "fl=" << fl << endl;

    return 0;
}