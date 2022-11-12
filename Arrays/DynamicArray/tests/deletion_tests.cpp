//
// Created by ajay on 11/3/22.
//

#include "dynamic_array.h"
#include "gtest/gtest.h"
#include <exception>

static const ds_impl::DynamicArray dummy_dynamic_array{1, 2, 3, 4};

TEST(Pop, WithZeroElements)
{
    ds_impl::DynamicArray<int> dynamic_array{};
    ASSERT_THROW(dynamic_array.pop(), std::length_error);
}

TEST(Pop, WithMultipleElements)
{
    ds_impl::DynamicArray dynamic_array{dummy_dynamic_array};
    dynamic_array.pop();
    ASSERT_EQ(dynamic_array.get_length(), 3);
}

TEST(Remove, Head)
{
    constexpr std::size_t index{0};
    ds_impl::DynamicArray dynamic_array{dummy_dynamic_array};
    dynamic_array.remove(index);
    ASSERT_EQ(dynamic_array[index], dummy_dynamic_array[index+1]);
}

TEST(Remove, Middle)
{
    constexpr std::size_t index{1};
    ds_impl::DynamicArray dynamic_array{dummy_dynamic_array};
    dynamic_array.remove(index);
    ASSERT_EQ(dynamic_array[index], dummy_dynamic_array[index+1]);
}

TEST(Remove, Tail)
{
    constexpr std::size_t index{3};
    ds_impl::DynamicArray dynamic_array{dummy_dynamic_array};
    dynamic_array.remove(index);
    ASSERT_EQ(dynamic_array[index-1], dummy_dynamic_array[index-1]);
}
