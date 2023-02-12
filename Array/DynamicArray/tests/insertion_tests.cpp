//
// Created by ajay on 9/29/22.
//

#include "dynamic_array.h"
#include "gtest/gtest.h"

static const ds_impl::DynamicArray dummy_dynamic_array{1, 2, 3, 4};

TEST(Push, WithZeroElements)
{
    constexpr int new_element{12};
    ds_impl::DynamicArray<int> dynamic_array{};
    dynamic_array.push(new_element);
    ASSERT_EQ(dynamic_array[0], new_element);
}

TEST(Push, WithMultipleElements)
{
    constexpr int new_element{12};
    ds_impl::DynamicArray dynamic_array{dummy_dynamic_array};
    dynamic_array.push(new_element);
    ASSERT_EQ(dynamic_array[4], new_element);
}

TEST(Insert,WithZeroElements)
{
    constexpr int new_element{4};
    constexpr std::size_t index{0};
    ds_impl::DynamicArray<int> dynamic_array{};
    ASSERT_THROW(dynamic_array.insert(new_element,index),std::out_of_range);
}

TEST(Insert, AtHead)
{
    constexpr int new_element{4};
    constexpr std::size_t index{0};
    ds_impl::DynamicArray dynamic_array{dummy_dynamic_array};
    dynamic_array.insert(new_element, index);
    ASSERT_EQ(dynamic_array[index], new_element);
}

TEST(Insert, AtMiddle)
{
    constexpr int new_element{4};
    constexpr std::size_t index{1};
    ds_impl::DynamicArray dynamic_array{dummy_dynamic_array};
    dynamic_array.insert(new_element, index);
    ASSERT_EQ(dynamic_array[index], new_element);
}

TEST(Insert, AtTail)
{
    constexpr int new_element{4};
    const std::size_t index{dummy_dynamic_array.get_length()-1};
    ds_impl::DynamicArray dynamic_array{dummy_dynamic_array};
    dynamic_array.insert(new_element, index);
    ASSERT_EQ(dynamic_array[index], new_element);
}
