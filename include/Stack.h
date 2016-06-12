#pragma once
#ifndef __ALGO_STACK_H
#define __ALGO_STACK_H

namespace algo
{
    template <typename T, typename Container = algo::Array<T>>
    class Stack
    {
    public:
        Stack();
        Stack(const Stack& rhs);
        Stack(Stack&& rhs);
        ~Stack();

        void Push(const T& t);
        void Push(T&& t);

        void Pop();

        const T& Top();
        T& Top();

    private:
        Container<T> _container;
    };
}

#endif // __ALGO_STACK_H