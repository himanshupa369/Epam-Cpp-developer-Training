---

### 🔹 **1. What is a thread in C++?**

A thread is the smallest unit of execution. In C++, `std::thread` (from C++11) is used to create and manage threads. Threads share memory with the main process and can run concurrently.

---

### 🔹 **2. Difference between a process and a thread?**

| Feature         | Process            | Thread                     |
| --------------- | ------------------ | -------------------------- |
| Memory          | Has its own memory | Shares memory with process |
| Overhead        | High               | Low                        |
| Communication   | Expensive (IPC)    | Easy (shared memory)       |
| Fault Isolation | Strong             | Weak                       |

---

### 🔹 **3. How do you create a thread in C++11 or later?**

```cpp
#include <iostream>
#include <thread>

void printHello() {
    std::cout << "Hello from thread\n";
}

int main() {
    std::thread t(printHello);
    t.join(); // Wait for thread to finish
    return 0;
}
```

---

### 🔹 **4. What happens if the main function ends before the thread joins?**

If `main()` ends before the thread is joined or detached, the program may crash or throw a runtime error because the thread is still running.

---

### 🔹 **5. Role of `std::thread::join()` and `detach()`?**

* `join()`: Waits for the thread to finish. Main thread blocks.
* `detach()`: Separates thread from main thread; runs independently (daemon-style).

> Only one of them should be used. If neither is used, it throws an exception.

---

### 🔹 **6. What are race conditions? How do you avoid them?**

**Race condition** happens when two threads access shared data and at least one thread writes to it, leading to unpredictable results.

**Avoidance:**

* Use `std::mutex`
* Apply locks (`std::lock_guard`, `std::unique_lock`)
* Use atomic types (`std::atomic`)

---

### 🔹 **7. How do you synchronize threads in C++?**

Using:

* `std::mutex`, `std::recursive_mutex`
* `std::lock_guard`, `std::unique_lock`
* `std::condition_variable`
* Atomic variables (`std::atomic<int>`)

---

### 🔹 **8. Explain the use of `std::mutex`.**

`std::mutex` ensures only one thread accesses the critical section at a time.

```cpp
std::mutex m;
void print() {
    m.lock();
    std::cout << "Thread-safe\n";
    m.unlock();
}
```

> Prefer `std::lock_guard` for exception safety.

---

### 🔹 **9. What is a deadlock? How can it be prevented?**

**Deadlock** occurs when two or more threads wait forever for each other to release a resource.

**Prevention:**

* Always lock resources in a consistent order
* Use `std::lock()` for multiple mutexes
* Avoid nested locking if possible

---

### 🔹 **10. Difference between `std::lock_guard` and `std::unique_lock`?**

| Feature                           | `lock_guard` | `unique_lock` |
| --------------------------------- | ------------ | ------------- |
| Simpler, lightweight              | ✅            | ❌ (heavier)   |
| Can unlock manually               | ❌            | ✅             |
| Required for `condition_variable` | ❌            | ✅             |

---

### 🔹 **11. What are condition variables? Use in producer-consumer?**

`std::condition_variable` allows threads to **wait** for a condition.

```cpp
std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void producer() {
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;
    cv.notify_one(); // Signal the consumer
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return ready; }); // Wait until ready
    std::cout << "Consumed\n";
}
```

---

### 🔹 **12. Difference between `std::async`, `std::future`, and `std::promise`?**

* `std::async`: Runs function asynchronously and returns a `future`.
* `std::future`: Holds result of async operation, can block with `.get()`.
* `std::promise`: Lets you manually set a value to a `future`.

---

### 🔹 **13. Thread-safe data structures in C++?**

C++ STL containers are **not thread-safe** by default. Alternatives:

* Use locks around `std::vector`, `std::queue`, etc.
* Use concurrent queues or libraries like TBB or `concurrent_queue` from Intel or Boost.

---

### 🔹 **14. How would you implement a thread pool in C++?**

Basic steps:

1. Create a fixed number of worker threads.
2. Maintain a task queue.
3. Each thread picks tasks from the queue.
4. Use `std::condition_variable` to notify waiting threads.
5. Properly shutdown all threads on program exit.

Would you like a code implementation for this?

---

### 🔹 **15. What is false sharing?**

False sharing happens when **multiple threads modify variables that are on the same cache line**, leading to performance degradation.

> Solution: Padding or aligning variables to separate cache lines.

---

### 🔹 **16. Describe a multithreading bug you encountered and how you fixed it.**

*(Example answer for a fresher intern):*
During my internship, I used a shared vector in multiple threads without protection, leading to data corruption. I fixed it by wrapping accesses with `std::mutex` and used `std::lock_guard` to ensure thread safety.

---

### 🔹 **17. How do you test and debug multithreaded code?**

* Use tools like **Valgrind**, **ThreadSanitizer**, or **Visual Studio debugger**.
* Add logging with thread IDs.
* Reproduce bugs with controlled inputs and `sleep()` if needed.
* Avoid data races by reviewing shared data access.

---

### 🔹 **18. How would you handle exception safety in threads?**

* Wrap thread functions in try-catch blocks.
* Use `std::future` and `std::async` to propagate exceptions safely.
* Avoid resource leaks using RAII (e.g., `std::lock_guard`).

---

###🔸 **19.When would you prefer std::async over std::thread?**<br>
✅ Use std::async when:

* You want simpler thread management
* You need return values or exception propagation
* You don’t want to manage join() manually

---

