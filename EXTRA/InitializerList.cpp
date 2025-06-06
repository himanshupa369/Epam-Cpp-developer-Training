🔹std::initializer_list<T> (C++11)
This is a template class in the STL that allows passing a list of values using curly braces {} to constructors or functions.

✅ std::initializer_list – Key Points with Examples:_
  
| **No.** | **Concept**                          | **Explanation**                                                                       | **Example Code**                                                        |
| ------- | ------------------------------------ | ------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| 1️⃣     | Lightweight Proxy Object             | Represents an array-like structure without owning data                                | `std::initializer_list<int> list = {1, 2, 3};`                          |
| 2️⃣     | Automatic Construction               | Automatically created from brace-enclosed list                                        | `ListSum obj = {10, 20, 30};` (see custom constructor)                  |
| 3️⃣     | Auto Type Inference                  | `auto` with brace list deduces `initializer_list`                                     | `auto values = {4, 5, 6}; // std::initializer_list<int>`                |
| 4️⃣     | Range-Based For Loop Use             | Brace list in for-loop creates an `initializer_list` object                           | `for (int x : {1, 2, 3}) cout << x;`                                    |
| 5️⃣     | Function or Constructor Argument     | Brace list passed to a function or constructor is converted into an initializer\_list | `void print(std::initializer_list<int> nums)`<br>`print({10, 20, 30});` |
| 6️⃣     | Not a True STL Container             | Doesn't support full container operations (like push\_back, size changes, etc.)       | ❌ `list.push_back(4); // Error!`                                        |
| 7️⃣     | Provides Iterators                   | You can iterate using `.begin()` and `.end()`                                         | `for (auto it = list.begin(); it != list.end(); ++it)`                  |
| 8️⃣     | Requires `<initializer_list>` Header | Must include this header to use the class                                             | `#include <initializer_list>`                                           |

//Example :-
#include <iostream>
#include <initializer_list>
using namespace std;

class ListSum {
public:
    ListSum(initializer_list<int> nums) {
        int sum = 0;
        for (int n : nums) sum += n;
        cout << "Sum = " << sum << endl;
    }
};

int main() {
    ListSum obj = {1, 2, 3, 4};  // initializer list
}
