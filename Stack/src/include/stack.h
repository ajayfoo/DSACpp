//
// Created by ajay on 9/30/22.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <any>
#include <array>
#include <cstddef>
#include <exception>
#include <iostream>

namespace ds_impl
{
template <typename T, std::size_t N> class Stack
{
    int m_top{-1};
    static constexpr std::size_t m_capacity{N};
    std::array<T, N> m_data;
    [[nodiscard]] auto is_empty() const -> bool
    {
        return m_top == -1;
    }
    [[nodiscard]] auto is_full() const -> bool
    {
        return static_cast<std::size_t>(m_top) == (m_capacity - 1);
    }

  public:
    Stack() = default;
    Stack(std::initializer_list<T> list)
    {
        if (list.size() > N)
        {
            throw std::length_error("Stack length is greater than its capacity");
        }
        if (list.size() != 0)
        {
            m_top = list.size() - 1;
        }
        for (std::size_t index{0}; auto ele : list)
        {
            m_data[index] = ele;
            ++index;
        }
    }
    auto push(T ele) -> void
    {
        if (is_full())
        {
            throw std::length_error("Stack is full. Stack overflow occurred.");
        }
        m_data[++m_top] = ele;
    }
    auto pop() -> T
    {
        if (is_empty())
        {
            throw std::length_error("Stack is empty. Stack underflow occurred.");
        }
        return m_data[m_top--];
    }
    auto peek() const -> T
    {
        if (is_empty())
        {
            throw std::length_error("Stack is empty.");
        }
        return m_data[m_top];
    }
    auto print() const -> void
    {
        std::cout << "Stack Top: " << m_top << " Capacity: " << m_capacity << '\n';
        for (int i{m_top}; i >= 0; --i)
        {
            std::cout << m_data[i] << '\n';
        }
    }
    [[nodiscard]] auto get_length() const -> std::size_t
    {
        return static_cast<std::size_t>(m_top + 1);
    }
};

template <typename T, typename... U> Stack(T, U... args) -> Stack<T, 1 + sizeof...(U)>;
template <typename... U> Stack() -> Stack<std::any, 0>;

} // namespace ds_impl

#endif // STACK_STACK_H
