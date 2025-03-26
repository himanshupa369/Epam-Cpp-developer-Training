#include <iostream>
#include "mem_tracker.h"
#define new new(__FILE__, __LINE__)
 
int main() {
    int* a = new int(42);
    int* b = new int[10];
 
    //delete a;     // Correct single-object delete
    delete[] b;   // Correct array delete
   
    checkLeaks(); // Should now report NO leaks
   
    return 0;
}
