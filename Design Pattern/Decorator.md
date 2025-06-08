---

## ✅ Decorator Design Pattern 

---

### 🧠 **Conceptual Questions (C++ Specific)**

---

### **1. What is the Decorator Pattern in C++?**

**Answer:**
It’s a **structural design pattern** that allows behavior to be **dynamically added** to objects by **wrapping** them in decorator classes — all while adhering to the same interface.

---

### **2. How is it different from inheritance in C++?**

| Inheritance                       | Decorator                                         |
| --------------------------------- | ------------------------------------------------- |
| Compile-time extension            | Runtime extension                                 |
| Tight coupling                    | Loose, dynamic composition                        |
| Can't modify an existing instance | Can add behavior without modifying original class |

---

### **3. What C++ features help implement Decorator?**

* **Interfaces (abstract classes)**
* **Polymorphism** (via virtual functions)
* **Smart pointers (`std::shared_ptr`)**
* **Object composition**

---

### **4. When should you use a Decorator over Inheritance?**

* When you want to add responsibilities **dynamically at runtime**
* To avoid **subclass explosion**
* When classes need **optional features or behaviors**

---

### 🧑‍💻 **Code-Based Questions**

---

### **5. Show a working Decorator Pattern in C++**

#### ✅ Example: Coffee + Milk + Sugar (runtime extensible)

```cpp
#include <iostream>
#include <memory>

// Component
class Coffee {
public:
    virtual std::string getDescription() const = 0;
    virtual double cost() const = 0;
    virtual ~Coffee() = default;
};

// Concrete Component
class BasicCoffee : public Coffee {
public:
    std::string getDescription() const override { return "Coffee"; }
    double cost() const override { return 5.0; }
};

// Base Decorator
class CoffeeDecorator : public Coffee {
protected:
    std::shared_ptr<Coffee> coffee;
public:
    CoffeeDecorator(std::shared_ptr<Coffee> c) : coffee(std::move(c)) {}
};

// Concrete Decorators
class Milk : public CoffeeDecorator {
public:
    Milk(std::shared_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}
    std::string getDescription() const override { return coffee->getDescription() + " + Milk"; }
    double cost() const override { return coffee->cost() + 1.5; }
};

class Sugar : public CoffeeDecorator {
public:
    Sugar(std::shared_ptr<Coffee> c) : CoffeeDecorator(std::move(c)) {}
    std::string getDescription() const override { return coffee->getDescription() + " + Sugar"; }
    double cost() const override { return coffee->cost() + 0.5; }
};

// Main
int main() {
    std::shared_ptr<Coffee> coffee = std::make_shared<BasicCoffee>();
    coffee = std::make_shared<Milk>(coffee);
    coffee = std::make_shared<Sugar>(coffee);

    std::cout << coffee->getDescription() << "\n"; // Coffee + Milk + Sugar
    std::cout << "Total: $" << coffee->cost() << "\n"; // 7.0
}
```

---

### **6. How do you achieve dynamic behavior extension in C++?**

**Answer:**
By using **object composition and polymorphism**, not inheritance — Decorators wrap objects and override methods to add behavior.

---

### **7. How is the Decorator pattern used in the STL or libraries?**

**Answer:**

* `iostream` system (`std::istream`, `std::ifstream`, `std::istringstream`)
* Each stream object wraps another to add new capabilities.

---

### **8. What are potential drawbacks of using Decorator in C++?**

* Can create **many small classes**
* Can be **hard to debug** if layers are deeply nested
* **Order matters** (e.g., adding Sugar before Milk may produce a different result visually)

---

### ✅ Real-World Analogy

| Concept   | Example                                         |
| --------- | ----------------------------------------------- |
| Component | Plain Pizza                                     |
| Decorator | Add Cheese, Pepperoni                           |
| Result    | Pizza + Cheese + Pepperoni (built step-by-step) |

---

