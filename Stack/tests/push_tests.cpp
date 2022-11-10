//
// Created by ajay on 9/29/22.
//

#include "stack.h"
#include "gtest/gtest.h"

TEST(Push, WithZeroElements)
{
    constexpr int new_element{1};
    ds_impl::Stack<int, 2> stack{};
    stack.push(new_element);
    ASSERT_EQ(stack.peek(), new_element);
}

TEST(Push, WithZeroCapacity)
{
    constexpr int new_element{1};
    ds_impl::Stack stack{};
    ASSERT_THROW(stack.push(new_element),std::length_error);
}

TEST(Push, WithMultipleElements)
{
    constexpr int new_element{1};
    ds_impl::Stack stack1{1,2,3,4};
    ds_impl::Stack<int, 4> stack{1, 2, 3};
    stack.push(new_element);
    ASSERT_EQ(stack.peek(), new_element);
}