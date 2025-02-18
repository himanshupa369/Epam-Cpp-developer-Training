#include <iostream>
#include<cstring>
using namespace std;
void Malloc() {
	int* p = (int*)malloc(5 * sizeof(int));
	//int *q = (int*)calloc(5, sizeof(int));
	//necessary condition for dynamic memory allocation
	if (p == nullptr) {
		cout << "Memory allocation failed" << endl;
		return;
	}
	*p = 5;
	cout << *p << endl;
	// if you didn't free(fail to release) the memory then this condition is called memory leak
	//Use smart pointers(std::unique_ptr, std::shared_ptr) to automatically manage memory.
	free(p);
}
void New() {
	int* p = new int;
	*p = 6;
	cout << *p << endl;
	delete p;
	//necessary with new 
	p = nullptr;
}
void NewArray() {
	int* p = new int[5];
	//int* p = new int[5]{1,3,4,5,8};
	for (int i = 0; i < 5; i++) {
		p[i] = i;
	}
	for (int i = 0; i < 5; i++) {
		cout << *(p+i) << endl;
	}
	// delete p ,it is use to delete single element from an array
	delete[]p;
}
void Strings() {
	char *p = new char[4];
	strcpy_s(p,4, "RAM"); //it is safer version of strcpy()
	// always use 1 extra bit size for terminating conditions
	cout << p << endl;
	delete[]p;
}
void TwoD() {
	int* p1 = new int[3]; // First row
	int* p2 = new int[3]; // Second row
	int** ptrArr = new int *[2]; // Array of pointers (2 rows)
	ptrArr[0] = p1;  // First pointer points to p1 (first row)
	ptrArr[1] = p2;  // Second pointer points to p2 (second row)
	// Populate the 2D array
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			ptrArr[i][j] = i + j;
		}
	}

	// Print the 2D array
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << ptrArr[i][j]<<" ";
		}
		cout << endl;
	}
	delete[]p1; //delete ptrArr[0];
	delete[]p2; //delete ptrArr[1]'
	delete[]ptrArr;
}
void ThreeD() {
	int x = 3, y = 3, z = 3;

	// Allocate memory for 3D array
	int*** array = new int** [x];
	for (int i = 0; i < x; ++i) {
		array[i] = new int* [y];
		for (int j = 0; j < y; ++j) {
			array[i][j] = new int[z];
		}
	}
	// Assign values to the 3D array
	int value = 1;
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			for (int k = 0; k < z; ++k) {
				array[i][j][k] = value++;
			}
		}
	}
	// Print the 3D array
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			for (int k = 0; k < z; ++k) {
				cout << array[i][j][k]<<" ";
			}
			cout <<endl;
		}
		cout << endl;
	}
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			delete[] array[i][j];
		}
		delete[] array[i];
	}
	delete[] array;
}
int main()
{
	/*Malloc();
	cout << endl;
	New();
	cout << endl;
	NewArray();
	Strings();
	TwoD();
	cout << endl;*/
	ThreeD();
	return 0;
}

