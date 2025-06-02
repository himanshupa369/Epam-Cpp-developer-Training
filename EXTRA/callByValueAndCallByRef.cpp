| Return Type         | Lifetime Management | Copy Overhead       | Can Modify Original? | Use When...                      |
| ------------------- | ------------------- | ------------------- | -------------------- | -------------------------------- |
| `ObjectType`        | New object          | Yes (but optimized) | No                   | Creating new objects             |
| `ObjectType&`       | Same as original    | No                  | Yes                  | Referring to existing members    |
| `const ObjectType&` | Same as original    | No                  | No                   | Access existing object read-only |

// used in smart pointer implementation.  
| Expression              | Meaning                                                             |
| ----------------------- | ------------------------------------------------------------------- |
| `Integer* operator->()` | Overload `->` so your object can behave like a pointer to `Integer` |
| Used in                 | Smart pointers, proxies, wrappers                                   |
| Why?                    | Enable `obj->member` syntax on non-pointer objects                  |


✅ Operator Overloading Rules with Examples in C++ :--
  //Important :- Operator function must be non static except new and delete.
🔧 Are They static?
   Yes — when inside a class, they must be declared as static functions implicitly, even though you don’t write static:

class MyClass {
public:
    static void* operator new(size_t);    // implicitly static
    static void  operator delete(void*);  // implicitly static
};

| Feature                   | Overloadable? | Static?                                  |
| ------------------------- | ------------- | ---------------------------------------- |
| `operator new` / `delete` | ✅ Yes         | ✅ Implicitly static in class             |
| Global `new` / `delete`   | ✅ Yes         | ❌ Not static (free functions)            |
| Can access `this`?        | ❌ Never       | Because it's for allocation/deallocation |

| **Rule**                                            | **Description**                                        | **Example**                                                          |
| --------------------------------------------------- | ------------------------------------------------------ | -------------------------------------------------------------------- |
| ✔ **Existing Operators Only**                       | You can only overload operators already defined in C++ | ✅ `operator+`, `operator==` <br> ❌ `operator**`, `operator%%`        |
| ✔ **One Operand Must Be a User-Defined Type (UDT)** | At least one operand must be a class or struct         | ✅ `MyClass operator+(MyClass, int)` <br> ❌ `int operator+(int, int)` |
| ✔ **Some Operators Must Be Member Functions**       | `=`, `()`, `[]`, `->` must be defined as class members | ✅ `MyClass& operator=(const MyClass&)` inside class                  |
| ❌ **Can't Change Number of Operands**               | Unary/binary behavior must remain                      | ❌ Can't make `a + b + c` into `operator+(a, b, c)`                   |
| ❌ **Can't Change Precedence or Associativity**      | Expression grouping stays the same                     | `a + b * c` → `b * c` happens first, always                          |
| ❌ **Some Operators Cannot Be Overloaded**           | Restricted by C++ language rules                       | ❌ `::`, `.`, `.*`, `?:`, `sizeof`                                    |
| ✔ **Should Follow Expected Behavior**               | Overloaded operators should act naturally              | ✅ `+` should combine, not subtract                                   |
| ✔ **Non-member Overload for Symmetry**              | Use global overloads when needed for symmetry          | `friend MyClass operator+(int a, const MyClass& b);`                 |
