// Lambda Capture list

//Capture Modes :

//[x] : Capture variable x by value(creates a copy).
//[&x] : Capture variable x by reference(works directly on the original variable).
//[=] : Capture all variables in scope by value.
//[&] : Capture all variables in scope by reference.
//[this] : Capture the this pointer(used inside member functions).
//[=, &x] : Capture all variables by value, but capture x by reference.

//#include <iostream>
//
//int main() {

    //Capture lists
    
     //double a{10};
     //double b{20};

     //auto func = [a,b](){
     //    std::cout  << "a + b : " << a + b << std::endl;
     //};
     //func();
     

     //Capturing by value
     
      //int c{42};

      //auto func = [c](){
      //    std::cout << "Inner value : " << c << " &inner : " <<&c <<  std::endl;
      //};

      //for(size_t i{} ; i < 5 ;++i){
      //    std::cout << "Outer value : " << c << " &outer : " << &c << std::endl;
      //    func();
      //    ++c;
      //}

      

      //Capture by reference
    //int c{ 42 };

    //auto func = [&c]() {
    //    std::cout << "Inner value : " << c << " &inner : " << &c << std::endl;
    //    };

    //for (size_t i{}; i < 5;++i) {
    //    std::cout << "Outer value : " << c << " &outer : " << &c << std::endl;
    //    func();
    //    ++c;
    //}

//    return 0;
//}


//#include <iostream>
//
//
//int main() {

    //Capture everything by value

     //int c{42};

     //auto func = [=](){
     //    std::cout << "Inner value : " << c << std::endl;
     //};

     //for(size_t i{} ; i < 5 ;++i){
     //    std::cout << "Outer value : " << c << std::endl;
     //    func();
     //    ++c;
     //}



     //Capturing all reference
//    int c{ 42 };
//    int d{ 5 };
//
//    auto func = [&]() {
//        std::cout << "Inner value : " << c << std::endl;
//        std::cout << "Inner value(d) : " << d << std::endl;
//        };
//
//    for (size_t i{}; i < 5;++i) {
//        std::cout << "Outer value : " << c << std::endl;
//        func();
//        ++c;
//    }
//
//    return 0;
//}

// [this]: Capturing the this Pointer

// We use this pointer, when we need to access the current instance of the
// class inside a lambda

//#include <iostream>
//#include <vector>
//#include <algorithm>

//class MyClass {
//private:
//    int multiplier;
//
//public:
//    MyClass(int m) : multiplier(m) {}
//
//    void modifyAndPrint(std::vector<int>& data) {
//        // Lambda captures `this` pointer to access the `multiplier` member
//        auto lambda = [this](int x) {
//            return x * multiplier;
//            };
//
//        for (int& elem : data) {
//            elem = lambda(elem);  // Multiply each element using `multiplier`
//        }
//
//        // Print modified data
//        for (const int& elem : data) {
//            std::cout << elem << " ";
//        }
//        std::cout << std::endl;
//    }
//};
//
//int main() {
//    std::vector<int> data = { 1, 2, 3, 4 };
//
//    MyClass obj(3);  // Multiplier = 3
//    obj.modifyAndPrint(data);
//    // Output: 3 6 9 12
//
//    return 0;
//}



// [=, &x]: Capturing All by Value and x by Reference

//[=] : Captures all variables in the enclosing scope by value(copies).
//& x : Overrides the default behavior for variable x, capturing it by 
// reference instead of by value.

//#include <iostream>
//
//int main() {
//    int a = 5, b = 10;
//
//    // Capture by `[=, &b]`
//    auto lambda = [=, &b]() mutable {
//        int result = a * 2;  // Captures `a` by value
//        b += 10;             // Captures `b` by reference, modifies the original `b`
//        std::cout << "Inside lambda: result = " << result << ", b = " << b << std::endl;
//        };
//
//    lambda();
//
//    // Outside lambda
//    std::cout << "Main function: a = " << a << ", b = " << b << std::endl;
//
//    return 0;
//}
