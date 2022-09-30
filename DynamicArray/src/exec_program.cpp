//
// Created by ajay on 9/29/22.
//
#include "dynamic_array.h"

int main()
{
    DynamicArray dynamic_array{4};
    dynamic_array.insert(9);
    dynamic_array.insert(11);
    dynamic_array.insert(13);
    dynamic_array.insert(15,1);
    dynamic_array.insert(16,2);
    dynamic_array.print();
}