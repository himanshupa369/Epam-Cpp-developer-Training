#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> source = {10, 20, 30, 40, 50};
    std::vector<int> destination(5);

    // Copy elements from vector to array and 
    //it is used to copy from vector to c style array also only changes needed that u have to write array name only
    std::copy(source.begin(), source.end(), destination.begin());

    // Print copied array
    for (int i : destination)
        std::cout << i << " ";
    
    return 0;
}
