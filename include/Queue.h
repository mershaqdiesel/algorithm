#pragma once
#ifndef __ALGO_QUEUE_H
#define __ALGO_QUEUE_H

#include <memory>

#include "List.h"

namespace algo
{
    template <typename T, typename Container = algo::List<T>>
    class Queue
    {
    public:
        Queue();
        Queue(const Queue<T, Container>& rhs);
        Queue(Queue<T, Container>&& rhs);
        Queue<T, Container>& operator=(const Queue<T, Container>& rhs);
        Queue<T, Container>& operator=(Queue<T, Container>&& rhs);
        ~Queue();

        void PushBack(const T& t);
        void PushBack(T& t);
        void PushFront(const T& t);
        void PushFront(T& t);

        void PopBack();
        void PopFront();

        const T& Front() const;
        T& Front();
        const T& Back() const;
        T& Back();

        size_t Size() const;
        void Clear();

    private:
        Container _container;
    };

    template <typename T, typename Container>
    algo::Queue<T, Container>::Queue() : _container{}
    {
    }

    template <typename T, typename Container>
    algo::Queue<T, Container>::Queue(const Queue<T, Container>& rhs)
        : _container{rhs._container}
    {
    }

    template <typename T, typename Container>
    algo::Queue<T, Container>::Queue(Queue<T, Container>&& rhs)
        : _container{std::move(rhs._container)}
    {
    }

    template <typename T, typename Container>
    Queue<T, Container>& algo::Queue<T, Container>::operator=(const Queue<T, Container>& rhs)
    {
        _container = rhs._container;
        return *this;
    }

    template <typename T, typename Container>
    Queue<T, Container>& algo::Queue<T, Container>::operator=(Queue<T, Container>&& rhs)
    {
        _container = std::move(rhs._container);
        return *this;
    }

    template <typename T, typename Container>
    algo::Queue<T, Container>::~Queue()
    {
    }

    template <typename T, typename Container>
    void algo::Queue<T, Container>::PushBack(const T& t)
    {
        _container.PushBack(t);
    }

    template <typename T, typename Container>
    void algo::Queue<T, Container>::PushBack(T& t)
    {
        _container.PushBack(t);
    }

    template <typename T, typename Container>
    void algo::Queue<T, Container>::PushFront(const T& t)
    {
        _container.PushFront(t);
    }

    template <typename T, typename Container>
    void algo::Queue<T, Container>::PushFront(T& t)
    {
        _container.PushFront(t);
    }

    template <typename T, typename Container>
    void algo::Queue<T, Container>::PopBack()
    {
        _container.PopBack();
    }

    template <typename T, typename Container>
    void algo::Queue<T, Container>::PopFront()
    {
        _container.PopFront();
    }

    template <typename T, typename Container>
    const T& algo::Queue<T, Container>::Front() const
    {
        return _container.Front();
    }

    template <typename T, typename Container>
    T& algo::Queue<T, Container>::Front()
    {
        return _container.Front();
    }

    template <typename T, typename Container>
    const T& algo::Queue<T, Container>::Back() const
    {
        return _container.Back();
    }

    template <typename T, typename Container>
    T& algo::Queue<T, Container>::Back()
    {
        return _container.Back();
    }

    template <typename T, typename Container>
    size_t algo::Queue<T, Container>::Size() const
    {
        return _container.Size();
    }

    template <typename T, typename Container>
    void algo::Queue<T, Container>::Clear()
    {
        _container.Clear();
    }
}

#endif // __ALGO_QUEUE_H
