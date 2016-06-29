#pragma once
#ifndef __ALGO_IDICTIONARY_H
#define __ALGO_IDICTIONARY_H

namespace algo
{
    template <typename K, typename V>
    class IDictionary
    {
    public:
        bool Put(const K& key, const V& value);
        V& operator[](const K&);
        const V& operator[](const K&) const;
    };
}

#endif // __ALGO_IDICTIONARY_H