### 🔹 `std::ref()` in C++

#### ✅ **What is `std::ref()`?**

`std::ref()` is a utility function in C++ that creates a **reference wrapper** for a given object. It is defined in the `<functional>` header.

---

### 🔸 **Why is it needed?**

When passing arguments to `std::thread`, STL containers, or algorithms, **objects are passed by value by default**. If you want to pass a **reference**, you must wrap it using `std::ref()`.

---

### 🔸 **Basic Syntax:**

```cpp
#include <iostream>
#include <thread>
#include <functional> // for std::ref

void update(int& x) {
    x += 5;
}

int main() {
    int a = 10;
    std::thread t(update, std::ref(a)); // pass a by reference
    t.join();
    std::cout << a; // prints 15
}
```

Without `std::ref(a)`, `a` would be copied and the original variable unchanged.

---

### 🔸 **Where is `std::ref()` used?**

1. ✅ **`std::thread`** (to pass references)
2. ✅ **STL algorithms** (e.g., using `std::for_each` with reference-capturing lambdas)
3. ✅ **Function wrappers or callables** that require reference semantics

---

### 🔸 **What does it return?**

`std::ref(obj)` returns a `std::reference_wrapper<T>`, which acts like a reference but is copyable.

---

### 🔸 **What is `std::cref()`?**

`std::cref()` creates a **const reference wrapper** — i.e., you can pass a `const T&` safely.

---

### 🔸 **When NOT to use `std::ref()`?**

* Don’t use it if the object might go **out of scope** before use.
* It doesn't extend the object’s lifetime — it just avoids copying.

---

