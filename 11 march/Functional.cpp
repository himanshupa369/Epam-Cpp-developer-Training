// #include<iostream>
// #include<functional>
// using namespace std;

// /* Call back function in case of lambda,Functions and Functor*/
// void fn(function<void()> functionParameter){
//     cout<<"hi, I am himanshu"<<endl;
//     functionParameter();
// }

// int main(){
//     auto greet=[](){
//         cout<<"This is my frnd Priyanshu:"<<endl;
//     };
//     fn(greet);
// }
// Online C++ compiler to run C++ program online

#include <iostream>

#include <functional>

using namespace std;

int add(int a,int b){

    return a+b;

}

// below two lines do the exactly same task but the first one is only valid for functions,lamdas,functors 

// and second one is valid for lambdas without capture list and valid for functions and functors

//function<int(int,int)>callback

//int (*callback)(int ,int)

int compute(int x,int y,int (*callback)(int ,int)){

    return callback(x,y);

}

int main(){

    cout<<compute(2,3,add);

}
 
