#include <iostream>
#include <memory>
#include <stack>

int main() {
    // Declaring two stacks of characters
    std::stack<char> s;
    std::stack<char> swapS;

    // Pushing elements onto stack 's'
    s.push('p');
    s.push('r');
    s.push('i');
    s.push('y');
    s.push('a');
    s.push('n');
    s.push('s');
    s.push('h');
    s.push('u');  // Now stack 's' contains: {p, r, i, y, a, n, s, h, u} (Top: 'u')

    // Displaying the size of both stacks before swapping
    std::cout << "size of stack s: " << s.size() << std::endl;       // Output: 9
    std::cout << "size of stack swapS: " << swapS.size() << std::endl; // Output: 0

    // Displaying the top element of stack 's'
    std::cout << "stack top element: " << s.top() << std::endl; // Output: 'u'

    // Checking if stack 's' is empty
    if (s.empty()) 
        std::cout << "stack is empty" << std::endl;
    else 
        std::cout << "stack is not empty" << std::endl; // Output: "stack is not empty"

    // Removing the top element ('u') from stack 's'
    s.pop();  // Stack now contains: {p, r, i, y, a, n, s, h}

    // Using emplace() to insert a new element 's' at the top
    s.emplace('s');  // Stack now contains: {p, r, i, y, a, n, s, h, s} (Top: 's')

    // Swapping the contents of 's' and 'swapS'
    swapS.swap(s); 

    // Now, 'swapS' has all the elements originally in 's'
    // and 's' becomes empty

    std::cout << "after swap swapS size: " << swapS.size() << std::endl; // Output: 9
    std::cout << "after swap s size: " << s.size() << std::endl;         // Output: 0

    return 0;
}
