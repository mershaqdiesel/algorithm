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
        Container _container;
    };

    algo::Stack<T, Container>::Stack() : _container{}
    {

    }

    algo::Stack<T, Container>::Stack(const Stack& rhs) : _container{rhs._container}
    {

    }

    algo::Stack<T, Container>::Stack(Stack&& rhs) : _container{std::move(rhs._container)}
    {

    }

    algo::Stack<T, Container>::~Stack()
    {
    }

    void algo::Stack<T, Container>::Push(const T& t)
    {
        _container.PushBack(t);
    }

    void algo::Stack<T, Container>::Push(T&& t)
    {
        _container.PushBack(t);
    }

    void algo::Stack<T, Container>::Pop()
    {
        _container.PopBack();
    }

    const T& algo::Stack<T, Container>::Top()
    {
        return _container.Back();
    }

    T& algo::Stack<T, Container>::Top()
    {
        return _container.Back();
    }
}

#endif // __ALGO_STACK_H