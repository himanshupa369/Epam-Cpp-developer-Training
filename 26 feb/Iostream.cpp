#include<iostream> //I/O stream
#include<iomanip> // I/O manipulator 
#include<fstream> // I/Ofile stream
#include<string>
using namespace std;

int main() {
	int x;
	cout << "Input stream to take input, Enter value of x:" << endl;
	cin >> x;
	cout << "It is Output stream to print the value of x: " << x << endl;

	//iomanip concepts
	float fl = 23.39542876;
	//Sets the width of the next output field setw(n)
	//Sets the fill character for the output setfill(ch)
	cout << "Set the width of output field: |"<<setfill('*') << setw(20) << fl << "|" << endl;
	// Controls the precision of floating-point numbers.
	cout << "setprecision of a variable: " << setprecision(3)<<fl << endl;
	//Left-aligns the output within the given field width.
	cout << left << setw(5) << 42 << endl;  // Output: "42   "
	//Right - aligns the output within the given field width.
	cout << right << setw(5) << 42 << endl;  // Output: "   42"
	//Forces the output of floating-point numbers to use scientific notation.
	cout << scientific << setprecision(2) << 1234.5678 << endl;  // Output: "1.23e+03"
	cout << hex << 255 << endl;  // Output: "ff"
	cout << oct << 255 << endl;  // Output: "377"
	cout << dec << 255 << endl;  // Output: "255"
	//Displays true or false for boolean values instead of 1 or 0.
	cout << boolalpha << true << endl;  // Output: "true"


	//file handling in cpp
	//fstream includes two class for file handling 1)ofstream (to create/open and write to a file)... 2)ifstream (to read from a file.)

	//opening a text file for writing
	ofstream objName("exp.txt"); //we can use this also :- ofstream objName.open("example.txt");

	// 1)error in file opening with is_open()
	if (!objName.is_open()) {
		cout << "Error opening the file." << endl;
		return 1;
	}

	// 2)check if the file has been opened properly
	if (!objName) {

		// print error message
		cout << "Error opening the file." << endl;

		// terminate the main() function
		return 1;
	}

	//3) true if fail opening in a file
	if (objName.fail()) {
		cout << "Error opening the file." << endl;
		return 1;
	}
	
	// Note:- basically method 1 is used widely.

	 // Write some content to the file
	objName << "Hello,swaraj.\n";
	objName << "How do you do?\n";
	objName << "File handling is fun in C++ so today we will  studied this topic!\n";
	
	//close the file
	objName.close();

	// open a text file for reading
	ifstream objName1("exp.txt");

	// check the file for errors
	if (!objName1) {
		cout << "Error: Unable to open the file." << endl;
		return 1;
	}

	// store the contents of the file in "line" string
	string line;

	// loop until the end of the text file
	while (getline(objName1, line)) {
		// print the line variable
		cout << line << endl;
	}

	// close the file
	objName1.close();

	// cerr and clog are both used to output error and log messages
	
	//cerr is unbuffered, meaning it outputs immediately.
	cerr << "An error occurred!" << endl;

	//clog is buffered, meaning it may be stored and output later.
	//clog is used for logging purposes and does not necessarily indicate an immediate problem.
	clog << "This is a log message." << endl;

	return 0;
}