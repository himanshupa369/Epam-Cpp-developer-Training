// Queue STL in C++ - Full Concept Revision
#include <iostream>
#include <queue>

int main() {
    // Declare two integer queues
    std::queue<int> q;
    std::queue<int> qSwap;

    // ===== Insertion Operations =====
    q.push(2);   // Insert element at the back
    q.push(5);
    q.push(3);
    q.push(9);

    q.emplace(7);  // Efficient insertion (in-place construction)
    // Queue now: front [2, 5, 3, 9, 7] back

    // ===== Size of Queues =====
    std::cout << "Size of queue q: " << q.size() << std::endl;        // Output: 5
    std::cout << "Size of queue qSwap: " << qSwap.size() << std::endl; // Output: 0

    // ===== Access Front and Back Elements =====
    std::cout << "Front element: " << q.front() << std::endl;  // Output: 2
    std::cout << "Last element: " << q.back() << std::endl;    // Output: 7

    // ===== Removal Operation =====
    q.pop();  // Removes 2 (front element)
    // Queue now: front [5, 3, 9, 7] back
    std::cout << "Front element after pop operation: " << q.front() << std::endl;  // Output: 5

    // ===== Check if Queue is Empty =====
    if (!q.empty())
        std::cout << "Queue is not empty" << std::endl;
    else
        std::cout << "Queue is empty" << std::endl;

    // ===== Swap Contents of Two Queues =====
    qSwap.swap(q);  // Swap q and qSwap

    // After swap:
    // q becomes empty
    // qSwap gets elements: [5, 3, 9, 7]
    std::cout << "Size of queue q after swap: " << q.size() << std::endl;         // Output: 0
    std::cout << "Size of queue qSwap after swap: " << qSwap.size() << std::endl; // Output: 4

    return 0;
}
