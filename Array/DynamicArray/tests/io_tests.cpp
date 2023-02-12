//
// Created by ajay on 10/19/22.
//
#include "dynamic_array.h"

void test_print_array()
{
    ds_impl::DynamicArray dynamic_array{1,2,3,4,5};
    dynamic_array.print();
}

int main()
{
    test_print_array();
    return 0;
}