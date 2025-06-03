// all_in_one_fstream.cpp
// File Handling in C++ using fstream for writing, reading, and appending

#include <iostream>
#include <fstream>  // Required for fstream
#include <string>
using namespace std;

int main() {
    fstream my_file;

    // 1. Writing to a file
    /*
    ios::out → Opens the file to write.
    If the file already exists, its contents are truncated.
    If it doesn't exist, it is created.
    */
    my_file.open("example1.txt", ios::out);

    if (my_file.is_open()) {
        my_file << "This is a test line." << endl;
        my_file << "Another line written using fstream." << endl;
        my_file.close();  // Close after writing
        cout << "File written successfully using fstream.\n";
    } else {
        cout << "Unable to open file for writing." << endl;
        return 1;
    }

    // 2. Reading from the same file
    /*
    ios::in → Opens the file to read.
    We read line-by-line using getline().
    */
    my_file.open("example1.txt", ios::in);
    string line;

    if (my_file.is_open()) {
        cout << "\nReading file content:\n";
        while (getline(my_file, line)) {
            cout << "Read: " << line << endl;
        }
        my_file.close();  // Close after reading
    } else {
        cout << "Unable to open file for reading." << endl;
        return 1;
    }

    // 3. Appending to the file
    /*
    ios::app → Opens file in append mode.
    It keeps the existing content and appends new data at the end.
    */
    my_file.open("example1.txt", ios::app);

    if (my_file.is_open()) {
        my_file << "This line was appended using fstream.\n";
        my_file.close();  // Close after appending
        cout << "\nData appended successfully using fstream.\n";
    } else {
        cout << "Unable to open file for appending." << endl;
        return 1;
    }

    return 0;
}
