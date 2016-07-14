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
        
        const V* operator[](const K&) const;
        const IIterable<K>& Keys() const;
        const IIterable<V>& Values() const;

        V* operator[](const K&);
        IIterable<K>& Keys();
        IIterable<V>& Values();
    };
}

#endif // __ALGO_IDICTIONARY_H