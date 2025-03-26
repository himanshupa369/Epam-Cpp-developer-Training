#include "mem_tracker.h"
#include <iostream>
#include <unordered_map>
#include <cstdlib> // malloc & free
#include <new>    // std::bad_alloc
 
std::unordered_map<void*, Allocation> allocMap;
 
void logAllocation(void* ptr, size_t size, const char* file, int line) {
    allocMap[ptr] = {size, file, line};
    //When new is called, this function stores the pointer along with allocation details.
}
 
void logDeallocation(void* ptr) {
    allocMap.erase(ptr);
    //When delete is called, it removes the pointer from allocMap
}
 
void checkLeaks() {
    if (allocMap.empty()) {
        std::cout << "No memory leaks detected.\n";
        return;
    }
    for (const auto& entry : allocMap) {
        std::cerr << "Leak detected: " << entry.second.size << " bytes at "
                  << entry.second.file << ":" << entry.second.line
                  << " (" << entry.first << ")\n";
    }
}
 
// Overloaded new operators
void* operator new(size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    if (!ptr) throw std::bad_alloc();
    logAllocation(ptr, size, file, line);
    return ptr;
}
 
void* operator new[](size_t size, const char* file, int line) {
    void* ptr = malloc(size);
    if (!ptr) throw std::bad_alloc();
    logAllocation(ptr, size, file, line);
    return ptr;
}
 
// Overloaded delete operators
void operator delete(void* ptr) noexcept {
    if (ptr) {
        logDeallocation(ptr);
        free(ptr);
    }
}
 
void operator delete[](void* ptr) noexcept {
    if (ptr) {
        logDeallocation(ptr);
        free(ptr);
    }
}
