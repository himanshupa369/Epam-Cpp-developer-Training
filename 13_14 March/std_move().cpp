/*

🔄 What is std::move() ?

=> std::move() is a standard library function defined in the <utility> header that casts an object to an r - value reference.
=> It does not actually move anything.It simply enables move semantics by converting an l - value into an r - value, so that the move constructor or move assignment operator can be used.
=> It's mainly used to avoid expensive deep copies (e.g., for containers, strings, or user-defined types with dynamic memory).
=> reinitialization is must after move a Lvalue.
=> It is also used for non copy operation where function only provides move operation.
*/

//#include <iostream>
//#include <string>
//#include <utility>
//#include<vector>
//
//void PrintArr(std::vector<int>&& v){
//    int n = v.size();
//    for (auto& i : v) {
//        std::cout << i << " ";
//    }
//}
//int main() {
//    std::string a = "Hyderabad";
//    std::string b = std::move(a); // move constructor is used
//    std::cout << "a: " << a << std::endl; // a is now in a valid but unspecified state
//    std::cout << "b: " << b << std::endl; // "Hyderabad"
//
//
//    std::vector<std::string> v;
//    v.emplace_back("C++ session"); //construct string directly in vector,avoiding temporaries.
//    v.push_back("CopyCreation"); // it create copy then move copy into container.
//
//    std::vector<int> arr = { 1,2,3,4,5 };
//    PrintArr(std::move(arr));
//    std::cout << std::endl;
//    //Print of array elements give us error because after move ,reinitialization is must to access those variables.
//    std::vector<int> arr2 = std::move(arr);
//    for (int i = 0; i < arr.size(); i++) {
//        std::cout << arr[i] << " ";
//    }
//
//
//}

