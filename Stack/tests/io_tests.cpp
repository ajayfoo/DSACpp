//
// Created by ajay on 10/19/22.
//

#include "stack.h"

auto test_print_stack() -> void
{
    const ds_impl::Stack stack{1, 2, 3, 4};
    stack.print();
}

auto main() -> int
{
    test_print_stack();
    return 0;
}
