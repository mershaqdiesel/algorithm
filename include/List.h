#pragma once
#ifndef __ALGO_LIST_H
#define __ALGO_LIST_H

#include <memory>
#include <initializer_list>

#include <iostream>

#include "IContainer.h"
#include "IIterable.h"

namespace algo
{
    template<typename T, typename Allocator = std::allocator<T>>
    class List : public IContainer<T>, public IIterable<T>
    {
    public:
        // Constructors
        List();
        List(const List& list);
        List(List&& list);
        List(std::initializer_list<T> list);
        
        // Assignment
        List<T, Allocator>& operator=(const List<T, Allocator>& rhs);
        List<T, Allocator>& operator=(List<T, Allocator>&& rhs);
        
        // Destructor
        ~List();

        // Push
        void PushFront(const T& t) override;
        void PushFront(T&& t) override;
        void PushBack(const T& t) override;
        void PushBack(T&& t) override;
        
        // Pop
        void PopFront() override;
        void PopBack() override;
        
        // Accessors
        const T& Front() const override;
        const T& Back() const override;
        
        T& Front() override;
        T& Back() override;
        
        T& operator[](int) override;
        const T& operator[](int) const override;
        
        size_t Size() const override;
        
        // Iterator
        class Iterator;
        
        algo::Iterator<T> Begin();
        algo::Iterator<T> End();
        const algo::Iterator<T> Begin() const;
        const algo::Iterator<T> End() const;

    private:
        struct Node
        {
            T       *elem;
            Node    *next;
            Node    *prev;
        };

        Node *_head;
        Node *_tail;
        Allocator _alloc;
        size_t _size;
        
        void Destroy();
        void PushFront(Node *n);
        void PushBack(Node *n);
    };
    
    template <typename T, typename Allocator>
    algo::List<T, Allocator>::List() : _head{nullptr}, _tail{nullptr}, _alloc{}, _size{0}
    {
    }
    
    template <typename T, typename Allocator>
    algo::List<T, Allocator>::List(const List& list)
        : _head{nullptr}, _tail{nullptr}, _alloc{}, _size{0}
    {
        // TODO: [pmd] switch to using iterator
        for (size_t i = 0; i < list._size; ++i)
        {
            PushBack(list[i]);
        }
    }
    
    template <typename T, typename Allocator>
    algo::List<T, Allocator>::List(List&& list) 
        : _head{list._head}, _tail{list._tail}, _alloc{std::move(list._alloc)}, _size{list._size}
    {
        list._tail = list._head = nullptr;
        list._size = 0;
    }
    
    template <typename T, typename Allocator>
    algo::List<T, Allocator>::List(std::initializer_list<T> list)
        : _head{nullptr}, _tail{nullptr}, _alloc{}, _size{0}
    {
        for (auto x : list)
        {
            PushBack(x);
        }
    }
    
    template <typename T, typename Allocator>
    List<T, Allocator>& algo::List<T, Allocator>::operator=(const List<T, Allocator>& rhs)
    {
        Destroy();
        // TODO: [pmd] switch to using iterator
        for (size_t i = 0; i < rhs._size; ++i)
        {
            PushBack(rhs[i]);
        }
        return *this;
    }
    
    template <typename T, typename Allocator>
    List<T, Allocator>& algo::List<T, Allocator>::operator=(List<T, Allocator>&& rhs)
    {
        Node *temp = _head;
        _head = rhs._head;
        rhs._head = temp;
        
        temp = _tail;
        _tail = rhs._tail;
        rhs._tail = temp;
        
        size_t s = _size;
        _size = rhs._size;
        rhs._size = s;
        
        return *this;
    }

    template <typename T, typename Allocator>
    algo::List<T, Allocator>::~List()
    {
        Destroy();
    }
    
    template <typename T, typename Allocator>
    void algo::List<T, Allocator>::Destroy()
    {
        Node *temp = _head;
        Node *next;
        while (temp != nullptr)
        {
            _alloc.destroy(temp->elem);
            _alloc.deallocate(temp->elem, 1);
            next = temp->next;
            delete temp;
            temp = next;
        }
        _size = 0;
        _head = _tail = nullptr;
    }
    
    template <typename T, typename Allocator>
    void algo::List<T, Allocator>::PushFront(const T& t)
    {
        Node *temp = new Node;
        temp->elem = _alloc.allocate(1);
        _alloc.construct(temp->elem, t);
        temp->next = temp->prev = nullptr;
        PushFront(temp);
    }
    
    template <typename T, typename Allocator>
    void algo::List<T, Allocator>::PushFront(T&& t)
    {
        Node *temp = new Node;
        temp->elem = _alloc.allocate(1);
        _alloc.construct(temp->elem, t);
        temp->prev = temp->next = nullptr;
        PushFront(temp);
    }
    
    template <typename T, typename Allocator>
    void algo::List<T, Allocator>::PushFront(Node *n)
    {
        if (_head == nullptr && _tail == nullptr)
        {
            _head = _tail = n;
        }
        else
        {
            n->next = _head;
            _head->prev = n;
            _head = n;
        }
        _size++;
    }

    template <typename T, typename Allocator>
    void algo::List<T, Allocator>::PushBack(const T& t)
    {
        Node *temp = new Node;
        temp->elem = _alloc.allocate(1);
        _alloc.construct(temp->elem, t);
        temp->prev = temp->next = nullptr;
        PushBack(temp);
    }
    
    template <typename T, typename Allocator>
    void algo::List<T, Allocator>::PushBack(T&& t)
    {
        Node *temp = new Node;
        temp->elem = _alloc.allocate(1);
        _alloc.construct(temp->elem, t);
        temp->prev = temp->next = nullptr;
        PushBack(temp);
    }
    
    template <typename T, typename Allocator>
    void algo::List<T, Allocator>::PushBack(Node *n)
    {
        if (_head == nullptr && _tail == nullptr)
        {
            _head = _tail = n;
        }
        else
        {
            n->prev = _tail;
            _tail->next = n;
            _tail = n;
        }
        _size++;
    }

    template <typename T, typename Allocator>
    void algo::List<T, Allocator>::PopFront()
    {
        if (_head == nullptr)
        {
            return;
        }
        
        if (_head == _tail)
        {
            _tail = nullptr;
        }
        
        _alloc.destroy(_head->elem);
        _alloc.deallocate(_head->elem, 1);
        Node *temp = _head;
        _head = _head->next;
        delete temp;
        _size--;
    }

    template <typename T, typename Allocator>
    void algo::List<T, Allocator>::PopBack()
    {
        if (_tail == nullptr)
        {
            return;
        }
        
        if (_head == _tail)
        {
            _head = nullptr;
        }
        
        _alloc.destroy(_tail->elem);
        _alloc.deallocate(_tail->elem, 1);
        Node *temp = _tail;
        _tail = _tail->prev;
        delete temp;
        _size--;
    }
    
    template <typename T, typename Allocator>
    const T& algo::List<T, Allocator>::Front() const
    {
        return *(_head->elem);
    }
    
    template <typename T, typename Allocator>
    const T& algo::List<T, Allocator>::Back() const
    {
        return *(_tail->elem);
    }
    
    template <typename T, typename Allocator>
    T& algo::List<T, Allocator>::Front()
    {
        return *(_head->elem);    
    }
    
    template <typename T, typename Allocator>
    T& algo::List<T, Allocator>::Back()
    {
        return *(_tail->elem);
    }
    
    template <typename T, typename Allocator>
    T& algo::List<T, Allocator>::operator[](int index)
    {
        if (index < 0)
        {
            // throw negative_index_execption;    
        }
        
        Node *itr = _head;
        for (size_t count = 0; count < static_cast<size_t>(index); count++)
        {
            itr = itr->next;
        }
        return *(itr->elem);
    }
    
    template <typename T, typename Allocator>
    const T& algo::List<T, Allocator>::operator[](int index) const
    {
        if (index < 0)
        {
            // throw negative_index_execption;    
        }
        
        Node *itr = _head;
        for (size_t count = 0; count < static_cast<size_t>(index); count++)
        {
            itr = itr->next;
        }
        return *(itr->elem);
    }
    
    template <typename T, typename Allocator>
    size_t algo::List<T, Allocator>::Size() const
    {
        return _size;
    }
    
    template <typename T, typename Allocator>
    class algo::List<T, Allocator>::Iterator : public algo::Iterator<T>
    {
    public:
        bool operator==(const algo::Iterator<T>& rhs) const override;
        T& operator*() override;
        void Next() override;
    private:
        Iterator(Node *curr) : _current{curr} {};
        Node *_current;
    };
    
    template <typename T, typename Allocator>
    bool algo::List<T, Allocator>::Iterator::operator==(const algo::Iterator<T>& rhs) const
    {
        return _current == rhs._current;
    }
    
    template <typename T, typename Allocator>
    T& algo::List<T, Allocator>::Iterator::operator*()
    {
        return *(_current->elem);
    }
    
    template <typename T, typename Allocator>
    void algo::List<T, Allocator>::Iterator::Next()
    {
        if (_current != nullptr && _current->next != nullptr)
        {
            _current = _current->next;
        }
    }
    
    template <typename T, typename Allocator>
    algo::Iterator<T> algo::List<T, Allocator>::Begin()
    {
        algo::List<T, Allocator>::Iterator itr{_head};
        return reinterpret_cast<algo::Iterator<T>>(itr);
    }
    
    template <typename T, typename Allocator>
    algo::Iterator<T> algo::List<T, Allocator>::End()
    {
        algo::List<T, Allocator>::Iterator itr{_tail};
        return reinterpret_cast<algo::Iterator<T>>(itr);
    }
    
    template <typename T, typename Allocator>
    const algo::Iterator<T> algo::List<T, Allocator>::Begin() const
    {
        const algo::List<T, Allocator>::Iterator itr{_head};
        return reinterpret_cast<algo::Iterator<T>>(itr);
    }
    
    template <typename T, typename Allocator>
    const algo::Iterator<T> algo::List<T, Allocator>::End() const
    {
        const algo::List<T, Allocator>::Iterator itr{_tail};
        return reinterpret_cast<algo::Iterator<T>>(itr);
    }
}

#endif // __ALGO_LIST_H