/* Pre and Post Increment Operator overloading */

//these are used in real - world use cases in STL or object - oriented design.
// 1)STL Iterators
// 2)Smart Pointers
// 3)Game Development
// 4)Mathematical Objects

#include <iostream>
using namespace std;

class OprOverLoad{
private:
    int x;

public:
    OprOverLoad(int val) : x(val){}

    // Prefix increment :- ( increment first, then assign)
    //Note:- Returns the modified object by reference → faster, avoids unnecessary copying.
    //       👉 Use prefix ++obj in loops when you don’t need the old value for better efficiency.
    OprOverLoad& operator ++() {
        ++x;
        return *this;
    }
    
    // Postfix increment :- ( assign first, then increment)
    //Note:- Returns a copy of the original object → slower due to extra object creation.
    //       ✅ Use postfix (obj++) when you need the old value before modification.
    OprOverLoad operator ++(int dummy) {
        OprOverLoad temp = *this;  // save current state
        x++;
        return temp;  // return old state
    }

    void display() {
        cout << "Value of x: " << x << endl;
    }
};

// Subscript Overloading //
class Arr {
private:
    int arr[7];
public:
    Arr() {
        for (int i = 0; i < 7; ++i) {
            arr[i] = i * 2;
        }
    }
    int& operator[](int index) {
        if (index < 0 || index >= 7) {
            cerr << "Index is out of bound " << endl;
            exit(1);
        }
        return arr[index];
    }
};

class FruitsExpense {
private:
    float amount;
public:
    FruitsExpense() :amount(0) {}
    FruitsExpense(float val) :amount(val) {}

    FruitsExpense operator+(const FruitsExpense& obj) {
        FruitsExpense tmp;
        tmp.amount = this->amount + obj.amount;
        return tmp;
    }
    FruitsExpense operator-(const FruitsExpense& obj) {
        FruitsExpense tmp;
        tmp.amount = this->amount - obj.amount;
        return tmp;
    }

    FruitsExpense& operator+=(const FruitsExpense& obj) {
        this->amount += obj.amount;
        return *this;
    }
    FruitsExpense& operator-=(const FruitsExpense& obj) {
        this->amount -= obj.amount;
        return *this;
    }
    void display() {
        cout << "Total amount:" << amount << endl;
    }
};

class Mul {
private:
    int x;
public:
    Mul(int val):x(val){}
    Mul operator*(const Mul& obj) {
        return this->x * obj.x;
    }
    void display() {
        cout << "x :" << x << endl;
    }
};

int main() {
    OprOverLoad obj(5);
    cout << "prefix increment: " << endl;
    ++obj;  
    obj.display(); 
    cout << "postfix increment: " << endl;
    obj++;  
    obj.display();

    //subscript main code //
    Arr a;
    cout <<"subscript overload" << a[2] << endl;
    a[2] = 10;
    cout << a[2] << endl;

    //subtract overloading and Assignment operator overloading main code //
    cout << endl;
    FruitsExpense apple1(11.5);
    FruitsExpense banana1(3.1);;
    FruitsExpense total1;
    cout << "After Buying Banana1:" << endl;
    total1 = total1 + banana1;
    total1.display();
    cout << "After Buying Apple1:" << endl;
    total1 = total1 + apple1;
    total1.display();
    cout << "After getting that Banana1 was rotten we initiat refund:" << endl;
    total1 = total1 - banana1;
    total1.display();

    FruitsExpense apple2(10.5);
    FruitsExpense banana2(2.1);;
    FruitsExpense total2;
    cout << "After Buying Banana2:" << endl;
    total2 += banana1;
    total2.display();
    cout << "After Buying Apple2:" << endl;
    total2 += apple1;
    total2.display();
    cout << "After getting that Banana2 was rotten we initiat refund:" << endl;
    total2 -= banana1;
    total2.display();

    //Multiplication operator overloading //
    Mul m1(3);
    Mul m2(4);
    Mul m3 = m1 * m2;
    m3.display();
}
