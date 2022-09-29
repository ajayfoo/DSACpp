//
// Created by ajay on 9/29/22.
//
#include "dynamic_array.h"
#include<iostream>

bool DynamicArray::array_is_full() const
{
    return m_length == m_capacity;
}

void DynamicArray::expand_array()
{
    m_array_ptr.release();
    m_array_ptr=std::make_unique<int[]>(m_capacity+EXTRA_SPACE);
}
void DynamicArray::insert(int ele)
{
    if (array_is_full())
    {
        expand_array();
    }
    m_array_ptr.get()[0]=ele;
    ++m_length;
}

DynamicArray::DynamicArray(std::size_t capacity) : m_capacity{capacity}, m_array_ptr{std::make_unique<int[]>(capacity)}
{

}

void DynamicArray::print()
{
    std::cout<<"Array Length: "<<m_length<<" Capacity: "<<m_capacity<<'\n';
    std::cout<<m_array_ptr[0]<<'\n';
}