//
// Created by ajay on 9/17/22.
//

#include"static_array.h"
#include <iostream>

int main()
{
    StaticArray static_array{};
    static_array.insert(3);
    static_array.insert(8);
    static_array.insert(-31);
    static_array.insert(9);
    static_array.insert(10);
    static_array.insert(23);
    static_array.insert(1);
    static_array.insert(69);
    static_array.print();
    static_array.insert(33, 0);
    std::cout << "After inserting\n";
    static_array.print();
    std::cout << static_array.search(8) << '\n';
    return 0;
}