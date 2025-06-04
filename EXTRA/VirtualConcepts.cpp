Ques.) Pure virtual destructor is possible or not? 
Ans. ) Yes, it can be possible in C++11 but there is no meaning of this pure Virtual destructor .

If the base class destructor is not virtual, then only the base class destructor is called—not the derived class's,
  which can lead to:
=> Resource leaks
=> Incomplete object destruction

📌 Key Points:
Always declare destructors as virtual in base classes if you expect polymorphic behavior.
Good practice: If a class has any virtual function, make its destructor virtual too.

✅ Difference Between NULL and nullptr in C++ :-
  nullptr is used in c++ 11 and later version

| Feature                  | `NULL`                         | `nullptr`                    |
| ------------------------ | ------------------------------ | ---------------------------- |
| **Type**                 | Typically `int` (macro)        | `nullptr_t` (a unique type)  |
| **Introduced In**        | Traditional C / C++            | C++11                        |
| **Defined As**           | `#define NULL 0` (or `0L`)     | A keyword                    |
| **Safe in Overloading?** | ❌ No – can cause ambiguity    | ✅ Yes – resolves overloads | 
| **Usage**                | Used to represent null pointer | Used for the same, but safer |
| **Recommended?**         | ❌ Not in modern C++           | ✅ Yes (type-safe & modern) |
