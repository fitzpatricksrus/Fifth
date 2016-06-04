#ifndef List_hpp
#define List_hpp

#include <stdio.h>

namespace us_cownet_utils {
    
    template <class T, int maxSize>
    class List {
    public:
        List();
        List(const List<T, maxSize>& other);
        List(List<T, maxSize>&& other);
        virtual ~List();
        List<T, maxSize>& operator=(const List<T, maxSize>& other);
        
        void add(const T& object);
        void remove(const T& object);
        void removeNdx(int ndx);
        void clear();
        int size() const;
        T& operator[](int ndx);
        int indexOf(const T& object);
        
        T& peek();
        T& peek(int ndx);
        void push(const T& object);
        void pop();
        void pop(int count);
        
    private:
        int currentSize;
        T values[maxSize];
    };
    
    template<class T, int maxSize>
    inline us_cownet_utils::List<T, maxSize>::List()
    : currentSize(0)
    {
    }

    template<class T, int maxSize>
    List<T, maxSize>::List(const List<T, maxSize>& other)
    : currentSize(other.currentSize)
    {
        for (int i = 0; i < currentSize; i++) {
            values[i] = other.values[i];
        }
    }

    template<class T, int maxSize>
    List<T, maxSize>::List(List<T, maxSize>&& other)
    : currentSize(other.currentSize)
    {
        for (int i = 0; i < currentSize; i++) {
            values[i] = other.values[i];
        }
    }

    template<class T, int maxSize>
    inline us_cownet_utils::List<T, maxSize>::~List() {
    }
    
    template<class T, int maxSize>
    List<T, maxSize>& List<T, maxSize>::operator=(const List<T, maxSize>& other)
    {
        if (this == &other) return *this;
        currentSize = other.currentSize;
        for (int i = 0; i < currentSize; i++) {
            values[i] = other.values[i];
        }
        return *this;
    }
    
    template<class T, int maxSize>
    inline void us_cownet_utils::List<T, maxSize>::add(const T& object) {
        values[currentSize++] = object;
    }
    
    template<class T, int maxSize>
    inline void us_cownet_utils::List<T, maxSize>::remove(const T& object) {
        int ndx = indexOf(object);
        if (ndx != -1) {
            removeNdx(ndx);
        }
    }
    
    template<class T, int maxSize>
    inline void us_cownet_utils::List<T, maxSize>::removeNdx(int ndx) {
        currentSize--;
        values[ndx] = values[currentSize];
    }
    
    template<class T, int maxSize>
    inline void us_cownet_utils::List<T, maxSize>::clear() {
        currentSize = 0;
    }
    
    template<class T, int maxSize>
    inline int us_cownet_utils::List<T, maxSize>::size() const {
        return currentSize;
    }
    
    template<class T, int maxSize>
    inline T& us_cownet_utils::List<T, maxSize>::operator [](int ndx) {
        return values[ndx];
    }
    
    template<class T, int maxSize>
    inline int us_cownet_utils::List<T, maxSize>::indexOf(const T& object) {
        for (int i = 0; i < currentSize; i++) {
            if (values[i] == object) {
                return i;
            }
        }
        return -1;
    }
    
    template<class T, int maxSize>
    inline T& List<T, maxSize>::peek() {
        return values[currentSize-1];
    }
    
    template<class T, int maxSize>
    inline T& List<T, maxSize>::peek(int ndx) {
        return values[currentSize - ndx -1];
    }
    
    template<class T, int maxSize>
    inline void List<T, maxSize>::push(const T& object) {
        values[currentSize++] = object;
    }
    
    template<class T, int maxSize>
    inline void List<T, maxSize>::pop() {
        currentSize--;
    }
    
    template<class T, int maxSize>
    inline void List<T, maxSize>::pop(int count) {
        currentSize -= count;
    }
}

#endif /* List_hpp */
