#pragma once
#ifndef __ALGO_BINARYTREE_H
#define __ALGO_BINARYTREE_H

#include <functional>
#include <memory>

#include "IDictonary.h"
#include "IIterable.h"
#include "List.h"

namespace algo
{
    // TODO: use boost static assert to ensure K is comparable (operator <)
    template <typename K, typename V, typename Compare = std::less<K>, typename Allocator = std::allocator<T>>
    class BinaryTree : public IDictonary<K, V>
    {
    public:
        BinaryTree();
        BinaryTree(const BinaryTree<K, V, Compare, Allocator>& rhs);
        BinaryTree(BinaryTree<K, V, Compare, Allocator>&& rhs);

        BinaryTree<K, V, Compare, Allocator> operator=(const BinaryTree<K, V, Compare, Allocator>& rhs);
        BinaryTree<K, V, Compare, Allocator> operator=(BinaryTree<K, V, Compare, Allocator>&& rhs);

        ~BinaryTree();

        bool Put(const K& key, const V& value) override;

        const V& operator[](const K&) const override;
        const IIterable<K>& Keys() const override;
        const IIterable<V>& Values() const override;

        V& operator[](const K&) override;
        IIterable<K>& Keys() override;
        IIterable<V>& Values() override;

    private:
        struct Node
        {
            K           *key;
            V           *value;
            struct Node *left;
            struct Node *right;
        };
        
        struct Node *_root;
        Allocator   _alloc;
        Compare     _compare;
    };

    algo::BinaryTree<K, V, Compare, Allocator>::BinaryTree()
    {

    }
    
    algo::BinaryTree<K, V, Compare, Allocator>::BinaryTree(const BinaryTree<K, V, Compare, Allocator>& rhs)
    {

    }
    
    algo::BinaryTree<K, V, Compare, Allocator>::BinaryTree(BinaryTree<K, V, Compare, Allocator>&& rhs)
    {

    }
    
    BinaryTree<K, V, Compare, Allocator> algo::BinaryTree<K, V, Compare, Allocator>::operator=(const BinaryTree<K, V, Compare, Allocator>& rhs)
    {

    }

    BinaryTree<K, V, Compare, Allocator> algo::BinaryTree<K, V, Compare, Allocator>::operator=(BinaryTree<K, V, Compare, Allocator>&& rhs)
    {

    }

    algo::BinaryTree<K, V, Compare, Allocator>::~BinaryTree()
    {

    }

    bool algo::BinaryTree<K, V, Compare, Allocator>::Put(const K& key, const V& value)
    {

    }

    const V& algo::BinaryTree<K, V, Compare, Allocator>::operator[](const K&) const
    {

    }

    const IIterable<K>& algo::BinaryTree<K, V, Compare, Allocator>::Keys() const
    {

    }

    const IIterable<V>& algo::BinaryTree<K, V, Compare, Allocator>::Values() const
    {

    }

    V& algo::BinaryTree<K, V, Compare, Allocator>::operator[](const K&)
    {

    }

    IIterable<K>& algo::BinaryTree<K, V, Compare, Allocator>::Keys()
    {

    }

    IIterable<V>& algo::BinaryTree<K, V, Compare, Allocator>::Values()
    {

    }
}

#endif // __ALGO_BINARYTREE_H