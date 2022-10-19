//
// Created by ajay on 9/29/22.
//

#ifndef DYNAMICARRAY_DYNAMIC_ARRAY_H
#define DYNAMICARRAY_DYNAMIC_ARRAY_H

#include <cstddef>
#include <array>
#include <memory>

namespace ds_impl
{
    class DynamicArray
    {
        std::size_t m_length{};
        std::size_t m_capacity{};
        static constexpr int EXTRA_SPACE_FOR_ARRAY{2};
        std::unique_ptr<int[]> m_array_ptr{};

        [[nodiscard]] bool is_full() const noexcept;

        void copy_to(std::unique_ptr<int[]>& new_array_ptr);

        void expand_array_if_needed();

        void check_index_bounds(std::size_t index)const;

        void shrink_array_if_needed();

    public:
        DynamicArray();

        DynamicArray(std::initializer_list<int> list);

        DynamicArray(const DynamicArray& array);

        DynamicArray& operator=(const DynamicArray& array);

        explicit DynamicArray(std::size_t capacity);

        [[nodiscard]] std::size_t get_length()const;

        void insert(int ele);

        void insert(int ele, std::size_t index);

        void print() const;

        [[nodiscard]]int& operator[](std::size_t index);

        [[nodiscard]]int search(int ele) const;

        void remove();

        void remove(std::size_t index);
    };
}

#endif //DYNAMICARRAY_DYNAMIC_ARRAY_H
