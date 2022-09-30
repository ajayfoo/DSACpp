#include<iostream>
#include "stack.h"

int main()
{
    Stack<double,4> stack{};
    stack.push(32);
    stack.push(34);
    stack.push(36);
    stack.print();
    stack.pop();
    stack.print();
    std::cout<<"Peek: "<<stack.peek()<<'\n';
    return 0;
}
