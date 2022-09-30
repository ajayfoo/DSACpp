//
// Created by ajay on 9/29/22.
//
#include "dynamic_array.h"
#include<iostream>

int main()
{
    DynamicArray dynamic_array{4};
    dynamic_array.insert(9);
    dynamic_array.insert(11);
    dynamic_array.insert(13);
    dynamic_array.insert(15, 1);
    dynamic_array.insert(16, 2);
    dynamic_array.print();
    std::cout<<"13 is at index: "<<dynamic_array.search(13)<<'\n';
    std::cout<<"Element at index 4: "<<dynamic_array[4]<<'\n';
    return 0;
}