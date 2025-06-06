
---

## 🧠 **RTTI (Run-Time Type Information) in C++**

### 📌 What is RTTI?

* RTTI allows the program to determine the **actual derived type of an object** pointed to by a base class pointer at **runtime**.
* Useful in polymorphism when you want to know the **real type** of the object.

---

## 🧰 **Scenario: Minimum Balance Check**

* A `Checking` class contains a member `MinimumBalance`.
* A getter method `GetMinimumBalance()` is used to access this value from outside.
* `MinimumBalance` is initialized via constructor.

---

## 🔁 **Upcasting**

* Example: `Account* acc = new Checking(50);`
* Automatically converts derived class object (Checking) to base class pointer (Account).
* ✅ **Safe** & implicit.
* Only base class methods can be accessed through the pointer.

---

## 🔁 **Downcasting**

* To access child class-specific methods like `GetMinimumBalance()`, downcasting is required.
* Example: `Checking* chk = (Checking*)acc;`
* ❌ **Unsafe** if the actual object isn't of `Checking` type.
* May lead to incorrect behavior or crash.

---

## ❗ Problem with Blind Downcasting

* If `Account* acc` actually points to `Savings` object:

  ```cpp
  Checking* chk = (Checking*)acc;
  chk->GetMinimumBalance();  // undefined behavior
  ```
* ❌ This would call the wrong method or give incorrect values.

---

## ✅ **Solution: Use RTTI with typeid**

### Required Header

```cpp
#include <typeinfo>
```

### Syntax:

```cpp
typeid(expression)   // returns std::type_info object
```

### Example:

```cpp
Account* p = new Savings(0.05f);
const std::type_info &ti=type_id(*p);
cout<< ti.name() <<endl;
cout << typeid(*p).name();  // Outputs: class Savings
```

### Real Use Case:

```cpp
if (typeid(*p) == typeid(Savings)) {
    cout << "p points to Savings object";
} else {
    cout << "p does NOT point to Savings object";
}
```

---

## 📚 typeid Notes

| Use Case               | Works on        | Time of Evaluation |
| ---------------------- | --------------- | ------------------ |
| `typeid(int)`          | Non-polymorphic | Compile-time       |
| `typeid(*basePointer)` | Polymorphic     | **Run-time**       |

---

## ⚙️ Summary of RTTI & `typeid`

| Feature               | Description                                                         |
| --------------------- | ------------------------------------------------------------------- |
| `typeid(obj)`         | Gets the type info of an object or expression                       |
| `type_info::name()`   | Returns a human-readable name of the type                           |
| Use in downcasting    | To **safely check** if base pointer actually points to derived obj  |
| Only works at runtime | For **polymorphic types** (must have at least one `virtual` method) |

---

## 🔐 Design Consideration

* Accessing derived class-specific methods through base class pointers creates **tight coupling** and **dependency** on derived classes.
* Better practice: use **virtual functions** or **interface-based design** to expose required behavior through base class itself.

---
---
### 🔍 typeid vs dynamic_cast

| Feature          | `typeid`                     | `dynamic_cast`                               |
| ---------------- | ---------------------------- | -------------------------------------------- |
| Returns          | `type_info` object           | Pointer or reference                         |
| Used For         | Type **checking**            | Type **conversion (downcasting)**            |
| On invalid cast  | Still runs, comparison fails | Returns `nullptr` (pointers) / throws (refs) |
| Works On         | Polymorphic types at runtime | Polymorphic types only                       |
| Runtime Overhead | Light                        | Higher (checks hierarchy)                    |


---

