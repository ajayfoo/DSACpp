//
// Created by ajay on 9/17/22.
//
#include "static_array.h"
#include<iostream>

int main()
{
    StaticArray static_array{};
    static_array.insert(8);
    static_array.insert(9);
    static_array.insert(10);
    static_array.insert(11);
    static_array.insert(12,2);
    static_array.print();
    std::cout<<"After deleting\n";
    static_array.remove();
    static_array.remove(2);
    static_array.print();
    static_array[1]=13;
    static_array.print();
    std::cout<<"Element at index 2: "<<static_array[2]<<'\n';
    return 0;
}