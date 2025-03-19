<p>Extra concepts::
Rule of 0;
rule of 1;
rule of 5;</p>

<h1>Rule of Three, Rule of Five, and Rule of Zero in C++</h1><br> <br>
<h2>1)Rule of Three :-</h2><br>
<h3>Introduction</h3><br>
<p> The Rule of Three in C++ states that if a class manages resources (like dynamic memory), it should explicitly define three special member functions to ensure proper resource management. </p>
<br>
<h3>The Three Special Member Functions</h3>
<p> Destructor (~ClassName()) - Cleans up resources.<br>

Copy Constructor (ClassName(const ClassName& other)) - Creates a deep copy.<br>

Copy Assignment Operator (operator=(const ClassName& other)) - Assigns a deep copy. <br></p>
<h3>Why is the Rule of Three Important?<br></h3>
<p><br>Prevents memory leaks and dangling pointers.<br>

Ensures proper copying behavior for dynamically allocated resources.<br>

Avoids double deletion issues in destructors. <br></p>

<h2>2)Rule of Five :-</h2>
<h3>Introduction</h3><br>
<p> The Rule of Five extends the Rule of Three in C++ by adding move semantics introduced in C++11. It ensures efficient resource management and prevents unnecessary deep copies. </p>
<br>
<h3>The Five Special Member Functions</h3>
<p> Destructor (~ClassName()) - Cleans up resources.<br>

Copy Constructor (ClassName(const ClassName& other)) - Creates a deep copy.<br>

Copy Assignment Operator (operator=(const ClassName& other)) - Assigns a deep copy.<br>

Move Constructor (ClassName(ClassName&& other) noexcept) - Transfers ownership of resources.<br>

Move Assignment Operator (operator=(ClassName&& other) noexcept) - Transfers ownership in assignment. <br></p>
<h3>Why is the Rule of Five Important?<br></h3>
<p><br>Prevents memory leaks and dangling pointers.

<br>Ensures efficient resource management.

<br>Enables move semantics for better performance.

<br>Avoids unnecessary deep copies, improving speed. <br></p>

<h3>When to Use the Rule of Five?</h3>
<p>When a class manages dynamic memory.<br>

When implementing resource-managing classes (e.g., file handles, sockets, smart pointers).<br>

When dealing with large objects where moving is preferable to copying. <br></p>

<h2>1)Rule of Zero :-</h2><br>
<h3>Introduction</h3><br>
<p> The Rule of Zero is a modern C++ design principle that states that user-defined special member functions (destructor, copy/move constructors, and copy/move assignment operators) should be avoided by leveraging RAII (Resource Acquisition Is Initialization) and standard library containers like std::unique_ptr and std::shared_ptr for resource management. </p>
<br>
<h3>Why Use the Rule of Zero?</h3>
<p> Reduces boilerplate code and manual resource management.<br>

Avoids memory leaks and dangling pointers.<br>

Increases exception safety.<br>

Takes advantage of modern C++ features (smart pointers, containers, etc.). <br></p>
<h3>When to Use the Rule of Zero?<br></h3>
<p><br>When using RAII (Resource Acquisition Is Initialization).<br>

When working with standard library containers (e.g., std::vector, std::string, std::shared_ptr).<br>

When writing modern, maintainable C++ code that avoids manual memory management. <br></p>







