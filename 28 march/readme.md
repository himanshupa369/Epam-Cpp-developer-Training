<h3>🔴 Data Structures Where Iterators Are Not Typically Used for Traversal</h3>
<h4>1. Stack</h4>
Access Method: LIFO (Last In First Out)
Traversal: Using pop() until empty
No direct iterator traversal (in C++ STL std::stack doesn’t expose iterators)

<h4>2. Queue</h4>
Access Method: FIFO (First In First Out)
Traversal: Using pop() until empty
No direct iterator traversal (std::queue doesn’t expose iterators)

<h4>3. Priority Queue / Heap</h4>
Access Method: Always get highest/lowest priority element
Traversal: Only top element is accessible; use pop() to go through
No iterator support in std::priority_queue in C++
