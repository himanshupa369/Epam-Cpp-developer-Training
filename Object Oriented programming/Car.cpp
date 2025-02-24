#include "Car.h"
#include <iostream>
using namespace std;

Car::Car() {
    cout << "Car()" << endl;
    fuel = 0;
    speed = 0;
    passenger = 0;
}
// below method is called constructor overloading or class with overloaded constructor //
Car::Car(float amount) {
    fuel = amount;
    speed = 0;
    passenger = 0;
}

Car::~Car() {
    cout << "~Car()" << endl;
}

void Car::FillFuel(float amount) {
    fuel = amount;
}

void Car::Accelarate() {
    speed++;
    fuel -= 0.5f;
}

void Car::Break() {
    speed = 0;
}

void Car::AddPassenger(int count) {
    passenger = count;
}

void Car::DashBoard() {
    cout << "Fuel: " << fuel << " " << "Speed: " << speed << " " << "Passenger: " << passenger << endl;
}
