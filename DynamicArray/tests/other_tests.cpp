//
// Created by ajay on 11/8/22.
//
#include "dynamic_array.h"
#include "gtest/gtest.h"
#include<utility>

TEST(OtherTests,UseCopyContructor)
{
    ds_impl::DynamicArray dynamic_array1{1,2,3,4};
    ds_impl::DynamicArray dynamic_array2{dynamic_array1};
    ASSERT_EQ(dynamic_array1[0],dynamic_array2[0]);
    ASSERT_EQ(dynamic_array1[3],dynamic_array2[3]);
}

TEST(OtherTests,UseCopyAssignment)
{
    ds_impl::DynamicArray dynamic_array1{1,2,3,4};
    ds_impl::DynamicArray dynamic_array2{1,1};
    dynamic_array2=dynamic_array1;
    ASSERT_EQ(dynamic_array2[0],dynamic_array1[0]);
    ASSERT_EQ(dynamic_array2[3],dynamic_array1[3]);
}

TEST(OtherTests,UseMoveConstructor)
{
    ds_impl::DynamicArray dynamic_array1{1,2,3,4};
    ds_impl::DynamicArray dynamic_array2{std::move(dynamic_array1)};
    ASSERT_EQ(dynamic_array2.get_length(),4);
    ASSERT_EQ(dynamic_array1.get_length(),0);
}

TEST(OtherTests,UseMoveAssignment)
{
    ds_impl::DynamicArray dynamic_array1{1,2,3,4};
    ds_impl::DynamicArray dynamic_array2{1};
    dynamic_array2=std::move(dynamic_array1);
    ASSERT_EQ(dynamic_array2.get_length(),4);
    ASSERT_EQ(dynamic_array1.get_length(),0);
}
