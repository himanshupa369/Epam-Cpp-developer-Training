// append.cpp
// Appending to a file using ofstream and ios::app

#include <iostream>
#include <fstream>  // Required for file handling
using namespace std;

int main() {
    /*
    To add/append to the existing content of a file,
    open it in append mode using ios::app
    */

    ofstream outFileAppend("example.txt", ios::app);

    if (outFileAppend.is_open()) {
        outFileAppend << "Appending this line to the file.\n";
        outFileAppend.close();
        cout << "Data appended to file successfully." << endl;
    } 
    else {
        cout << "Unable to open file for appending." << endl;
    }

    return 0;
}
