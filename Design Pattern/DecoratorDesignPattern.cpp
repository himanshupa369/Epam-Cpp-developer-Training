/*
Decorator Design Pattern:-
=> The Decorator Design Pattern is a structural design pattern that allows behavior to be added to individual objects dynamically, without affecting the behavior of other objects from the same class.
=> It involves creating a set of decorator classes that are used to wrap concrete components.
=> It is needed to solve the Class Explosion Problem.
=> Real world use case where this pattern is used :-IceCream Shop,Coffee Shop,Pizza Shop;
=> This pattern is useful when you need to add functionality to objects in a flexible and reusable way.
=> It follows the open/closed principle, as new decorators can be added without modifying existing code, making it a powerful tool for building modular and customizable software components.

***********************************************
Real-World Example of Decorator Design Pattern ):-
***********************************************
Consider a video streaming platform where users can watch movies and TV shows. 
Each video content may have additional features or options available, such as subtitles, language preferences, video quality options, and audio enhancements.

**********************************************
Key Components of the Decorator Design Pattern ):-
**********************************************
A) Component Interface :- This is an abstract class or interface that defines the common interface for both the concrete components and decorators. It specifies the operations that can be performed on the objects.
B) Concrete Component :- These are the basic objects or classes that implement the Component interface. They are the objects to which we want to add new behavior or responsibilities.
C) Decorator :- This is an abstract class that also implements the Component interface and has a reference to a Component object. Decorators are responsible for adding new behaviors to the wrapped Component object.
D) Concrete Decorator :- These are the concrete classes that extend the Decorator class. They add specific behaviors or responsibilities to the Component. Each Concrete Decorator can add one or more behaviors to the Component.

*/

#include <iostream>
#include <memory>
using namespace std;

// 🎯 Abstract Base Component (Component Interface)
class BasePizza {
public:
    virtual int cost() = 0; // Pure virtual function: all pizzas must define cost
    virtual ~BasePizza() = default; // Virtual destructor for safety
};

// 🍕 Concrete Base Pizzas (Concrete Component)
class VegDelight : public BasePizza {
public:
    int cost() override {
        return 100;
    }
};

class FarmhousePizza : public BasePizza {
public:
    int cost() override {
        return 130;
    }
};

class MargheritaPizza : public BasePizza {
public:
    int cost() override {
        return 150;
    }
};

// 🍥 Abstract Decorator (Decorator) – also derived from BasePizza
class ToppingDecorator : public BasePizza {
protected:
    unique_ptr<BasePizza> bPizza; // Composition: wraps another BasePizza
public:
    ToppingDecorator(unique_ptr<BasePizza> bp) : bPizza(move(bp)) {}
};

// 🧀 Concrete Toppings (Concrete Decorator)– Decorators extending ToppingDecorator
class ExtraCheese : public ToppingDecorator {
public:
    ExtraCheese(unique_ptr<BasePizza> bp1) : ToppingDecorator(move(bp1)) {}

    int cost() override {
        return bPizza->cost() + 20; // Add cost of Extra Cheese
    }
};

class Mushroom : public ToppingDecorator {
public:
    Mushroom(unique_ptr<BasePizza> bp1) : ToppingDecorator(move(bp1)) {}

    int cost() override {
        return bPizza->cost() + 40; // Add cost of Mushroom
    }
};

class Capsicum : public ToppingDecorator {
public:
    Capsicum(unique_ptr<BasePizza> bp1) : ToppingDecorator(move(bp1)) {}

    int cost() override {
        return bPizza->cost() + 15; // Add cost of Capsicum
    }
};

// 🧪 Main Function – Test the Decorator Pattern
int main() {
    // Step 1: Create a base pizza (Margherita)
    unique_ptr<BasePizza> pizza = make_unique<MargheritaPizza>();

    // Step 2: Add Extra Cheese on top of Margherita
    pizza = make_unique<ExtraCheese>(move(pizza));

    // Step 3: Add Mushroom on top of Cheese
    pizza = make_unique<Mushroom>(move(pizza));

    // Step 4: Add Capsicum on top of Mushroom
    pizza = make_unique<Capsicum>(move(pizza));

    // Step 5: Print final cost of the decorated pizza
    cout << "Total Cost: " << pizza->cost() << endl;

    return 0;
}
