#pragma once
#ifndef __ALGO_BINARYTREE_H
#define __ALGO_BINARYTREE_H

#include <memory>

#include "IDictonary.h"

namespace algo
{
    // TODO: use boost static assert to ensure K is comparable (operator <)
    template <typename K, typename V, typename Allocator = std::allocator<T>>
    class BinaryTree : public IDictonary<T>
    {
    public:
        BinaryTree();
        BinaryTree(const BinaryTree<K, V, Allocator>& rhs);
        BinaryTree(BinaryTree<K, V, Allocator>&& rhs);
        BinaryTree<K, V, Allocator> operator=(const BinaryTree<K, V, Allocator>& rhs);
        BinaryTree<K, V, Allocator> operator=(BinaryTree<K, V, Allocator>&& rhs);
        ~BinaryTree();



    private:
        typedef struct node
        {
            K key;
            V value;
            Node * left;
            Node * right;
        } Node;
        
        Node * _root;
        Allocator _alloc;
    };
}

#endif // __ALGO_BINARYTREE_H