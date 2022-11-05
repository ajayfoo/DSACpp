//
// Created by ajay on 10/18/22.
//
#include "static_array.h"

static constexpr ds_impl::StaticArray dummy_static_array{1, 2, 3, 4};

auto test_print() -> void
{
    dummy_static_array.print();
}

auto test_print_empty_array() -> void
{
    ds_impl::StaticArray<int, 3> static_array{};
    static_array.print();
    static_array.insert(1);
    static_array.insert(2);
    static_array.print();
}

auto main() -> int
{
    test_print_empty_array();
    return 0;
}