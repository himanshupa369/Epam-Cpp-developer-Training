<!DOCTYPE html>
<html>
<head>
    <title>Rule of Three, Rule of Five, and Rule of Zero in C++</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            background-color: #f4f4f4;
            padding: 20px;
        }
        .container {
            max-width: 900px;
            margin: auto;
            background: #fff;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.1);
        }
        h1 {
            color: #ff5733;
            text-align: center;
        }
        h2 {
            color: #3498db;
        }
        h3 {
            color: #27ae60;
        }
        p {
            font-size: 16px;
            line-height: 1.6;
            color: #555;
        }
        .highlight {
            background-color: #ffeb3b;
            padding: 5px;
            border-radius: 5px;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1>Rule of Three, Rule of Five, and Rule of Zero in C++</h1>

        <h2>1) Rule of Three</h2>
        <h3>Introduction</h3>
        <p>The <span class="highlight">Rule of Three</span> in C++ states that if a class manages resources (like dynamic memory), it should explicitly define three special member functions to ensure proper resource management.</p>

        <h3>The Three Special Member Functions</h3>
        <p><b>Destructor:</b> <code>~ClassName()</code> - Cleans up resources.<br>
        <b>Copy Constructor:</b> <code>ClassName(const ClassName& other)</code> - Creates a deep copy.<br>
        <b>Copy Assignment Operator:</b> <code>operator=(const ClassName& other)</code> - Assigns a deep copy.</p>

        <h3>Why is the Rule of Three Important?</h3>
        <p>
            ✅ Prevents memory leaks and dangling pointers.<br>
            ✅ Ensures proper copying behavior for dynamically allocated resources.<br>
            ✅ Avoids double deletion issues in destructors.
        </p>

        <h2>2) Rule of Five</h2>
        <h3>Introduction</h3>
        <p>The <span class="highlight">Rule of Five</span> extends the Rule of Three in C++ by adding move semantics introduced in C++11. It ensures efficient resource management and prevents unnecessary deep copies.</p>

        <h3>The Five Special Member Functions</h3>
        <p>
            <b>Destructor:</b> <code>~ClassName()</code> - Cleans up resources.<br>
            <b>Copy Constructor:</b> <code>ClassName(const ClassName& other)</code> - Creates a deep copy.<br>
            <b>Copy Assignment Operator:</b> <code>operator=(const ClassName& other)</code> - Assigns a deep copy.<br>
            <b>Move Constructor:</b> <code>ClassName(ClassName&& other) noexcept</code> - Transfers ownership of resources.<br>
            <b>Move Assignment Operator:</b> <code>operator=(ClassName&& other) noexcept</code> - Transfers ownership in assignment.
        </p>

        <h3>Why is the Rule of Five Important?</h3>
        <p>
            ✅ Prevents memory leaks and dangling pointers.<br>
            ✅ Ensures efficient resource management.<br>
            ✅ Enables move semantics for better performance.<br>
            ✅ Avoids unnecessary deep copies, improving speed.
        </p>

        <h3>When to Use the Rule of Five?</h3>
        <p>
            ➤ When a class manages dynamic memory.<br>
            ➤ When implementing resource-managing classes (e.g., file handles, sockets, smart pointers).<br>
            ➤ When dealing with large objects where moving is preferable to copying.
        </p>

        <h2>3) Rule of Zero</h2>
        <h3>Introduction</h3>
        <p>The <span class="highlight">Rule of Zero</span> is a modern C++ design principle that states that user-defined special member functions should be avoided by leveraging RAII (Resource Acquisition Is Initialization) and standard library containers.</p>

        <h3>Why Use the Rule of Zero?</h3>
        <p>
            ✅ Reduces boilerplate code and manual resource management.<br>
            ✅ Avoids memory leaks and dangling pointers.<br>
            ✅ Increases exception safety.<br>
            ✅ Takes advantage of modern C++ features (smart pointers, containers, etc.).
        </p>

        <h3>When to Use the Rule of Zero?</h3>
        <p>
            ➤ When using RAII (Resource Acquisition Is Initialization).<br>
            ➤ When working with standard library containers (e.g., <code>std::vector</code>, <code>std::string</code>, <code>std::shared_ptr</code>).<br>
            ➤ When writing modern, maintainable C++ code that avoids manual memory management.
        </p>
    </div>
</body>
</html>
