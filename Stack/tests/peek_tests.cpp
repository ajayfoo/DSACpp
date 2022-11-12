//
// Created by ajay on 11/10/22.
//
#include "stack.h"
#include "gtest/gtest.h"
#include<exception>

TEST(Peek,WithZeroElements)
{
    ds_impl::Stack stack{};
    ASSERT_THROW(stack.peek(),std::length_error);
}

TEST(Peek,WithMultipleElements)
{
    ds_impl::Stack stack{1,2,3,4};
    ASSERT_EQ(stack.peek(),4);
}