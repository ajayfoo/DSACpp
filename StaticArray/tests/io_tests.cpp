//
// Created by ajay on 10/18/22.
//
#include "static_array.h"

void test_print()
{
    ds_impl::StaticArray<int, 4> static_array{1, 2, 3, 4};
    static_array.print();
}

int main()
{
    test_print();
    return 0;
}