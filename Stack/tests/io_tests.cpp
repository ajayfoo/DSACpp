//
// Created by ajay on 10/19/22.
//

#include "stack.h"

void test_print_stack()
{
    Stack<int,5> stack{};
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.print();
}

int main()
{
    test_print_stack();
    return 0;
}