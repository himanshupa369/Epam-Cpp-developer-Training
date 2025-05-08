//Delegating constructors in C++ are constructors that call another constructor of the same class to avoid code duplication and simplify constructor definitions.
//Introduced in C++11, this feature helps in reusing initialization logic.
/*
⚠️ Important Rules:
Delegating constructor must delegate to another constructor in the same class.
You can't form cycles (e.g., A → B → A).
Only one constructor can be delegated to (no multiple delegation).
*/
#include<iostream>
using namespace std;

class Car {
private:
    float fuel;
    int speed;
    int passenger;

public:
    Car() : Car(0) {
        cout << "Car()" << endl;
    }

    Car(int speed) : Car(speed, 0) {
        cout << "Car(int speed)" << endl;
    }

    Car(int speed, int passenger)
        : speed(speed), passenger(passenger), fuel(0.0f) {
        cout << "Car(int speed, int passenger)" << endl;
    }

    ~Car() {
        cout << "Destructor called" << endl;
    }
};

int main(){
    Car car;
    return 0;
}
