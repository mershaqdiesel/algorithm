#pragma once
#ifndef __ALGO_IITERABLE_H
#define __ALGO_IITERABLE_H

#include <memory>

#include "Iterator.h"

namespace algo
{
    template <typename T>
    class IIterable
    {
    public:
        virtual std::unique_ptr<Iterator<T>> Begin() = 0;
        virtual std::unique_ptr<Iterator<T>> End() = 0;
        virtual std::unique_ptr<const Iterator<T>> Begin() const = 0;
        virtual std::unique_ptr<const Iterator<T>> End() const = 0;
    };
}

#endif // __ALGO_IITERABLE_H