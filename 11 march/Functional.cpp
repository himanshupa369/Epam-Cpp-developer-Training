#include<iostream>
#include<functional>
using namespace std;

/* Call back function in case of lambda,Functions and Functor*/
void fn(function<void()> functionParameter){
    cout<<"hi, I am himanshu"<<endl;
    functionParameter();
}

int main(){
    auto greet=[](){
        cout<<"This is my frnd Priyanshu:"<<endl;
    };
    fn(greet);
}
