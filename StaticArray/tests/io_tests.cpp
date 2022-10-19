//
// Created by ajay on 10/18/22.
//
#include "static_array.h"

void test_print_static_array()
{
    StaticArray<int,10> static_array{1,2,3,4,5};
    static_array.print();
}

int main()
{
    test_print_static_array();
    return 0;
}