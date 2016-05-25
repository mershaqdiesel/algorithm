#pragma once
#ifndef __ALGO_ARRAY_H
#define __ALGO_ARRAY_H

namespace algo
{
	template <typename T>
	class Array
	{
	public:
		Array();
		~Array();

		PushBack(const T& t);
		PushFront(const T& t);



	private:
		unsigned int capacity;
		unsigned int length;
		T* vec;
	};
}

#endif // __ALGO_ARRAY_H
