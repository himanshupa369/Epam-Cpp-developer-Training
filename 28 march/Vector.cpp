/*... c++ vector */

#include<iostream>
#include<vector>
using namespace std;

//Note:- "Vs code" increses size of vector half of capacity for space but "gcc" increses twice of previous size.

//4. When to Use emplace_back() ?
//✔ Use emplace_back() when inserting objects that require constructor arguments.
//✔ Prefer it for performance optimization when working with complex objects.
//✔ push_back() is still fine for simple types like int and double.

class Student {
public:
   string name;
   int age;

   Student(string n, int a) : name(n), age(a) {
       std::cout << "Constructor called for " << name << std::endl;
   }
   // Copy Constructor
   Student(const Student& s) {
       name = s.name;
       age = s.age;
       cout << "Copy Constructor called for " << name << endl;
   }

   // Move Constructor
   Student(Student&& s) noexcept {
       name = move(s.name);
       age = s.age;
       cout << "Move Constructor called for " << name << endl;
   }
};

int main() {
   std::vector<int> v1;  // Empty vector
   std::vector<int> v2(5);  // Vector of size 5 (default-initialized elements)
   std::vector<int> v3(5, 100);  // Vector of size 5, all initialized to 100
   std::vector<int> v4 = { 1, 2, 3, 4, 5 };  // Initialization list
   /*
   push_back(value)	   Adds an element at the end
   pop_back()	           Removes the last element
   insert(pos, value)	   Inserts an element at a specific position
   erase(pos)	           Removes an element at a specific position
   clear()	               Removes all elements
   resize(new_size)	   Resizes the vector

*** shrink_to_fit()	       Reduces capacity to fit the current size ***
   front()	               First element
   back()	               Last element
   data()             	   Pointer to raw array
   v[i]	               Direct access (No bound checking)
   v.at(i)	               Access with bound checking
   size()	               Returns the number of elements
   capacity()	           Returns allocated memory size
   empty()	               Returns true if vector is empty
   reserve(n)	           Pre-allocates memory for n elements
   */
   std::vector<int> v = { 10, 20, 30, 40 };
   std::cout << v[2] << std::endl;       // Output: 30 (No bound check)
   std::cout << v.at(2) << std::endl;    // Output: 30 (Throws exception if out of bounds)
   std::cout << v.front() << std::endl;  // Output: 10
   std::cout << v.back() << std::endl;   // Output: 40

   //Using a Simple Loop
   for (int i = 0; i < v.size(); i++)
       std::cout << v[i] << " ";
   std::cout << std::endl;

   //Using Iterators
   for (auto it = v.begin(); it != v.end(); ++it)
       std::cout << *it << " ";
   std::cout << std::endl;

   std::vector<int> vec;
   std::cout << "Initial size: " << std::endl;
   std::cout << "Size: " << vec.size() << std::endl;
   std::cout << "Capacity: " << vec.capacity() << std::endl;

   vec.push_back(5);
   std::cout << "After 1 element insertion: " << std::endl;
   std::cout << "Size: " << vec.size() << std::endl;
   std::cout << "Capacity: " << vec.capacity() << std::endl;

   std::cout << "after reserving size: " << std::endl;
   vec.reserve(10);  // Allocates space for 10 elements
   std::cout << "Size: " << vec.size() << std::endl;
   std::cout << "New Capacity: " << vec.capacity() << std::endl;

   vec.shrink_to_fit();
   std::cout << "Size: " << vec.size() << std::endl;
   std::cout << "Capacity: " << vec.capacity() << std::endl;

   std::vector<Student> students;
   students.reserve(3); //Analyse the case without reserve also
   std::cout << "type 1: " << std::endl;
   Student s1("Alex", 24);

   // Using push_back()
   students.push_back(s1);
   std::cout << "type 2: " << std::endl;
   students.push_back(Student("Alice", 20));  // Temporary object created, then moved
   std::cout << "type 3: " << std::endl;
   // Using emplace_back()
   students.emplace_back("Bob", 22);  // No temporary object, constructed in place
}
