#pragma once
#ifndef __ALGO_ARRAY_H
#define __ALGO_ARRAY_H

#include <memory>
#include <initializer_list>

#include "IContainer.h"
#include "IIterable.h"

using namespace std;

namespace algo
{
    template < typename T >
    class Array : public IContainer< T >, public IIterable< T >
    {
    public:
        Array();
        explicit Array( size_t capacity );
        Array( const Array& rhs );
        Array( Array&& rhs );
        Array( initializer_list< T > lst );

        Array< T >& operator=( const Array< T >& rhs );
        Array< T >& operator=( Array< T >&& rhs );

        ~Array();

        void PushFront( const T& t ) override;
        void PushFront( T&& t ) override;
        void PushBack( const T& t ) override;
        void PushBack( T&& t ) override;
        
        // Pop
        void PopFront() override;
        void PopBack() override;
        
        // Accessors
        const T& Front() const override;
        const T& Back() const override;
        
        T& Front() override;
        T& Back() override;
        
        T& operator[]( int index ) override;
        const T& operator[]( int index ) const override;
        
        size_t Size() const override;

        void Clear() override;

        class Iterator;

        std::unique_ptr< algo::Iterator< T> > Begin() override;
        std::unique_ptr< algo::Iterator< T> > End() override;
        std::unique_ptr< const algo::Iterator< T > > Begin() const override;
        std::unique_ptr< const algo::Iterator< T > > End() const override;

    private:
        size_t _capacity;
        size_t _size;
        T* _vec;

        void Resize( size_t newCapacity );
    };

    template < typename T >
    algo::Array< T >::Array()
        : _capacity{ 10 }, _size{ 0 }, _vec{ nullptr }
    {
        _vec = new T[ _capacity ];
    }

    template < typename T >
    algo::Array< T >::Array( size_t capacity )
        : _capacity{ capacity }, _size{ 0 }, _vec{ nullptr }
    {
        _vec = new T[ _capacity ];
    }

    template < typename T >
    algo::Array< T >::Array( const Array< T >& rhs )
        : _capacity{ rhs._capacity }, _size{ rhs._size }, _vec{ nullptr }
    {
        _vec = new T[ _capacity ];
        for ( size_t i = 0; i < rhs._size; ++i )
        {
            _vec[ i ] = rhs._vec[ i ];
        }
    }

    template < typename T >
    algo::Array< T >::Array( Array< T >&& rhs )
        : _capacity{ rhs._capacity }, _size{ rhs._size }, _vec{ rhs._vec }
    {
        rhs._vec = nullptr;
        rhs._capacity = rhs._size = 0;
    }

    template < typename T >
    algo::Array< T >::Array( initializer_list< T > lst )
        : _capacity{ 10 }, _size{ 0 }, _vec{ nullptr }
    {
        _vec = new T[ _capacity ];
        for ( auto i : lst )
        {
            PushBack( i );
        }
    }

    template < typename T >
    Array< T >& algo::Array< T >::operator=( const Array< T >& rhs )
    {
        _capacity = rhs._capacity;
        _size = rhs._size;
        _vec = new T [ _capacity ];
        for ( size_t i = 0; i < rhs._size; ++i )
        {
            _vec[ i ] = rhs._vec[ i ];
        }
        return *this;
    }

    template <typename T>
    Array< T >& algo::Array< T >::operator=( Array< T >&& rhs )
    {
        _vec = rhs._vec;
        _capacity = rhs._capacity;
        _size = rhs._size;
        rhs._vec = nullptr;
        rhs._capacity = rhs._size = 0;
        return *this;
    }

    template < typename T >
    algo::Array< T >::~Array()
    {
        delete [] _vec;
    }

    template < typename T >
    void algo::Array< T >::Resize( size_t newCapacity )
    {
        T* tmp = new T[ newCapacity ];
        for ( size_t i = 0; i < _size; ++i )
        {
            tmp[ i ] = _vec[ i ];
        }
        delete [] _vec;
        _vec = tmp;
        _capacity = newCapacity;
    }

    template < typename T >
    void algo::Array< T >::PushFront( const T& t )
    {
        if ( _size == _capacity )
        {
            Resize( _capacity * 2 );
        }

        for ( size_t i = _size; i > 0; --i )
        {
            _vec[ i ] = _vec[ i - 1 ];
            (&_vec[ i - 1 ])->~T();
        }
        _vec[ 0 ] = t;
        _size++;
    }

    template < typename T >
    void algo::Array< T >::PushFront( T&& t )
    {
        if ( _size == _capacity )
        {
            Resize( _capacity * 2 );
        }

        for ( size_t i = _size; i > 0; --i )
        {
            _vec[ i ] = _vec[ i - 1 ];
            (&_vec[ i - 1 ])->~T();
        }
        _vec[ 0 ] = t;
        _size++;
    }

    template < typename T >
    void algo::Array< T >::PushBack( const T& t )
    {
        if ( _size == _capacity )
        {
            Resize( _capacity * 2 );
        }
        _vec[ _size ] = t;
        _size++;
    }

    template < typename T >
    void algo::Array< T >::PushBack( T&& t )
    {
        if ( _size == _capacity )
        {
            Resize( _capacity * 2 );
        }
        _vec[ _size ] = t;
        _size++;
    }
    
    // Pop
    template < typename T >
    void algo::Array< T >::PopFront()
    {
        for ( size_t i = 0; i < _size - 1; ++i )
        {
            (&_vec[ i ])->~T();
            _vec[ i ] = _vec[ i + 1 ];
        }
        (&_vec[ _size - 1 ])->~T();
        _size--;
    }

    template < typename T >
    void algo::Array< T >::PopBack()
    {
        if ( _size > 0 )
        {
            (&_vec[ _size - 1 ])->~T();
            _size--;
        }
    }
    
    // Accessors
    template < typename T >
    const T& algo::Array< T >::Front() const
    {
        return _vec[ 0 ];
    }

    template < typename T >
    const T& algo::Array< T >::Back() const
    {
        return _vec[ _size - 1 ];
    }
    
    template < typename T >
    T& algo::Array< T >::Front()
    {
        return _vec[ 0 ];
    }

    template < typename T >
    T& algo::Array< T >::Back()
    {
        return _vec[ _size - 1 ];
    }
    
    template < typename T >
    T& algo::Array< T >::operator[]( int index )
    {
        return _vec[ index ];
    }

    template < typename T >
    const T& algo::Array< T >::operator[]( int index ) const
    {
        return _vec[ index ];
    }
    
    template < typename T >
    size_t algo::Array< T >::Size() const
    {
        return _size;
    }

    template < typename T >
    void algo::Array< T >::Clear()
    {
        delete [] _vec;
        _vec = new T[ _capacity ];
        _size = 0;
    }

    template < typename T >
    class algo::Array< T >::Iterator : public algo::Iterator< T >
    {
        public:
            friend class algo::Array< T >;
            bool operator==( const algo::Iterator< T >& rhs ) const override;
            T& Data() override { return _array[ _index ]; };
            void Next() override { _index++; };
        private:
            Iterator( T* array, size_t index );
            T* _array;
            size_t _index;
    };

    template < typename T >
    algo::Array< T >::Iterator::Iterator( T* array, size_t index )
        : _array{ array }, _index{ index }
    {
    }

    template < typename T >
    bool algo::Array< T >::Iterator::operator==( const algo::Iterator< T >& rhs ) const
    {
        bool samePtr = _array == dynamic_cast< const algo::Array< T >::Iterator& >( rhs )._array;
        bool sameIndex = _index == dynamic_cast< const algo::Array< T >::Iterator& >( rhs )._index;
        return ( samePtr && sameIndex );
    }

    template < typename T >
    std::unique_ptr< Iterator< T > > algo::Array< T >::Begin()
    {
        algo::Array< T >::Iterator * itr = new algo::Array< T >::Iterator{ _vec, 0 };
        return std::unique_ptr< algo::Iterator< T > >{ itr };
    }

    template < typename T >
    std::unique_ptr< Iterator< T > > algo::Array< T >::End()
    {
        algo::Array< T >::Iterator * itr = new algo::Array< T >::Iterator{ _vec, _size };
        return std::unique_ptr< algo::Iterator< T > >{ itr };
    }

    template < typename T >
    std::unique_ptr< const Iterator< T > > algo::Array< T >::Begin() const
    {
        const algo::Array< T >::Iterator * itr = new const algo::Array< T >::Iterator{ _vec, 0 };
        return std::unique_ptr< const algo::Iterator< T > >{ itr };
    }

    template < typename T >
    std::unique_ptr< const Iterator< T > > algo::Array< T >::End() const
    {
        const algo::Array< T >::Iterator * itr = new const algo::Array< T >::Iterator{ _vec, _size };
        return std::unique_ptr< const algo::Iterator< T > >{ itr };
    }
}

#endif // __ALGO_ARRAY_H