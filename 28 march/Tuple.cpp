/* ** Tuple in C++ ** */

//std::tuple is a fixed-size collection of heterogeneous (different types) values, introduced in C++11. It is similar to std::pair but can store more than two elements.
#include <iostream>
#include <tuple>
#include<complex>
using namespace std;

std::tuple<int, double, std::string> getData() {
    return std::make_tuple(42, 9.81, "Physics");
}

int main() {
    std::tuple<int, double, std::string> t1(10, 3.14, "Hello");

    // Alternative: Using std::make_tuple
    auto t2 = std::make_tuple(42, 2.718, "World");

    // std::get<index>(tuple) extracts values at the specified index.
    std::cout << "Integer: " << std::get<0>(t1) << std::endl;
    std::cout << "Double: " << std::get<1>(t1) << std::endl;
    std::cout << "String: " << std::get<2>(t1) << std::endl;

    // tuple size
    std::cout << "Tuple size: " << std::tuple_size<decltype(t2)>::value << std::endl;

    //Tuple Type(std::tuple_element)
    using T = std::tuple<int, double, std::string>;
    std::tuple_element<1, T>::type x=2.50000;  // x is of type double
    std::cout<<"x is : "<<x<<std::endl;

    //Tuple Unpacking(std::tie)
    std::tuple<int, double, std::string> t(4, 5.76, "Hello");

    int a;
    double b;
    std::string c;

    std::tie(a, b, c) = t;  // Unpacks tuple into variables
    /*note:-To ignore an element, use std::ignore : 
    std::tie(a, std::ignore, c) = t;  // Ignore the second element
    */

    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;

    //Concatenating Tuples (std::tuple_cat)
    std::tuple<int, char> t4(10, 'A');
    std::tuple<std::string, double> t5("Hello", 3.14);
    auto t6 = std::tuple_cat(t4, t5);  // t6 = (10, 'A', "Hello", 3.14)

    //Tuple Comparison
    std::tuple<int, double> t7(1, 2.5), t8(1, 3.0);

    if (t7 < t8) {
        std::cout << "t7 is smaller\n";
    }

    //auto [x, y, z] = getData();  // Structured Binding (C++17) my version is 14.2.0
    int x1;
    double y;
    std::string z;
    std::tie(x1,y,z)=getData();
    std::cout << "x: " << x1 << ", y: " << y << ", z: " << z << std::endl;
}
