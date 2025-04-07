/*...Iterator...*/

//✅ Summary Table
//Iterator Type	                Direction	                       Access	                         Used In Containers
//input_iterator	            Forward	                           Read - only	                     istream, custom inputs
//output_iterator	            Forward	                           Write - only	                     ostream, insert iterators
//forward_iterator	            Forward	                           Read / Write	                     forward_list
//bidirectional_iterator	    Forward & Back	                   Read / Write	                     list, set, map
//random_access_iterator	    Any	                               Read / Write,Indexing	         vector, deque, array

//Input Iterator....

//✅ Theory :
//Reads elements only once(single pass)
//Can move forward only
//Used in input streams like std::istream_iterator

//🧠 Use Case :
//Reading values from cin, files, or other input sources

#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main() {
    cout << "Enter vector elements: ";
    std::istream_iterator<int> inputIt(std::cin);
    std::istream_iterator<int> end;
    std::vector<int> vec(inputIt, end);  // Reads until stream ends or user stops

    cout << "entered element is: ";
    for (auto el : vec)
        cout << el << " ";
    cout << endl;
    return 0;
}

//Output Iterator...

//✅ Theory :
//Write - only, single - pass
//Cannot read or reassign

//🧠 Use Case :
//Writing data to cout, files, or containers(e.g., using std::copy)

#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
int main() {
    std::vector<int> arr{ 1,2,3,4,5 };

    std::cout << "Output: ";
    std::ostream_iterator<int> outputItr(std::cout, " ");
    copy(arr.begin(), arr.end(), outputItr);
    return 0;
}

// Forward Iterator...

//✅ Theory :
//Can read / write and move forward
//Multiple passes allowed
//Used in forward_list, unordered_set, etc.

//🧠 Use Case :
//When you only need one - way traversal, like in forward_list

#include <iostream>
#include <forward_list>
// Note :-There is no need to describe Iterator header .

int main() {
    std::forward_list<int> flist = { 10, 20, 30 };

    for (auto it = flist.begin(); it != flist.end(); ++it) {
        *it += 5;  // Modifying elements
        std::cout << *it << " ";
    }

    return 0;
}


// Bidirectional Iterator...

//✅ Theory :
//Can move forward and backward
//Used in list, set, map

//🧠 Use Case :
//Needed when two - way traversal is required(e.g., doubly linked list)

#include <iostream>
#include <list>

int main() {
    std::list<int> myList = { 1, 2, 3, 4 };

    auto it = myList.end();
    --it;  // Start from last element because myList.end() points (n+1)th location.

    while (true) {
        *it += 2;
        std::cout << *it << " ";
        if (it == myList.begin()) break;
        --it;
    }

    return 0;
}

// Random Access Iterator...
//✅ Theory :
//Supports full pointer - like access : +, -, [], comparisons
//Used in vector, deque, array

//🧠 Use Case :
//Required for algorithms like std::sort, binary_search

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> arr = { 50, 20, 10, 40 };

    std::sort(arr.begin(), arr.end());  // Needs random access iterator

    // Using operator[]
    for (size_t i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";

    return 0;
}
