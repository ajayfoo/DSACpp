//
// Created by ajay on 9/17/22.
//

#ifndef STATICARRAY_STATIC_ARRAY_H
#define STATICARRAY_STATIC_ARRAY_H

#include <stdexcept>
#include <iostream>

template<typename T, std::size_t N>
class StaticArray
{
    static constexpr std::size_t m_capacity{N};
    T m_data[m_capacity]{};
    std::size_t m_length{0};

    [[nodiscard]] bool is_full() const noexcept
    {
        return m_capacity == m_length;
    }

    void check_index_bounds(std::size_t index) const
    {
        if (index >= m_length)
        {
            throw std::out_of_range{"Array index is out of bounds"};
        }
    }

public:
    void insert(T ele)
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

    void insert(T ele, std::size_t index)
    {
        if (is_full())
        {
            throw std::length_error{"Array is full"};
        }
        check_index_bounds(index);
        ++m_length;
        for (std::size_t i{m_length}; i > index; --i)
        {
            m_data[i] = m_data[i - 1];
        }
        m_data[index] = ele;
    }

    [[nodiscard]] int search(T ele) const noexcept
    {
        for (std::size_t i{0}; i < m_length; ++i)
        {
            if (m_data[i] == ele)return static_cast<int>(i);
        }
        return -1;
    }

    void print() const
    {
        std::cout << "Array Length: " << m_length << " Capacity: " << m_capacity << '\n';
        for (std::size_t i{0}; i < m_length; ++i)
        {
            std::cout << "StaticArray[" << i << "] : " << m_data[i] << '\n';
        }
    }

    [[nodiscard]] T& operator[](std::size_t index)
    {
        check_index_bounds(index);
        return m_data[index];
    }

    void remove()
    {
        --m_length;
    }

    void remove(size_t index)
    {
        check_index_bounds(index);
        for (std::size_t i{index}; i < (m_length - 1); ++i)
        {
            m_data[i] = m_data[i + 1];
        }
        --m_length;
    }
};

#endif //STATICARRAY_STATIC_ARRAY_H
