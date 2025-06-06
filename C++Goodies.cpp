//The enum keyword in C++ defines a set of named integral constants. It helps make code more readable and maintainable.
#include <iostream>
enum class Color: long{ RED = 1, GREEN = 2, BLUE = 3 };

int main() {
    Color c = RED;

    // Convert enum to int
    int i = static_cast<int>(c);
    std::cout << "Enum as int: " << i << std::endl;  // Outputs: 1

    // Convert int to enum
    int input = 2;
    Color c2 = static_cast<Color>(input);
    std::cout << "Int to enum: " << static_cast<int>(c2) << std::endl;  // Outputs: 2
}

// string :- 

//string streams 

#include <iostream>
#include <sstream>   // Required for stringstream
#include <string>
#include <vector>

/*
🔷 THEORY: STRINGSTREAM IN C++

👉 Header: #include <sstream>
👉 Purpose: To perform input/output operations on strings (just like cin/cout on console).

| Method       | Purpose                              |
| ------------ | ------------------------------------ |
| `str()`      | Get internal buffer as string        |
| `str("...")` | Set new buffer                       |
| `clear()`    | Clear stream state flags (e.g., EOF) |
| `<<`         | Insert into stream (like `cout`)     |
| `>>`         | Extract from stream (like `cin`)     |

🌐 Main Classes:
- std::stringstream: both input and output on strings
- std::istringstream: only input (reading) from strings
- std::ostringstream: only output (writing) to strings

🧠 Common Uses:
1. Convert string ↔ number
2. Parse strings (e.g., split words)
3. Build strings using << operators (like cout)
4. Modify or extract specific parts of a string

⚠️ Works with internal buffer (std::string)
*/

int main() {
    // ---------- 1. Converting string to int ----------
    std::string numStr = "12345";
    int number;
    std::stringstream ss1(numStr);  // input stream
    ss1 >> number;
    std::cout << "Converted string to int: " << number << "\n";

    // ---------- 2. Converting int to string ----------
    int value = 789;
    std::stringstream ss2;
    ss2 << value;
    std::string strValue = ss2.str();  // fetch buffer ss2
    std::cout << "Converted int to string: " << strValue << "\n";

    // ---------- 3. Splitting a space-separated string ----------
    std::string line = "one two three four five";
    std::istringstream iss(line);
    std::string word;
    std::vector<std::string> words;

    while (iss >> word) {
        words.push_back(word);
    }

    std::cout << "Words from line: ";
    for (const auto& w : words) std::cout << w << " ";
    std::cout << "\n";

    // ---------- 4. Building a string like cout ----------
    std::ostringstream oss;
    oss << "Sum of " << 10 << " + " << 20 << " is " << (10 + 20);
    std::string builtString = oss.str();
    std::cout << "Built string: " << builtString << "\n";

    // ---------- 5. Reusing stringstream (clearing buffer) ----------
    std::stringstream ss3;
    ss3 << "999";
    int x;
    ss3 >> x;
    std::cout << "First read: " << x << "\n";

    // Clear and reuse
    ss3.clear();          // reset state flags
    ss3.str("888");       // set new buffer
    ss3 >> x;
    std::cout << "Second read after reuse: " << x << "\n";

    return 0;
}

User defined Literals :-

  ✅ What Are User-Defined Literals in C++?
  User-Defined Literals (UDLs) allow you to define custom meanings for literal suffixes like "10_kg" or "45_sec" by overloading the operator"".
  📌 Introduced in C++11 and extended in C++14 and C++20

🔹 Benefits of UDLs:
Improves readability and type safety.
Useful for units (meters, kg), currency, time, sizes (MB, GB), etc.
Eliminates magic numbers in code.

#include <iostream>
using namespace std;

/*
🧠 THEORY: User-Defined Literals (UDLs)
---------------------------------------
Syntax to define UDL:
    ReturnType operator"" _suffix(Type arg);

Types allowed in UDLs:
    - unsigned long long       → for integers
    - long double              → for floating points
    - const char*, size_t      → for strings
    - char                     → for single characters

You define a suffix like _kg, _m, _s etc., and attach logic to it.
*/

// -----------------------------
// Literal for kilograms (int)
// -----------------------------
constexpr long double operator"" _kg(unsigned long long kg) {
    return kg * 1000.0;  // returns in grams
}

// -----------------------------
// Literal for distance (meters to cm)
// -----------------------------
constexpr long double operator"" _m(long double meters) {
    return meters * 100.0;  // returns in cm
}

// -----------------------------
// Literal for seconds (returns milliseconds)
// -----------------------------
constexpr long long operator"" _sec(unsigned long long s) {
    return s * 1000;
}

// -----------------------------
// Literal for binary size (MB to bytes)
// -----------------------------
constexpr unsigned long long operator"" _MB(unsigned long long mb) {
    return mb * 1024 * 1024;
}

// -----------------------------
// Literal from string (C++14+)
// -----------------------------
std::string operator"" _tag(const char* str, size_t len) {
    return std::string("#") + str;
}

// =============================
// Main usage
// =============================
int main() {
    long double weight = 5_kg;
    long double height = 1.75_m;
    auto timeout = 3_sec;
    auto fileSize = 2_MB;
    std::string hashtag = "cpprocks"_tag;

    cout << "Weight in grams: " << weight << endl;
    cout << "Height in cm: " << height << endl;
    cout << "Timeout in milliseconds: " << timeout << endl;
    cout << "File size in bytes: " << fileSize << endl;
    cout << "Tagged string: " << hashtag << endl;

    return 0;
}

Important Points :-
 
*Custom literals should begin with underscore
   • literals without underscore are reserved for the standard library
* You cannot redefine the meaning of built-in literal suffixes
* Only following types can be suffixed to make a user-defined literal
   • unsigned long long, long double, const char*, char
*Literal operator functions cannot be member functions

| Question                                 | Good Answer                                                                                             |
| ---------------------------------------- | ------------------------------------------------------------------------------------------------------- |
| What are UDLs?                           | They are user-defined suffixes for literals that enable type-safe conversions and improved readability. |
| Where would you use them?                | Units of measurement, currency, time, formatting strings, strong types                                  |
| Do UDLs affect performance?              | No, especially with `constexpr`, they are compile-time operations.                                      |
| Which types can be used with operator""? | `unsigned long long`, `long double`, `const char*`, `char`, etc.                                        |

//constexpr

✅ constexpr in C++ – Complete Theory + Code Examples
constexpr is a keyword introduced in C++11 (and improved in C++14/17/20) that tells the compiler:
“This function or variable can be evaluated at compile time.”
properties :-
* Represents an expression that is constant
* Such expressions are possibly evaluated at compile time
* Can be applied to variable declarations or functions
* May increase the performance of the code as computation is done at compile time
/* 
Constant Expression Function rules:
1. SHould accept and return literals types only
(void,scalar types (int,float,char),references,etc....)
2. Should contain only single line statement that should be a single return statement.
(if you return something using if else then it shows error because more than 2 return statements.)
3. constexpre always work as a inline function.
*/

🔹 Why Use constexpr?
Improves performance by doing computations at compile time.
Enables use in constant expressions, like array sizes, template parameters, etc.
Safer and clearer than #define macros or const.

✅ constexpr Rules Overview

| Context      | Meaning                                                          |
| ------------ | ---------------------------------------------------------------- |
| Variable     | Value must be **known at compile time**                          |
| Function     | Can be evaluated at compile time **if all inputs are constexpr** |
| Constructor  | Allows creation of **constexpr objects**                         |
| if-constexpr | Compile-time `if` (C++17 onward)                                 |

🔹 1. constexpr Variable
constexpr int size = 10;
int arr[size];  // OK, evaluated at compile time

🔹 2. constexpr Function
constexpr int square(int x) {
    return x * x;
}
constexpr int Add(int a,int b) {
    return a + b;
}

int main() {
    constexpr int result = square(5);   // Compile-time :: constexpr function
    const int res=square(3); // It also behave like constexpr function
    int x = 6;
    int runtimeResult = square(x);     // Runtime Behave like normal function (if x isn't constexpr)
    // note:- constexpr always except const values in right side of function call  
    // constexpr int sum=Add(3,5); works fine but Add(x,5) will gie error
}

🔹 3. constexpr Class & Constructor (C++11+)
struct Point {
    int x, y;
    constexpr Point(int a, int b) : x(a), y(b) {}
    constexpr int sum() const { return x + y; }
};

int main() {
    constexpr Point p(3, 4);
    constexpr int s = p.sum();  // OK at compile time
}

🔹 4. if constexpr (C++17)
template<typename T>
void printTypeSize() {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "Integral type: " << sizeof(T) << "\n";
    } else {
        std::cout << "Not integral type\n";
    }
}

🔍 Differences: constexpr vs const :-

| Feature                    | `constexpr`                   | `const`                         |
| -------------------------- | ----------------------------- | ------------------------------- |
| Time                       | Compile-time only             | Can be compile-time or runtime  |
| Functions                  | Yes (can define constexpr fn) | No                              |
| Safer for arrays/templates | ✅ Yes                         | ❌ Not always                    |
| Use in switch              | ✅ Always                      | ✅ Only if compile-time constant |

   

