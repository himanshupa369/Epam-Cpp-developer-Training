#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <fcntl.h>
#include <io.h>

class LeakClass {
private:
    int* arr;
    int size;
public:
    LeakClass(int s) {
        size = s;
        arr = new int[size];  // Memory allocated but never freed
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }
        std::cout << "Memory allocated for " << size << " integers." << std::endl;
    }
};

void createLeak() {
    LeakClass* obj1 = new LeakClass(10);  // Memory leak
    LeakClass* obj2 = new LeakClass(20);  // Another memory leak
}

int main() {
    // Set debugging flags
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Redirect memory leak output to the console
    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);  // Redirects to console

    createLeak();  // Memory is allocated but never freed

    std::cout << "Program ended. Checking for memory leaks..." << std::endl;

    _CrtDumpMemoryLeaks();  // 🚀 Now prints leaks to the console

    return 0;
}

//Without memory leak

//#define _CRTDBG_MAP_ALLOC
//#include <cstdlib>
//#include <crtdbg.h>
//#include <iostream>
//
//class LeakClass {
//private:
//    int* arr;
//    int size;
//public:
//    // Constructor: Allocates memory
//    LeakClass(int s) {
//        size = s;
//        arr = new int[size];  // Allocate memory
//        for (int i = 0; i < size; i++) {
//            arr[i] = i + 1;
//        }
//        std::cout << "Memory allocated for " << size << " integers." << std::endl;
//    }
//
//    // Destructor: Frees memory
//    ~LeakClass() {
//        delete[] arr;  // Properly free allocated memory
//        std::cout << "Memory deallocated for " << size << " integers." << std::endl;
//    }
//};
//
//void createLeak() {
//    LeakClass* obj1 = new LeakClass(10);
//    LeakClass* obj2 = new LeakClass(20);
//
//    delete obj1;  // Free memory properly
//    delete obj2;  // Free memory properly
//}
//
//int main() {
//    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//    createLeak();  // Memory is allocated and then properly freed
//
//    std::cout << "Program ended. Checking for memory leaks..." << std::endl;
//    _CrtDumpMemoryLeaks();  // Should report NO memory leaks
//
//    return 0;
//}
