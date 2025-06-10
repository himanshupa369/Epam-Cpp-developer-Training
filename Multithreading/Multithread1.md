---

## ✅ Interview Questions on Deadlock (with Answers)

---

### 🔸 1. **What is a deadlock in multithreading?**

**Answer:**
A deadlock is a situation where **two or more threads are waiting forever for resources** held by each other, preventing further progress.

---

### 🔸 2. **Give a real-world example of deadlock.**

**Answer:**
Imagine:

* **Thread A** locks `mutex1` and waits for `mutex2`
* **Thread B** locks `mutex2` and waits for `mutex1`
  Both wait forever — that's a deadlock.

---

### 🔸 3. **What are the four Coffman conditions required for a deadlock to occur?**

**Answer:**

1. **Mutual Exclusion** – Resources can be held by only one thread
2. **Hold and Wait** – A thread holds one resource and waits for another
3. **No Preemption** – Resources can't be forcibly taken away
4. **Circular Wait** – A circular chain of threads waiting on each other

---

### 🔸 4. **How can you prevent deadlocks in C++?**

**Answer:**

* Always acquire locks in a **consistent order**
* Use `std::lock()` for **atomic locking of multiple mutexes**
* Avoid holding locks longer than necessary
* Use **timeout mechanisms** (`try_lock_for`, `try_lock_until`)

---

### 🔸 5. **Write a code example that can cause a deadlock.**

```cpp
std::mutex m1, m2;

void thread1() {
    std::lock_guard<std::mutex> lock1(m1);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock2(m2);
}

void thread2() {
    std::lock_guard<std::mutex> lock2(m2);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::lock_guard<std::mutex> lock1(m1);
}
```

Here, both threads can deadlock if they acquire the first mutex and wait for the second.

---

### 🔸 6. **How does `std::lock()` help prevent deadlocks?**

**Answer:**
`std::lock()` atomically locks multiple mutexes **without deadlock**, using a safe internal order.

```cpp
std::lock(m1, m2);
std::lock_guard<std::mutex> lock1(m1, std::adopt_lock);
std::lock_guard<std::mutex> lock2(m2, std::adopt_lock);
```

---

### 🔸 7. **What is the difference between deadlock and livelock?**

**Answer:**

| Feature | Deadlock                 | Livelock                          |
| ------- | ------------------------ | --------------------------------- |
| Threads | Blocked, not progressing | Active, but still not progressing |
| Cause   | Waiting on each other    | Constantly reacting to others     |
| Example | Circular wait            | Two threads repeatedly yielding   |

---

### 🔸 8. **How can `try_lock()` be used to avoid deadlocks?**

**Answer:**
It tries to acquire a lock **without blocking**.
If locking fails, the thread can **back off and retry later**, avoiding circular wait.

---

### 🔸 9. **Can `std::recursive_mutex` help with deadlocks?**

**Answer:**
It helps **avoid self-deadlock** when a thread tries to re-lock the same mutex, but it doesn't prevent deadlocks between multiple threads.

---

### 🔸 10. **What tools can you use to detect deadlocks in C++ code?**

**Answer:**

* **Valgrind’s Helgrind**
* **ThreadSanitizer (TSan)**
* **Static analyzers** (like Clang-Tidy)
* Logging/thread visualization tools

---
---

## ✅ Interview Questions on Thread Synchronization in C++

---

### 🔸 1. **What is thread synchronization?**

**Answer:**
Thread synchronization is the process of **controlling access to shared resources** in a multithreaded program to avoid **race conditions, data corruption, or undefined behavior**.

---

### 🔸 2. **Why is synchronization important in multithreading?**

**Answer:**
Without synchronization:

* Multiple threads may read/write shared data simultaneously
* Results can become inconsistent or unpredictable
* Crashes or corrupted output can occur

---

### 🔸 3. **What are the common synchronization tools in C++?**

**Answer:**

* `std::mutex`
* `std::recursive_mutex`
* `std::timed_mutex`
* `std::shared_mutex` (C++17)
* `std::condition_variable`
* `std::atomic`

---

### 🔸 4. **What is a race condition?**

**Answer:**
A race condition occurs when **two or more threads access shared data at the same time**, and the result depends on the **timing or order** of execution.

---

### 🔸 5. **How does `std::mutex` help in synchronization?**

**Answer:**
`std::mutex` ensures **mutual exclusion**, allowing only one thread at a time to execute a block of code that accesses shared data.

```cpp
std::mutex m;
void safe() {
    std::lock_guard<std::mutex> lock(m);
    // critical section
}
```

---

### 🔸 6. **What is a critical section?**

**Answer:**
A critical section is a part of the program where **shared data is accessed**.
It must be **protected by synchronization mechanisms** like mutexes to avoid conflicts.

---

### 🔸 7. **What happens if a mutex is not released properly?**

**Answer:**
Other threads will block forever waiting for the mutex — causing a **deadlock**.
RAII wrappers like `std::lock_guard` help avoid this.

---

### 🔸 8. **Difference between `lock_guard` and `unique_lock` for synchronization?**

| Feature       | `std::lock_guard` | `std::unique_lock`     |
| ------------- | ----------------- | ---------------------- |
| RAII Lock     | ✅ Yes             | ✅ Yes                  |
| Manual unlock | ❌ No              | ✅ Yes (`unlock()`)     |
| Timed Locking | ❌ No              | ✅ Yes (`try_lock_for`) |
| Movable       | ❌ No              | ✅ Yes                  |

---

### 🔸 9. **What is `std::atomic` and how is it used in synchronization?**

**Answer:**
`std::atomic` provides **lock-free synchronization** for primitive types.
Operations like load, store, increment, compare-exchange are **thread-safe**.

```cpp
std::atomic<int> counter = 0;
counter.fetch_add(1);
```

---

### 🔸 10. **How does `condition_variable` aid in synchronization?**

**Answer:**
`std::condition_variable` allows threads to **wait for a condition** to become true.
Useful in **producer-consumer problems**.

```cpp
std::mutex m;
std::condition_variable cv;
bool ready = false;

void consumer() {
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, [] { return ready; }); // waits until ready == true
    // proceed
}
```

---

### 🔸 11. **What is spurious wake-up and how to handle it?**

**Answer:**
A thread may wake up from `wait()` even if the condition is false.
Always use `wait(lock, predicate)` or check the condition in a loop.

---

### 🔸 12. **Difference between blocking and non-blocking synchronization?**

| Feature       | Blocking             | Non-blocking                 |
| ------------- | -------------------- | ---------------------------- |
| Example       | `std::mutex::lock()` | `try_lock()` / `std::atomic` |
| Wait behavior | Waits until acquired | Tries once, may fail         |
| CPU usage     | Less efficient       | Can reduce wait time         |

---

### 🔸 13. **How can deadlocks be avoided in synchronization?**

**Answer:**

* Lock mutexes in **consistent order**
* Use `std::lock()` for multiple locks
* Use **timeout-based locking** (`try_lock_for`)
* Minimize lock scope

---
---

## ✅ Interview Questions on `std::lock` in C++

---

### 🔸 1. **What is `std::lock` in C++?**

**Answer:**
`std::lock` is a C++ Standard Library function that **locks multiple mutexes atomically** to prevent **deadlocks** when multiple threads lock shared resources.

---

### 🔸 2. **Why do we use `std::lock` instead of locking mutexes manually?**

**Answer:**
Manual locking (e.g., `mutex1.lock(); mutex2.lock();`) can lead to **deadlocks** if another thread locks them in a different order.
`std::lock` ensures a **deadlock-free** locking of multiple mutexes, regardless of order.

---

### 🔸 3. **What happens if one of the mutexes passed to `std::lock()` is already locked by the same thread?**

**Answer:**
It will result in **undefined behavior or deadlock**. You should not pass a **mutex that is already locked by the same thread** unless it's a `recursive_mutex`.

---

### 🔸 4. **Write a code example using `std::lock` safely.**

```cpp
std::mutex m1, m2;

void safeAccess() {
    std::lock(m1, m2);  // lock both without deadlock
    std::lock_guard<std::mutex> lg1(m1, std::adopt_lock);
    std::lock_guard<std::mutex> lg2(m2, std::adopt_lock);
    // critical section
}
```

---

### 🔸 5. **What is `std::adopt_lock` and why is it used with `std::lock`?**

**Answer:**
`std::adopt_lock` tells the lock\_guard or unique\_lock **not to lock the mutex**, because it has already been locked by `std::lock()`.

---

### 🔸 6. **Can `std::lock` throw exceptions?**

**Answer:**
Yes. If any mutex throws an exception during locking (e.g., due to system error), `std::lock()` will throw, and **any mutexes that were already locked will be unlocked automatically**.

---

### 🔸 7. **What are the requirements for mutexes passed to `std::lock()`?**

**Answer:**

* All mutexes must be **different objects**
* They should not be **already locked**
* They must support **lock()** and **unlock()** (like `std::mutex`)

---

### 🔸 8. **Can you use `std::unique_lock` with `std::lock()`?**

**Answer:**
Yes. Use `std::lock()` to lock the mutexes first, then construct `unique_lock` with `std::adopt_lock`.

```cpp
std::mutex m1, m2;

void threadFunc() {
    std::lock(m1, m2);
    std::unique_lock<std::mutex> lk1(m1, std::adopt_lock);
    std::unique_lock<std::mutex> lk2(m2, std::adopt_lock);
}
```

---

### 🔸 9. **What is the difference between `std::lock` and `std::scoped_lock`?**

| Feature              | `std::lock`             | `std::scoped_lock` (C++17)             |
| -------------------- | ----------------------- | -------------------------------------- |
| Locking type         | Function                | RAII class                             |
| Manual unlock needed | No                      | No (automatic on destruction)          |
| Usage complexity     | Medium (requires adopt) | Easy (directly takes multiple mutexes) |

---

### 🔸 10. **Is `std::lock` blocking or non-blocking?**

**Answer:**
`std::lock` is a **blocking operation**. It blocks until all mutexes can be acquired safely without deadlock.

---

### 🔸 11. **Can `std::lock` be used with timed or recursive mutexes?**

**Answer:**
Yes — but only if those mutex types implement `lock()` and `unlock()`.
You **cannot** use `std::lock` for timed locking (`try_lock_for`) — use manual logic for that.

---

### 🔸 12. **What happens if you pass the same mutex twice to `std::lock`?**

```cpp
std::lock(mutex, mutex); // Is this safe?
```

**Answer:**
❌ No — this leads to **undefined behavior**. Never pass the **same mutex** multiple times to `std::lock()`.

---
---

## ✅ Interview Questions on `std::promise` and `std::future` in C++

---

### 🔸 1. **What is `std::promise` in C++?**

**Answer:**
`std::promise` is an object used to **set a value or exception** that will be **retrieved asynchronously by a `std::future`**.

---

### 🔸 2. **What is `std::future`?**

**Answer:**
`std::future` is an object that **retrieves the result** from a `std::promise` (or `std::async`) when it's ready.
It represents a **value to be set in the future**.

---

### 🔸 3. **How do `promise` and `future` work together?**

**Answer:**

* A `std::promise` creates a **communication channel**.
* The associated `std::future` retrieves the result once the promise sets it.

```cpp
std::promise<int> p;
std::future<int> f = p.get_future();

std::thread t([&p]() {
    p.set_value(42);
});

std::cout << f.get();  // Waits for value from promise
t.join();
```

---

### 🔸 4. **What happens if `get()` is called before the promise sets the value?**

**Answer:**
The `get()` call on `future` **blocks** until the value becomes available.

---

### 🔸 5. **What happens if `set_value()` is never called?**

**Answer:**
If the future tries to get the value, and the promise is destroyed without setting it, a `std::future_error` exception is thrown.

---

### 🔸 6. **What is `std::future_status` and how is it used?**

**Answer:**
`std::future_status` is used with `future.wait_for()` or `future.wait_until()` to check status:

* `future_status::ready`
* `future_status::timeout`
* `future_status::deferred`

```cpp
if (f.wait_for(std::chrono::seconds(1)) == std::future_status::ready)
    std::cout << f.get();
```

---

### 🔸 7. **What is the difference between `get()` and `wait()` on `future`?**

| Function | Behavior                                        |
| -------- | ----------------------------------------------- |
| `get()`  | Waits and retrieves the result (only once)      |
| `wait()` | Only waits for result, does **not retrieve** it |

---

### 🔸 8. **What happens if `set_value()` is called multiple times?**

**Answer:**
It throws a `std::future_error`, because a promise can **only set a value once**.

---

### 🔸 9. **How can you use `std::promise` to send exceptions between threads?**

```cpp
std::promise<int> p;
std::future<int> f = p.get_future();

std::thread t([&]() {
    try {
        throw std::runtime_error("error");
    } catch (...) {
        p.set_exception(std::current_exception());
    }
});

try {
    f.get();
} catch (const std::exception& e) {
    std::cout << e.what();  // Outputs: error
}
t.join();
```

---

### 🔸 10. **What is the difference between `std::async` and `std::promise` + `std::future`?**

| Feature           | `std::async` | `std::promise` + `std::future` |
| ----------------- | ------------ | ------------------------------ |
| Simpler usage     | ✅            | ❌ (Manual management needed)   |
| Thread management | Automatic    | Manual (`std::thread`)         |
| Value passing     | Return value | Explicit set via `set_value()` |

---

### 🔸 11. **Can you move a promise or future?**

**Answer:**
Yes. `std::promise` and `std::future` **are movable** but **not copyable**, because each represents unique ownership of the communication channel.

---

### 🔸 12. **How do you use `shared_future` and how is it different from `future`?**

| `std::future`          | `std::shared_future`             |
| ---------------------- | -------------------------------- |
| Single ownership       | Multiple threads can share       |
| `.get()` callable once | `.get()` callable multiple times |

---
---

## ✅ Interview Questions on `std::async` in C++

---

### 🔸 1. **What is `std::async` in C++?**

**Answer:**
`std::async` is a function template in C++ that runs a **function asynchronously**, potentially on a new thread, and returns a `std::future` that holds the result.

---

### 🔸 2. **What is returned by `std::async`?**

**Answer:**
It returns a `std::future<T>`, where `T` is the return type of the function passed to `std::async`.

---

### 🔸 3. **Write a simple example of `std::async`.**

```cpp
int compute() {
    return 42;
}

std::future<int> fut = std::async(compute);
int result = fut.get();  // Blocks until compute() finishes
```

---

### 🔸 4. **What are the launch policies of `std::async`?**

**Answer:**
`std::launch::async` — forces a **new thread**
`std::launch::deferred` — **runs only when `.get()` or `.wait()` is called**
`std::launch::async | std::launch::deferred` — implementation decides (default)

---

### 🔸 5. **Difference between `std::async` and `std::thread`?**

| Feature            | `std::async`               | `std::thread`                   |
| ------------------ | -------------------------- | ------------------------------- |
| Return value       | Captured via `std::future` | Manual communication needed     |
| Thread management  | Automatic                  | Manual (must `join()`/`detach`) |
| Exception handling | Automatic (via `future`)   | Manual                          |

---

### 🔸 6. **What happens if you don't call `.get()` on the future?**

**Answer:**
If the policy is `deferred`, the function **might never run**.
If it’s `async`, the thread runs, but the result is discarded unless `.get()` is called.

---

### 🔸 7. **Can `std::async` throw exceptions?**

**Answer:**
Yes, if the **function inside throws**, the exception is stored and rethrown when you call `.get()` on the returned `future`.

---

### 🔸 8. **What is deferred execution in `std::async`?**

**Answer:**
If `std::launch::deferred` is specified, the function won’t execute until `future.get()` or `future.wait()` is called.
It runs **synchronously on the calling thread**.

---

### 🔸 9. **How do you check if an `async` task has completed?**

```cpp
if (fut.wait_for(std::chrono::seconds(0)) == std::future_status::ready)
    std::cout << "Done";
```

Use `wait_for()` or `wait_until()` on the future object.

---

### 🔸 10. **How do exceptions thrown in `std::async` get propagated?**

**Answer:**
The exception is **captured** by the `std::future`.
It is **re-thrown** when you call `.get()` on the future.

---

### 🔸 11. **Does `std::async` always create a new thread?**

**Answer:**
Only if you use `std::launch::async`.
Without that, the system may choose to **defer execution** or run it on a thread pool.

---

### 🔸 12. **What happens if you copy or move a future returned by `std::async`?**

**Answer:**
`std::future` is **move-only**, not copyable.
You can **move it** to transfer ownership.

---

### 🔸 13. **When should you prefer `std::async` over `std::thread`?**

**Answer:**
Use `std::async` when:

* You need the **return value** of the task
* You want **automatic lifetime and exception handling**
* You prefer **simpler code**

---

### 🔸 14. **Can you pass arguments to the function in `std::async`?**

**Answer:**
Yes, just like a normal function call.

```cpp
int add(int a, int b) { return a + b; }
auto fut = std::async(add, 5, 10);
std::cout << fut.get();  // 15
```

---
---

## ✅ Interview Questions on Producer-Consumer Problem in C++

---

### 🔸 1. **What is the Producer-Consumer problem?**

**Answer:**
It's a classic multi-threading synchronization problem where:

* The **Producer** generates data and puts it into a shared buffer.
* The **Consumer** takes data out of the buffer.
  Proper synchronization is required to prevent **race conditions**, **overflows**, and **underflows**.

---

### 🔸 2. **What are the main challenges in solving it?**

**Answer:**

* Synchronizing access to shared buffer
* Preventing buffer **overflow** (producer too fast)
* Preventing buffer **underflow** (consumer too fast)
* Avoiding **deadlock** and **race conditions**

---

### 🔸 3. **What synchronization tools are typically used in C++?**

**Answer:**

* `std::mutex` for mutual exclusion
* `std::condition_variable` for signaling between threads
* Optionally `std::queue` as the shared buffer

---

### 🔸 4. **How does `std::condition_variable` help in this problem?**

**Answer:**
It allows a thread to **wait** (sleep) until:

* Producer has space to produce
* Consumer has data to consume
  It avoids busy waiting by putting threads to **sleep efficiently** until a condition is met.

---

### 🔸 5. **Write a simplified code example (bounded buffer):**

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> buffer;
const unsigned int MAX_SIZE = 5;

std::mutex mtx;
std::condition_variable cv;

void producer() {
    int value = 0;
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [](){ return buffer.size() < MAX_SIZE; });

        buffer.push(value);
        std::cout << "Produced: " << value++ << '\n';

        lock.unlock();
        cv.notify_all();  // notify consumers
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [](){ return !buffer.empty(); });

        int val = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << val << '\n';

        lock.unlock();
        cv.notify_all();  // notify producers
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}
```

---

### 🔸 6. **How does the above code prevent deadlock and race conditions?**

**Answer:**

* Uses `std::mutex` to **lock access** to shared buffer.
* Uses `cv.wait(lock, condition)` to **sleep and wake** threads properly.
* Uses `notify_all()` to **wake up** waiting producers/consumers when buffer state changes.

---

### 🔸 7. **What is a bounded buffer, and why is it used?**

**Answer:**
A buffer with **limited capacity**, e.g., size 5.
It's used to simulate **real-world constraints** (e.g., memory limit) and force the need for **synchronization**.

---

### 🔸 8. **What happens if you don’t use `cv.wait()` and just check conditions in a loop?**

**Answer:**
It causes **busy waiting**, which wastes CPU cycles by continuously checking conditions rather than sleeping.

---

### 🔸 9. **How would you solve it using `std::async`, `std::future`, or `promise`?**

**Answer:**
These are not ideal for repeated coordination between threads. They're better suited for **one-time communication**.
Use `mutex + condition_variable` for continuous producer-consumer coordination.

---

### 🔸 10. **How can you extend this to multiple producers and consumers?**

**Answer:**

* Launch multiple threads for producer and consumer.
* Use the **same shared queue**, mutex, and condition variable.
* Synchronization logic remains the same.

---

---

## ✅ Interview Questions on `sleep` vs `wait` in C++ Multithreading

---

### 🔸 1. **What is the difference between `sleep` and `wait` in C++?**

| Feature       | `sleep`                          | `wait` (`std::condition_variable`)           |
| ------------- | -------------------------------- | -------------------------------------------- |
| Purpose       | Pauses the thread for fixed time | Waits for a condition to become true         |
| Thread state  | Always sleeps                    | Sleeps only if condition is false            |
| CPU usage     | Passive (no CPU used)            | Passive (efficient wait)                     |
| Wakes up when | Time expires                     | `notify_one()` or `notify_all()` is called   |
| Use case      | Delays, simulation               | Thread coordination, producer-consumer, etc. |

---

### 🔸 2. **How do you use `std::this_thread::sleep_for()`?**

```cpp
#include <thread>
#include <chrono>

std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Sleeps for 100 ms
```

It **suspends the thread** for a fixed duration.

---

### 🔸 3. **What is `std::this_thread::sleep_until()`?**

It pauses the thread until a **specific time point**.

```cpp
std::this_thread::sleep_until(std::chrono::steady_clock::now() + std::chrono::seconds(2));
```

---

### 🔸 4. **How does `wait()` work with `std::condition_variable`?**

```cpp
std::condition_variable cv;
std::mutex mtx;
std::unique_lock<std::mutex> lock(mtx);

cv.wait(lock, []{ return condition_is_met; });
```

It **releases the mutex**, puts the thread to sleep, and wakes it only when:

* It's notified via `cv.notify_one()` / `notify_all()`, and
* The condition becomes true

---

### 🔸 5. **What happens if `wait()` is used without a condition predicate?**

```cpp
cv.wait(lock);  // Unsafe
```

This can lead to **spurious wakeups**, where a thread wakes up **without a notify**.
**Best Practice:** Always use `cv.wait(lock, predicate)` form.

---

### 🔸 6. **Can `sleep_for()` be interrupted like `wait()`?**

**Answer:**
No. `sleep_for()` **cannot be interrupted** by another thread.
`wait()` can be interrupted via `notify_one()`/`notify_all()`.

---

### 🔸 7. **Which is better for synchronizing threads: sleep or wait?**

**Answer:**
`wait()` is **better and more efficient** for thread synchronization.
`sleep_for()` is generally used for timing/simulation delays — **never for synchronization**.

---

### 🔸 8. **What are spurious wakeups in `wait()`?**

**Answer:**
These are cases where `wait()` **returns without any notify**.
Hence, always use a **predicate form**:

```cpp
cv.wait(lock, []{ return ready; });
```

---

### 🔸 9. **What is the effect of calling `notify_one()` before `wait()` is called?**

**Answer:**
The notification is **lost** if no thread is currently waiting.
This is why `wait()` is placed **before** `notify_one()` in thread coordination.

---

### 🔸 10. **Can you use `sleep` to simulate a slow producer or consumer?**

**Answer:**
Yes. For example:

```cpp
std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Simulate slow producer
```

Used in demos to **simulate real-time delays**, not for synchronization.

---
---

## ✅ Interview Questions on Mutex, Semaphore & Binary Semaphore in C++

---

### 🔸 1. **What is a mutex?**

**Answer:**
A `mutex` (**mutual exclusion**) is a synchronization primitive used to **protect shared resources** from concurrent access by multiple threads.

```cpp
std::mutex mtx;
mtx.lock();
// critical section
mtx.unlock();
```

---

### 🔸 2. **What is a semaphore?**

**Answer:**
A **semaphore** is a signaling mechanism that **controls access** to a shared resource using a **counter**.

* A semaphore with count `n` allows `n` threads to enter.
* When a thread acquires it, count decreases.
* When released, count increases.

C++20 provides `std::counting_semaphore`.

---

### 🔸 3. **What is a binary semaphore?**

**Answer:**
A **binary semaphore** is a semaphore with a maximum count of **1**.
It works similar to a **mutex**, but:

* It’s more general-purpose for signaling (not just mutual exclusion)
* Doesn’t require a specific thread to unlock

---

### 🔸 4. **Difference Between Mutex and Binary Semaphore**

| Feature       | `mutex`                 | `binary semaphore`      |
| ------------- | ----------------------- | ----------------------- |
| Ownership     | Thread owns the lock    | No ownership            |
| Usage         | Mutual exclusion        | Signaling or exclusion  |
| Unlock by     | Same thread only        | Any thread              |
| Deadlock risk | Higher (if not careful) | Lower (signaling-based) |

---

### 🔸 5. **When would you use a semaphore over a mutex?**

**Answer:**
Use a **semaphore** when:

* Multiple identical resources are available (count > 1)
* You want to **signal** between threads (e.g., producer-consumer)

Use a **mutex** when:

* Only one thread should access a resource at a time

---

### 🔸 6. **Is C++11 semaphore available?**

No. Semaphores were **added in C++20** via:

```cpp
#include <semaphore>

std::counting_semaphore<3> sem(3); // allows 3 threads
```

Before C++20, developers used:

* OS-level APIs (e.g., POSIX semaphores)
* Workarounds like condition variables and counters

---

### 🔸 7. **Code Example: Binary Semaphore with C++20**

```cpp
#include <semaphore>
#include <thread>
#include <iostream>

std::binary_semaphore binSem(1); // works like a mutex

void task(int id) {
    binSem.acquire();  // Wait
    std::cout << "Thread " << id << " in critical section\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    binSem.release();  // Signal
}

int main() {
    std::thread t1(task, 1);
    std::thread t2(task, 2);
    t1.join();
    t2.join();
}
```

---

### 🔸 8. **Can a semaphore cause a deadlock?**

**Answer:**
Yes, if threads wait indefinitely without being released, or if the **release logic is flawed**, leading to blocked threads forever.

---

### 🔸 9. **How do mutexes prevent race conditions?**

**Answer:**
They **serialize access** to critical sections, so only one thread modifies the shared data at a time.

---

### 🔸 10. **Mutex vs Semaphore Summary**

| Feature   | Mutex            | Semaphore                    |
| --------- | ---------------- | ---------------------------- |
| Controls  | One thread only  | Multiple threads             |
| Count     | No               | Yes (can be 1 or more)       |
| Ownership | Thread-specific  | Not thread-specific          |
| Usage     | Mutual exclusion | Signaling, producer-consumer |
| Type      | Lock             | Counter                      |

---
---

## ✅ Interview Questions on `std::atomic` in C++

---

### 🔸 1. **What is an atomic variable in C++?**

**Answer:**
An atomic variable is a variable that supports **atomic (indivisible) operations**, meaning operations like read, write, increment, etc., are performed **without interruption** from other threads.

```cpp
#include <atomic>

std::atomic<int> counter = 0;
```

---

### 🔸 2. **Why do we use `std::atomic`?**

**Answer:**
To prevent **race conditions** without using `mutex`.
Atomic operations are **lock-free** (in most cases) and **faster** than mutexes.

---

### 🔸 3. **Is `std::atomic` thread-safe?**

**Answer:**
Yes, operations on `std::atomic` variables are **thread-safe by design**.
Example:

```cpp
counter++; // Atomic increment, safe across threads
```

---

### 🔸 4. **Give an example of race condition solved by `atomic`:**

Without atomic (unsafe):

```cpp
int count = 0;
void increment() { count++; }  // Race condition
```

With atomic (safe):

```cpp
std::atomic<int> count = 0;
void increment() { count++; }  // Thread-safe
```

---

### 🔸 5. **What types can be atomic?**

Most **primitive types**:

* `int`, `bool`, `float`, `pointer`
* Custom types if they are trivially copyable (with `std::atomic<T>` specialization)

---

### 🔸 6. **How does `fetch_add()` work?**

```cpp
std::atomic<int> x = 0;
x.fetch_add(1);  // Atomically adds 1 and returns old value
```

Other atomic methods:

* `fetch_sub()`, `exchange()`, `compare_exchange_weak/strong()`

---

### 🔸 7. **What is `compare_exchange_weak()` used for?**

Used in **lock-free algorithms** (like atomic stacks/queues).

```cpp
int expected = 10;
if (x.compare_exchange_weak(expected, 20)) {
    // value was 10, now changed to 20
}
```

---

### 🔸 8. **What are memory orderings in atomics?**

**Answer:**
Control how operations are **seen across threads**. Common ones:

* `memory_order_relaxed`
* `memory_order_acquire`
* `memory_order_release`
* `memory_order_seq_cst` (default)

Example:

```cpp
x.store(10, std::memory_order_release);
int val = x.load(std::memory_order_acquire);
```

For interviews, knowing **relaxed vs acquire-release vs sequential consistency** is useful.

---

### 🔸 9. **Is `std::atomic` faster than `std::mutex`?**

**Answer:**
Yes, typically faster because it avoids kernel-level locking.
But it’s limited to **simple operations**.

---

### 🔸 10. **Can atomic variables cause deadlocks?**

**Answer:**
No. Atomics **don’t block**, so they cannot cause deadlocks — a big advantage over `mutex`.

---

### 🔸 11. **What is `std::atomic_flag`?**

A low-level atomic boolean flag, useful for implementing spinlocks:

```cpp
std::atomic_flag flag = ATOMIC_FLAG_INIT;

if (!flag.test_and_set()) {
    // enter critical section
    flag.clear(); // release
}
```

---

### 🔸 12. **When not to use `std::atomic`?**

Avoid atomics when:

* You're dealing with complex logic (not just counters)
* You need strong consistency across multiple variables (use `mutex`)
* Portability or memory ordering is a concern

---

## ✅ Summary Table

| Feature            | `std::atomic`             | `std::mutex`                    |
| ------------------ | ------------------------- | ------------------------------- |
| Thread-safe?       | ✅ Yes                     | ✅ Yes                           |
| Blocking?          | ❌ No                      | ✅ Yes (may block other threads) |
| Performance        | 🚀 Fast (for simple ops)  | ⛓️ Slower (more overhead)       |
| Deadlock possible? | ❌ No                      | ✅ Yes                           |
| Use case           | Counters, flags, pointers | Complex critical sections       |

---
---

## ✅ 1. `std::scoped_lock` in C++ (C++17)

### 🔸 Interview Question: What is `std::scoped_lock`?

**Answer:**
It is a C++17 RAII-style lock guard that can **lock multiple mutexes** at once, **deadlock-free**.

```cpp
std::mutex m1, m2;

void func() {
    std::scoped_lock lock(m1, m2);  // Locks both mutexes safely
    // Critical section
}
```

### 🔸 Key Points:

* Safer alternative to `std::lock_guard` for multiple mutexes
* Avoids deadlocks by **locking in a consistent order internally**
* Releases all locks automatically when going out of scope

---

## ✅ 2. Oversubscription

### 🔸 Interview Question: What is thread oversubscription?

**Answer:**
**Oversubscription** happens when **more threads are created than CPU cores** available.

Example: On a 4-core CPU, creating 100 threads → oversubscription

### 🔸 Why is it bad?

* Increases **context-switching overhead**
* Reduces performance and cache efficiency
* Threads **spend more time switching** than executing

### 🔸 Interview follow-up: How do you prevent it?

* Use **thread pools**
* Use `std::thread::hardware_concurrency()` to query core count
* Avoid creating a thread per task

---

## ✅ 3. Thread Pool

### 🔸 Interview Question: What is a Thread Pool?

**Answer:**
A **thread pool** is a collection of worker threads reused to execute multiple tasks efficiently, reducing the overhead of creating/destroying threads repeatedly.

### 🔸 Example Use Case:

* Server handling 1000 client requests
* Instead of 1000 threads, use a **fixed pool** (e.g., 8 threads) to handle tasks concurrently

### 🔸 Basic C++ Concept (pseudo-code):

```cpp
std::queue<std::function<void()>> taskQueue;
std::vector<std::thread> workers;
```

Each worker:

```cpp
while (running) {
    if (!taskQueue.empty()) {
        auto task = taskQueue.front(); taskQueue.pop();
        task();
    }
}
```

### 🔸 Benefits:

* Avoids oversubscription
* Improves performance via thread reuse
* Easier to manage resource limits

### 🔸 C++ Libraries Supporting It:

* Boost.ThreadPool
* Intel TBB
* Custom implementations
* C++20 introduces `std::jthread` (not a full pool but helps lifecycle)

---

## ✅ 4. Object Pool

### 🔸 Interview Question: What is an Object Pool?

**Answer:**
An object pool is a design pattern that **pre-allocates a fixed set of reusable objects** to avoid the cost of frequent allocation/deallocation.

### 🔸 Use Case:

* Database connections
* Network sockets
* Reusable buffers (game dev, embedded systems)

### 🔸 Pseudocode:

```cpp
class ObjectPool {
    std::vector<MyObject*> pool;
public:
    MyObject* acquire();
    void release(MyObject*);
};
```

### 🔸 Benefits:

* **Reduces dynamic memory allocation cost**
* Predictable performance
* Ideal for **real-time or high-performance** systems

---

## ✅ Summary Table

| Concept          | Purpose                             | Benefit                       | C++ Support          |
| ---------------- | ----------------------------------- | ----------------------------- | -------------------- |
| `scoped_lock`    | Lock multiple mutexes safely        | Deadlock-free multi-lock      | C++17                |
| Oversubscription | Too many threads > CPU cores        | Reduces performance, avoid it | NA                   |
| Thread Pool      | Reuse a fixed number of threads     | Efficient task management     | Manual/C++20 helpers |
| Object Pool      | Reuse objects instead of new/delete | Fast, memory-efficient        | Manual               |

---



