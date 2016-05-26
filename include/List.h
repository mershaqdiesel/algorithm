#pragma once
#ifndef __ALGO_LIST_H
#define __ALGO_LIST_H

#include <memory>

#include "IITerable.h"

namespace algo
{
	template<typename T, typename Allocator = std::allocator>
	class List : public IIterable
	{
	public:
		List();
		~List();

		void PushFront(const T& t);
		void PopFront();
		const T& Front() const;
		T& Front();
		
		void PushBack(const T& t);
		void PopBack();
		const T& Back() const;
		T& Back();

	private:
		class Node
		{
			T elem;
			Node *next;
			Node *prev;
		};

		Node *_head;
		Node *_tail;
	};
	
	template <typename T, typename Allocator>
	algo::List<T, Allocator>::List() : _head(nullptr), _tail(nullptr)
	{

	}

	template <typename T, typename Allocator>
	algo::List<T, Allocator>::~List()
	{
		Node *current = this->_head;
		while (current != nullptr)
		{
			Node *next = current->next;
			delete current;
			current = next;
		}
	}

	template <typename T, typename Allocator>
	void algo::List<T, Allocator>::PushBack(const T& t)
	{
		Node *tmp = new Node;
		tmp->elem = t;
		tmp->prev = nullptr;
		tmp->next = nullptr;

		if (_head == nullptr)
		{
			_head = tmp;
			_tail = tmp;
		}
		else
		{
			_tail->next = tmp;
			tmp->prev = _tail;
			_tail = tmp;
		}
	}

	template <typename T, typename Allocator>
	void algo::List<T, Allocator>::PushFront(const T& t)
	{
		Node *tmp = new Node;
		tmp->elem = t;
		tmp->next = nullptr;
		tmp->prev = nullptr;

		if (_tail == nullptr)
		{
			_tail = tmp;
			_head = tmp;
		}
		else
		{
			tmp->next = _head;
			_head->prev = tmp;
			_head = tmp;
		}
	}

	template <typename T, typename Allocator>
	T algo::List<T, Allocator>::PopFront()
	{
		T retval;
		if (_head == _tail && _head != nullptr)
		{
			retval = _head->elem;
			delete _head;
			_head = _tail = nullptr;
		}
		else if (_head != nullptr)
		{
			Node *tmp = _head;
			retval = _head->elem;
			_head = tmp->next;
			tmp->prev = nullptr;
			delete tmp;
		}
		return retval;
	}

	template <typename T, typename Allocator>
	T algo::List<T, Allocator>::PopBack()
	{
		T retval;
		if (_head == _tail && _tail != nullptr)
		{
			retval = _tail->elem;
			delete _tail;
			_head = _tail = nullptr;
		}
		else if (_tail != nullptr)
		{
			retval = _tail->elem;
			Node *tmp = _tail;
			_tail->prev->next = nullptr;
			_tail = _tail->prev;
			delete tmp;
		}
		return retval;
	}
}

#endif // __ALGO_LIST_H
