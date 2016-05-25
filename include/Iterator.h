#pragma once
#ifndef __ALGO_ITERTOR_H
#define __ALGO_ITERTOR_H

namespace algo
{
    template <typename T>
    class Iterator
    {
    public:
        virtual bool operator==(const Iterator<T>& rhs) = 0;
        virtual T& operator*() = 0;
    }
}

#endif // __ALGO_ITERTOR_H