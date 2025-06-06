---

## 🔵 Object-Oriented Programming Relationships in C++

In Object-Oriented Programming (OOP), classes and objects **do not exist in isolation**. Real-world systems require **collaboration between objects**. This collaboration is achieved through **relationships** between objects and classes.

---

### 📌 Why Relationships Between Classes?

* Classes/Objects model the real-world system.
* Objects **collaborate** to define the behavior of the system.
* Relationships help model such collaboration using:

  * **Composition (Has-a)**
  * **Inheritance (Is-a)**

---

## 🧱 1. Composition (Has-a Relationship)

### ✅ Definition:

Composition is when **one object contains another** object as a part.
Used to represent a **"has-a" or "part-of"** relationship.

### 📖 Example:

* A **Car has an Engine**.
* Engine provides power, Car uses it to move.

### ⚙️ Code Example:

```cpp
class Engine {
public:
    void Start() { std::cout << "Engine started\n"; }
};

class Car {
    Engine engine; // composition
public:
    void Accelerate() {
        engine.Start();
        std::cout << "Car accelerating...\n";
    }
};
```

### ✅ Benefits:

* Reuse functionality of inner class.
* Promotes modularity and reusability.

---

## 🧱 2. Inheritance (Is-a Relationship)

### ✅ Definition:

Inheritance is a mechanism where a **child class inherits properties and behavior** from a **parent (base) class**.
Represents an **"is-a"** relationship.

### 📖 Example:

* **Dog is an Animal**.
* Dog can **Eat**, **Run**, and **Speak** (bark).

### ⚙️ Syntax:

```cpp
class Base { /* ... */ };
class Derived : public Base { /* ... */ }; // 'public' is the access specifier
```

### ⚙️ Code Example:

```cpp
class Animal {
public:
    void Eat() { std::cout << "Animal eats\n"; }
    void Run() { std::cout << "Animal runs\n"; }
    void Speak() { std::cout << "Animal speaks\n"; }
};

class Dog : public Animal {
public:
    void Eat() { std::cout << "Dog eats bones\n"; }
    void Speak() { std::cout << "Dog barks\n"; }
};
```

### ✅ Usage:

```cpp
int main() {
    Dog d;
    d.Eat();   // Dog's version (overridden)
    d.Speak(); // Dog's version (overridden)
    d.Run();   // Inherited from Animal
}
```

### ✅ Key Points:

* Inheritance promotes **code reuse**.
* Child class **inherits** functions and **can override** (hide) them.
* When child reimplements a function from base with the same name, it **hides** base's implementation.
* Overridden functions are **called from child** class object.

---

## 🧠 Summary Table

| Feature           | Composition                   | Inheritance                      |
| ----------------- | ----------------------------- | -------------------------------- |
| Relationship Type | Has-a / Part-of               | Is-a                             |
| Usage             | Reuse via **member objects**  | Reuse via **class hierarchy**    |
| Coupling          | Low                           | High (tight coupling)            |
| Flexibility       | High                          | Limited due to rigid structure   |
| Example           | Car has Engine                | Dog is an Animal                 |
| Functionality     | Delegate inner class behavior | Override or extend base behavior |
| Runtime Change    | Easier with composition       | Difficult with inheritance       |

---

## 🔚 Conclusion

* **Composition** is preferred when designing flexible and modular systems.
* **Inheritance** is useful when a clear **"is-a"** hierarchy exists and **shared behavior** can be reused.
* C++ allows both relationships, and choosing the right one depends on the **problem domain**.

