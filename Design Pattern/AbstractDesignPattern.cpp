
/* 
🆚 Key Differences

Feature	                        Factory Method	                                             Abstract Factory
Purpose	                        Create one product	                                         Create a family of related products
Factory Type	                One creator class	                                         Multiple factories (abstract + concrete)
Flexibility	                    Simple, less flexible	                                     More flexible and scalable
Usage	                        Single product selection	                                 Multiple product types with related variants
Client knows	                Somewhat knows about product enum/type                       Knows only the abstract factory

✅ Example Analogy:-
=> Factory Method:-
You go to a fast-food kiosk and say, "I want a burger." They give you a burger (but only burgers are served here).

=> Abstract Factory:-
You go to a meal combo counter. You pick "Indian Veg Meal" — it gives you paneer, roti, lassi. Or pick "Italian Meal" — it gives you pizza, pasta, wine.
Everything is designed to go together.


*/

//Abstract Factory Pattern...

#include <iostream>
#include <memory>

using namespace std;

// -----------------------------------------------------
// Product Interface
// -----------------------------------------------------
class Vehicle {
public:
   virtual void aboutVehicle() = 0;
   virtual ~Vehicle() = default;
};

// -----------------------------------------------------
// Concrete Product 1: Four Wheeler
// -----------------------------------------------------
class Car : public Vehicle {
public:
   void aboutVehicle() override {
       cout << "This is a Four Wheeler (Car)" << endl;
   }
};

// -----------------------------------------------------
// Concrete Product 2: Two Wheeler
// -----------------------------------------------------
class Bike : public Vehicle {
public:
   void aboutVehicle() override {
       cout << "This is a Two Wheeler (Bike)" << endl;
   }
};

// -----------------------------------------------------
// Abstract Factory Interface
// -----------------------------------------------------
class VehicleFactory {
public:
   virtual shared_ptr<Vehicle> createVehicle() = 0;
   virtual ~VehicleFactory() = default;
};

// -----------------------------------------------------
// Concrete Factory: Four Wheeler Factory
// -----------------------------------------------------
class FourWheelerFactory : public VehicleFactory {
public:
   shared_ptr<Vehicle> createVehicle() override {
       return make_shared<Car>();
   }
};

// -----------------------------------------------------
// Concrete Factory: Two Wheeler Factory
// -----------------------------------------------------
class TwoWheelerFactory : public VehicleFactory {
public:
   shared_ptr<Vehicle> createVehicle() override {
       return make_shared<Bike>();
   }
};

// -----------------------------------------------------
// Client Code
// -----------------------------------------------------
int main() {
   // Pointer to abstract factory
   shared_ptr<VehicleFactory> factory;

   // Let's say we want a two-wheeler
   factory = make_shared<TwoWheelerFactory>();

   // Create the vehicle using the factory
   shared_ptr<Vehicle> myVehicle = factory->createVehicle();

   // Use the product
   myVehicle->aboutVehicle();

   return 0;
}

//other example of abstract factory method. :-

//#include <iostream>
//using namespace std;
//
//// --------------------------------------------------------
//// Abstract Product A: Button
//// --------------------------------------------------------
//class IButton {
//public:
//    virtual void press() = 0;
//    virtual ~IButton() = default;
//};
//
//// Concrete Product A1: Mac Button
//class MacButton : public IButton {
//public:
//    void press() override {
//        cout << "Mac Button" << endl;
//    }
//};
//
//// Concrete Product A2: Windows Button
//class WinButton : public IButton {
//public:
//    void press() override {
//        cout << "Win Button" << endl;
//    }
//};
//
//// --------------------------------------------------------
//// Abstract Product B: TextBox
//// --------------------------------------------------------
//class ITextBox {
//public:
//    virtual void TextMessage() = 0;
//    virtual ~ITextBox() = default;
//};
//
//// Concrete Product B1: Mac TextBox
//class MacText : public ITextBox {
//public:
//    void TextMessage() override {
//        cout << "Mac Text" << endl;
//    }
//};
//
//// Concrete Product B2: Windows TextBox
//class WinText : public ITextBox {
//public:
//    void TextMessage() override {
//        cout << "Win Text" << endl;
//    }
//};
//
//// --------------------------------------------------------
//// Abstract Factory: Interface to create families of products
//// --------------------------------------------------------
//class IOsFactory {
//public:
//    virtual IButton* createButton() = 0;     // Abstract factory method for Button
//    virtual ITextBox* createTextBox() = 0;   // Abstract factory method for TextBox
//    virtual ~IOsFactory() = default;
//};
//
//// Concrete Factory 1: Creates Windows UI components
//class WinOsFactory : public IOsFactory {
//public:
//    IButton* createButton() override {
//        return new WinButton();   // Creates Windows button
//    }
//
//    ITextBox* createTextBox() override {
//        return new WinText();     // Creates Windows text box
//    }
//};
//
//// Concrete Factory 2: Creates Mac UI components
//class MacOsFactory : public IOsFactory {
//public:
//    IButton* createButton() override {
//        return new MacButton();   // Creates Mac button
//    }
//
//    ITextBox* createTextBox() override {
//        return new MacText();     // Creates Mac text box
//    }
//};
//
//// --------------------------------------------------------
//// Helper: Enum to identify OS type at runtime
//// --------------------------------------------------------
//enum class OSType { MAC, WIN };
//
//// --------------------------------------------------------
//// Factory Selector: Returns appropriate Abstract Factory
//// --------------------------------------------------------
//class OSFactoryClass {
//public:
//    static IOsFactory* getOsType(OSType type) {
//        if (type == OSType::MAC)
//            return new MacOsFactory();
//        else if (type == OSType::WIN)
//            return new WinOsFactory();
//        return nullptr;
//    }
//};
//
//// --------------------------------------------------------
//// Client Code: Uses abstract interfaces only
//// --------------------------------------------------------
//int main() {
//    OSType type = OSType::WIN;
//
//    // Get the appropriate factory based on OS type
//    IOsFactory* osFactory = OSFactoryClass::getOsType(type);
//
//    // Create UI components using the abstract factory
//    IButton* button = osFactory->createButton();
//    ITextBox* textbox = osFactory->createTextBox();
//
//    // Use the created objects
//    button->press();
//    textbox->TextMessage();
//
//    // Clean up manually (or use smart pointers for safety)
//    delete button;
//    delete textbox;
//    delete osFactory;
//
//    return 0;
//}


