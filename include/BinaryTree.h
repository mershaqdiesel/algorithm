#pragma once
#ifndef __ALGO_BINARYTREE_H
#define __ALGO_BINARYTREE_H

#include <functional>
#include <memory>

#include "IDictonary.h"

namespace algo
{
    template < typename K, typename V, typename Compare = std::less< K > >
    class BinaryTree : public IDictonary< K, V >
    {
    public:
        BinaryTree();
        BinaryTree( const BinaryTree< K, V, Compare >& rhs );
        BinaryTree( BinaryTree< K, V, Compare >&& rhs );

        BinaryTree< K, V, Compare > operator=( const BinaryTree<K, V, Compare >& rhs );
        BinaryTree< K, V, Compare > operator=( BinaryTree< K, V, Compare >&& rhs );

        ~BinaryTree();

        bool Put( const K& key, const V& value ) override;

        const V& operator[]( const K& ) const override;
        const List< K > Keys() const override;
        const List< V > Values() const override;

        V& operator[]( const K& ) override;
        List< K > Keys() override;
        List< V > Values() override;

    private:
        struct Node
        {
            K           *key;
            V           *value;
            struct Node *left;
            struct Node *right;
        };
        
        struct Node *_root;
        Compare      _compare;

        void CopyNode( const struct Node const *src, struct Node **dst );
        void DestroyTree( struct Node* n );
        void DestroyNode( struct Node* n );
        struct Node * CreateNode( const K& key, const V& value );

    };

    template < typename K, typename V, typename Compare >
    algo::BinaryTree< K, V, Compare >::BinaryTree()
        : _root{ nullptr }, _compare{}
    {
    }
    
    template < typename K, typename V, typename Compare >
    algo::BinaryTree< K, V, Compare >::BinaryTree( const BinaryTree< K, V, Compare >& rhs )
        : _root{ nullptr }, _compare{ rhs._compare }
    {
        CopyNode( rhs._root, _root );
    }
    
    template < typename K, typename V, typename Compare >
    algo::BinaryTree< K, V, Compare >::BinaryTree( BinaryTree< K, V, Compare >&& rhs )
        : _root{ rhs._root }, _compare{ std::move( rhs._compare ) }
    {
        rhs._root = nullptr;
    }

    template < typename K, typename V, typename Compare >
    BinaryTree< K, V, Compare > algo::BinaryTree< K, V, Compare >::operator=( const BinaryTree< K, V, Compare >& rhs )
    {
        BinaryTree< K, V, Compare > copy = rhs;
        std::swap( *this, copy );
        return *this;
    }

    template < typename K, typename V, typename Compare >
    BinaryTree< K, V, Compare > algo::BinaryTree< K, V, Compare >::operator=( BinaryTree< K, V, Compare >&& rhs )
    {
        std::swap( _root, rhs._root );
        std::swap( _keyAlloc, rhs._keyAlloc );
        std::swap( _valueAlloc, rhs._valueAlloc );
        std::swap( _compare, rhs._compare );
        return *this;
    }

    template < typename K, typename V, typename Compare >
    algo::BinaryTree< K, V, Compare >::~BinaryTree()
    {
        DestroyTree( _root );   
    }

    template < typename K, typename V, typename Compare >
    bool algo::BinaryTree< K, V, Compare >::Put( const K& key, const V& value )
    {
        if ( _root == nullptr )
        {
            _root = CreateNode( key, value );        
            return true;
        }

        bool inserted = false;
        bool exists = false;
        struct Node * n = _root;

        while ( !inserted || !exists )
        {
            // n->key < key
            if ( _compare( *n->key, key ) )
            {
                if ( n->right == nullptr )
                {
                    n->right = CreateNode( key, value );
                    inserted = true;
                }
                else
                {
                    n = n->right;
                }
            }
            // key < n->key
            else if ( _compare( key, *n->key ) )
            {
                if ( n->left == nullptr )
                {
                    n->left = CreateNode( key, value );
                    inserted = true;
                }
                else
                {
                    n = n->left;
                }
            }
            // key == n->key
            else
            {
                exists = true;
            }
        }
        return inserted;
    }

    template < typename K, typename V, typename Compare >
    const V& algo::BinaryTree< K, V, Compare >::operator[]( const K& k ) const
    {
        return (*this)[ k ]; 
    }

    template < typename K, typename V, typename Compare >
    const List< K > algo::BinaryTree< K, V, Compare >::Keys() const
    {
        return this->Keys();
    }

    template < typename K, typename V, typename Compare >
    const List< V > algo::BinaryTree< K, V, Compare >::Values() const
    {
        return this->Values();
    }

    template < typename K, typename V, typename Compare >
    V& algo::BinaryTree< K, V, Compare >::operator[]( const K& )
    {
        struct Node * n = _root;
        bool found = n != nullptr;

        while ( !found )
        {
            // n->key < k
            if ( _compare( *n->key, k ) )
            {
                if ( n->right != nullptr )
                {
                    n = n->right;
                }
                else
                {
                    return nullptr;
                }    
            }
            // k < n->key
            else if ( _compare( k, *n->key ) )
            {
                if ( n->left != nullptr )
                {
                    n = n->left;
                }
                else
                {
                    return nullptr;
                }
            }
            else
            {
                found = true;
            }
        }

        if ( !found )
        {
            // throw key not found exception
        }
        return *n->value;
    }

    template < typename K, typename V, typename Compare >
    List< K > algo::BinaryTree< K, V, Compare >::Keys()
    {
        List< K > keys;
        Queue< struct Node * > queue; // depth first
        queue.PushBack( _root );
        
        while ( queue.Size() > 0 )
        {
            struct Node *current = queue.PopFront();
            if ( current == nullptr )
            {
                continue;
            } 

            if ( current->key != nullptr )
            {
                keys.PushBack( *current->key );
            }
            if ( current->left != nullptr )
            {
                queue.PushBack( current->left );
            }
            if ( current->right != nullptr )
            {
                queue.PushBack( current->right );
            }
        }

        return keys;
    }

    template < typename K, typename V, typename Compare >
    List< V > algo::BinaryTree< K, V, Compare >::Values()
    {
        List< V > values;
        Queue< struct Node * > queue;
        queue.PushBack( _root );

        while ( queue.Size() > 0 )
        {
            struct Node *current = queue.PopFront();
            if ( current == nullptr )
            {
                continue;
            } 

            if ( current->value != nullptr )
            {
                values.PushBack( *current->value )
            }
            if ( current->left != nullptr )
            {
                queue.PushBack( current->left );
            }
            if ( current->right != nullptr )
            {
                queue.PushBack( current->right );
            }
        }
        
        return values;
    }

    template < typename K, typename V, typename Compare >
    void algo::BinaryTree< K, V, Compare >::CopyNode( const struct Node const *src, struct Node **dst )
    {
        if ( src == nullptr )
        {
            *dst = nullptr;
            return;
        }

        ( *dst ) = CreateNode( src->key, src->value );
        CopyNode( src->left, &( *dst )->left );
        CopyNode( src->right, &( *dst )->right );
    }

    template < typename K, typename V, typename Compare >
    void algo::BinaryTree< K, V, Compare >::DestroyTree( struct Node* n )
    {
        if ( n == nullptr )
        {
            return;
        }

        DestroyNode( n );

        DestroyTree( n->left );
        DestroyTree( n->right );

        delete n;
    }

    template < typename K, typename V, typename Compare >
    void algo::BinaryTree< K, V, Compare >::DestroyNode( struct Node* n )
    {
        if ( n == nullptr )
        {
            return;
        }

        n->key->~K();
        delete n->key;

        n->value->~V();
        delete n->value;
    }

    template < typename K, typename V, typename Compare >
    struct Node * algo::BinaryTree< K, V, Compare >::CreateNode( const K& key, const V& value )
    {
        struct Node *n = new struct Node;

        n->key = new K;
        *n->key = key;

        n->value = new V;
        *n->value = value;

        n->left = nullptr;
        n->right = nullptr;

        return n;
    }
}

#endif // __ALGO_BINARYTREE_H
