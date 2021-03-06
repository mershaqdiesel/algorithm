#pragma once
#ifndef __ALGO_STACK_H
#define __ALGO_STACK_H

#include <memory>

#include "Array.h"

namespace algo
{
    template <typename T, typename Container = algo::Array<T>>
    class Stack
    {
    public:
        Stack();
        Stack(const Stack<T, Container>& rhs);
        Stack(Stack<T, Container>&& rhs);
        Stack<T, Container>& operator=(const Stack<T, Container>& rhs);
        Stack<T, Container>& operator=(Stack<T, Container>&& rhs);
        ~Stack();


        void Push(const T& t);
        void Push(T&& t);

        void Pop();

        const T& Top() const;
        T& Top();

        void Clear();
        size_t Size() const;

    private:
        Container _container;
    };

    template <typename T, typename Container>
    algo::Stack<T, Container>::Stack() : _container{}
    {

    }

    template <typename T, typename Container>
    algo::Stack<T, Container>::Stack(const Stack& rhs) : _container{rhs._container}
    {

    }

    template <typename T, typename Container>
    algo::Stack<T, Container>::Stack(Stack&& rhs) : _container{std::move(rhs._container)}
    {

    }

    template <typename T, typename Container>
    Stack<T, Container>& algo::Stack<T, Container>::operator=(const Stack<T, Container>& rhs)
    {
        _container = rhs._container;
        return *this;
    }

    template <typename T, typename Container>
    Stack<T, Container>& algo::Stack<T, Container>::operator=(Stack<T, Container>&& rhs)
    {
        _container = std::move(rhs._container);
        return *this;
    }

    template <typename T, typename Container>
    algo::Stack<T, Container>::~Stack()
    {
    }

    template <typename T, typename Container>
    void algo::Stack<T, Container>::Push(const T& t)
    {
        _container.PushBack(t);
    }

    template <typename T, typename Container>
    void algo::Stack<T, Container>::Push(T&& t)
    {
        _container.PushBack(t);
    }

    template <typename T, typename Container>
    void algo::Stack<T, Container>::Pop()
    {
        _container.PopBack();
    }

    template <typename T, typename Container>
    const T& algo::Stack<T, Container>::Top() const
    {
        return _container.Back();
    }

    template <typename T, typename Container>
    T& algo::Stack<T, Container>::Top()
    {
        return _container.Back();
    }

    template <typename T, typename Container>
    void algo::Stack<T, Container>::Clear()
    {
        _container.Clear();
    }

    template <typename T, typename Container>
    size_t algo::Stack<T, Container>::Size() const
    {
        return _container.Size();
    }
}

#endif // __ALGO_STACK_H