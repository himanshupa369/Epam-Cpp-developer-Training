#pragma once
#ifndef MEM_TRACKER_H
#define MEM_TRACKER_H
 
#include <iostream>
#include <unordered_map>
 
struct Allocation {
    size_t size;//Stores the size of allocated memory.
    const char* file;//Stores the filename where allocation happened.
    int line;//tores the line number where allocation happened.
};
 
// Global allocation map declaration
extern std::unordered_map<void*, Allocation> allocMap;
 
//Adds a new memory allocation record.
void logAllocation(void* ptr, size_t size, const char* file, int line);
 
 
//Removes a record when memory is freed
void logDeallocation(void* ptr);
 
//Checks for leaks and prints detected ones.
void checkLeaks();
 
// Placement new overloads
void* operator new(size_t size, const char* file, int line);
void* operator new[](size_t size, const char* file, int line);
 
// Correct delete overloads
void operator delete(void* ptr) noexcept;
void operator delete[](void* ptr) noexcept;
 
#endif // MEM_TRACKER_H
