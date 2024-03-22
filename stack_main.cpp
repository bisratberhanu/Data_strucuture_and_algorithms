#include <iostream>
#include "Stack.cpp"
using namespace std;
int main(void){
    // Your code here!
    Stack stack;
    stack.Push(2.5);
    stack.Push(7.9);
    stack.Push(12.6);
    cout << "Here are the initial values of stack:\n";
    stack.DisplayStack();
    stack.Pop();
    cout << "Here are the values of stack after one pop:\n";
    stack.DisplayStack();
    
    stack.Pop();
    cout << "Here are the values of stack after two pops:\n";
    stack.DisplayStack();
}