<h1>Iterator Invalidation</h1>
<!DOCTYPE html>
<html>
<head>
  <title>Iterator Invalidation Table</title>
</head>
<body>

<h2>Iterator Invalidation Rules</h2>

<h3>General Containers</h3>
<table border="1">
  <tr>
    <th>Container</th>
    <th>What Breaks</th>
    <th>Fix</th>
  </tr>
  <tr>
    <td>vector</td>
    <td>Capacity change on insert</td>
    <td>Use reserve()</td>
  </tr>
  <tr>
    <td>deque</td>
    <td>Insert at front/back</td>
    <td>Avoid keeping iterators across mutations</td>
  </tr>
  <tr>
    <td>list</td>
    <td>Erased element</td>
    <td>Use returned iterator from erase()</td>
  </tr>
  <tr>
    <td>set/map</td>
    <td>Erased element</td>
    <td>Same as list</td>
  </tr>
  <tr>
    <td>unordered_map</td>
    <td>Rehashing</td>
    <td>Use reserve()</td>
  </tr>
</table>

<h3>Other STL Containers</h3>
<table border="1">
  <tr>
    <th>Container</th>
    <th>Unsafe Action</th>
    <th>Fix</th>
  </tr>
  <tr>
    <td>forward_list</td>
    <td>erase_after()</td>
    <td>Use returned iterator</td>
  </tr>
  <tr>
    <td>multiset/multimap</td>
    <td>erase()</td>
    <td>Use returned iterator</td>
  </tr>
  <tr>
    <td>unordered_multiset</td>
    <td>insert()</td>
    <td>Use reserve() beforehand</td>
  </tr>
  <tr>
    <td>unordered_multimap</td>
    <td>insert()</td>
    <td>Use reserve() beforehand</td>
  </tr>
</table>

</body>
</html>
