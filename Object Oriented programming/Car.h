#pragma once

class Car {
private:
    float fuel;
    float speed;
    int passenger;

public:
    //Note:-Default member functions of a class are default and copy constructor ,assignment operator and
    //destructor
    Car();  
    Car(float amount);
    ~Car(); 

    void FillFuel(float amount);
    void Accelarate();
    void Break();
    void AddPassenger(int count);
    void DashBoard();
};
