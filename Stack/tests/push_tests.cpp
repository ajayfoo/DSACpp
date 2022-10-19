//
// Created by ajay on 9/29/22.
//

#include "stack.h"
#include "gtest/gtest.h"

TEST(PushTests,EmptyStack)
{
    ds_impl::Stack<int,2> stack{};
    ASSERT_EQ(stack.get_length(),0);
}

TEST(PushTests,Push)
{
    ds_impl::Stack<int,1> stack{};
    stack.push(3);
    ASSERT_EQ(stack.peek(),3);
}