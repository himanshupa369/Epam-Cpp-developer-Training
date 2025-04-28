/*

Factory Method Design :-
=> The Factory Method Pattern is a creational design pattern that provides an interface for creating objects, but lets subclasses decide which class to instantiate.
=> It is used for conditional based object creation. 
=>If your application needs to create different versions of a product or may introduce new types in the future, the Factory 
Method Pattern provides a flexible way to handle these variations by defining specific factory methods for each product type.

🧠 Why Use Factory Method?
=> You want to delegate object creation to child classes.
=> You want to decouple code from specific classes (avoid new everywhere).
=> Helps in extending code easily by just adding new subclasses.

Components of Factory Method Design Pattern:-

Below are the main components of Factory Design Pattern:-
A) Creator(factory) Interface:- This is an abstract class or an interface that declares the factory method. The creator typically contains a method that serves as a factory for creating objects. It may also contain other methods that work with the created objects.
B) Concrete Creator:-- Concrete Creator classes are subclasses of the Creator that implement the factory method to create specific types of objects. Each Concrete Creator is responsible for creating a particular product.
C) Product Interface:- This is the interface or abstract class for the objects that the factory method creates. The Product defines the common interface for all objects that the factory method can create.
D) Concrete Product:- Concrete Product classes are the actual objects that the factory method creates. Each Concrete Product class implements the Product interface or extends the Product abstract class.

*/

//Factory Pattern...

#include <iostream>
#include <memory>

using namespace std;

// --------------------------------------------
// Product Interface
// --------------------------------------------
class Vehicle {
public:
   // Abstract method to be implemented by all concrete products
   virtual void aboutVehicle() = 0;

   // Virtual destructor for proper cleanup
   virtual ~Vehicle() = default;
};

// --------------------------------------------
// Concrete Product 1: Four Wheeler
// --------------------------------------------
class FourW : public Vehicle {
public:
   void aboutVehicle() override {
       cout << "This is a four wheeler factory" << endl;
   }
};

// --------------------------------------------
// Concrete Product 2: Two Wheeler
// --------------------------------------------
class TwoW : public Vehicle {
public:
   void aboutVehicle() override {
       cout << "This is a two wheeler factory" << endl;
   }
};

// --------------------------------------------
// Enum to represent the type of Vehicle
// --------------------------------------------
enum class VehicleType { FourWheeler, TwoWheeler };

// --------------------------------------------
// Creator (Factory Class)
// --------------------------------------------
class VehicleFactory {
public:
   // Factory Method: returns a Vehicle based on the type
   static shared_ptr<Vehicle> getVehicle(VehicleType type) {
       if (type == VehicleType::FourWheeler) {
           return make_shared<FourW>(); // Create Four Wheeler
       }
       else if (type == VehicleType::TwoWheeler) {
           return make_shared<TwoW>(); // Create Two Wheeler
       }
       return nullptr; // Default case (in case of unknown type)
   }
};

// --------------------------------------------
// Client Code
// --------------------------------------------
int main() {
   auto type = VehicleType::TwoWheeler; // Specify desired vehicle type

   // Get the appropriate Vehicle using the factory
   shared_ptr<Vehicle> vec = VehicleFactory::getVehicle(type);

   // Use the product
   if (vec) {
       vec->aboutVehicle();
   }
   else {
       cout << "Invalid vehicle type" << endl;
   }

   return 0;
}
