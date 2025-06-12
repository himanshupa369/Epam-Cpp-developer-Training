#include <iostream>
using namespace std;

class A {
public:
    void show() {
        cout << "From A\n";
    }
};

class B : public A {};
class C : public A {};
class D : public B, public C {};  // Diamond

int main() {
    D obj;
    // obj.show();  ❌ Error: Ambiguous
    obj.B::show();  // ✅ OK
    obj.C::show();  // ✅ OK
}
