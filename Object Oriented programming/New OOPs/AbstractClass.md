---
title: Abstract Classes & Pure Virtual Functions – Quick Notes
date: 2025-06-05
layout: post
---

## 🔹 Abstract Classes & Pure Virtual Functions – Quick Notes

### 🧩 **1. Problem with Default Virtual Functions**
...


* Base class `Document` defines a `virtual void Serialize()`.
* Derived classes (e.g., `XML`) may **forget to override** `Serialize()`.
* If client calls `Serialize()` on `Document*` pointing to `XML`, base version is used.
* ❗ This leads to **incorrect behavior** – XML data isn't serialized, but the client doesn’t know.

---

### 🧩 **2. Solution – Make `Serialize()` a Pure Virtual Function**

```cpp
virtual void Serialize() = 0;  // Pure Virtual Function
```

* Declared with `= 0`, known as **pure specifier**.
* Forces derived classes to **override** the function.
* Makes `Document` an **abstract class**.

---

### 📘 **3. What is an Abstract Class?**

* A class with **at least one pure virtual function**.
* **Cannot be instantiated** directly.
* Can have:

  * Data members
  * Non-virtual functions
  * Virtual functions
  * Static members
* Can create **pointers/references** to abstract class.

---

### 🔧 **4. Use Case in Client Code**

```cpp
void Write(Document* doc) {
    doc->Serialize();  // Guaranteed to call derived implementation
}
```

* If `Serialize()` is pure virtual, derived classes **must implement** it.
* Guarantees correct polymorphic behavior at runtime.

---

### 📋 **5. Interfaces in C++**

* A class with **only pure virtual functions** (and no other members).
* Used as **contracts** to be fulfilled by implementers.
* Often used in **modular / plugin-based systems**.

---

### 🌀 **6. Can Pure Virtual Functions Have Definitions?**

* ✅ Yes, they can have a definition even if marked `= 0`.

```cpp
virtual void Serialize() = 0 {
    // Optional default implementation
}
```

* Still **must be overridden**.
* The base class definition can only be invoked from **derived classes**.

---

### 🧠 **7. Behavior in VTable**

* Pure virtual functions **do not have actual entries** in the base class's vtable.
* But their **slot is reserved** to enforce overriding in derived classes.

---

### 🚨 **8. If Not Overridden**

* Derived class becomes **abstract**.
* Cannot be instantiated.

---

## 🟩 Summary Table

| Feature                 | Description                                  |
| ----------------------- | -------------------------------------------- |
| `= 0`                   | Declares a pure virtual function             |
| Abstract Class          | Has at least one pure virtual function       |
| Cannot Instantiate      | Abstract classes can't have objects          |
| Must Override           | Derived classes must override pure functions |
| Interface               | Class with only pure virtual functions       |
| Optional Implementation | Allowed, but uncommon                        |
| Pure Function in VTable | Reserves slot, no actual code in base        |

---

## 🔹 Why Use = 0 in C++ for Pure Virtual Functions? **✅ Purpose of = 0:**

### In C++, writing = 0 in a virtual function declaration explicitly tells the compiler:

> “This function has no implementation here, and must be implemented by derived classes.”

---
