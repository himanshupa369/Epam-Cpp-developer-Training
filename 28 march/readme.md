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

<h3>🟡 Data Structures Where Iterators May Exist But Are Not Commonly Used</h3>
<h4>4. Hash Table (Unordered Map/Set)</h4>
Iterator support is available (e.g., std::unordered_map)<br>
But traversal order is non-deterministic, so often not used for logical traversal patterns<br>

<h4>5. Binary Heap (Min/Max Heap)</h4>
Backed by array<br>
You could technically iterate over the array, but it's not meaningful in terms of heap logic<br>
