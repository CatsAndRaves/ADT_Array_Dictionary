/** @file Entry.cpp */
#include "Entry.hpp"

//Protected
template<class KeyType, class T>
void Entry<KeyType, T>::setKey(const KeyType &itemKey)
{
    searchKey = itemKey;
}//end setKey

//Public
template<class KeyType, class T>
Entry<KeyType, T>::Entry()
{ ; }//end default constructor

template<class KeyType, class T>
Entry<KeyType, T>::Entry(T newEntry, KeyType itemKey)
{
    item = newEntry;
    searchKey = itemKey;
}//end constructor

template<class KeyType, class T>
T Entry<KeyType, T>::getItem() const
{
    return item;
}//end getItem

template<class KeyType, class T>
KeyType Entry<KeyType, T>::getKey() const
{
    return searchKey;
}//end getKey

template<class KeyType, class T>
void Entry<KeyType, T>::setItem(const T &newEntry)
{
    item = newEntry;
}//end setItem

//Overloaded Operators
template<class KeyType, class T>
bool Entry<KeyType, T>::operator==(const Entry<KeyType, T>
                                         &rightHandItem) const
{
    return (searchKey == rightHandItem.getKey());
}//end operator ==

template<class KeyType, class T>
bool Entry<KeyType, T>::operator>(const Entry<KeyType, T>
                                        &rightHandItem) const
{
    return (searchKey > rightHandItem.getKey());
}//operator >
