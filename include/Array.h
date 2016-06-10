#pragma once
#ifndef __ALGO_ARRAY_H
#define __ALGO_ARRAY_H

#include <memory>

#include "IContainer.h"
#include "IIterable.h"

using namespace std;

namespace algo
{
    template <typename T, typename Allocator = std::allocator<T>>
    class Array : public IContainer<T>, public IIterable<T>
    {
    public:
        Array();
        explicit Array(size_t capacity);
        Array(const Array& rhs);
        Array(Array&& rhs);

        Array<T, Allocator>& operator=(const Array<T, Allocator>& rhs);
        Array<T, Allocator>& operator=(Array<T, Allocator>&& rhs);

        ~Array();

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

        class Iterator;

        std::unique_ptr<algo::Iterator<T>> Begin() override;
        std::unique_ptr<algo::Iterator<T>> End() override;
        std::unique_ptr<const algo::Iterator<T>> Begin() const override;
        std::unique_ptr<const algo::Iterator<T>> End() const override;

    private:
        size_t _capacity;
        size_t _size;
        T* _vec;
        Allocator _alloc;

        void Resize(size_t);
        void Destroy(T* vec, size_t size, size_t cap);
    };

    template <typename T, typename Allocator>
    algo::Array<T, Allocator>::Array()
        : _capacity{10}, _size{0}, _vec{nullptr}, _alloc{}
    {
        _vec = _alloc.allocate(_capacity * sizeof(T));
    }

    template <typename T, typename Allocator>
    algo::Array<T, Allocator>::Array(size_t capacity)
        : _capacity{capacity}, _size{0}, _vec{nullptr}, _alloc{}
    {
        _vec = _alloc.allocate(_capacity * sizeof(T));
    }

    template <typename T, typename Allocator>
    algo::Array<T, Allocator>::Array(const Array& rhs)
        : _capacity{rhs._capacity}, _size{rhs._size}, _vec{nullptr}, _alloc{rhs._alloc}
    {
        _vec = _alloc.allocate(_capacity * sizeof(T));
        for (size_t i = 0; i < rhs._size; ++i)
        {
            _alloc.construct(_vec + (i * sizeof(T)), rhs._vec[i]);
        }
    }

    template <typename T, typename Allocator>
    algo::Array<T, Allocator>::Array(Array&& rhs)
        : _capacity{rhs._capacity}, _size{rhs._size}, _vec{rhs._vec}, _alloc{rhs._alloc}
    {
        rhs._vec = nullptr;
        rhs._capacity = rhs._size = 0;
    }

    template <typename T, typename Allocator>
    Array<T, Allocator>& algo::Array<T, Allocator>::operator=(const Array<T, Allocator>& rhs)
    {
        _capacity = rhs._capacity;
        _size = rhs._size;
        _vec = _alloc.allocate(_capacity * sizeof(T));
        for (size_t i = 0; i < rhs._size; ++i)
        {
            _alloc.construct(_vec + (i * sizeof(T)), rhs._vec[i]);
        }
        return *this;
    }

    template <typename T, typename Allocator>
    Array<T, Allocator>& algo::Array<T, Allocator>::operator=(Array<T, Allocator>&& rhs)
    {
        _vec = rhs._vec;
        _capacity = rhs._capacity;
        _size = rhs._size;
        rhs._vec = nullptr;
        rhs._capacity = rhs._size = 0;
        return *this;
    }

    template <typename T, typename Allocator>
    algo::Array<T, Allocator>::~Array()
    {
        Destroy(_vec, _size, _capacity);
    }

    template <typename T, typename Allocator>
    void algo::Array<T, Allocator>::Resize(size_t newCapacity)
    {
        T* tmp = _alloc.allocate(newCapacity * sizeof(T));
        for (size_t i = 0; i < _size; ++i)
        {
            _alloc.construct(tmp + (i * sizeof(T)), _vec[i]);
        }
        Destroy(_vec, _size, _capacity);
        _vec = tmp;
        _capacity = newCapacity;
    }

    template <typename T, typename Allocator>
    void algo::Array<T, Allocator>::Destroy(T* vec, size_t size, size_t cap)
    {
        for (size_t i = 0; i < size; ++i)
        {
            _alloc.destroy(vec);
        }
        _alloc.deallocate(vec, cap);
    }

    template <typename T, typename Allocator>
    void algo::Array<T, Allocator>::PushFront(const T& t)
    {
        if (_size == _capacity - 1)
        {
            Resize(_capacity * 2);
        }

        for (size_t i = _size; i > 0; --i)
        {
            _alloc.construct(_vec + (i * sizeof(T)), _vec[i - 1]);
            _alloc.destroy(_vec + (i - 1 * sizeof(T)));
        }
        _alloc.construct(_vec, t);
        _size++;
    }

    template <typename T, typename Allocator>
    void algo::Array<T, Allocator>::PushFront(T&& t)
    {
        if (_size == _capacity - 1)
        {
            Resize(_capacity * 2);
        }

        for (size_t i = _size; i > 0; --i)
        {
            _alloc.construct(_vec + (i * sizeof(T)), _vec[i - 1]);
            _alloc.destroy(_vec + (i - 1 * sizeof(T)));
        }
        _alloc.construct(_vec, t);
        _size++;
    }

    template <typename T, typename Allocator>
    void algo::Array<T, Allocator>::PushBack(const T& t)
    {
        if (_size == _capacity - 1)
        {
            Resize(_capacity * 2);
        }
        _alloc.construct(_vec + (_size * sizeof(T)), t);
        _size++;
    }

    template <typename T, typename Allocator>
    void algo::Array<T, Allocator>::PushBack(T&& t)
    {
        if (_size == _capacity - 1)
        {
            Resize(_capacity * 2);
        }
        _alloc.construct(_vec + (_size * sizeof(T)), t);
        _size++;
    }
    
    // Pop
    template <typename T, typename Allocator>
    void algo::Array<T, Allocator>::PopFront()
    {
        for (size_t i = 0; i < _size; ++i)
        {
            _alloc.destroy(_vec + (i * sizeof(T)));
            _alloc.construct(_vec + (i * sizeof(T)), _vec[i + 1]);
        }
        _size--;
    }

    template <typename T, typename Allocator>
    void algo::Array<T, Allocator>::PopBack()
    {
        if (_size > 0)
        {
            _alloc.destroy(_vec + ((_size - 1) * sizeof(T)));
            _size--;
        }
    }
    
    // Accessors
    template <typename T, typename Allocator>
    const T& algo::Array<T, Allocator>::Front() const
    {
        return _vec[0];
    }

    template <typename T, typename Allocator>
    const T& algo::Array<T, Allocator>::Back() const
    {
        return _vec[_size - 1];
    }
    
    template <typename T, typename Allocator>
    T& algo::Array<T, Allocator>::Front()
    {
        return _vec[0];
    }

    template <typename T, typename Allocator>
    T& algo::Array<T, Allocator>::Back()
    {
        return _vec[_size - 1];
    }
    
    template <typename T, typename Allocator>
    T& algo::Array<T, Allocator>::operator[](int index)
    {
        if (index < 0 || static_cast<size_t>(index) >= _size)
        {
            // throw out_of_range 
        }
        return _vec[index];
    }

    template <typename T, typename Allocator>
    const T& algo::Array<T, Allocator>::operator[](int index) const
    {
        if (index < 0 || static_cast<size_t>(index) >= _size)
        {
            // throw out_of_range 
        }
        return _vec[index];
    }
    
    template <typename T, typename Allocator>
    size_t algo::Array<T, Allocator>::Size() const
    {
        return _size;
    }

    template <typename T, typename Allocator>
    class algo::Array<T, Allocator>::Iterator : public algo::Iterator<T>
    {
        public:
            friend class algo::Array<T, Allocator>;
            bool operator==(const algo::Iterator<T>& rhs) const override;
            T& Data() override { return _array[_index]; };
            void Next() override { _index++; };
        private:
            Iterator(T* array, size_t index);
            T* _array;
            size_t _index;
    };

    template <typename T, typename Allocator>
    algo::Array<T, Allocator>::Iterator::Iterator(T* array, size_t index)
        : _array{array}, _index{index}
    {
    }

    template <typename T, typename Allocator>
    bool algo::Array<T, Allocator>::Iterator::operator==(const algo::Iterator<T>& rhs) const
    {
        bool samePtr = _array == dynamic_cast<const algo::Array<T, Allocator>::Iterator&>(rhs)._array;
        bool sameIndex = _index == dynamic_cast<const algo::Array<T, Allocator>::Iterator&>(rhs)._index;
        return (samePtr && sameIndex);
    }

    template <typename T, typename Allocator>
    std::unique_ptr<Iterator<T>> algo::Array<T, Allocator>::Begin()
    {
        algo::Array<T, Allocator>::Iterator * itr = new algo::Array<T, Allocator>::Iterator{_vec, 0};
        return std::unique_ptr<algo::Iterator<T>>{itr};
    }

    template <typename T, typename Allocator>
    std::unique_ptr<Iterator<T>> algo::Array<T, Allocator>::End()
    {
        algo::Array<T, Allocator>::Iterator * itr = new algo::Array<T, Allocator>::Iterator{_vec, _size + 1};
        return std::unique_ptr<algo::Iterator<T>>{itr};
    }

    template <typename T, typename Allocator>
    std::unique_ptr<const Iterator<T>> algo::Array<T, Allocator>::Begin() const
    {
        const algo::Array<T, Allocator>::Iterator * itr = new const algo::Array<T, Allocator>::Iterator{_vec, 0};
        return std::unique_ptr<const algo::Iterator<T>>{itr};
    }

    template <typename T, typename Allocator>
    std::unique_ptr<const Iterator<T>> algo::Array<T, Allocator>::End() const
    {
        const algo::Array<T, Allocator>::Iterator * itr = new const algo::Array<T, Allocator>::Iterator{_vec, _size + 1};
        return std::unique_ptr<const algo::Iterator<T>>{itr};
    }
}

#endif // __ALGO_ARRAY_H