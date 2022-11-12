//
// Created by ajay on 11/10/22.
//
#include "stack.h"
#include "gtest/gtest.h"
#include<exception>
#include<typeinfo>

TEST(Constructors,InitializerList)
{
    ds_impl::Stack<int,2> stack{1,2};
    ASSERT_EQ(stack.get_length(),2);
}

TEST(CTAD,WithMultipleElements)
{
    using type=float;
    constexpr std::size_t length{2};
    ds_impl::Stack stack{1.2F,3.04F};
    ASSERT_EQ(stack.get_length(),length);
    ASSERT_EQ(typeid(stack.peek()).name(),typeid(type).name());
}
