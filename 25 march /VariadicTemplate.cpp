#include <iostream>

// Variadic class template
template <typename... Types>
class DataHolder {};

// Specialization for at least one argument
template <typename FirstType, typename... OtherTypes>
class DataHolder<FirstType, OtherTypes...> {
public:
    FirstType value;
    DataHolder<OtherTypes...> next;

    DataHolder(FirstType val, OtherTypes... rest) : value(val), next(rest...) {}

    void display() {
        std::cout << value << " ";
        next.display();
    }
};

// Base case specialization
template <>
class DataHolder<> {
public:
    void display() {}
};

int main() {
    DataHolder<std::string, float, int> dh("Hello", 3.14, 42);
    dh.display();  // Output: Hello 3.14 42
    return 0;
}
