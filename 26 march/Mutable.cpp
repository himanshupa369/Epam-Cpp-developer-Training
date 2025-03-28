//🔹 1️⃣ mutable Keyword
/* The mutable keyword allows a non-static class member variable to be modified inside a const function and lambda function. Normally, const functions cannot modify member variables, but mutable provides an exception. */

// 🔹 When to Use mutable?

// ✅ Use mutable when:
// ✔ You need to modify a variable inside a const function (e.g., caching, logging).
// ✔ You have non-critical state changes (e.g., tracking access count).

// 🚫 Avoid mutable when:
// ✔ You want strict const correctness.
// ✔ Modifying the variable breaks the expected behavior of const objects.



#include <iostream>
using namespace std;

class Example {
private:
    mutable int counter;  // Can be modified even in const functions

public:
    Example() : counter(0) {}

    void show() const {  // Const function
        counter++;  // ✅ Allowed due to 'mutable'
        cout << "Counter: " << counter << endl;
    }
};

int main() {
    Example obj;
    obj.show();
    obj.show();  // Counter will still increment
    
    int count = 0;

    auto lambda = [=]() mutable {  // Captures count by value, but allows modification
        count++;  // ✅ Allowed
        cout << "Inside lambda: " << count << endl;
    };

    lambda();
    cout << "Outside lambda: " << count << endl;  // Original count remains unchanged
    return 0;
}
