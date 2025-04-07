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


<table border="1">
  <thead>
    <tr>
      <th>Data Structure</th>
      <th>Iterator Used?</th>
      <th>Notes</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Stack (std::stack)</td>
      <td>❌</td>
      <td>No iterators exposed</td>
    </tr>
    <tr>
      <td>Queue (std::queue)</td>
      <td>❌</td>
      <td>No iterators exposed</td>
    </tr>
    <tr>
      <td>Priority Queue</td>
      <td>❌</td>
      <td>No iterators exposed</td>
    </tr>
    <tr>
      <td>Vector</td>
      <td>✅</td>
      <td>Full iterator support</td>
    </tr>
    <tr>
      <td>Map/Set</td>
      <td>✅</td>
      <td>Ordered traversal via iterators</td>
    </tr>
    <tr>
      <td>Unordered Map/Set</td>
      <td>✅ (❗)</td>
      <td>Traversal exists but order not guaranteed</td>
    </tr>
    <tr>
      <td>Heap</td>
      <td>❌</td>
      <td>No logical iterator traversal</td>
    </tr>
    <tr>
      <td>Trees (custom)</td>
      <td>❌ / ✅</td>
      <td>Usually use recursion/queue/stack for traversal</td>
    </tr>
  </tbody>
</table>
