//
// Created by ajay on 9/27/22.
//

#include "static_array.h"
#include <gtest/gtest.h>

TEST(StaticArrayTest, EmptyArray)
{
    StaticArray staticArray{};
    staticArray.insert(8);
    EXPECT_EQ(staticArray.element_at(0), 8);
}