#include <iostream>
#include <string>
using namespace std;
// example for padding
struct abc{
    char ch;
    int it;
    double db;
};

#pragma pack(1);
struct abd {
    char ch;
    int it;
    double db;
};

union un {
    char ch;
    int it;
    double db;
};
//Note:- The pointer increment (ptr++) or decrement (ptr--) moves the pointer by the size of the data type it points to.
// Pointer Arithmetic is valid only within an array or memory block.
class String {
private:
    char* str;

public:
    // Constructor
    String(const char* value) {
        str = new char[strlen(value) + 1];  // Allocate memory
        strcpy_s(str, strlen(value) + 1, value);  // Safe copy of string
    }

    // Copy Constructor
    String(const String& other) {
        str = new char[strlen(other.str) + 1];  // Allocate memory
        strcpy_s(str, strlen(other.str) + 1, other.str);  // Safe copy
    }

    // Overloading the Assignment Operator
    String& operator=(const String& other) {
        // Self-assignment check
        if (this == &other) {
            return *this;
        }

        // Release the current memory
        delete[] str;

        // Allocate new memory and copy the data from the other object
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);  // Safe copy

        return *this;
    }

    // Destructor to free allocated memory
    ~String() {
        delete[] str;
    }

    // Function to display the string
    void display() {
        cout << str << endl;
    }
};
// Define a structure
struct Person {
    // Data members (properties) of the structure
    string name;   // Name of the person
    int age;       // Age of the person
    double height; // Height of the person (in cm)

    // Function within a structure (C++ allows functions inside structures but not C)
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << " cm" << endl;
    }
};

// Nested structure
struct Address {
    // Data members for Address structure
    string street;
    string city;
    string state;
    int zipCode;

    // Function to display address
    void displayAddress() {
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "State: " << state << endl;
        cout << "Zip Code: " << zipCode << endl;
    }
};

// Structure with another structure as a member (Composition)
struct Employee {
    string employeeID;
    Person personInfo;  // Nested structure as a member
    Address addressInfo; // Nested structure as a member
};

// Array of structures
struct Book {
    string title;
    string author;
    int publicationYear;
};

int main() {
    /*
    // Creating an object of the Person structure
    Person person1;

    // Input for the person object (using getline for strings)
    cout << "Enter Details of Person" << endl;
    cout << "Name: ";
    getline(cin, person1.name); // Use getline to handle spaces in strings
    cout << "Age: ";
    cin >> person1.age;
    cout << "Height (in cm): ";
    cin >> person1.height;
    cin.ignore(); // To clear the buffer after reading integers

    // Calling a function inside the structure
    cout << "\nPerson 1 Information:" << endl;
    person1.displayInfo();

    // Creating an object of the Address structure
    Address addr;
    cout << "\nEnter Address Details" << endl;
    cout << "Street: ";
    getline(cin, addr.street);
    cout << "City: ";
    getline(cin, addr.city);
    cout << "State: ";
    getline(cin, addr.state);
    cout << "Zip Code: ";
    cin >> addr.zipCode;
    cin.ignore(); // To clear the buffer after reading the zip code

    // Displaying the address using the function in the structure
    cout << "\nAddress Information:" << endl;
    addr.displayAddress();

    // Creating an Employee structure that uses nested structures
    Employee emp;
    emp.employeeID = "E12345";
    emp.personInfo = person1;  // Assigning a structure to a member
    emp.addressInfo = addr;    // Assigning a structure to a member

    cout << "\nEmployee Information:" << endl;
    cout << "Employee ID: " << emp.employeeID << endl;
    emp.personInfo.displayInfo();  // Accessing the nested structure's function
    emp.addressInfo.displayAddress();  // Accessing the nested structure's function

    // Array of structures: Creating an array of Book structures
    Book books[2]; // Declare an array of two books

    // Populating the array
    books[0].title = "C++ Primer";
    books[0].author = "Stanley B. Lippman";
    books[0].publicationYear = 2012;

    books[1].title = "Effective C++";
    books[1].author = "Scott Meyers";
    books[1].publicationYear = 2005;

    // Displaying information from the array of structures
    cout << "\nBook Information:" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << "Book " << i + 1 << ":" << endl;
        cout << "Title: " << books[i].title << endl;
        cout << "Author: " << books[i].author << endl;
        cout << "Publication Year: " << books[i].publicationYear << endl;
    }


    String str1("Hello");
    String str2("World");

    cout << "Before assignment:" << endl;
    str1.display();  // Output: Hello
    str2.display();  // Output: World

    // Using the overloaded assignment operator
    str1 = str2;  // Assigning str2 to str1

    cout << "After assignment:" << endl;
    str1.display();  // Output: World
    str2.display();  // Output: World
    */

    /*
    //pointer arithmetic
     // Define an array of integers
    int arr[] = { 10, 20, 30, 40, 50 };

    // Pointer to the first element of the array
    int* ptr = arr;

    // Print the array elements using pointer arithmetic
    cout << "Using pointer arithmetic to access elements in array:" << endl;
    cout << "*ptr: " << *ptr << endl;  // Output: 10 (first element)
    printf("address of array first element is :%p\n", ptr);

    // Increment pointer
    ptr++;  // Move to the next element
    cout << "*ptr after incrementing: " << *ptr << endl;  // Output: 20

    // Decrement pointer
    ptr--;  // Move back to the previous element
    cout << "*ptr after decrementing: " << *ptr << endl;  // Output: 10

    // Access elements using pointer addition
    ptr = arr;  // Reset pointer to the first element
    cout << "Accessing elements using pointer addition:" << endl;
    cout << "*(ptr + 1): " << *(ptr + 1) << endl;  // Output: 20 (2nd element)
    cout << "*(ptr + 2): " << *(ptr + 2) << endl;  // Output: 30 (3rd element)
    cout << "*(ptr + 3): " << *(ptr + 3) << endl;  // Output: 40 (4th element)

    // Pointer difference: Calculate the number of elements between two pointers
    int* ptr2 = &arr[4];  // Point to the last element of the array
    //gives the number of elements between the two pointers.
    //result of pointer subtraction is not the byte difference but the number of elements

    int diff = ptr2 - ptr;  // Difference between the two pointers
    cout << "Difference between ptr2 and ptr: " << diff << endl;  // Output: 4 (size difference between two adjacent element)
    printf("difference of address: %p\t\n", diff);
    printf("difference of address: %d", diff);

    // Subtracting pointers gives the number of elements
    ptr = &arr[2];  // Point to the 3rd element
    ptr2 = &arr[4];  // Point to the 5th element
    diff = ptr2 - ptr;  // The number of elements between ptr and ptr2
    cout << "\n Note :- difference of index will be printed \t Difference between ptr and ptr2: " << diff << endl;  // Output: 2 (2 elements between)

    // Pointer comparison
    if (ptr < ptr2) {
        cout << "ptr points to an earlier element than ptr2" << endl;
    }

    // Accessing elements with pointer and array indexing
    cout << "Accessing array elements with pointer arithmetic (ptr + i):" << endl;
    //ptr = &arr[0];
    for (int i = 0; i < 10; i++) {
        cout << *(ptr + i) << " ";  // Output: 30 40 50 garbage garbage (starting from arr[2])
    }  
      */
// Define a 2D array (3x3)
/*
int arry[3][3] = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
};
// Pointer to the first element of the 2D array
int* pttr = &arry[0][0];  // Points to arr[0][0]
printf("address of array and arry[0][0]: %p\n",pttr);
printf("address of array and arry[0][1]: %p\n", ++pttr);
pttr--;

// Accessing elements using pointer arithmetic
cout << "Using pointer arithmetic to access elements of 2D array:" << endl;

// Accessing arr[0][0]
cout << "First element: " << *pttr << endl;  // Output: 1
pttr++;
printf("address of arry[0][1]: %p\n ", pttr);
// Accessing arr[0][1] using pointer arithmetic
cout << "Second element (arr[0][1]): " << *(pttr) << endl;  // Output: 2

// Accessing arr[0][2] using pointer arithmetic
cout << "Third element (arr[0][2]): " << *(pttr + 1) << endl;  // Output: 3
*/
struct abc art;
cout << "Size of structure with padding: " << sizeof(art) << endl;
struct abd art1;
cout << "Size of structure with padding: " << sizeof(art1) << endl;
union un ug;
cout << "Size of union: " << sizeof(ug) << endl;
ug.ch = 'A';
printf("char data is : %c\n", ug.ch);
ug.it = 2;
printf("char data is : %d\n", ug.it);
//over written is done here in union//
cout << "understand the change" << endl;
printf("char data is : %d\n", ug.ch);


    return 0;
}
