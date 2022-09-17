//
// Created by ajay on 9/17/22.
//

#ifndef STATICARRAY_STATIC_ARRAY_H
#define STATICARRAY_STATIC_ARRAY_H

#include <stdexcept>
#include <iostream>

class StaticArray
{
    static constexpr int capacity{100};
    int m_data[capacity]{};
    int m_length{};

    [[nodiscard]] bool is_full() const noexcept;

public:
    void insert(int ele);

    void insert(int ele, int index);

    void print() const;
};

#endif //STATICARRAY_STATIC_ARRAY_H
