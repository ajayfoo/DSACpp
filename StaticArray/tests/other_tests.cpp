//
// Created by ajay on 10/20/22.
//
#include "static_array.h"
#include "gtest/gtest.h"

TEST(OtherTests, NewArrayLenghtIsZero)
{
    constexpr ds_impl::StaticArray<int,0> static_array{};
    ASSERT_EQ(static_array.get_length(),0);
}