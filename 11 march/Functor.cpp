//<...Functor...>

//A functor(function object) is a class or struct that overloads the operator() to behave like a function.
//Functors are commonly used in C++ for custom operations in STL algorithms, callback mechanisms, and function wrappers.

//1) use in function wrappers.
//2) Functors are widely used in STL, especially in algorithms like sort(), for_each(), etc.
//3) functor is Stateful.

//Feature	  Functor(Function Object)	    Function Pointer	         Lambda Expression
//Stateful	        ✅ Yes	                      ❌ No         	     ✅ Yes(captures)
//Encapsulation	    ✅ Yes	                      ❌ No	               ❌ No
//Performance	      ✅ Inline optimization	      ❌ No optimization   ✅ Optimized
//Flexibility	      ✅ High	                      ❌ Low	              ✅ High
//Code Complexity	  ❌ More boilerplate	          ✅ Simple	            ✅ Simple


//🔹 Why Use Functors Instead of Function Pointers ?

//More flexible(can store state).
//Inline optimization(compiler optimizes them better).
//Encapsulation(better for object - oriented design).


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Goblin{
	int Health;
	int strength;
	Goblin(int val1,int val2):Health(val1),strength(val2){}
	bool operator<(const Goblin &obj) {
		return this->Health < obj.Health;
	}
};
struct GoblinComparator {
	bool operator()(const Goblin& lh, const Goblin& rh) {
		return lh.strength < rh.strength;
	}
};

class Greet {
private:
	string greet;
public:
	Greet(string strr): greet(strr){}
	string operator()(string name) {
		return this->greet + " " + name + "!";
	}

};
int main() {
	vector<Goblin> goblins{ Goblin(3,30),Goblin(5,25),Goblin(100,2) };
	// Sorting using functor
	sort(begin(goblins), end(goblins), GoblinComparator());

	for (auto i : goblins) {
		cout << i.Health << " ";
	}
	cout << endl;

	Greet gt("Hello");
	// Below LOC describes that Functor always maintain their state
	cout << gt("Himanshu") << endl;
	cout << gt("Swaraj") << endl;
   cout << gt("Abhijeet") << endl;

	Greet gt1("Bye Bye");
	cout << gt1("Sunny") << endl;
	cout << gt1("Shivom") << endl;

}
