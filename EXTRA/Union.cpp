✅ What is a Union?
A union allows storing different data types in the same memory location.
It is similar to struct or class, but:
In a struct, all members have separate memory.
In a union, all members share the same memory.
  
✅ Difference Between struct and union in C++ :-

| Feature               | `struct`                                                    | `union`                                                              |
| --------------------- | ----------------------------------------------------------- | -------------------------------------------------------------------- |
| **Memory Allocation** | Each member gets **its own memory**.                        | All members **share the same memory location**.                      |
| **Size**              | Size = **sum of sizes** of all members (with padding).      | Size = **size of the largest member**.                               |
| **Accessing Members** | You can access **all members independently** at once.       | Only **one member is valid at a time**.                              |
| **Data Overwrite**    | Values are retained independently.                          | Writing to one member **overwrites others**.                         |
| **Usage**             | Used when all data members are **required simultaneously**. | Used to **conserve memory** when only one value is needed at a time. |
| **Initialization**    | All members can be initialized.                             | Only **one member** can be initialized at a time.                    |
| **Example Use Case**  | Holding student info: name, age, roll number.               | Holding different data types in a variant type (e.g., int or float). |
| **Padding**           | Padding may increase overall size.                          | No padding needed beyond the largest member.                         |

🧠 Use Tip:
=> Use struct for storing heterogeneous data together.
=> Use union for efficient memory use when variables are mutually exclusive in usage.

| Concept                                     | Answer                                                        |
| ------------------------------------------- | ------------------------------------------------------------- |
| Can a struct have functions?                | ✅ Yes                                                         |
| Can a struct have constructors/destructors? | ✅ Yes                                                         |
| Can a struct have virtual functions?        | ✅ Yes                                                         |
| Is inheritance supported in struct?         | ✅ Yes                                                         |
| Is access modifier difference there?        | ✅ Yes — default is `public` in `struct`, `private` in `class` |

⚠️ Disadvantages / Limitations of Unions in C++ :-

=> ❌ No type tracking
No way to know which member is currently active.
Reading from a non-active member leads to undefined behavior.
=> ⚠️ Default constructor is deleted
If a member has a known default constructor, the union’s default constructor is deleted.
=> ⚠️ Destructor is also deleted
You must implement your own destructor manually.

=> 🚫 Before C++11:
Unions could not contain user-defined types with constructors/destructors.
=> ✅ Since C++11:
User-defined types are allowed, but:
  You must implement constructor and destructor yourself.
  Use placement new to construct user-defined types in union.
  Manually call destructors for those types — they're not called automatically.

=> 🚫 Unions can't:
Inherit from other classes.
Contain virtual functions.

💡 Rules & Behaviors:-
Only one member can be initialized at a time in a union.
Initializing more than one member causes compile-time error.
Default access of union members is public (like in struct).

//Example:-
union Test {
    int x;
    char ch;

    Test() { ch = 'A'; }        // Only one member can be initialized
    ~Test() {}                  // Must define manually if needed
};

int main() {
    Test t;
    std::cout << t.ch << std::endl;

    t.x = 100;                  // Overwrites memory shared with 'ch'
    std::cout << t.x << std::endl;

    std::cout << sizeof(Test);  // Size = size of largest member
}

🧠 Concept: User-defined types in a union :-

#include <iostream>
#include <string>
#include <new>  // for placement new

using namespace std;

// 🧱 Class A implementing Rule of 5
class A {
public:
    A() { cout << "A::Constructor\n"; }
    A(const A&) { cout << "A::Copy Constructor\n"; }
    A(A&&) noexcept { cout << "A::Move Constructor\n"; }
    A& operator=(const A&) { cout << "A::Copy Assignment\n"; return *this; }
    A& operator=(A&&) noexcept { cout << "A::Move Assignment\n"; return *this; }
    ~A() { cout << "A::Destructor\n"; }
};

// 🧱 Class B implementing Rule of 5
class B {
public:
    B() { cout << "B::Constructor\n"; }
    B(const B&) { cout << "B::Copy Constructor\n"; }
    B(B&&) noexcept { cout << "B::Move Constructor\n"; }
    B& operator=(const B&) { cout << "B::Copy Assignment\n"; return *this; }
    B& operator=(B&&) noexcept { cout << "B::Move Assignment\n"; return *this; }
    ~B() { cout << "B::Destructor\n"; }
};

// 🧩 Union holding user-defined types
union MyUnion {
    A a;
    B b;
    std::string s;

    // 🚫 Default constructor is deleted if any member has a user-defined constructor
    // ✅ So we must define our own
    MyUnion() {}  // Must be user-defined
    ~MyUnion() {} // Must be manually defined to avoid deletion
};

int main() {
    cout << "=== Demonstrating user-defined types in a union ===\n";

    MyUnion u;

    // 🚫 You cannot assign to 'a' or 'b' directly — object does not exist yet
    // u.a = A(); // ❌ Undefined behavior: 'a' is not constructed yet

    // ✅ Correct way: use placement new to construct object in union memory
    new (&u.a) A();  // Calls constructor of A

    // At this point, `a` is the active member of union
    // u.a = A();  // Now assignment is valid (optional)

    // 🚫 Destructor is not automatically called for union members
    // ✅ So you must manually destroy the active object
    u.a.~A(); // Manually calling destructor of A

    // Let’s try with std::string
    new (&u.s) std::string("Hello Union!");

    cout << "String inside union: " << u.s << endl;

    u.s.~basic_string();  // Manually destroy the string

    // Now try with B
    new (&u.b) B();  // Construct B using placement new
    u.b.~B();        // Destroy manually

    cout << "=== Program complete ===\n";
    return 0;
}

