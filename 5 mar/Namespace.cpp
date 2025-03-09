//...Namespace...//
#include<iostream>
using namespace  std;

//Introduction...

//Namespaces in C++ provide a way to group related code together and prevent name conflicts, especially in large projects.
//They allow developers to define separate scopes for identifiers, such as functions, classes, and variables, avoiding naming collisions.

//Key Features of Namespaces...
 
//Avoids Name Conflicts : Helps in organizing code and preventing clashes between identifiers with the same name in different libraries.
//Supports Nested Namespaces : Allows defining namespaces inside other namespaces.
//Can Be Extended : A namespace can be reopened and modified in different parts of the code.
//Allows Alias for Shortening Namespaces : Provides an easier way to reference deeply nested namespaces.
//Supports using Directive and Declaration : Simplifies code usage by avoiding repetitive namespace qualification.

//When to Use Namespaces...

//When developing large projects to avoid naming conflicts.
//When organizing code into logical units.
//When integrating third - party libraries that may have conflicting names.

//When Not to Use using namespace...

//In header files(can lead to conflicts in multiple inclusions).
//In global scope(can introduce ambiguities).
//When specific namespace qualification improves code readability.


//Defining a namespace
namespace Avg {
    float calculate(float x, float y) {
        return (x + y) / 2;
    }
}
namespace Summ {
    float calculate(float x, float y) {
        return x + y;
    }
}

namespace valDisplay {
    int value = 42;
    void display() {
        cout << "Value: " << value << endl;
    }
}

//Nested namespace
namespace Outr {
    namespace Innr {
        void show() {
            cout << "Inside Nested Namespace" << endl;
        }
    }
}

// Namespace alias
namespace alias = Outr::Innr;

int main() {
    // use of namepsace 
    //1)Method : using namespace qualification
    using namespace Avg;
    float f = calculate(5.3, 6.7);
    //2)Method : using scope resolution operator //
    float fl = Summ::calculate(5.3, 6.7);
    cout << "f=" << f << endl;
    cout << "fl=" << fl << endl;

    valDisplay::display();
    cout << "Namespace variable: " << valDisplay::value << endl;

    // Accessing nested namespace
    Outr::Innr::show();

    // Using alias
    alias::show();

}
