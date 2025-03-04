/* Assignment operator overloading 
copy constructor
*/

// Copy constructor always be in public area of class.
// It have neither return types nor void.
// CC has same name as class name.
// It accepts only one parameter.
// Always create new location to copy dynamic allocated datatypes (code beauty).

//when Copy constructor invoked?
//1) When an object is initialized using another object of the same class.
//2) When an object is passed by value to a function.
//3) When an object is returned by value from a function (However, most modern compilers use Return Value Optimization (RVO) to avoid an extra copy.)
//4) When an object is explicitly copied using another object

////when Assignment Operator overloading invoked?
//1️) Self-Assignment (A = A)
//2)Shallow vs. Deep Copy
    //✅ If your class uses dynamic memory (new), always implement:
         //Copy Constructor(Book(const Book& obj))
         //Destructor(~Book())
         //Assignment Operator(operator=)
         //    Without these, two objects might share the same memory, leading to double deletion(crash).
//3️) Chained Assignment (A = B = C)

#include<iostream>
using namespace std;

class Book{
public:
	string Title;
	string Author;
	float* Rates;
	int RatesCounter;
	Book(){}
	Book(string title, string author) {
		Title = title;
		Author = author;

		RatesCounter = 2;
		Rates = new float[RatesCounter];
		Rates[0] = 5;
		Rates[1] = 4;
	}
	//Copy Constructor
	Book(const Book& obj) {
		Title = obj.Title;
		Author = obj.Author;
		RatesCounter = obj.RatesCounter;
		Rates = new float[RatesCounter];
		for (int i = 0; i < RatesCounter; ++i) {
			Rates[i] = obj.Rates[i];
		}
	}

	//Assignment Operator Overloading
	Book& operator=(const Book& obj) {
		
		//Handle self-assignment case
		if (this == &obj)
			return *this;

		//Free existing memory to avoid memory leaks
		delete[] Rates;

		else {
			Title = obj.Title;
			Author = obj.Author;
			RatesCounter = obj.RatesCounter;

			//if u copied directly then u have to face with memory leak problem//
			Rates = new float[RatesCounter];
			for (int i = 0; i < RatesCounter; ++i) {
				Rates[i] = obj.Rates[i];
			}
			return *this;
		}
	}
	void display() {
		cout << "Title: " << Title << endl;
		cout << "Author: " << Author << endl;
	}

	~Book() {
		delete[] Rates;
		Rates = nullptr;
	}
};

int main() {

	Book book1("Concept Of Physics", "H.C Verma");
	Book book2("Universal", "A.R Karim");
	book1.display();
	book2.display();

	//Testing copy constructor
	Book book3(book2); //// Calls Copy Constructor
	book3.display();

	//Testing assignment operator
	Book book4;
	book4 = book3 = book2; //Chained assignment
	book4.display();

	return 0;
}
