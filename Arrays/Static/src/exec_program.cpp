//
// Created by ajay on 9/17/22.
//

#include"static_array.h"
#include <iostream>

int main()
{
    StaticArray static_array{};
    static_array.insert(33, 0);
    std::cout << "After inserting\n";
    static_array.print();
    std::cout << static_array.search(8) << '\n';
    return 0;
}