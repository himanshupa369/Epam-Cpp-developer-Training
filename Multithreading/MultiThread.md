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

🔸 **19.When would you prefer std::async over std::thread?**<br>
✅ Use std::async when:

* You want simpler thread management
* You need return values or exception propagation
* You don’t want to manage join() manually

---
---

### 🔹 **1. What is the purpose of `std::thread::join()` in C++?**

✅ **Answer:**
`join()` blocks the calling thread (usually `main`) until the thread finishes execution. It ensures the thread completes before the program exits.

🧾 **Example:**

```cpp
void task() { std::cout << "Running...\n"; }

int main() {
    std::thread t(task);
    t.join(); // Waits for 't' to finish
}
```

---

### 🔹 **2. What happens if you don’t call `join()` or `detach()` on a thread?**

✅ **Answer:**
If a thread object is **not joined or detached**, it leads to a **runtime error** (e.g., `std::terminate()` will be called when the destructor runs).

---

### 🔹 **3. What is `std::thread::detach()` used for?**

✅ **Answer:**
`detach()` allows the thread to run **independently in the background**. The thread becomes **detached from the thread object**, and resources are released automatically after execution.

🧾 **Example:**

```cpp
void backgroundTask() { /* do something */ }

int main() {
    std::thread t(backgroundTask);
    t.detach(); // No need to join
}
```

> ❗ Be careful: you **can’t join a detached thread**, and there’s **no control or cleanup** after it.

---

### 🔹 **4. When should you use `detach()` instead of `join()`?**

✅ **Answer:**
Use `detach()` when:

* The thread runs **indefinitely** or performs **background work**.
* You **don’t need results** from the thread.
* You want the thread to **run independently** of the main thread's lifetime.

---

### 🔹 **5. What is `joinable()` in `std::thread` and why is it important?**

✅ **Answer:**
`joinable()` checks if a thread has **an associated running thread** that hasn't been joined or detached yet. It returns `true` if the thread can be joined or detached.

🧾 **Example:**

```cpp
std::thread t(task);

if (t.joinable()) {
    t.join();
}
```

> Always check `joinable()` before calling `join()` or `detach()` to avoid **undefined behavior**.

---

### 🔹 **6. Can you call `join()` or `detach()` more than once on a thread?**

❌ **No.** Calling `join()` or `detach()` **more than once** results in a **runtime exception** or **undefined behavior**.

---

### 🔹 **7. What happens if you destroy a thread object that is still joinable?**

❗ **Answer:**
It causes the program to call `std::terminate()` and crash.

🛡️ **Best Practice:**
Always check `joinable()` before destruction:

```cpp
std::thread t(task);
if (t.joinable()) t.join(); // Safe cleanup
```

---

### 🔹 **8. Can `join()` and `detach()` be used together on the same thread?**

❌ **No.** Once you call either `join()` or `detach()`, the thread is no longer joinable. Attempting to use both leads to an error.

---

### 🔹 **9. In what situation is `joinable()` false?**

✅ **Answer:**
`joinable()` is `false` when:

* The thread has not been started (default-constructed)
* The thread has been **joined**
* The thread has been **detached**
* The thread object has been **moved from**

---

### 🔹 **10. What happens if you try to `join()` a thread that is not joinable?**

❗ **Answer:**
It throws a `std::system_error` exception at runtime.

---
---

## ✅ **Interview Questions on `mutex` in C++**

---

### 🔸 1. **What is a `mutex` in C++? Why is it used?**

**Answer:**
A `mutex` (short for *mutual exclusion*) is used to protect **critical sections** — shared data that must not be accessed simultaneously by multiple threads. It ensures **only one thread can access the resource at a time**.

---

### 🔸 2. **How do you use `std::mutex` in C++?**

**Answer:**

```cpp
std::mutex mtx;

void threadFunc() {
    mtx.lock();
    // critical section
    mtx.unlock();
}
```

Or better:

```cpp
std::lock_guard<std::mutex> guard(mtx); // automatic unlock on scope exit
```

---

### 🔸 3. **What is `std::lock_guard` and why is it preferred?**

**Answer:**
`std::lock_guard` is an RAII wrapper around `std::mutex`. It automatically locks the mutex when created and unlocks it when it goes out of scope — avoiding manual `lock()`/`unlock()` errors.

---

### 🔸 4. **What is the difference between `std::lock_guard` and `std::unique_lock`?**

| Feature              | `lock_guard` | `unique_lock`        |
| -------------------- | ------------ | -------------------- |
| Simpler, faster      | ✅            | ❌ (slightly heavier) |
| Manual lock/unlock   | ❌            | ✅                    |
| Use with cond. vars? | ❌            | ✅                    |

---

### 🔸 5. **What is a deadlock? How can you prevent it when using mutexes?**

**Answer:**
A **deadlock** occurs when two or more threads are waiting on each other to release a resource, but none do.

**Prevention Techniques:**

* Always lock multiple mutexes in the **same order**.
* Use `std::lock()` to lock multiple mutexes atomically.
* Avoid nested locking when possible.

---

### 🔸 6. **What happens if one thread locks a mutex and another tries to lock it too?**

**Answer:**
The second thread will **block and wait** until the first thread unlocks the mutex.

---

### 🔸 7. **What is `std::recursive_mutex`? When would you use it?**

**Answer:**
A `recursive_mutex` allows **the same thread** to lock the mutex multiple times without deadlock.
Used when a function that locks the mutex is **called recursively**.

```cpp
std::recursive_mutex m;
void f() {
    m.lock();
    // do something
    f(); // recursive call
    m.unlock();
}
```

---

### 🔸 8. **What is `std::try_lock()`? When is it useful?**

**Answer:**
`try_lock()` attempts to lock the mutex but returns immediately with `true/false` instead of blocking.

Useful when:

* You want to do something else if the lock is unavailable (non-blocking behavior).

```cpp
if (mtx.try_lock()) {
    // do work
    mtx.unlock();
} else {
    // skip or try later
}
```

---

### 🔸 9. **What happens if a mutex is not unlocked?**

**Answer:**
The mutex stays locked, blocking other threads indefinitely → leading to **deadlocks or starvation**.

---

### 🔸 10. **What is `std::scoped_lock` (C++17)?**

**Answer:**
`std::scoped_lock` can lock **multiple mutexes** simultaneously and safely, preventing deadlocks due to inconsistent locking order.

```cpp
std::mutex m1, m2;
void f() {
    std::scoped_lock lock(m1, m2);
    // safe access
}
```

---

## 🔹 `try_lock()` – Interview Questions in C++

---

### 🔸 1. **What is `std::try_lock()` in C++?**

**Answer:**
`try_lock()` attempts to acquire the lock **without blocking**.
If the mutex is already locked, it **returns immediately** with `false`.
If it acquires the lock successfully, it returns `true`.

---

### 🔸 2. **What is the difference between `lock()` and `try_lock()`?**

| Feature     | `lock()`             | `try_lock()`                |
| ----------- | -------------------- | --------------------------- |
| Blocking    | Yes (waits for lock) | No (returns immediately)    |
| Return type | void                 | `bool`                      |
| Use case    | When waiting is okay | When non-blocking is needed |

---

### 🔸 3. **When would you prefer `try_lock()` over `lock()`?**

**Answer:**

* When you don’t want the thread to **block/wait**.
* In **polling situations**, **low-priority background tasks**, or to **avoid deadlock** by backing off.

Example:

```cpp
if (mtx.try_lock()) {
    // safe access
    mtx.unlock();
} else {
    // Do something else, try again later
}
```

---

### 🔸 4. **What happens if two threads call `try_lock()` at the same time?**

**Answer:**
Only **one thread will acquire the lock** and get `true`; the other will get `false` immediately and must handle failure logic (like retrying or skipping work).

---

### 🔸 5. **Can `try_lock()` cause a deadlock?**

**Answer:**
It helps **avoid** deadlocks when locking **multiple mutexes**, as it does **not block**.

Example:

```cpp
if (m1.try_lock()) {
    if (m2.try_lock()) {
        // safe work
        m2.unlock();
        m1.unlock();
    } else {
        m1.unlock();
    }
}
```

---

### 🔸 6. **What is `std::try_lock(m1, m2, ...)` with multiple mutexes?**

**Answer:**
It’s an overload in `<mutex>` that tries to lock multiple mutexes **without deadlock**.
It returns `-1` on success, or the index of the mutex that couldn’t be locked.

```cpp
int i = std::try_lock(m1, m2); // locks both or fails
if (i == -1) {
    // both locked successfully
} else {
    // handle lock failure at m[i]
}
```

---

### 🔸 7. **How would you use `try_lock()` in a performance-critical application?**

**Answer:**
Use it to:

* Try grabbing the lock quickly without blocking critical threads
* Avoid contention
* Log failed attempts or apply backoff strategies

---

### 🔸 8. **What are the drawbacks of using `try_lock()`?**

**Answer:**

* It may result in **busy waiting (polling)** if not used carefully
* Can lead to **unfair scheduling** or **starvation** for some threads
* Requires **manual retry or alternative logic**

---

### 🔸 9. **Is `try_lock()` exception-safe?**

**Answer:**
Yes, but if you acquire the lock with `try_lock()`, make sure to **manually unlock** it, or better, use `std::unique_lock` with `defer_lock`.

---

### 🔸 10. **Can `try_lock()` be used with `std::lock_guard` or `std::unique_lock`?**

**Answer:**

* `std::lock_guard` does **not support** `try_lock()`.
* `std::unique_lock` **does**:

```cpp
std::unique_lock<std::mutex> lock(mtx, std::try_to_lock);
if (lock.owns_lock()) {
    // locked successfully
}
```

---


