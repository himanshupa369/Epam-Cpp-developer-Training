// Constructor Initialization List

//what is constructor initialization List?
//In C++, the constructor initialization list is a mechanism for initializing member variables before the constructor body is executed.

/* Example :- 
class MyClass {
    int x;
    const int y;
public:
    MyClass(int a, int b) : x(a), y(b) {
        // Constructor body
    }
};*/

//Significance of CIL 

//a.Initializing Constant Variables(const variables)

//#include<iostream>
//using namespace std;
//class A {
//private:
//    const int i1;
//public:
//    A(int val):i1(val){}
//    void print() {
//        cout << "i1 = "<<i1 << endl;
//    }
//};
//int main() {
//    A a(8);
//    a.print();
//}

//b. Initializing Static Variables

//#include<iostream>
//using namespace std;
//class A {
//private:
//    static int i1;
//public:
//     // we can modify static variable inside static method.
//    static void setStatic(int val) {
//        i1 = val;
//    }
//    void print() {
//        cout << "i1 = "<<i1 << endl;
//    }
//};
//
//  it must be declare outside of class
//  int A::i1 = 0;
//
//int main() {
//    A a;
//    a.print();
//    a.setStatic(5);
//    a.print();
//}

// c.Base Class Constructor

//#include<iostream>
//using namespace std;
//class Base {
//    int x;
//public:
//    Base(int xv):x(xv) {
//        cout << "x is =" << x << endl;
//        cout << "constructor called" << endl;
//    }
// 
//};
//
//class derive :public Base {
//public:
//    /*no default constructor exists for class "Base" in below situations
//    derive() {
//        cout << "derive class will be called" << endl;
//    }*/
//
//    //use of CIL.
//    derive() :Base(10){
//        cout << "derive class will be called" << endl;
//    }
//};
//int main() {
//    derive d;
//}

// d. Initialization of reference members

//#include<iostream>
//using namespace std;
//class A {
//private:
//    //Reference members also need to be initialized in the constructor’s initialization list, as they cannot be assigned a value later in the constructor body.
//     int& i1;
//public:
//    //A() {}  // when you create A a; Error: Reference 'i1' must be initialized in the constructor’s initialization list.
//    A(int val):i1(val){}
//    void print() {
//        cout << "reference variable i1 = "<<i1 << endl;
//    }
//};
//int main() {
//    A a(8);
//    a.print();
//}

//#include <iostream>
//using namespace std;
//class A {
//private:
//    int i = 8;
//    int& i1;  // Reference to i, i must initialize with a value// 
//public:
//    A(int val) : i(val), i1(i) {}
//    void print() {
//        cout << "i= " << i << endl;
//        cout << "i1= " << i1 << endl;
//    }
//};
//
//
//int main()
//{
//    A a(5);
//    a.print();
//    return 0;
//}

// e. In has a relation

#include<iostream>
using namespace std;

class A {
private:
    int x;
public:
    A(int val):x(val){
        cout << "x is =" << x << endl;
        cout << "A constructor call" << endl;
    }

};

class B {
private:
    A a;
public:

    B():a(10) { 
        cout << "B constructor call" << endl;
    }
};
int main() {
    B b;
    return 0;
}

//f. avoid garbage value for same allocation name for data member and assign value

// #include<iostream>
// class test{
//     mutable int data;
//     public:
//     test(int data):data(data){}
//     void modify()const{
//         data = 90;
//     }
//     void normal(){}
// };
// int main(){
//     const test t(5);
//     t.normal();
//     return 0;
// }
