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
    template <typename K, typename V, typename Compare = std::less<K> >
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
        Compare     _compare;

        void CopyNode(const struct Node const *src, struct Node **dst);
        void DestroyTree(struct Node* n);
        void DestroyNode(struct Node* n);
        struct Node * CreateNode(const K& key, const V& value);

    };

    template < typename K, typename V, typename Compare >
    algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::BinaryTree()
        : _root{nullptr}, _compare{}
    {
    }
    
    template < typename K, typename V, typename Compare >
    algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::BinaryTree(const BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>& rhs)
        : _root{nullptr}, _compare{rhs._compare}
    {
        CopyNode(rhs._root, _root);
    }
    
    template < typename K, typename V, typename Compare >
    algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::BinaryTree(BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>&& rhs)
        : _root{rhs._root}, _compare{std::move(rhs._compare)}
    {
        rhs._root = nullptr;
    }

    template < typename K, typename V, typename Compare >
    BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc> algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::operator=(const BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>& rhs)
    {
        BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc> copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    template < typename K, typename V, typename Compare >
    BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc> algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::operator=(BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>&& rhs)
    {
        std::swap(_root, rhs._root);
        std::swap(_keyAlloc, rhs._keyAlloc);
        std::swap(_valueAlloc, rhs._valueAlloc);
        std::swap(_compare, rhs._compare);
        return *this;
    }

    template < typename K, typename V, typename Compare >
    algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::~BinaryTree()
    {
        DestroyTree(_root);   
    }

    template < typename K, typename V, typename Compare >
    bool algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::Put(const K& key, const V& value)
    {
        if (_root == nullptr)
        {
            _root = CreateNode(key, value);        
            return true;
        }

        bool inserted = false;
        bool exists = false;
        struct Node * n = _root;

        while (!inserted && !exists)
        {
            // n->key < key
            if (_compare(*n->key, key))
            {
                if (n->right == nullptr)
                {
                    n->right = CreateNode(key, value);
                    inserted = true;
                }
                else
                {
                    n = n->right;
                }
            }
            // key < n->key
            else if (_compare(key, *n->key))
            {
                if (n->left == nullptr)
                {
                    n->left = CreateNode(key, value);
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
    const V& algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::operator[](const K& k) const
    {
        struct Node * n = _root;
        bool found = n != nullptr;

        while (!found)
        {
            // n->key < k
            if (_compare(*n->key, k))
            {
                   
            }
            // k < n->key
            else if (_compare(k, *n->key))
            {

            }
            else
            {
                found = true;
            }
        }

        if (found)
        {
            return *n->value;
        }
        return nullptr;
    }

    template < typename K, typename V, typename Compare >
    const IIterable<K>& algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::Keys() const
    {

    }

    template < typename K, typename V, typename Compare >
    const IIterable<V>& algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::Values() const
    {

    }

    template < typename K, typename V, typename Compare >
    V& algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::operator[](const K&)
    {

    }

    template < typename K, typename V, typename Compare >
    IIterable<K>& algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::Keys()
    {

    }

    template < typename K, typename V, typename Compare >
    IIterable<V>& algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::Values()
    {

    }

    template < typename K, typename V, typename Compare >
    void algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::CopyNode(const struct Node const *src, struct Node **dst)
    {
        if (src == nullptr)
        {
            *dst = nullptr;
            return;
        }

        (*dst) = CreateNode(src->key, src->value);
        CopyNode(src->left, &(*dst)->left);
        CopyNode(src->right, &(*dst)->right);
    }

    template < typename K, typename V, typename Compare >
    void algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::DestroyTree(struct Node* n)
    {
        if (n == nullptr)
        {
            return;
        }

        DestroyNode(n);

        DestroyTree(n->left);
        DestroyTree(n->right);

        delete n;
    }

    template < typename K, typename V, typename Compare >
    void algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::DestroyNode(struct Node* n)
    {
        if (n == nullptr)
        {
            return;
        }

        _keyAlloc.destroy(*n->key);
        _keyAlloc.deallocate(n->key, 1);
        _valueAlloc.destroy(*n->value);
        _valueAlloc.deallocate(n->value, 1);
    }

    template < typename K, typename V, typename Compare >
    struct Node * algo::BinaryTree<K, V, Compare, KeyAlloc, ValueAlloc>::CreateNode(const K& key, const V& value)
    {
        struct Node *n = new struct Node;
        n->key = _keyAlloc.allocate(1);
        _keyAlloc.construct(*n->key, key);
        n->value = _valueAlloc.allocate(1);
        _valueAlloc.construct(*n->value, value);
        n->left = nullptr;
        n->right = nullptr;
        return n;
    }
}

#endif // __ALGO_BINARYTREE_H