//
// Created by ajay on 9/29/22.
//
#include "dynamic_array.h"
#include<iostream>

DynamicArray::DynamicArray() = default;

DynamicArray::DynamicArray(std::size_t capacity) : m_capacity{capacity}, m_array_ptr{std::make_unique<int[]>(capacity)}
{

}

DynamicArray::DynamicArray(const DynamicArray& array)
{
    m_array_ptr.release();
    m_length = array.m_length;
    m_capacity = array.m_capacity;
    m_array_ptr = std::make_unique<int[]>(m_capacity);
    for (std::size_t i{0}; i < m_length; ++i)
    {
        m_array_ptr[i] = array.m_array_ptr[i];
    }
}

DynamicArray& DynamicArray::operator=(const DynamicArray& array)
{
    m_array_ptr.release();
    m_length = array.m_length;
    m_capacity = array.m_capacity;
    m_array_ptr = std::make_unique<int[]>(m_capacity);
    for (std::size_t i{0}; i < m_length; ++i)
    {
        m_array_ptr[i] = array.m_array_ptr[i];
    }
    return *this;
}

bool DynamicArray::is_full() const noexcept
{
    return m_length == m_capacity;
}

void DynamicArray::copy_to(std::unique_ptr<int[]>& new_array_ptr)
{
    for (std::size_t i{0}; i < m_length; ++i)
    {
        new_array_ptr[i] = m_array_ptr[i];
    }
}

void DynamicArray::expand_array()
{
    std::unique_ptr<int[]> new_array_ptr = std::make_unique<int[]>(m_capacity + EXTRA_SPACE);
    copy_to(new_array_ptr);
    m_array_ptr.release();
    m_array_ptr = std::move(new_array_ptr);
    m_capacity = m_capacity + EXTRA_SPACE;
}

void DynamicArray::insert(int ele)
{
    if (is_full())
    {
        expand_array();
    }
    m_array_ptr[m_length] = ele;
    ++m_length;
}

void DynamicArray::insert(int ele, std::size_t index)
{
    if (is_full())
    {
        expand_array();
    }
    if (index > m_length)
    {
        throw std::out_of_range{"Array's index is out of bounds"};
    } else
    {
        ++m_length;
        for (std::size_t i{m_length}; i > index; --i)
        {
            m_array_ptr[i] = m_array_ptr[i - 1];
        }
        m_array_ptr[index] = ele;
    }
}

void DynamicArray::print() const
{
    std::cout << "Array Length: " << m_length << " Capacity: " << m_capacity << '\n';
    std::cout << m_array_ptr[0] << '\n';
    for (int i{0}; i < m_length; ++i)
    {
        std::cout << "DynamicArray[" << i << "] : " << m_array_ptr.get()[i] << '\n';
    }
}

[[nodiscard]]int DynamicArray::operator[](std::size_t index) const
{
    if (index >= m_length)
    {
        throw std::out_of_range{"Array's index is out of bounds"};
    }
    return m_array_ptr[index];
}

[[nodiscard]]int DynamicArray::search(int ele) const
{
    for (int i{0}; i < m_length; ++i)
    {
        if (m_array_ptr[i] == ele)return i;
    }
    return -1;
}
