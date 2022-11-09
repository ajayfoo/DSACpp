//
// Created by ajay on 9/29/22.
//

#ifndef DYNAMICARRAY_DYNAMIC_ARRAY_H
#define DYNAMICARRAY_DYNAMIC_ARRAY_H

#include <any>
#include <array>
#include <cstddef>
#include <iostream>
#include <memory>
#include <utility>

namespace ds_impl
{
template <typename T> class DynamicArray
{
    std::size_t m_length{};
    std::size_t m_capacity{};
    static constexpr int EXTRA_SPACE_FOR_ARRAY{2};
    std::unique_ptr<T[]> m_array_ptr{};

    [[nodiscard]] auto is_full() const noexcept -> bool
    {
        return m_length == m_capacity;
    }
    auto copy_to(std::unique_ptr<T[]>& new_array_ptr) -> void
    {
        for (std::size_t i{0}; i < m_length; ++i)
        {
            new_array_ptr[i] = m_array_ptr[i];
        }
    }
    void expand_array_if_needed()
    {
        if (is_full())
        {
            std::unique_ptr<T[]> new_array_ptr = std::make_unique<T[]>(m_capacity + EXTRA_SPACE_FOR_ARRAY);
            copy_to(new_array_ptr);
            m_array_ptr = std::move(new_array_ptr);
            m_capacity = m_capacity + EXTRA_SPACE_FOR_ARRAY;
        }
    }
    void shrink_array_if_needed()
    {
        if (m_capacity - m_length > EXTRA_SPACE_FOR_ARRAY * 2)
        {
            std::unique_ptr<T[]> new_array_ptr = std::make_unique<T[]>(m_length + EXTRA_SPACE_FOR_ARRAY);
            copy_to(new_array_ptr);
            m_array_ptr = std::move(new_array_ptr);
            m_capacity = m_length + EXTRA_SPACE_FOR_ARRAY;
        }
    }
    void check_index_bounds(std::size_t index) const
    {
        if (index >= m_length)
        {
            throw std::out_of_range{"Array's index is out of bounds"};
        }
    }

  public:
    DynamicArray() = default;

    DynamicArray(std::initializer_list<T> list)
        : m_capacity{list.size()}, m_length{list.size()}, m_array_ptr{std::make_unique<T[]>(list.size())}
    {
        for (std::size_t i{0}; auto ele : list)
        {
            m_array_ptr[i] = ele;
            ++i;
        }
    }
    DynamicArray(const DynamicArray& array)
        : m_length{array.m_length}, m_capacity{array.m_capacity}, m_array_ptr{std::make_unique<T[]>(m_capacity)}
    {
        for (std::size_t i{0}; i < m_length; ++i)
        {
            m_array_ptr[i] = array.m_array_ptr[i];
        }
    }
    auto operator=(const DynamicArray& array) -> DynamicArray&
    {
        if (this == &array)
        {
            return *this;
        }
        m_length = array.m_length;
        m_capacity = array.m_capacity;
        m_array_ptr = std::make_unique<T[]>(m_capacity);
        for (std::size_t i{0}; i < m_length; ++i)
        {
            m_array_ptr[i] = array.m_array_ptr[i];
        }
        return *this;
    }
    DynamicArray(DynamicArray&& array) noexcept
        : m_capacity{array.m_capacity}, m_length{array.m_length}, m_array_ptr{std::move(array.m_array_ptr)}
    {
        array.m_capacity = 0;
        array.m_length = 0;
        array.m_array_ptr = nullptr;
    }
    auto operator=(DynamicArray&& array) noexcept -> DynamicArray&
    {
        if (&array == this)
        {
            return *this;
        }
        m_capacity = array.m_capacity;
        m_length = array.m_length;
        m_array_ptr = std::move(array.m_array_ptr);
        array.m_capacity = 0;
        array.m_length = 0;
        array.m_array_ptr = nullptr;
        return *this;
    }
    virtual ~DynamicArray() = default;
    [[nodiscard]] auto get_length() const -> std::size_t
    {
        return m_length;
    }
    auto push(T ele) -> void
    {
        expand_array_if_needed();
        m_array_ptr[m_length] = ele;
        ++m_length;
    }
    auto insert(T ele, std::size_t index) -> void
    {
        expand_array_if_needed();
        check_index_bounds(index);
        ++m_length;
        for (std::size_t i{m_length}; i > index; --i)
        {
            m_array_ptr[i] = m_array_ptr[i - 1];
        }
        m_array_ptr[index] = ele;
    }
    void print() const
    {
        std::cout << "Array Length: " << m_length << " Capacity: " << m_capacity << '\n';
        for (std::size_t i{0}; i < m_length; ++i)
        {
            std::cout << "DynamicArray[" << i << "] : " << m_array_ptr.get()[i] << '\n';
        }
    }
    [[nodiscard]] auto operator[](std::size_t index) -> T&
    {
        check_index_bounds(index);
        return m_array_ptr[index];
    }
    [[nodiscard]] auto operator[](std::size_t index) const -> T
    {
        check_index_bounds(index);
        return m_array_ptr[index];
    }
    [[nodiscard]] auto search(T ele) const -> T
    {
        for (std::size_t i{0}; i < m_length; ++i)
        {
            if (m_array_ptr[i] == ele)
                return i;
        }
        return -1;
    }
    auto pop() -> void
    {
        if(m_length==0)
        {
            throw std::length_error("Array is empty!");
        }
        --m_length;
        shrink_array_if_needed();
    }
    auto remove(std::size_t index) -> void
    {
        check_index_bounds(index);

        for (size_t i = index; i < (m_length - 1); ++i)
        {
            m_array_ptr[i] = m_array_ptr[i + 1];
        }
        --m_length;
        shrink_array_if_needed();
    }
};

} // namespace ds_impl

#endif // DYNAMICARRAY_DYNAMIC_ARRAY_H
