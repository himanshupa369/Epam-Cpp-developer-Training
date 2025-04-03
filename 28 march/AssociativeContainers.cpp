/* Associative Containers */
#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include<string>
using namespace std;

//Feature	                                    set                multiset	                   unordered_set
//Duplicates	                                ❌ No	           ✅ Yes	                   ❌ No
//Sorting	                                    ✅ Sorted	       ✅ Sorted	               ❌ No order
//Implementation	                            Red - Black Tree   Red - Black Tree	           Hash Table
//Insertion Complexity                       	O(log n)	       O(log n)	                   O(1) (avg), O(n) (worst)
//Search Complexity                         	O(log n)	       O(log n)	                   O(1) (avg), O(n) (worst)
//Allows lower_bound()& upper_bound() ?         ✅ Yes	           ✅ Yes	                   ❌ No
//Iterator Type	                                Bidirectional	   Bidirectional	           Forward

//When to Use What ?
//Scenario	                                                   Best Choice
//Need unique elements in sorted order ?                       set
//Need duplicates in sorted order ?                            multiset
//Need fast lookups and no order ?                             unordered_set
//Need efficient lower and upper bounds ?                      set or multiset
//Need O(1) insert / delete / search in average case ?         unordered_set

//1. Set(std::set)
//A set is an ordered collection of unique elements.It is implemented using a self - balancing binary search tree(Red - Black Tree), ensuring O(log n) time complexity for operations like insertion, deletion, and search.

//Key Features :
//Unique Elements : No duplicate values are allowed.
//Sorted Order : Elements are always stored in sorted(ascending) order.
//Efficient Operations : Search, insert, and delete in O(log n) time.
//Iterator Support : Supports bidirectional iterators.


//2. Multiset(std::multiset)
//A multiset is an ordered collection that allows duplicate values.Like set, it is also implemented using a Red - Black Tree, providing O(log n) operations.

//Key Features :
//Duplicates Allowed : Multiple occurrences of the same element can be stored.
//Sorted Order : Elements are always stored in ascending order.
//Efficient Operations : Search, insert, and delete in O(log n) time.


//3. Unordered Set(std::unordered_set)
//An unordered_set is a hash - based container that stores unique elements in an arbitrary order.It is implemented using a hash table, making operations on average O(1) time complexity.

//Key Features :
//Unique Elements : No duplicates are allowed.
//Unordered Storage : Elements are stored in any order(depends on hash function).
//Fast Operations : Insert, search, and delete take O(1) (average case) but O(n) (worst case).

//4. Map(std::map)
//A map is an ordered associative container that stores key - value pairs.It is implemented using a self - balancing binary search tree(Red - Black Tree), ensuring O(log n) operations for insertion, deletion, and lookup.

//Key Features :
//Unique Keys : No duplicate keys are allowed.
//Sorted Order : Keys are always sorted in ascending order.
//Efficient Operations : Search, insert, and delete in O(log n) time.
//Key - Value Pair Storage : Each key maps to a single value.


//5. Multimap(std::multimap)
//A multimap is an ordered associative container that allows multiple values for the same key.Like map, it is also implemented using a Red - Black Tree, providing O(log n) operations.

//Key Features :
//Duplicate Keys Allowed : A single key can store multiple values.
//Sorted Order : Keys are sorted in ascending order.
//Efficient Operations : Insert, delete, and search in O(log n).

//6. Unordered Map(std::unordered_map)
//An unordered_map is a hash - based associative container that stores key - value pairs in an unordered manner.It is implemented using a hash table, making operations O(1) (average case) but O(n) (worst case).

//Key Features :
//Unique Keys : No duplicate keys are allowed.
//Unordered Storage : Elements are stored in an arbitrary order(depends on hash function).
//Fast Operations : Insert, search, and delete take O(1) (average case) but O(n) (worst case).

// struct Node{
//     int val; //in case of multimap here vector<int> val;
//     int key;
//     Node* left;
//     Node* right;

// };

int main() {
    /* SET: Stores unique elements in sorted order */
    set<int> s = { 5, 2, 8, 5, 1 };
    cout << "Set elements: ";
    for (int x : s) cout << x << " "; // Output: 1 2 5 8
    cout << "\n";
    cout << endl;

    /* MULTISET: Stores elements in sorted order but allows duplicates */
    multiset<int> ms = { 5, 2, 8, 5, 1 };
    cout << "Multiset elements: ";
    for (int x : ms) cout << x << " "; // Output: 1 2 5 5 8
    cout << "\n";
    cout << endl;

    /* UNORDERED SET: Stores unique elements in any order (Hash Table) */
    unordered_set<int> us = { 5, 2, 8, 5, 1 };
    cout << "Unordered Set elements: ";
    for (int x : us) cout << x << " "; // Output order is unpredictable
    cout << "\n";
    cout << endl;

    /* MAP: Key-value pairs, unique keys, sorted by keys */
    map<int, char> mp = { {3, 'a'}, {5, 'b'}, {2, 'c'} };
    cout << "Map elements: ";
    for (auto el : mp) cout << el.first << "->" << el.second << " ";
    cout << "\n";
    cout << endl;

    /* MULTIMAP: Allows duplicate keys, keys are sorted */
    multimap<int, string> mm = { {1, "Alice"}, {2, "Bob"}, {2, "Charlie"}, {3, "David"} };
    cout << "Multimap elements:\n";
    for (auto el : mm) cout << el.first << "->" << el.second << "\n";
    cout << endl;

    /* UNORDERED MAP: Key-value pairs, unique keys, order not guaranteed */
    unordered_map<int, string> ump = { {1, "Apple"}, {3, "Banana"}, {2, "Cherry"} };
    cout << "Unordered Map elements: ";
    for (auto el : ump) cout << el.first << "->" << el.second << " ";
    cout << "\n";
    cout << endl;

    cout << "set size: " << s.size() << endl;
    cout << "multiset size: " << ms.size() << endl;
    cout << "unordered_set size: " << us.size() << endl;
    cout << "map size: " << mp.size() << endl;
    cout << "multimap size: " << mm.size() << endl;
    cout << "unordered_map size: " << ump.size() << endl;
    cout << endl;

    /* FIND OPERATION: Works in all containers */
    if (mp.find(3) != mp.end())
        cout << "Key 3 exists in map\n";
    if (us.find(8) != us.end())
        cout << "Element 8 exists in unordered_set\n";

    /* ERASE OPERATION */
    mp.erase(3);
    cout << "Map after erase: ";
    for (auto el : mp)
        cout << el.first << "->" << el.second << " ";
    cout << "\n";

    /* LOWER BOUND & UPPER BOUND (only for ordered containers) */
    // 💡 lower_bound(x) → Finds first element ≥ x
    // 💡 upper_bound(x) → Finds first element > x
    auto lb1 = mp.lower_bound(2);
    auto ub1 = mp.upper_bound(2);
    cout << "Lower Bound: " << lb1->first << "\n";
    cout << "Upper Bound: " << (ub1 != mp.end() ? to_string(ub1->first) : "None") << "\n";

    /* INSERTING ELEMENTS */
    s.insert(10);
    ms.insert(10);
    us.insert(10);
    mp.insert({ 4, 'd' });
    mp.emplace(9, 'w');
    mp.try_emplace(30, 'k'); //c++ 17 Important
    mm.insert(make_pair(4, "hello"));
    ump.insert({ 4, "Date" });


    /* COUNT FUNCTION: Useful for checking existence */
    cout << "Element 5 count in set: " << s.count(5) << "\n";
    cout << "Element 5 count in multiset: " << ms.count(5) << "\n";
    cout << "Key 2 count in map: " << mp.count(2) << "\n";

    /* RANGE-BASED ERASE (C++20) */
    // mp.erase(mp.begin(), mp.find(4));

    /* below concept is defined in c++ 20
    * bool contains(const Key& key) const;
    Returns true if the key exists in the map.
    Returns false if the key does not exist.
    if (mp.contains(5))
    cout << "Key 5 exists in the unordered_map" << endl;
    else
    cout << "Key 5 does not exist" << endl;*/


    /* TRY_EMPLACE (C++17) */
    ump.try_emplace(5, "Elderberry");

    /* Note:-
    syntax:: auto range = my_map.equal_range(key);
    Returns a pair<iterator, iterator>:
    range.first → Iterator to the first occurrence of the key.
     range.second → Iterator to the next element after the key's last occurrence.*/

    auto range = mm.equal_range(2); //Imporatant

    std::cout << "Values for key 2:" << std::endl;
    for (auto it = range.first; it != range.second; ++it)
        std::cout << it->first << " -> " << it->second << std::endl;
    //If equal_range() is not available, you can use:
    std::cout << "If equal_range() is not available, you can use:" << std::endl;
    auto lb = mm.lower_bound(2);
    auto ub = mm.upper_bound(2);

    for (auto it = lb; it != ub; ++it)
        cout << it->first << " -> " << it->second << endl;

    //the multimap is sorted in descending order (2 -> Charlie, 2 -> Bob, 1 -> Alice).
    multimap<int, string, greater<int>> mmpp = { {1, "Alice"}, {2, "Bob"}, {2, "Charlie"} };



    /* SWAP FUNCTION */
    set<int> another_set = { 100, 200 };
    s.swap(another_set);
    cout << "After swap, set elements: ";
    for (int x : s) cout << x << " ";
    cout << "\n";

    return 0;
}
