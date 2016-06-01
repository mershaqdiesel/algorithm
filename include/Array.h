#pragma once
#ifndef __ALGO_ARRAY_H
#define __ALGO_ARRAY_H

#include <memory>

#include "IIterable.h"

using namespace std;

namespace algo
{
    template <typename T, typename Allocator = std::allocator>
    class Array : public IIterable
    {
    public:
        Array();
        explicit Array(sizt_t capacity);
        ~Array();

        void PushFront(const T& t);
        void PopFront();
        const T& Front() const;
        T& Front();
        
        void PushBack(const T& t);
        void PopBack();
        const T& Back() const;
        T& Back(); 

    private:
        size_t _capacity;
        size_t _size;
        T* _vec;
    };
}

#endif // __ALGO_ARRAY_H
