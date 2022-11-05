//
// Created by ajay on 9/17/22.
//

#ifndef STATICARRAY_STATIC_ARRAY_H
#define STATICARRAY_STATIC_ARRAY_H

#include <array>
#include <iostream>
#include <stdexcept>

namespace ds_impl
{
template <typename T, std::size_t N>
class StaticArray
{
    static constexpr std::size_t m_capacity{N};
    T                            m_data[m_capacity]{};
    std::size_t                  m_length{0};

    [[nodiscard]] auto           is_full() const noexcept -> bool
    {
        return m_capacity == m_length;
    }

    auto check_capacity() const -> void
    {
        if (is_full())
        {
            throw std::length_error("Array is full.");
        }
    }
    auto check_index_bounds(std::size_t index) const -> void
    {
        if (index == 0 && m_length == 0)
        {
            return;
        }
        if (index >= m_length)
        {
            throw std::out_of_range{"Array index is out of bounds"};
        }
    }

  public:
    constexpr StaticArray() = default;
    constexpr StaticArray(const std::initializer_list<T>& list) : m_length{list.size()}
    {
        if (m_length > N)
        {
            throw std::length_error("Length of array exceeded its capacity.");
        }
        for (std::size_t i{0}; auto ele : list)
        {
            m_data[i] = ele;
            ++i;
        }
    }
    [[nodiscard]] constexpr auto get_length() const -> int
    {
        return m_length;
    }
    auto insert(T ele) -> void
    {
        check_capacity();
        m_data[m_length] = ele;
        ++m_length;
    }

    auto insert(T ele, std::size_t index) -> void
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

    [[nodiscard]] auto search(T ele) const noexcept -> int
    {
        for (std::size_t i{0}; i < m_length; ++i)
        {
            if (m_data[i] == ele)
                return static_cast<int>(i);
        }
        return -1;
    }

    auto print() const -> void
    {
        std::cout << "Array Length: " << m_length << " Capacity: " << m_capacity << '\n';
        for (std::size_t i{0}; i < m_length; ++i)
        {
            std::cout << "StaticArray[" << i << "] : " << m_data[i] << '\n';
        }
    }

    [[nodiscard]] auto operator[](std::size_t index) -> T &
    {
        check_index_bounds(index);
        return m_data[index];
    }
    [[nodiscard]] auto operator[](std::size_t index)const -> T
    {
        check_index_bounds(index);
        return m_data[index];
    }
    auto remove() -> void
    {
        if(m_length==0)
        {
            throw std::length_error("Remove operation failed, array is empty");
        }
        --m_length;
    }

    auto remove(size_t index) -> void
    {
        check_index_bounds(index);
        for (std::size_t i{index}; i < (m_length - 1); ++i)
        {
            m_data[i] = m_data[i + 1];
        }
        --m_length;
    }
};

template< typename T, typename... U>
 StaticArray(T,U...)->StaticArray<T,1+sizeof...(U)>;

} // namespace ds_impl

#endif // STATICARRAY_STATIC_ARRAY_H
