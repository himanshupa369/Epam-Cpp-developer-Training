#include <iostream>
void fn(std::string && str){
    std::cout<<str<<std::endl;
}
int main() {
    std::string str = "Himanshu";
    std::cout<<sizeof(str)<<std::endl;
    fn(std::move(str));
    std::cout << "After move, str: " << str << std::endl;

    std::cout<<sizeof(str)<<std::endl;
 
    return 0;
}


// #include <iostream>
// void fn(std::string && str){
//     std::cout << str << std::endl;  // Printing the moved string
// }
 
// int main() {
//     std::string str = "Himanshu";
//     std::cout << "Length of str before move: " << str.length() << std::endl;
//     fn(std::move(str));  // Moving str into fn
//     std::cout << "Length of str after move: " << str.length() << std::endl;
 
//     return 0;
// }
