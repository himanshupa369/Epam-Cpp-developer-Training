---



---


1. **What is the Singleton Design Pattern?**

   * Answer: Ensures a class has only one instance and provides a global point of access to it.

2. **Why would you use a Singleton?**

   * Centralized control (e.g., Logger, Configuration Manager, Database connection).

3. **What are the key characteristics of a Singleton?**

   * Private constructor
   * Static method to access instance
   * Static instance variable
   * Optional: thread safety, lazy initialization

4. **What is the difference between Eager and Lazy initialization in Singleton?**

   * Eager: instance is created at startup
   * Lazy: instance is created on first access (can save resources)

5. **Can Singleton be broken in C++?**

   * Yes, through:

     * Copy constructor
     * Assignment operator
     * Multithreading (race condition)

6. **How do you prevent copy of Singleton?**

   * Make copy constructor and assignment operator `= delete`

7. **Is Singleton an anti-pattern?**

   * Sometimes. Overuse leads to **global state**, **tight coupling**, and **unit test difficulty**.

---

### 🧑‍💻 **Code-Based Questions**

 **Write a basic Singleton in C++.**

```cpp
class Singleton {
private:
    static Singleton* instance;
    Singleton() {} // Private constructor

public:
    static Singleton* getInstance() {
        if (!instance)
            instance = new Singleton();
        return instance;
    }
};

// Static member init
Singleton* Singleton::instance = nullptr;
```

---

 **Implement Singleton using C++11 thread-safe lazy initialization.**

```cpp
class Singleton {
private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance; // Thread-safe in C++11+
        return instance;
    }
};
```

---

 **What are the drawbacks of using Singleton?**

* Hard to unit test (no easy mocking)
* Global state → hidden dependencies
* Violates SRP and DIP (in some cases)
* Thread-safety complexity in some implementations

---

 **What is Meyers’ Singleton?**

> A C++-specific singleton implementation using a static local variable (C++11 makes it thread-safe):

```cpp
Singleton& Singleton::getInstance() {
    static Singleton instance;
    return instance;
}
```

---

 **Can we create a Singleton with smart pointers?**

> Yes, for memory management:

```cpp
class Singleton {
private:
    Singleton() {}
public:
    static std::shared_ptr<Singleton> getInstance() {
        static std::shared_ptr<Singleton> instance(new Singleton());
        return instance;
    }
};
```

---


**Where is Singleton used in real-life systems?**

* Logger
* Database connection
* Configuration manager
* Thread pool
* Cache manager

---
