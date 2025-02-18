#include<iostream>
using namespace std;

int Add(int* a, int* b) {
    int result = *a + *b;
    return result;
}
void AddVal(int* a, int* b, int* result) {
    *result = *a + *b;
    cout << *result << endl;
}

void Swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << *a << " " << *b << endl;
}

void Factorial(int* a, int* fact) {
    int n = *a;
    for (int i = 1; i <= n; i++) {
        *fact *= i;
    }
    cout << *a << " " << "Factorial is=" << *fact << endl;
}

void Add(int a, int b, int& result) {
    result = (a + b);
    cout << result << endl;
}

void Factorial(int a, int& result) {
    result = 1;
    for (int i = 1; i <= a; i++) {
        result *= i;
    }
    cout << result << endl;
}
void Swap(int& a, int& b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "After Swap" << endl;
    cout << a << " " << b << endl;
}
