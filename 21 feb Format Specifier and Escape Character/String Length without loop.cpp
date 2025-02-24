#include <iostream>
#include <string>
using namespace std;

int strLength(string str2) {
    // Base case
    if (str2.empty()) {
        return 0;
    }
        return 1 + strLength(str2.substr(1));
}

int strlength(const char* str) {
    // Base case
    if (*str == '\0') {
        return 0;
    }
    return 1 + strlength(++str);
}

int main() {
    const char* str1 = "Hello Anna";
    string str2 = "Hello c++ team";
    
    cout << "Length of the C string: " << strlength(str1) << endl;
    cout << "Length of the Cpp string: " << strLength(str2) << endl;

    return 0;
}
