//
// Created by ajay on 9/17/22.
//

#ifndef STATICARRAY_STATIC_ARRAY_H
#define STATICARRAY_STATIC_ARRAY_H

#include <stdexcept>
#include <iostream>

namespace ds_impl
{
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

        void check_capacity()const
        {
            if(is_full())
            {
                throw std::length_error("Array is full.");
            }
        }
        void check_index_bounds(std::size_t index) const
        {
            if (index >= m_length)
            {
                throw std::out_of_range{"Array index is out of bounds"};
            }
        }

    public:
        StaticArray() = default;

        StaticArray(std::initializer_list<T> list) : m_length{list.size()}
        {
            if(m_length>N)
            {
                throw std::length_error("Length of array exceeded its capacity.");
            }
            for (std::size_t i{0}; auto ele: list)
            {
                m_data[i] = ele;
                ++i;
            }
        }

        [[nodiscard]] int get_length()const
        {
            return m_length;
        }
        void insert(T ele)
        {
            check_capacity();
            m_data[m_length] = ele;
            ++m_length;
        }

        void insert(T ele, std::size_t index)
        {
            check_capacity();
            check_index_bounds(index);
            for (std::size_t i{m_length}; i > index; --i)
            {
                m_data[i] = m_data[i - 1];
            }
            ++m_length;
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

}

#endif //STATICARRAY_STATIC_ARRAY_H
