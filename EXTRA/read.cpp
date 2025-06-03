
// read.cpp
// Reading from a file using ifstream in C++

#include <iostream>
#include <fstream>
#include <string>  // Required for using string with getline
using namespace std;

int main() {
    ifstream inFile("example.txt");  // ifstream opens file for reading
    string line;  // variable to store each line from file

    /*
    To read the file line-by-line, use getline() in a loop.
    We loop until all lines are read (i.e., until end of file).
    
    eof() returns:
    - true  → if the file pointer is at the end
    - false → otherwise
    */
    
    // loop until the end of the file
// while (!inFile.eof()) {

//     // store the current line of the file
//     // in the "line" variable
//     getline(inFile, line);

//     // print the line variable
//     cout << line << endl;
// }

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;  // Output each line to the console
        }
        inFile.close();  // Always close file after reading
    } 
    else {
        cout << "Unable to open file for reading." << endl;
    }

    return 0;
}
