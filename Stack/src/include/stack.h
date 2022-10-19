//
// Created by ajay on 9/30/22.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

#include <cstddef>
#include<exception>
#include <array>
#include <iostream>

namespace ds_impl
{
    template<typename T, std::size_t N>
    class Stack
    {
        int m_top{-1};
        std::size_t m_capacity{N};
        std::array<T,N> m_data;
        [[nodiscard]]bool is_empty()
        {
            return m_top==-1;
        }
        [[nodiscard]]bool is_full()
        {
            return m_top==(m_capacity-1);
        }
    public:
        Stack()=default;
        void push(T ele)
        {
            if(is_full())
            {
                throw std::length_error("Stack is full. Stack overflow occurred.");
            }
            m_data[++m_top]=ele;
        }
        T pop()
        {
            if(is_empty())
            {
                throw std::length_error("Stack is empty. Stack underflow occurred.");
            }
            return m_data[m_top--];
        }
        T peek()
        {
            if(is_empty())
            {
                throw std::length_error("Stack is empty.");
            }
            return m_data[m_top];
        }
        void print()
        {
            std::cout<<"Stack Top: "<<m_top<<" Capacity: "<<m_capacity<<'\n';
            for(int i{m_top};i>=0;--i)
            {
                std::cout<<m_data[i]<<'\n';
            }
        }
        [[nodiscard]]std::size_t get_length()const
        {
            return static_cast<std::size_t>(m_top+1);
        }
    };
}

#endif //STACK_STACK_H
