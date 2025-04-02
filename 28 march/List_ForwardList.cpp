/*...List in CPP...*/

/* The std::list is a doubly linked list implementation in the C++ Standard Template Library (STL).
It allows fast insertions and deletions at both the beginning and the end but has slower random access compared to vectors. */

//empty()	Checks if the list is empty
//clear()	Removes all elements
//front()	Returns the first element
//back()	Returns the last element

//Comparison: std::list vs std::forward_list ********

//Feature	                            std::list(Doubly Linked List)	            std::forward_list(Singly Linked List)
//Memory Usage	                        Higher(Two pointers per node)	            Lower(One pointer per node)
//Traversal	                            Both forward& backward	                    Only forward
//Insert / Delete at Front	            ✅ Fast(O(1))	                            ✅ Fast(O(1))
//Insert / Delete at End	            ✅ Fast(O(1))	                            ❌ Not available
//Insert / Delete in Middle           	✅ Possible                                	✅ Possible(but only forward)
//Random Access([])	                    ❌ No	                                    ❌ No
//size() Function	                    ✅ Yes	                                    ❌ No
//Sorting(sort())	                    ✅ Yes	                                    ✅ Yes
//Splicing(splice())	                ✅ Yes	                                    ✅ Yes(splice_after())

//When to Use std::forward_list ?

//✅ Use std::forward_list when :

//You need a memory - efficient linked list.
//You only need forward traversal.
//You perform frequent insertions at the front.

//❌ Avoid std::forward_list when :

//You need fast random access(use std::vector).
//You need bidirectional traversal(use std::list).


#include <iostream>
#include <list> //header file for list

void Print(std::list<int>& myList2) {
   for (auto itr = myList2.begin(); itr != myList2.end(); ++itr) {
       std::cout << *itr << " ";
   }std::cout << std::endl;
}
int main() {
   std::list<int> myList = { 10, 20, 30, 40 };  // Declare and initialize a list

   // Printing the list
   std::cout <<"myList: "<< std::endl;
   for (int &val : myList) {
       std::cout << val << " ";
   }std::cout << std::endl;
   //Adds an element to the front
   myList.push_front(0);
   //Adds an element to the end
   myList.push_back(50);

   std::cout << "Print using iterator after push operation: " << std::endl;
   //Since std::list does not allow random access (like vector[i]), we must use iterators or range-based loops.
   for (auto itr = myList.begin(); itr != myList.end(); ++itr) {
       std::cout << *itr << " ";
   }std::cout << std::endl;
   std::cout << "Front: " << myList.front() << std::endl;
   std::cout << "Back: " << myList.back() << std::endl;
   std::cout<< std::endl;

   //Returns the number of elements
   std::cout << "size of myList: " << myList.size() << std::endl;

   std::list<int> myList2 = { 0,1,2,3,4,5 };

   std::cout <<"myList2: " << std::endl;
   for (int& val : myList2) {
       std::cout << val << " ";
   }
   std::cout << std::endl;
   //Removes the first element
   myList2.pop_front();
   //Removes the last element
   myList2.pop_back();

   std::cout << "Print using iterator after pop operation: " << std::endl;
   for (auto itr = myList2.begin(); itr != myList2.end(); ++itr) {
       std::cout << *itr << " ";
   }std::cout << std::endl;
   std::cout << "size of myList2: " << myList2.size() << std::endl;

      /* Function	                Description
       insert(iterator, value)	    Inserts an element before the given iterator
       erase(iterator)             	Removes the element at the given iterator
       erase(start, end)	            Removes a range of elements*/
   auto itr1 = myList2.begin();
   myList2.insert(itr1, 5);
   std::cout << "After insertion: ";
   Print(myList2);
   std::advance(itr1, 2);  // Move iterator to the 3rd element
   myList2.erase(itr1); //doubt pointing to 3rd then why it delete 4th one.
   std::cout << "After erase: ";
   Print(myList2);

   std::cout << "After reverse: ";
   myList2.reverse();  // Reverse the sorted list
   Print(myList2);

   std::cout << "After sort: ";
   myList2.sort();  // Sort in ascending order
   Print(myList2);

   std::cout << "After merge with another list: ";
   std::list<int> list0 = { 5, 15, 25 };
   myList2.merge(list0);  // Merge with another sorted list
   Print(myList2);

       /* Removing Elements
       Function	            Description
       remove(value)	        Removes all elements with the given value
       remove_if(predicate)	Removes elements based on a condition
       unique()	            Removes consecutive duplicates*/

   std::list<int> myList3 = { 1, 2, 2, 3, 4, 4, 5 };

   std::cout << "myList3: ";
   Print(myList3);
   std::cout << "after using remove(): ";
   myList3.remove(2);  // Removes all occurrences of 2
   Print(myList3);

   std::cout << "after using unique(): ";
   myList3.unique();   // Removes consecutive duplicates
   Print(myList3);

       /*Splicing(Moving Elements Between Lists)
       The splice() function moves elements from one list to another.

       Function	                   Description
       splice(pos, list2)	       Moves all elements from list2 to list1 at pos
       splice(pos, list2, it)	   Moves only one element at it from list2 to list1*/

   std::list<int> list1 = { 1, 2, 3 };
   std::list<int> list2 = { 4, 5, 6 };

   auto it = std::next(list2.begin(),2);
   list1.splice(list1.end(), list2,it);  // Moves all elements of list2 to list1
   Print(list1);


   return 0;
}

#include <iostream>
#include <forward_list> // header file for forward_list

void Print(std::forward_list<int>& myList) {
   for (int val : myList) {
       std::cout << val << " ";
   }
   std::cout << std::endl;
}

int main() {
   std::forward_list<int> myList = { 10, 20, 30, 40 }; // Declare and initialize a forward_list

   std::cout << "myList: " << std::endl;
   Print(myList);

   // Adds an element to the front (forward_list does not support push_back)
   myList.push_front(0);

   std::cout << "Print after push operation: " << std::endl;
   Print(myList);

   std::cout << "Front: " << myList.front() << std::endl;

   std::cout << "size calculation is not available directly in forward_list." << std::endl;
   std::cout << "size of myList: " << std::distance(myList.begin(), myList.end()) << std::endl;

   std::forward_list<int> myList2 = { 0, 1, 2, 3, 4, 5 };

   std::cout << "myList2: " << std::endl;
   Print(myList2);

   // Removes the first element (forward_list does not support pop_back)
   myList2.pop_front();

   std::cout << "Print after pop operation: " << std::endl;
   Print(myList2);

   auto itr1 = myList2.before_begin();
   myList2.insert_after(itr1, 5);
   std::cout << "After insertion: ";
   Print(myList2);

   auto itr2 = myList2.begin();
   std::advance(itr2, 2);
   myList2.erase_after(itr1); // Removes element after itr1
   std::cout << "After erase: ";
   Print(myList2);

   std::cout << "After reverse: ";
   myList2.reverse();
   Print(myList2);

   std::cout << "After sort: ";
   myList2.sort();
   Print(myList2);

   std::cout << "After merge with another list: ";
   std::forward_list<int> list0 = { 5, 15, 25 };
   myList2.merge(list0);
   Print(myList2);

   std::forward_list<int> myList3 = { 1, 2, 2, 3, 4, 4, 5 };
   std::cout << "myList3: ";
   Print(myList3);

   std::cout << "After using remove(): ";
   myList3.remove(2);
   Print(myList3);

   std::cout << "After using unique(): ";
   myList3.unique();
   Print(myList3);

   std::forward_list<int> list1 = { 1, 2, 3 };
   std::forward_list<int> list2 = { 4, 5, 6 };

   list1.splice_after(list1.before_begin(), list2);
   Print(list1);

   return 0;
}
