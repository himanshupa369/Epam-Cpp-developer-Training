// std::move()...

// It is a function from C++ standard library  for casting to a rvalue reference.

#include<iostream>
#include<vector>
using namespace std;

void printVector(vector<int>& v) {
	cout << "size: (" << v.size() <<") " << " Array elements:" << endl;
	for (auto i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
}


template<typename T>
void Swap(T& a, T& b) {
	T temp = move(a);
	a = move(b);
	b = move(temp);
}

int main() {
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 5; ++i) {
		v1.push_back(i + 1);
	}
	for (int i = 10; i < 15; ++i) {
		v2.push_back(i + 1);
	}
	printVector(v1);
	printVector(v2);

	//Normal Copy Assignment
	//v2 = v1;
	//Move Copy Assignment
	//v2 = move(v1);
	::Swap(v1, v2);

	printVector(v1);
	printVector(v2);
}
