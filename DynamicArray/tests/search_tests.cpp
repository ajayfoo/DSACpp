//
// Created by ajay on 11/5/22.
//
#include "dynamic_array.h"
#include "gtest/gtest.h"

static const ds_impl::DynamicArray dummy_dynamic_array{1, 2, 3, 4};

TEST(Search, WithEmptyElements)
{
    ds_impl::DynamicArray<int> dynamic_array{};
    ASSERT_EQ(dynamic_array.search(2), -1);
}

TEST(Search, WithMultipleElements)
{
    ASSERT_EQ(dummy_dynamic_array.search(2), 1);
}