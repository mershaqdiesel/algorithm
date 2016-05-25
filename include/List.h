#pragma once
#ifndef __ALGO_LIST_H
#define __ALGO_LIST_H

#include <memory>

namespace algo
{
	template<typename T, typename Allocator = std::allocator>
	class List
	{
	public:
		List();
		~List();

		void PushBack(const T& t);
		void PushFront(const T& t);

		T PopFront();
		T PopBack();

	private:
		class Node
		{
			T elem;
			Node *next;
			Node *prev;
		};

		Node *head;
		Node *tail;
	};
	
	template <typename T, typename Allocator>
	algo::List<T, Allocator>::List() : head(nullptr), tail(nullptr)
	{

	}

	template <typename T, typename Allocator>
	algo::List<T, Allocator>::~List()
	{
		Node *current = this->head;
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

		if (head == nullptr)
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tmp->prev = tail;
			tail = tmp;
		}
	}

	template <typename T, typename Allocator>
	void algo::List<T, Allocator>::PushFront(const T& t)
	{
		Node *tmp = new Node;
		tmp->elem = t;
		tmp->next = nullptr;
		tmp->prev = nullptr;

		if (tail == nullptr)
		{
			tail = tmp;
			head = tmp;
		}
		else
		{
			tmp->next = head;
			head->prev = tmp;
			head = tmp;
		}
	}

	template <typename T, typename Allocator>
	T algo::List<T, Allocator>::PopFront()
	{
		T retval;
		if (head == tail && head != nullptr)
		{
			retval = head->elem;
			delete head;
			head = tail = nullptr;
		}
		else if (head != nullptr)
		{
			Node *tmp = head;
			retval = head->elem;
			head = tmp->next;
			tmp->prev = nullptr;
			delete tmp;
		}
		return retval;
	}

	template <typename T, typename Allocator>
	T algo::List<T, Allocator>::PopBack()
	{
		T retval;
		if (head == tail && tail != nullptr)
		{
			retval = tail->elem;
			delete tail;
			head = tail = nullptr;
		}
		else if (tail != nullptr)
		{
			retval = tail->elem;
			Node *tmp = tail;
			tail->prev->next = nullptr;
			tail = tail->prev;
			delete tmp;
		}
		return retval;
	}
}

#endif // __ALGO_LIST_H
