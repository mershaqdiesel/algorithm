#pragma once
#ifndef __ALGO_LIST_H
#define __ALGO_LIST_H

#include <memory>
#include <initializer_list>

#include "IContainer.h"
#include "IITerable.h"

namespace algo
{
	template<typename T, typename Allocator = std::allocator<T> >
	class List : public IContainer//, public IIterable
	{
	public:
		// Constructors
		List();
		// List(const List& list);
		// List(List&& list);
		// List(initializer_list<T> list);
		
		// Assignment
		// List<T, Allocator>& operator=(const List<T, Allocator>& rhs);
		// List<T, Allocator>& operator=(List<T, Allocator>&& rhs);
		// List<T, Allocator>& operator=(initializer_list<T> rhs);
		
		// Destructor
		~List();

		// Push
		void PushFront(const T& t);
		// void PushFront(T&& t);
		void PushBack(const T& t);
		// void PushFront(T&& t);
		
		// Pop
		void PopFront();
		void PopBack();
		
		// Accessors
		// const T& Front() const;
		// const T& Back() const;
		
		// T& Front();
		// T& Back();
		
		// T& operator[](size_t index);
		
		size_t Size() const;
		
		// Iterator
		// Iterator<T> Begin();
        // Iterator<T> End();

	private:
		class Node
		{
			T 		*elem;
			Node 	*next;
			Node 	*prev;
		};

		Node *_head;
		Node *_tail;
		Allocator _alloc;
		size_t _size;
	};
	
	template <typename T, typename Allocator>
	algo::List<T, Allocator>::List() : _head{nullptr}, _tail{nullptr}, _alloc{}, _size{0}
	{
	}
	
	// template <typename T, typename Allocator>
	// algo::List<T, Allocator>::List(const List& list)
	// {
		
	// }
	
	// template <typename T, typename Allocator>
	// algo::List<T, Allocator>::List(List&& list)
	// {
		
	// }
	
	// template <typename T, typename Allocator>
	// algo::List<T, Allocator>::List(initializer_list<T> list)
	// {
		
	// }
	
	// template <typename T, typename Allocator>
	// List<T, Allocator>& algo::List<T, Allocator>::operator=(const List<T, Allocator>& rhs)
	// {
		
	// }
	
	// template <typename T, typename Allocator>
	// List<T, Allocator>& algo::List<T, Allocator>::operator=(List<T, Allocator>&& rhs)
	// {
		
	// }
	
	// template <typename T, typename Allocator>
	// List<T, Allocator>& algo::List<T, Allocator>::operator=(initializer_list<T> rhs)
	// {
		
	// }

	template <typename T, typename Allocator>
	algo::List<T, Allocator>::~List()
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
	}
	
	template <typename T, typename Allocator>
	void algo::List<T, Allocator>::PushFront(const T& t)
	{
		Node *temp = new Node;
		temp->elem = _alloc.allocate(1);
		_alloc.construct(temp->elem, t);
		temp->next = temp->prev = nullptr;
		
		if (_head == nullptr && _tail == nullptr)
		{
			_head = _tail = temp;
		}
		else
		{
			temp->next = _head;
			_head->prev = temp;
			_head = temp;
		}
		_size++;
	}
	
	// template <typename T, typename Allocator>
	// void algo::List<T, Allocator>::PushFront(T&& t)
	// {
		
	// }

	template <typename T, typename Allocator>
	void algo::List<T, Allocator>::PushBack(const T& t)
	{
		Node *temp = new Node;
		temp->elem = _alloc.allocate(1);
		_alloc.construct(temp->elem, t);
		temp->prev = temp->next = nullptr;
		if (_head == nullptr && _tail == nullptr)
		{
			_head = _tail = temp;
		}
		else
		{
			temp->prev = _tail;
			_tail->next = temp;
			_tail = temp;
		}
		_size++;
	}
	
	// template <typename T, typename Allocator>
	// void algo::List<T, Allocator>::PushBack(T&& t)
	// {
		
	// }

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
	
	// template <typename T, typename Allocator>
	// const T& algo::List<T, Allocator>::Front() const
	// {
		
	// }
	
	// template <typename T, typename Allocator>
	// const T& algo::List<T, Allocator>::Back() const
	// {
		
	// }
	
	// template <typename T, typename Allocator>
	// T& algo::List<T, Allocator>::Front()
	// {
		
	// }
	
	// template <typename T, typename Allocator>
	// T& algo::List<T, Allocator>::Back()
	// {
		
	// }
	
	// template <typename T, typename Allocator>
	// T& algo::List<T, Allocator>::operator[](size_t index)
	// {
		
	// }
	
	template <typename T, typename Allocator>
	size_t algo::List<T, Allocator>::Size() const
	{
		return _size;
	}
	
	// template <typename T, typename Allocator>
	// Iterator<T> algo::List<T, Allocator>::Begin()
	// {
		
	// }
	
	// template <typename T, typename Allocator>
	// Iterator<T> algo::List<T, Allocator>::End()
	// {
		
	// }
}

#endif // __ALGO_LIST_H
