
/*

Rule of 3 :-(Resource allocation)

   * If a class manages a resource (e.g., dynamic memory, file handle) and defines any of the following, it should define all three:
   1)* Destructor
   2)* Copy Constructor
   3)* Copy Assignment Operator
   * This rule ensures proper resource management for classes with value semantics, particularly before C++11.
   * The compiler-generated default versions perform shallow copies, which can lead to:
    * Memory leaks
    * Double deletion
    * Incorrect resource sharing
   Why is the Rule of Three Important?
   1)Prevents memory leaks and dangling pointers.
   2)Ensures proper copying behavior for dynamically allocated resources.
   3)Avoids double deletion issues in destructors.

Rule Of 5 :- (ownership)
   *The Rule of Five extends the Rule of Three in C++ by adding move semantics introduced in C++11.
   It ensures efficient resource management and prevents unnecessary deep copies.
   * Consequently, you should implement the rule of 5 for such classes
   * If a class has ownership semantics, then you must provide a user-defined
     * Destructor
     * Copy constructor
     * Copy assignment operator
     * Move constructor
     * Move assignment operator
   * This is to ensure proper handling of the underlying resource
   * Why is the Rule of Five Important?
     *Prevents memory leaks and dangling pointers.
     *Ensures efficient resource management.
     *Enables move semantics for better performance.
     *Avoids unnecessary deep copies, improving speed.
   *When to Use the Rule of Five?
     *When a class manages dynamic memory.
     *When implementing resource-managing classes (e.g., file handles, sockets, smart pointers).
     *When dealing with large objects where moving is preferable to copying.

Rule of 0 :-(Renting)
   *The Rule of Zero is a modern C++ design principle that states that user-defined special member functions (destructor, copy/move constructors, and copy/move assignment operators) should be avoided
   by leveraging RAII (Resource Acquisition Is Initialization) and standard library containers like std::unique_ptr and std::shared_ptr for resource management.
   * If a class does not have ownership semantics, then do not provide any user defined function from the rule of 5
   * This is called the "rule of 0"
   * This way the compiler will automatically synthesize the necessary functions
   * Providing user-defined implementation of some functions will prevent the compiler from synthesizing others
   * Basically is totally depends on RAII concept.
   *Why Use the Rule of Zero?
      *Reduces boilerplate code and manual resource management.
      *Avoids memory leaks and dangling pointers.
      *Increases exception safety.
      *Takes advantage of modern C++ features (smart pointers, containers, etc.).
   *When to Use the Rule of Zero?
      1)When using RAII (Resource Acquisition Is Initialization).
      2)When working with standard library containers (e.g., std::vector, std::string, std::shared_ptr).
      3)When writing modern, maintainable C++ code that avoids manual memory management.



*/
