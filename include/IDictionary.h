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
        bool Put( const K& key, const V& value );
        
        const V& operator[]( const K& ) const;
        const List< K > Keys() const;
        const List< V > Values() const;

        V& operator[]( const K& );
        List< K > Keys();
        List< V > Values();
    };
}

#endif // __ALGO_IDICTIONARY_H