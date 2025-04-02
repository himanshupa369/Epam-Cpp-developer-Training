/*... C++ Dequeue ...*/

#include <iostream>
#include <deque>
#include<algorithm>

//Operation	           Description
//push_back(val)	   Adds an element at the end
//push_front(val)	   Adds an element at the front
//pop_back()	       Removes the last element
//pop_front()	       Removes the first element
//size()	           Returns the number of elements
//empty()	           Checks if the deque is empty
//clear()	           Removes all elements
//front()	           Returns the first element
//back()	           Returns the last element

//When to Use std::deque ?
//✅ Use std::deque when :

//You need fast insertions / removals at both ends.
//You need random access(like vector).
//You don't want the memory overhead of std::list.

//❌ Avoid std::deque when :

//You need continuous memory allocation(use vector).
//You perform many insertions in the middle(use list).

void Print(std::deque<int>& dq) {
    for (int val : dq) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
int main() {
    std::deque<int> dq = { 10, 20, 30, 40 };
    // Printing deque elements
    Print(dq);

    dq.push_back(10);
    dq.push_front(20);
    dq.push_back(30);

    std::cout << "Front: " << dq.front() << std::endl;
    std::cout << "Back: " << dq.back() << std::endl;
    Print(dq); 

    dq.pop_front();  // Removes 20
    dq.pop_back();   // Removes 30
    Print(dq);

    std::cout << "Size: " << dq.size() << std::endl;

       /* Accessing Elements
        Method	    Description
        dq[index]	Access element at a given index
        at(index)	Safe access with bounds checking*/

    std::cout << "Element at index 2: " << dq[2] << std::endl;
    std::cout << "Element at index 1 (using at()): " << dq.at(1) << std::endl;

    std::cout << "Deque elements: ";
    for (std::deque<int>::iterator itr = dq.begin(); itr != dq.end(); ++itr) {
        std::cout << *itr << " ";
    }

        /*Inserting Erasing Elements
        Function	                Description
        insert(iterator, value)	    Inserts an element before the given position
        erase(iterator)	            Removes the element at the given position
        erase(start, end)	        Removes a range of elements*/
    std::deque<int> dq1 = { 10, 20, 30, 40 };
    auto it = dq1.begin()+2;  // Points to 30
    //it = std::next(it, 2);
    Print(dq1);
    std::cout << "after insert(): " << std::endl;
    dq1.insert(it, 25);  // Insert 25 before 30
    Print(dq1);
    std::cout << "after erase(): " << std::endl;
    dq1.erase(it);       // Erase the original 30
    Print(dq1);

        /*Sorting and Reversing
        Function	                       Description
        sort(dq.begin(), dq.end())	       Sorts the deque in ascending order
        reverse(dq.begin(), dq.end())	   Reverses the deque
        remove(value)	                   Removes all occurrences of value (not efficient)*/
    std::cout<<  "After reverse: " << std::endl;
    std::reverse(dq1.begin(), dq1.end());  // Reverse
    Print(dq1);

    std::cout << "after sort: " << std::endl;
    std::sort(dq1.begin(), dq1.end());  // Sort (necessary to declare algorithm header file)
    Print(dq1);

    std::cout << "after remove() call: " << std::endl;
    dq1.erase(std::remove(dq1.begin(), dq1.end(), 30), dq1.end());
    Print(dq1);
    return 0;
}
