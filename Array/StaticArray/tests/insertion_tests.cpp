//
// Created by ajay on 9/27/22.
//

#include "static_array.h"
#include "gtest/gtest.h"
#include <array>

static constexpr ds_impl::StaticArray dummy_static_array{1, 2, 3, 4};

TEST(InsertAtHead, WithZeroElements)
{
    constexpr int new_element{2};
    ds_impl::StaticArray<int, 3> static_array{};
    static_array.insert(new_element, 0);
    ASSERT_EQ(static_array[0], new_element);
    ASSERT_EQ(static_array.get_length(), 1);
}
TEST(InsertAfterEnd, WithZeroElements)
{
    constexpr int new_element{3};
    ds_impl::StaticArray<int, 4> static_array{};
    static_array.insert(new_element);
    ASSERT_EQ(static_array[0], new_element);
}

TEST(InsertAfterEnd, WithOneElement)
{
    constexpr int new_element{4};
    ds_impl::StaticArray<int, 2> static_array{1};
    static_array.insert(new_element);
    ASSERT_EQ(static_array[1], new_element);
}

TEST(InsertAfterEnd, WithMultipleElements)
{
    ds_impl::StaticArray static_array{1, 2, 3, 4};
    ASSERT_EQ(static_array[3], 4);
}

TEST(InsertAfterEnd, WithZeroCapacity)
{
    ds_impl::StaticArray static_array{};
    bool exception_thrown{false};
    try
    {
        static_array.insert(2);
    }
    catch (const std::length_error&)
    {
        exception_thrown = true;
    }
    ASSERT_EQ(exception_thrown, true);
}

TEST(InsertAt, WithOneElement)
{
    constexpr int new_element{4};
    ds_impl::StaticArray<int, 2> static_array{1};
    static_array.insert(new_element, 0);
    ASSERT_EQ(static_array[0], new_element);
}

TEST(InsertAt, WithMultipleElements)
{
    ds_impl::StaticArray<int, dummy_static_array.get_length()> static_array{};
    for (std::size_t i{0}; i < dummy_static_array.get_length(); ++i)
    {
        static_array.insert(dummy_static_array[i], 0);
    }
    ASSERT_EQ(static_array[3], 1);
}