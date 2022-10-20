//
// Created by ajay on 9/27/22.
//

#include "static_array.h"
#include "gtest/gtest.h"
#include <array>

TEST(InsertAfterEnd, InsertWithZeroElement)
{
    constexpr int new_element{3};
    ds_impl::StaticArray<int,5> static_array{};
    static_array.insert(new_element);
    ASSERT_EQ(static_array[0],new_element);
}

TEST(InsertAfterEnd, InsertWithOneElement)
{
    constexpr int new_element{4};
    ds_impl::StaticArray<int,2> static_array{1};
    static_array.insert(new_element);
    ASSERT_EQ(static_array[1],new_element);
}

TEST(InsertAfterEnd, InsertMultipleElements)
{
    constexpr std::array new_elements{1,2,3,4,5,6};
    constexpr std::size_t num_elements{new_elements.size()};
    ds_impl::StaticArray<int,num_elements> static_array{};
    for(auto ele: new_elements)
    {
        static_array.insert(ele);
    }
    ASSERT_EQ(static_array[3],4);
}

TEST(InsertAt, InsertWithOneElement)
{
    constexpr int new_element{4};
    ds_impl::StaticArray<int,2> static_array{1};
    static_array.insert(new_element,0);
    ASSERT_EQ(static_array[0],new_element);
}

TEST(InsertAt, InsertMultipleElements)
{
    constexpr std::array new_elements{1,2,3,4,5,6};
    constexpr std::size_t num_elements{new_elements.size()};
    ds_impl::StaticArray<int,num_elements+1> static_array{};
    static_array.insert(100);
    for(auto ele: new_elements)
    {
        static_array.insert(ele,0);
    }
    ASSERT_EQ(static_array[2],4);
}