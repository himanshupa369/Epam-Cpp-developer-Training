// write.cpp
// Writing to a file using ofstream in C++

#include <iostream>
#include <fstream>  // Required for file handling
using namespace std;

int main() {
    // Writing to a file
    ofstream outFile("example.txt");  // ofstream creates/opens file for writing

    // write multiple lines to the file
    outFile << "Line 1" << endl;
    outFile << "Line 2" << endl;
    outFile << "Line 3" << endl;

    /*
    Check the File for Errors

    Using the is_open() Function:
    - true  → file opened successfully
    - false → file open failed or in error state

    Using the fail() Function:
    - true  → file failed to open or is in error state
    - false → file was opened successfully
    */

    if (outFile.is_open()) {
        outFile << "Hello, this is a line of text.\n";
        outFile << "This is another line of text.\n";
        outFile.close(); // Always close the file after finishing writing
        cout << "Data written to file successfully." << endl;
    } 
    else {
        cout << "Unable to open file for writing." << endl;
    }

    return 0;
}
