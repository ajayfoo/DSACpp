//
// Created by ajay on 11/5/22.
//
#include "static_array.h"
#include "gtest/gtest.h"

static constexpr ds_impl::StaticArray dummy_static_array{1, 2, 3, 4};

TEST(Search, WithEmptyElements)
{
    ds_impl::StaticArray<int, 0> static_array{};
    ASSERT_EQ(static_array.search(2), -1);
}

TEST(Search, WithMultipleElements)
{
    ASSERT_EQ(dummy_static_array.search(2), 1);
}