//
// Created by ajay on 9/29/22.
//

#ifndef DYNAMICARRAY_DYNAMIC_ARRAY_H
#define DYNAMICARRAY_DYNAMIC_ARRAY_H

#include <cstddef>
#include <array>
#include <memory>

class DynamicArray
{
    std::size_t m_length{};
    std::size_t m_capacity{};
    static constexpr int EXTRA_SPACE{10};
    std::unique_ptr<int[]> m_array_ptr{};
    [[nodiscard]] bool array_is_full() const;
    void expand_array();
public:
    void insert(int ele);
    DynamicArray()=delete;
    explicit DynamicArray(std::size_t capacity);
    void print();
};

#endif //DYNAMICARRAY_DYNAMIC_ARRAY_H
