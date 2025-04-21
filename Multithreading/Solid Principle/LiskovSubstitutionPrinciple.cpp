/*
🔹 L — Liskov Substitution Principle (LSP)

🧠 Definition:
Subtypes must be substitutable for their base types without altering the correctness of the program.

That means:
Derived classes should extend behavior, not break expectations.

In other words:
"If class B is a subclass of class A, we should be able to replace A with B without breaking the program."

💥 Why It Matters:
- Promotes safe polymorphism
- Prevents unexpected bugs when using inheritance
- Keeps code interchangeable and flexible

🧪 Real-World Analogy:
A Bird is an Animal.
You can substitute a Bird where an Animal is expected — but if you try substituting a Penguin and expect it to fly... boom! 🐧✈️💥

📌 Summary:

✅ Good Practice                     ❌ Bad Practice
-----------------------------       -----------------------------
Subclasses respect base behavior    Subclasses override or remove essential behavior
Consistent return values            Unexpected exceptions or logic
Safe, predictable substitution      Breaks polymorphism assumptions
*/


// 📐 Mini Project: Area Calculator for Shapes

#include <iostream>
#include <vector>
#include <memory>
#include <cmath>

// 🔷 Base class
class Shape {
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};

// ⬛ Rectangle class (inherits from Shape)
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

// ⚪ Circle class (inherits from Shape)
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return M_PI * radius * radius;
    }
};

// 📏 Area calculator — works with any Shape (LSP compliant)
class AreaCalculator {
public:
    double totalArea(const std::vector<std::shared_ptr<Shape>>& shapes) {
        double total = 0;
        for (const auto& shape : shapes) {
            total += shape->area(); // safe substitution: works for any Shape
        }
        return total;
    }
};

int main() {
    std::vector<std::shared_ptr<Shape>> shapes;

    shapes.push_back(std::make_shared<Rectangle>(10, 5));
    shapes.push_back(std::make_shared<Circle>(3));

    AreaCalculator calc;
    std::cout << "Total Area: " << calc.totalArea(shapes) << "\n";

    return 0;
}

/*
✅ LSP Applied:

We created a base Shape class and derived Rectangle and Circle.
All subclasses can be used in place of Shape without breaking the program.

Component        | Responsibility
-----------------|--------------------------------------
Shape            | Abstract base with area() method
Rectangle        | Implements area for rectangle
Circle           | Implements area for circle
AreaCalculator   | Works with Shape pointers (polymorphism)

All subclasses are substitutable — no broken behavior or surprises.
*/
