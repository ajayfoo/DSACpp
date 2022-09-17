//
// Created by ajay on 9/17/22.
//
#include "static_array.h"

[[nodiscard]] bool StaticArray::is_full() const noexcept
{
    return capacity == m_length;
}

void StaticArray::insert(int ele)
{
    if (is_full())
    {
        throw std::length_error{"Array is full"};
    } else
    {
        m_data[m_length] = ele;
        ++m_length;
    }
}

void StaticArray::insert(int ele, int index)
{
    if (is_full())
    {
        throw std::length_error{"Array is full"};
    }
    if (index < 0 || index >= m_length)
    {
        throw std::out_of_range{"Array index is out of bounds"};
    } else
    {
        for (int i = m_length - 1; i > index; --i)
        {
            m_data[i] = m_data[i - 1];
        }
        m_data[index] = ele;
        ++m_length;
    }
}

void StaticArray::print() const
{
    for (int i{0}; i < m_length; ++i)
    {
        std::cout << "StaticArray[" << i << "] : " << m_data[i] << '\n';
    }
}