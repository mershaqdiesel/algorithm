#pragma once
#ifndef __ALGO_ICONTAINTER_H
#define __ALGO_ICONTAINTER_H

#include <cstddef>

namespace algo
{
    template <typename T>
    class IContainer
    {
    public:
        // Push
        virtual void PushFront(const T& t) = 0;
        virtual void PushFront(T&& t) = 0;
        virtual void PushBack(const T& t) = 0;
        virtual void PushBack(T&& t) = 0;
        
        // Pop
        virtual void PopFront() = 0;
        virtual void PopBack() = 0;
        
        // Accessors
        virtual const T& Front() const = 0;
        virtual const T& Back() const = 0;
        
        virtual T& Front() = 0;
        virtual T& Back() = 0;
        
        virtual T& operator[](int) = 0;
        virtual const T& operator[](int) const = 0;
        
        virtual size_t Size() const = 0;

        virtual void Clear() = 0;
    };
}

#endif // __ALGO_ICONTAINTER_H