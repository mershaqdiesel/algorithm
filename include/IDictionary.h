#pragma once
#ifndef __ALGO_IDICTIONARY_H
#define __ALGO_IDICTIONARY_H

#include "List.h"

namespace algo
{
    template <typename K, typename V>
    class IDictionary
    {
    public:
        virtual bool Put( const K& key, const V& value ) = 0;
        
        virtual const V& operator[]( const K& ) const = 0;
        virtual const List< K > Keys() const = 0;
        virtual const List< V > Values() const = 0;

        virtual V& operator[]( const K& ) = 0;
        virtual List< K > Keys() = 0;
        virtual List< V > Values() = 0;
    };
}

#endif // __ALGO_IDICTIONARY_H