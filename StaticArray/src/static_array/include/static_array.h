//
// Created by ajay on 9/17/22.
//

#ifndef STATICARRAY_STATIC_ARRAY_H
#define STATICARRAY_STATIC_ARRAY_H

#include <stdexcept>
#include <iostream>

class StaticArray
{
    static constexpr std::size_t capacity{100};
    int m_data[capacity]{};
    std::size_t m_length{0};

    [[nodiscard]] bool is_full() const noexcept;

public:
    void insert(int ele);

    void insert(int ele, std::size_t index);

    [[nodiscard]] int search(int ele) const noexcept;

    [[nodiscard]] int element_at(std::size_t index) const;

    void print() const;

    void update(std::size_t index, int ele);

    void remove(size_t index);
};

#endif //STATICARRAY_STATIC_ARRAY_H
