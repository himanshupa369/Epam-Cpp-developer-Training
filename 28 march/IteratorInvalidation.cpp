// iterator_invalidation_examples.cpp

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// ======================== VECTOR ========================
void vector_example() {
    // ❌ Problem: Inserting into vector may invalidate iterators if reallocation occurs
    std::vector<int> v = { 1, 2, 3 };
    auto it = v.begin();
    v.push_back(4); // May invalidate it
    // std::cout << *it; // ❌ Undefined behavior if reallocated

    // ✅ Solution: Reserve capacity in advance to avoid invalidation
    v = { 1, 2, 3 };
    v.reserve(10);
    it = v.begin();
    v.push_back(4);
    std::cout << "Vector iterator: " << *it << "\n";
}

// ======================== DEQUE ========================
void deque_example() {
    // ❌ Problem: Inserting at front/back may invalidate iterators
    std::deque<int> d = { 1, 2, 3 };
    auto it = d.begin();
    d.push_front(0); // ❌ may invalidate it

    // ✅ Solution: Avoid storing iterators across such operations
    //d = { 1, 2, 3 };
    std::cout << "Deque element: ";
    //d.push_back(4);
    //d.insert(d.begin() + 3, 4);  //❌ may invalidate iterators
   // d.insert(it + 2, 4);  //❌ may invalidate iterators
    for (auto it = d.begin(); it != d.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

// ======================== LIST ========================
void list_example() {
    // ❌ Problem: Using erased iterator
    std::list<int> l = { 1, 2, 3 };
    auto it = l.begin();
    l.erase(it);
    // std::cout << *it; // ❌ invalid

    // ✅ Solution: Use returned iterator
    it = l.begin();
    it = l.erase(it);
    std::cout << "List iterator: " << *it << "\n";
}

// ======================== FORWARD_LIST ========================
void forward_list_example() {
    // ❌ Problem: Erasing invalidates the iterator after the erased one
    std::forward_list<int> fl = { 1, 2, 3 };
    auto it = fl.begin();
    //fl.erase_after(it); //problem....
    // std::cout << *++it; // ❌ may be invalid

    // ✅ Solution:
    it = fl.begin();
    auto next = fl.erase_after(it);
    std::cout << "Forward list iterator: " << *next << "\n";
}

// ======================== SET ========================
void set_example() {
    // ❌ Problem: Using erased iterator
    std::set<int> s = { 1, 2, 3 };
    auto it = s.find(2);
    //s.erase(it);   //Problem....
    // std::cout << *it; // ❌ invalid

    // ✅ Solution:
    it = s.find(2);
    it = s.erase(it);
    if (it != s.end()) std::cout << "Set iterator: " << *it << "\n";
}

// ======================== MULTISET ========================
void multiset_example() {
    // ❌ Problem: Using erased iterator
    std::multiset<int> ms = { 1, 2, 2, 3 };
    auto it = ms.find(2);
    ms.erase(it);
    // std::cout << *it; // ❌ invalid

    // ✅ Solution:
    it = ms.find(2);
    it = ms.erase(it);
    if (it != ms.end()) std::cout << "Multiset iterator: " << *it << "\n";
}

// ======================== MULTIMAP ========================
void multimap_example() {
    // ❌ Problem: Using erased iterator
    std::multimap<int, std::string> mm = { {1, "one"}, {2, "two"}, {2, "deux"} };
    auto it = mm.find(2);
    //mm.erase(it);   //problem...
    // std::cout << it->second; // ❌ invalid

    // ✅ Solution:
    it = mm.find(2);
    it = mm.erase(it);
    if (it != mm.end()) std::cout << "Multimap iterator: " << it->second << "\n";
}

// ======================== UNORDERED_MAP ========================
void unordered_map_example() {
    // ❌ Problem: Insertion may cause rehash and invalidate iterators
    std::unordered_map<int, int> m = { {1, 10}, {2, 20} };
    auto it = m.begin();
    m.insert({ 3, 30 });
    // std::cout << it->first; // ❌ invalid if rehashed

    // ✅ Solution:
    m = { {1, 10}, {2, 20} };
    m.reserve(10); // prevent rehash
    it = m.begin();
    m.insert({ 3, 30 });
    std::cout << "Unordered map iterator: " << it->first << "\n";
}

// ======================== UNORDERED_MULTISET ========================
void unordered_multiset_example() {
    // ❌ Problem: Insert may cause rehash and invalidate iterators
    std::unordered_multiset<int> ums = { 1, 2, 3 };
    auto it = ums.begin();
    ums.insert(4);
    // std::cout << *it; // ❌ invalid if rehashed

    // ✅ Solution:
    ums = { 1, 2, 3 };
    ums.reserve(10);
    it = ums.begin();
    ums.insert(4);
    std::cout << "Unordered multiset iterator: " << *it << "\n";
}

// ======================== UNORDERED_MULTIMAP ========================
void unordered_multimap_example() {
    // ❌ Problem: Insert may cause rehash and invalidate iterators
    std::unordered_multimap<int, std::string> umm = { {1, "one"}, {2, "two"} };
    auto it = umm.begin();
    umm.insert({ 3, "three" });
    // std::cout << it->first; // ❌ invalid if rehashed

    // ✅ Solution:
    umm = { {1, "one"}, {2, "two"} };
    umm.reserve(10);
    it = umm.begin();
    umm.insert({ 3, "three" });
    std::cout << "Unordered multimap iterator: " << it->first << "\n";
}

int main() {
    vector_example();
    deque_example();
    list_example();
    forward_list_example();
    set_example();
    multiset_example();
    multimap_example();
    unordered_map_example();
    unordered_multiset_example();
    unordered_multimap_example();
    return 0;
}
