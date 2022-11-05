//
// Created by ajay on 11/3/22.
//

#include "static_array.h"
#include "gtest/gtest.h"
#include <exception>

static constexpr ds_impl::StaticArray dummy_static_array{1, 2, 3, 4};

TEST(RemoveLast, WithZeroElements)
{
    ds_impl::StaticArray<int, 1> static_array{1};
    static_array.remove();
    bool exception_was_thrown{false};
    try
    {
        static_array.remove();
    }
    catch (const std::length_error&)
    {
        exception_was_thrown = true;
    }
    ASSERT_EQ(exception_was_thrown, true);
}

TEST(RemoveLast, WithMultipleElements)
{
    ds_impl::StaticArray static_array{1, 2, 3, 4};
    ASSERT_EQ(static_array.get_length(), dummy_static_array.get_length());
    static_array.remove();
    ASSERT_EQ(static_array.get_length(), 3);
}

TEST(RemoveLast, WithZeroCapacity)
{
    ds_impl::StaticArray static_array{};
    bool exception_was_thrown{false};
    try
    {
        static_array.remove();
    }
    catch (const std::length_error&)
    {
        exception_was_thrown = true;
    }
    ASSERT_EQ(exception_was_thrown, true);
}