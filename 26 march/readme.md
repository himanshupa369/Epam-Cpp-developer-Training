<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>C++ Interview Preparation</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 20px;
            padding: 20px;
            background-color: #f4f4f4;
        }
        .container {
            max-width: 900px;
            margin: auto;
            background: white;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }
        h1, h2, h3 {
            color: #333;
        }
        pre {
            background: #eee;
            padding: 10px;
            border-radius: 5px;
            overflow-x: auto;
        }
        code {
            font-family: monospace;
            color: #d63384;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>C++ Interview Preparation</h1>
        <p>This document covers essential C++ concepts, exceptions, use cases, and best practices.</p>
        
        <h2>1. Mutable Keyword</h2>
        <p>The <code>mutable</code> keyword in C++ allows a class member variable to be modified even if the containing object is declared as <code>const</code>. This provides flexibility in scenarios where internal state changes do not alter the logical state of an object.</p>
        
        <h3>Key Properties:</h3>
        <ul>
            <li>Only applicable to **non-static** class member variables.</li>
            <li>Allows modification within <code>const</code> member functions.</li>
            <li>Useful in **caching**, **lazy evaluations**, **thread synchronization**, and **logging**.</li>
        </ul>
        
        <h3>Example 1: Basic Usage</h3>
        <pre><code>
#include &lt;iostream&gt;
class Test {
private:
    mutable int counter; // Can be modified even in a const object
public:
    Test() : counter(0) {}
    void update() const {
        counter++; // Allowed due to mutable
        std::cout << "Counter: " << counter << std::endl;
    }
};

int main() {
    const Test obj;
    obj.update(); // Works even though obj is const
    obj.update();
    return 0;
}
        </code></pre>
        
        <h3>Example 2: Mutable with Thread Synchronization</h3>
        <p>In multi-threaded applications, **mutable** is used to modify synchronization primitives like mutexes inside <code>const</code> member functions.</p>
        <pre><code>
#include &lt;iostream&gt;
#include &lt;mutex&gt;
class ThreadSafeLogger {
private:
    mutable std::mutex logMutex;
public:
    void logMessage(const std::string& msg) const {
        std::lock_guard<std::mutex> lock(logMutex);
        std::cout << "Log: " << msg << std::endl;
    }
};

int main() {
    ThreadSafeLogger logger;
    logger.logMessage("Thread-safe logging.");
    return 0;
}
        </code></pre>
        
        <h3>Example 3: Mutable with Caching</h3>
        <p>Using <code>mutable</code> to implement **lazy evaluation** and caching computed values.</p>
        <pre><code>
#include &lt;iostream&gt;
class DataProcessor {
private:
    mutable bool cacheValid;
    mutable int cachedResult;
public:
    DataProcessor() : cacheValid(false), cachedResult(0) {}
    int getProcessedData() const {
        if (!cacheValid) {
            cachedResult = computeHeavyOperation();
            cacheValid = true;
        }
        return cachedResult;
    }
private:
    int computeHeavyOperation() const {
        return 42; // Simulating a costly computation
    }
};

int main() {
    DataProcessor processor;
    std::cout << "Result: " << processor.getProcessedData() << std::endl;
    return 0;
}
        </code></pre>
        
        <h3>Use Cases:</h3>
        <ul>
            <li>Logging inside <code>const</code> member functions.</li>
            <li>Caching values that do not conceptually modify an object.</li>
            <li>Thread synchronization where internal changes do not affect the object's external state.</li>
            <li>Lazy evaluations to avoid recomputation.</li>
        </ul>
        
        <h3>When Not to Use:</h3>
        <ul>
            <li>If variable changes affect the logical state of the object.</li>
            <li>Overusing <code>mutable</code> can lead to code that is harder to understand and maintain.</li>
            <li>Should not be used as an excuse to modify state arbitrarily in a <code>const</code> object.</li>
        </ul>
    </div>
</body>
</html>

