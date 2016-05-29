#pragma once
#ifndef __ALGO_IITERABLE_H
#define __ALGO_IITERABLE_H

#include "Iterator.h"

namespace algo
{
    template <typename T>
    class IIterable
    {
    public:
        virtual Iterator<T> Begin() = 0;
        virtual Iterator<T> End() = 0;
    };
}

#endif // __ALGO_IITERABLE_H