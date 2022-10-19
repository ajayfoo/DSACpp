//
// Created by ajay on 9/27/22.
//

#include "static_array.h"
#include <gtest/gtest.h>

TEST(InsertionTests, EmptyArray)
{
    StaticArray<int,0> static_array{};
    ASSERT_EQ(static_array.get_length(), 0);
}

TEST(InsertionTests, InsertInTheMiddle)
{
    StaticArray<int,5> static_array{1,2,3};
    static_array.insert(98,1);
    ASSERT_EQ(static_array[1],98);
}