//
// Created by ajay on 9/17/22.
//

#include"static_array.h"

int main()
{
    StaticArray static_array{};
    static_array.print();
    static_array.insert(3);
    static_array.insert(8, 0);
    static_array.print();
    return 0;
}