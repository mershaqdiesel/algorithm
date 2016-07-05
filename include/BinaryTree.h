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
    template <typename K, typename V, typename Compare = std::less<K>, typename KeyAlloc = std::allocator<K>, typename ValueAlloc = std::allocator<V>>
    class BinaryTree : public IDictonary<K, V>
    {
    public:
        BinaryTree();
        BinaryTree(const BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>& rhs);
        BinaryTree(BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>&& rhs);

        BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc> operator=(const BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>& rhs);
        BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc> operator=(BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>&& rhs);

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
        KeyAlloc    _keyAlloc;
        ValueAlloc  _valueAlloc;
        Compare     _compare;
    };

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    algo::BinaryTree<K, V, Compare, Allocator>::BinaryTree()
    {

    }
    
    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    algo::BinaryTree<K, V, Compare, Allocator>::BinaryTree(const BinaryTree<K, V, Compare, Allocator>& rhs)
    {

    }
    
    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    algo::BinaryTree<K, V, Compare, Allocator>::BinaryTree(BinaryTree<K, V, Compare, Allocator>&& rhs)
    {

    }

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    BinaryTree<K, V, Compare, Allocator> algo::BinaryTree<K, V, Compare, Allocator>::operator=(const BinaryTree<K, V, Compare, Allocator>& rhs)
    {

    }

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    BinaryTree<K, V, Compare, Allocator> algo::BinaryTree<K, V, Compare, Allocator>::operator=(BinaryTree<K, V, Compare, Allocator>&& rhs)
    {

    }

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    algo::BinaryTree<K, V, Compare, Allocator>::~BinaryTree()
    {

    }

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    bool algo::BinaryTree<K, V, Compare, Allocator>::Put(const K& key, const V& value)
    {

    }

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    const V& algo::BinaryTree<K, V, Compare, Allocator>::operator[](const K&) const
    {

    }

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    const IIterable<K>& algo::BinaryTree<K, V, Compare, Allocator>::Keys() const
    {

    }

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    const IIterable<V>& algo::BinaryTree<K, V, Compare, Allocator>::Values() const
    {

    }

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    V& algo::BinaryTree<K, V, Compare, Allocator>::operator[](const K&)
    {

    }

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    IIterable<K>& algo::BinaryTree<K, V, Compare, Allocator>::Keys()
    {

    }

    template <typename K, typename V, typename Compare, typename KeyAlloc, typename ValueAlloc>
    IIterable<V>& algo::BinaryTree<K, V, Compare, Allocator>::Values()
    {

    }
}

#endif // __ALGO_BINARYTREE_H