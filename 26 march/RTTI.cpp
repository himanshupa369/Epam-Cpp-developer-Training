// Online C++ compiler to run C++ program online
#include <iostream>
#include <typeinfo>
using namespace std;
class Animal{
    virtual void dummy(){}
};
class Cat:public Animal{
    public:
    void meow(){
        cout<<"meow meow"<<endl;
    }
    
};
class Lion:public Animal{
    public:
    
};
void show(Animal* animalPtr){
    //C style cast is unsafe
    // Cat* catPtr=(Cat*)animalPtr;
    // catPtr->meow();
    // Using dynamic_cast to safely downcast the pointer
    Cat* catPtr=dynamic_cast<Cat*>(animalPtr);
    if(catPtr) catPtr->meow();
    else cout<<"Related Instance has no meow"<<endl;
}
int main(){
    Animal* animalPtr=new Animal;
    Cat* catPtr=new Cat;
    Lion* lionPtr=new Lion;
    cout<<"for Animal:"<<endl;
    show(animalPtr);
    cout<<"for Cat:"<<endl;
    show(catPtr);
    cout<<"for Lion:"<<endl;
    show(lionPtr);
    cout<<"Type: "<<typeid(*animalPtr).name()<<endl;
    cout<<"Type: "<<typeid(*catPtr).name()<<endl;
    cout<<"Type: "<<typeid(*lionPtr).name()<<endl;
    delete animalPtr;
    delete catPtr;
    delete lionPtr;
    return 0;
}
