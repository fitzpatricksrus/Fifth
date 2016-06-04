#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>

#include "List.hpp"

namespace us_cownet_utils {
    
    template <class K, class V, int maxSize>
    class Map {
    public:
        Map(K notFoundKey, V notFoundValue);
        virtual ~Map();
        
        void put(K key, V value);
        V get(K key);
        int size() const;
        
        K notFoundKey;
        V notFoundValue;
        
        typedef List<K, maxSize> KeyListType;
        typedef List<V, maxSize> ValueListType;
        
        KeyListType keyList;
        ValueListType valueList;
    };
    
    template <class K, class V, int maxSize>
    Map<K, V, maxSize>::Map(K notFoundKeyIn, V notFoundValueIn)
    : notFoundKey(notFoundKeyIn), notFoundValue(notFoundValueIn)
    {
    }
    
    template <class K, class V, int maxSize>
    inline Map<K, V, maxSize>::~Map() {
    }
    
    template <class K, class V, int maxSize>
    inline void Map<K, V, maxSize>::put(K key, V value) {
        int ndx = keyList.indexOf(key);
        if (ndx != -1) {
            keyList.removeNdx(ndx);
            valueList.removeNdx(ndx);
        }
        keyList.add(key);
        valueList.add(value);
    }
    
    template <class K, class V, int maxSize>
    inline V Map<K, V, maxSize>::get(K key) {
        int ndx = keyList.indexOf(key);
        if (ndx != -1) {
            return valueList[ndx];
        } else {
            return notFoundValue;
        }
    }
    
    template <class K, class V, int maxSize>
    inline int Map<K, V, maxSize>::size() const {
        return keyList.size();
    }
    
} /* namespace us_cownet_utils */

#endif /* Map_hpp */
