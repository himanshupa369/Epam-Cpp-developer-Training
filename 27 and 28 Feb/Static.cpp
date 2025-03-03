/* Static Member Function */

//A static function belongs to the class rather than to an instance of the class.
//It cannot access non - static members because it does not have a this pointer.
//It can only access static data members and static functions.
//It can be called using the class name (ClassName::StaticFunction()), without creating an instance.

#include <iostream>
using namespace std;

class Test {
private:
   static int cnt;

public:
   static void showCount() {
       cout << "Count: " << cnt << endl;
   }
};

// Initialize static variable outside class
int Test::cnt = 5;

int main() {
   Test ts;
   //by creating instance.
   ts.showCount();
   // without creating instance.
   Test::showCount(); 
   return 0;
}
