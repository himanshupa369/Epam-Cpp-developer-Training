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

// Example:-
#include <iostream>
#include <initializer_list>
#include <cassert>

class Bag {
	int arr[10];
	int m_Size{};
public:
	//Provides uniform initialization support for braced list of elements as arguments
	Bag(std::initializer_list<int> values) {
		assert(values.size() < 10);
		auto it = values.begin();
		while (it != values.end()) {
			Add(*it);
			++it;
		}
	}
	void Add(int value) {
		assert(m_Size < 10);
		arr[m_Size++] = value;
	}
	void Remove() {
		--m_Size;
	}
	int operator [](int index) {
		return arr[index];
	}
	int GetSize()const {
		return m_Size;
	}
};

void Print(std::initializer_list<int> values) {
	//auto it = values.begin();
	//while (it != values.end()) {
	//	std::cout << *it++ << " ";
	//}
	for (auto x : values) {
		std::cout << x << " ";
	}
}


int main() {
	int x{ 0 };
	float y{ 3.1f };
	int arr[5]{ 3,1,3,8,2 };
	std::string s{ "Hello C++" };
	std::initializer_list<int> data = { 1,2,3,4 };
	//Braced list of elements automatically creates an initializer_list object
	auto values = { 1,2,3,4 };

	//Bag b{ 3,1,8 };
	////b.Add(3);
	////b.Add(1);
	////b.Add(8);
	//for (int i = 0; i < b.GetSize(); ++i) {
	//	std::cout << b[i] << " "; 
	//}

	//Print({ 8,2,6,7 });
	for (auto x : { 8,2,6,7 }) {
		std::cout << x << " ";
	}
	return 0;
}
