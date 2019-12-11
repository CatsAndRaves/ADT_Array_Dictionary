/** @file DictionayInterface.h */
#ifndef DictionaryInterface_h
#define DictionaryInterface_h
#include "NotFoundException.h"

//Two data types allow KeyType to differ from dictionary
//data items
template<class KeyType, class T>
class DictionaryInterface
{
public:
    /** isEmpty() sees wheter the dictionary is
        empty
        @return true if empty, else false */
    virtual bool isEmpty() const = 0;
    
    /** getNumberOfItems() gets the nuber of items
        in this dictionary
        @return the number of items in the dictionary */
    virtual int getNumberOfItems() const = 0;
    
    /** add() inserts an item into the dictionary
        according to the item's search key
        @pre search key is unique
        @post if successful newItem is in the
        dictionary
        @param searchKey the seach key associated with
        the item to be inserted
        @param newItem is the item to add to the
        dictionary
        @return True if the item was successfully added
        else false */
    virtual bool add(const KeyType &searchKey,
                     const T &newItem) = 0;
    
    /** remove() removes an item with the given search
        key from this dictionary
        @post if the item whose search key equals
        seachKey existed in the dictionary, the
        item was removed
        @param searchKey the search key of the item
        to be removed
        @return true if success, else false */
    virtual bool remove(const KeyType &searchKey) = 0;
    
    /** clear() removes all entries from the dictionary */
    virtual void clear() = 0;
    
    /** getItem() retreives an item with a given search
        key from the dictionary
        @post if the retrevial is successful the
        item is returned
        @param searchKey is the serach key of the item
        to be retrieved
        @return the item associated with the search key
        @throw NotFoundException if the item does not exist */
    virtual T getItem(const KeyType &searchKey) const
                         throw(NotFoundException) = 0;
    
    /** contains() sees whether the dicitionary contains an item
        with a given search key
        @post dictionary is unchanged
        @param searchKey the search key of the item to be
        retrieved
        @return true if an item with the given search key exists
        in the dictionary */
    virtual bool contains(const KeyType &searchKey) const = 0;
    
    /** traverse() traverses the dictionary and calls a given
        client function for each item
        @post the given functions action occurs once for each
        item in the dictionay and possibly alters item
        @param visit a client function */
    virtual void traverse(void visit(T &anItem)) const = 0;
};//end DicitionaryInterface
#endif /* DictionaryInterface_h */
