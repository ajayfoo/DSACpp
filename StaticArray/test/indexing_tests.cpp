//
// Created by ajay on 9/27/22.
//

#include "static_array.h"
#include <gtest/gtest.h>

TEST(StaticArrayTest, EmptyArray)
{
    StaticArray<int,0> static_array{};
    EXPECT_EQ(static_array.get_length(), 0);
}