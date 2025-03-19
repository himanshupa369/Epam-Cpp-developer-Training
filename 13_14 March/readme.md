<p>Extra concepts::
Rule of 0;
rule of 1;
rule of 5;</p>

<h1>Rule of Three, Rule of Five, and Rule of Zero in C++</h1><br> <br>
<h2>Rule of Three</h2><br>
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












