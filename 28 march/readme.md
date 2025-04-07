<h3>🔴 Data Structures Where Iterators Are Not Typically Used for Traversal</h3>
<h4>1. Stack</h4>
Access Method: LIFO (Last In First Out)<br>
Traversal: Using pop() until empty<br>
No direct iterator traversal (in C++ STL std::stack doesn’t expose iterators)<br>

<h4>2. Queue</h4>
Access Method: FIFO (First In First Out)<br>
Traversal: Using pop() until empty<br>
No direct iterator traversal (std::queue doesn’t expose iterators)<br>

<h4>3. Priority Queue / Heap</h4>
Access Method: Always get highest/lowest priority element <br>
Traversal: Only top element is accessible; use pop() to go through <br>
No iterator support in std::priority_queue in C++ <br>
