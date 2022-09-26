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

void StaticArray::insert(int ele, std::size_t index)
{
    if (is_full())
    {
        throw std::length_error{"Array is full"};
    }
    if (index < 0 || index > m_length)
    {
        throw std::out_of_range{"Array index is out of bounds"};
    } else
    {
        ++m_length;
        for (std::size_t i{m_length - 1}; i > index; --i)
        {
            m_data[i] = m_data[i - 1];
        }
        m_data[index] = ele;
    }
}

[[nodiscard]] int StaticArray::search(int ele) const noexcept
{
    for (std::size_t i{0}; i < m_length; ++i)
    {
        if (m_data[i] == ele)return static_cast<int>(i);
    }
    return -1;
}

void StaticArray::print() const
{
    for (std::size_t i{0}; i < m_length; ++i)
    {
        std::cout << "StaticArray[" << i << "] : " << m_data[i] << '\n';
    }
}