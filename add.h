#pragma once
int Add(int* a, int* b);    //Add two numbers and return the sum
void AddVal(int* a, int* b, int* result); //Add two numbers and return the sum through the third pointer argument
void Swap(int* a, int* b);  //Swap the value of two integers
void Factorial(int* a, int* result);       //Generate the factorial of a number and return that through the second pointer argument

void Add(int a, int b, int& result);    //Add two numbers and return the result through a reference parameter
void Factorial(int a, int& result);    //Find factorial of a number and return that through a reference parameter
void Swap(int& a, int& b);            //Swap two numbers through reference arguments