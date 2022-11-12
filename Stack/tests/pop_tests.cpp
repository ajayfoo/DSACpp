//
// Created by ajay on 11/10/22.
//
#include "stack.h"
#include "gtest/gtest.h"
#include<exception>

TEST(Pop,WithZeroElements)
{
    ds_impl::Stack<int,2> stack{};
    ASSERT_THROW(stack.pop(),std::length_error);
}
TEST(Pop,WithMultipleElements)
{
    ds_impl::Stack stack{1,2,3,4};
    ASSERT_EQ(stack.pop(),4);
}