/** @file Entry.hpp */
#ifndef Entry_hpp
#define Entry_hpp
#include <stdio.h>

template<class KeyType, class T>
class Entry
{
private:
    T       item;
    KeyType searchKey;
    
protected:
    void setKey(const KeyType &itemKey);
    
public:
    Entry();
    Entry(T newEntry, KeyType searchKey);
    T getItem() const;
    KeyType getKey() const;
    void setItem(const T &newEntry);
    
    //Overloaded operators
    bool operator==(const Entry<KeyType, T> &rightHandItem) const;
    bool operator >(const Entry<KeyType, T> &rightHandItem) const;
};//end Entry
#endif /* Entry_hpp */
