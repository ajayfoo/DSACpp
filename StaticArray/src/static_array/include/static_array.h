//
// Created by ajay on 9/17/22.
//

#ifndef STATICARRAY_STATIC_ARRAY_H
#define STATICARRAY_STATIC_ARRAY_H

#include <stdexcept>
#include <iostream>

class StaticArray
{
    static constexpr std::size_t m_capacity{100};
    int m_data[m_capacity]{};
    std::size_t m_length{0};

    [[nodiscard]] bool is_full() const noexcept;

    void check_index_bounds(std::size_t index) const;

public:
    void insert(int ele);

    void insert(int ele, std::size_t index);

    [[nodiscard]] int search(int ele) const noexcept;

    void print() const;

    [[nodiscard]] int& operator[](std::size_t index);

    void remove();

    void remove(size_t index);
};

#endif //STATICARRAY_STATIC_ARRAY_H
