#pragma once
#ifndef __ALGO_ICONTAINTER_H
#define __ALGO_ICONTAINTER_H

namespace algo
{
    template <typename T>
    class IContainer
    {
    public:
        virtual void PushFront(const T& t) = 0;
		virtual void PopFront() = 0;
		virtual const T& Front() const = 0;
		virtual T& Front();
		
		virtual void PushBack(const T& t) = 0;
		virtual void PopBack() = 0;
		virtual const T& Back() const = 0;
		virtual T& Back() = 0;
    };
}

#endif // __ALGO_ICONTAINTER_H