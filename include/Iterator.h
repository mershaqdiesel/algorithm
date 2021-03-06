#pragma once
#ifndef __ALGO_ITERTOR_H
#define __ALGO_ITERTOR_H

namespace algo
{
    template <typename T>
    class Iterator
    {
    public:
        virtual bool operator==(const Iterator<T>& rhs) const = 0;
        virtual bool operator!=(const Iterator<T>& rhs) const { return !(*this == rhs); }
        virtual T& Data() = 0;
        virtual void Next() = 0;
    };
}

#endif // __ALGO_ITERTOR_H