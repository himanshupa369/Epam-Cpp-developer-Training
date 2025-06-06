---

## 🔐 Access Modifiers in C++ (Revisited)

Access modifiers define **how class members (variables/functions)** can be accessed. They also affect how members are **inherited** in derived classes.

---

### 🧱 Types of Access Modifiers

| Modifier    | Accessible within Class | Accessible in Derived Class | Accessible Outside Class |
| ----------- | ----------------------- | --------------------------- | ------------------------ |
| `private`   | ✅ Yes                   | ❌ No                        | ❌ No                     |
| `protected` | ✅ Yes                   | ✅ Yes                       | ❌ No                     |
| `public`    | ✅ Yes                   | ✅ Yes                       | ✅ Yes                    |

---

## 🧬 Access Modifiers and Inheritance

When a class inherits from a base class, the access level of the **base class members** may change depending on the **inheritance specifier** used (`public`, `protected`, or `private`).

### 📌 Public Inheritance (`class Child : public Base`)

* `public` members of `Base` ➝ remain `public` in `Child`
* `protected` members of `Base` ➝ remain `protected` in `Child`
* `private` members of `Base` ➝ inherited but **not accessible** in `Child`

➡️ **Most commonly used inheritance type**

---

### 📌 Protected Inheritance (`class Child : protected Base`)

* `public` & `protected` members of `Base` ➝ become `protected` in `Child`
* `private` members ➝ inherited but **not accessible**

➡️ Used when you want to **restrict access** from outside but still allow derived classes to use it.

---

### 📌 Private Inheritance (`class Child : private Base`)

* All `public` and `protected` members of `Base` ➝ become `private` in `Child`
* `private` members ➝ inherited but **not accessible**

➡️ Used for **implementation inheritance**, not interface inheritance.

---

## ⚠️ Default Inheritance Mode

* If no access modifier is specified during inheritance:

  * `class` ➝ defaults to **private**
  * `struct` ➝ defaults to **public**

```cpp
class Base { };
class Derived : Base { };   // private inheritance by default

struct StructDerived : Base { }; // public inheritance by default
```

---

## 🧪 Constructor and Destructor Order in Inheritance

* **Construction Order**: Base ➝ Derived
* **Destruction Order**: Derived ➝ Base

```cpp
class Base {
public:
    Base() { std::cout << "Base constructor\n"; }
    ~Base() { std::cout << "Base destructor\n"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor\n"; }
    ~Derived() { std::cout << "Derived destructor\n"; }
};
```

📌 Output:

```
Base constructor
Derived constructor
Derived destructor
Base destructor
```

---

## 🧱 Inheritance of Data Members

* **Child object includes all base class members**.
* However, **private members of base are inaccessible** directly in the child class.

```cpp
class A {
private:
    int x, y;
};

class B : public A {
private:
    int z;
    // x and y are part of B but not accessible here
};
```

---

## ✅ Summary

| Aspect                        | Public Inheritance  | Protected Inheritance  | Private Inheritance |
| ----------------------------- | ------------------- | ---------------------- | ------------------- |
| Inherited `public` becomes    | `public`            | `protected`            | `private`           |
| Inherited `protected` becomes | `protected`         | `protected`            | `private`           |
| Inherited `private` becomes   | Not accessible      | Not accessible         | Not accessible      |
| Default for `class`           | `private`           | —                      | —                   |
| Default for `struct`          | `public`            | —                      | —                   |
| Use case                      | "is-a" relationship | Restricted inheritance | Implementation only |

---

