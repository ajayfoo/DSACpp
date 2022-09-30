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

    [[nodiscard]] bool is_full() const noexcept;

    void copy_to(std::unique_ptr<int[]>& new_array_ptr);

    void expand_array();

public:
    DynamicArray();

    DynamicArray(const DynamicArray& array);

    DynamicArray& operator=(const DynamicArray& array);

    explicit DynamicArray(std::size_t capacity);

    void insert(int ele);

    void insert(int ele, std::size_t index);

    void print() const;

    [[nodiscard]]int operator[](std::size_t index) const;

    [[nodiscard]]int search(int ele) const;

};

#endif //DYNAMICARRAY_DYNAMIC_ARRAY_H
