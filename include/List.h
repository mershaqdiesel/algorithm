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
    // TODO: fix to using empty head and tail nodes
    template< typename T >
    class List : public IContainer< T >, public IIterable< T >
    {
    public:
        // Constructors
        List();
        List( const List& list );
        List( List&& list );
        List( std::initializer_list< T > list );
        
        // Assignment
        List< T >& operator=( const List< T >& rhs );
        List<T >& operator=( List< T >&& rhs );
        
        // Destructor
        ~List();

        // Push
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
        
        // Iterator
        class Iterator;
        
        std::unique_ptr< algo::Iterator< T > > Begin() override;
        std::unique_ptr< algo::Iterator< T > > End() override;
        std::unique_ptr< const algo::Iterator< T > > Begin() const override;
        std::unique_ptr< const algo::Iterator< T > > End() const override;

    private:
        struct Node
        {
            T           *elem;
            struct Node *next;
            struct Node *prev;
        };

        struct Node *_head;
        struct Node *_tail;
        size_t _size;
        
        void Destroy();
        void PushFront( Node *n );
        void PushBack( Node *n );
    };
    
    template < typename T >
    algo::List< T >::List() : _head {nullptr }, _tail{ nullptr} , _size{ 0 }
    {
    }
    
    template < typename T >
    algo::List< T >::List( const List< T >& list )
        : _head{ nullptr }, _tail{ nullptr }, _size{ 0 }
    {
        // TODO: [pmd] switch to using iterator
        for ( size_t i = 0; i < list._size; ++i )
        {
            PushBack( list[ i ] );
        }
    }
    
    template < typename T >
    algo::List< T >::List( List&& list ) 
        : _head{ list._head }, _tail{ list._tail }, _size{ list._size }
    {
        list._tail = list._head = nullptr;
        list._size = 0;
    }
    
    template < typename T >
    algo::List< T >::List( std::initializer_list< T > list )
        : _head{ nullptr }, _tail{ nullptr }, _size{ 0 }
    {
        for ( auto x : list )
        {
            PushBack( x );
        }
    }
    
    template < typename T >
    List<T >& algo::List< T >::operator=( const List< T >& rhs )
    {
        Destroy();
        // TODO: [pmd] switch to using iterator
        for ( size_t i = 0; i < rhs._size; ++i )
        {
            PushBack( rhs[ i ] );
        }
        return *this;
    }
    
    template < typename T >
    List< T >& algo::List< T >::operator=( List< T >&& rhs)
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

    template < typename T >
    algo::List< T >::~List()
    {
        Destroy();
    }
    
    template < typename T >
    void algo::List< T >::Destroy()
    {
        Node *temp = _head;
        Node *next;
        while ( temp != nullptr )
        {
            temp->elem->~T();
            delete temp->elem;
            next = temp->next;
            delete temp;
            temp = next;
        }
        _size = 0;
        _head = _tail = nullptr;
    }
    
    template < typename T >
    void algo::List< T >::PushFront( const T& t )
    {
        Node *temp = new Node;
        temp->elem = new T;
        temp->elem = t;
        temp->next = temp->prev = nullptr;
        PushFront( temp );
    }
    
    template < typename T >
    void algo::List< T >::PushFront( T&& t )
    {
        Node *temp = new Node;
        std::swap( temp->elem, t );
        temp->prev = temp->next = nullptr;
        PushFront( temp );
    }
    
    template < typename T >
    void algo::List< T >::PushFront( Node *n )
    {
        if ( _head == nullptr && _tail == nullptr )
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

    template < typename T >
    void algo::List< T >::PushBack( const T& t )
    {
        Node *temp = new Node;
        temp->elem = new T;
        temp->elem = t;
        temp->prev = temp->next = nullptr;
        PushBack( temp );
    }
    
    template < typename T >
    void algo::List< T >::PushBack( T&& t )
    {
        Node *temp = new Node;
        std::swap( temp->elem, t );
        temp->prev = temp->next = nullptr;
        PushBack( temp );
    }
    
    template < typename T >
    void algo::List< T >::PushBack( Node *n )
    {
        if ( _head == nullptr && _tail == nullptr )
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

    template < typename T >
    void algo::List< T >::PopFront()
    {
        if ( _head == nullptr )
        {
            return;
        }
        
        if ( _head == _tail )
        {
            _tail = nullptr;
        }
        
        _head->elem->~T();
        delete _head->elem;
        Node *temp = _head;
        _head = _head->next;
        delete temp;
        _size--;
    }

    template < typename T >
    void algo::List< T >::PopBack()
    {
        if ( _tail == nullptr )
        {
            return;
        }
        
        if ( _head == _tail )
        {
            _head = nullptr;
        }
        
        _tail->elem->~T();
        delete _tail->elem;
        Node *temp = _tail;
        _tail = _tail->prev;
        delete temp;
        _size--;
    }
    
    template < typename T >
    const T& algo::List< T >::Front() const
    {
        return *( _head->elem );
    }
    
    template < typename T >
    const T& algo::List< T >::Back() const
    {
        return *( _tail->elem );
    }
    
    template < typename T >
    T& algo::List< T >::Front()
    {
        return *( _head->elem );    
    }
    
    template < typename T >
    T& algo::List< T >::Back()
    {
        return *( _tail->elem );
    }
    
    template < typename T >
    T& algo::List< T >::operator[]( int index )
    {
        Node *itr = _head;
        for ( size_t count = 0; count < static_cast< size_t >( index ); count++ )
        {
            itr = itr->next;
        }
        return *( itr->elem );
    }
    
    template < typename T >
    const T& algo::List< T >::operator[]( int index ) const
    {
        Node *itr = _head;
        for ( size_t count = 0; count < static_cast< size_t >( index ); count++ )
        {
            itr = itr->next;
        }
        return *( itr->elem );
    }
    
    template < typename T >
    size_t algo::List< T >::Size() const
    {
        return _size;
    }

    template < typename T >
    void algo::List< T >::Clear()
    {
        Destroy();
    }
    
    template < typename T >
    class algo::List< T >::Iterator : public algo::Iterator< T >
    {
    public:
        friend class algo::List< T >;
        bool operator==( const algo::Iterator< T >& rhs ) const override;
        T& Data() override;
        void Next() override;
    private:
        Iterator( Node *curr ) : _current{ curr } {};
        Node *_current;
    };
    
    template < typename T >
    bool algo::List< T >::Iterator::operator==( const algo::Iterator< T >& rhs ) const
    {
        return _current == dynamic_cast< const algo::List< T >::Iterator& >( rhs )._current;
    }
    
    template < typename T >
    T& algo::List< T >::Iterator::Data()
    {
        return *( _current->elem );
    }
    
    template < typename T >
    void algo::List< T >::Iterator::Next()
    {
        if ( _current != nullptr )
        {
            _current = _current->next;
        }
    }
    
    template < typename T >
    std::unique_ptr< algo::Iterator< T > > algo::List< T >::Begin()
    {
        algo::List< T >::Iterator* itr = new algo::List< T >::Iterator{ _head };
        return std::unique_ptr< algo::Iterator< T > >{ itr };
    }
    
    template < typename T >
    std::unique_ptr< algo::Iterator< T > > algo::List< T >::End()
    {
        algo::List< T >::Iterator *itr = new algo::List< T >::Iterator{ _tail->next };
        return std::unique_ptr< algo::Iterator< T > >{ itr };
    }
    
    template < typename T >
    std::unique_ptr< const algo::Iterator< T > > algo::List< T >::Begin() const
    {
        const algo::List< T >::Iterator *itr = new const algo::List< T >::Iterator{ _head };
        return std::unique_ptr< const algo::Iterator< T > >{ itr };
    }
    
    template < typename T >
    std::unique_ptr< const algo::Iterator< T > > algo::List< T >::End() const
    {
        const algo::List< T >::Iterator *itr = new const algo::List< T >::Iterator{ _tail->next };
        return std::unique_ptr< const algo::Iterator< T > >{ itr };
    }
}

#endif // __ALGO_LIST_H