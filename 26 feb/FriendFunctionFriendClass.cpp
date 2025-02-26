#include<iostream>
using namespace std;
class A {
private:
	int x;
	int y;
public:
	A(int xv,int yv):x(xv),y(yv){}
	void print() {
		cout << "x is= " << x << endl;
		cout << "y is= " << y << endl;
	}
	virtual ~A() {
		cout << "A Destructor is called" << endl;
	}
	friend void display(const A& obj);
	friend class B;
};
void display(const A& obj) {
	cout << "Friend Fn access: x is = " << obj.x << endl;
	cout << "Friend Fn access: y is = " << obj.y << endl;
}
class B {
public:
	void displayA_Private(const A& obj) {
		cout << "Friend Class access: x is = " << obj.x << endl;
		cout << "Friend Class access: y is = " << obj.y << endl;
	}
	virtual ~B() {
		cout << "B destructor is called" << endl;
	}
};
//Note:- Friend class Chaining is not possible where a friendship relationship A->B->C exists there 'C' can't acces private data member of 'A', for Acessing it should be friend of A. //
int main() {
	A *a=new A(4,5);
	a->print();
	display(*a);
	B b;
	b.displayA_Private(*a);
	delete a;
	return 0;
}
