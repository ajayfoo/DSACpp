//
// Created by ajay on 10/18/22.
//
#include "static_array.h"

static constexpr ds_impl::StaticArray dummy_static_array{1, 2, 3, 4};

auto test_print() -> void
{
    dummy_static_array.print();
}

auto main() -> int
{
    test_print();
    return 0;
}