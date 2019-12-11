/** An array based implementation of the ADT dictionary
    that orgainizes its data items in sorted search key
    order, Search keys in the dictionary are unique */

#ifndef ArrayDictionary_hpp
#define ArrayDictionary_hpp

#include <stdio.h>
#include "DictionaryInterface.h"
#include "Entry.hpp"
#include "NotFoundException.h"
#include "NotFoundException.cpp"
#include "PrecondViolatedExcep.h"
#include "PrecondViolatedExcep.cpp"
template<class KeyType, class T>
class ArrayDicitionary : public DictionaryInterface<KeyType, T>
{
private:
    static const int DEFAULT_CAPACITY = 21;         //Small, tests full dicitionary
    
    Entry<KeyType, T> *items;                       //Dicitionary array of Entries 
    int itemCount;                                  //Dicitionary item count
    int maxItems;                                   //Max capacity of dictionary
    
    void destroyDictionary();
    int findEntryIndex(int firstIndex, int lastIndex,
                       const KeyType &searchKey) const;
    
public:
    ArrayDicitionary();
    ArrayDicitionary(int maxNumberOfEntries);
    //ArrayDicitionary(const ArrayDicitionary<KeyType, T>, T &dictionary);
    virtual ~ArrayDicitionary();
    
    bool isEmpty() const;
    int  getNumberOfItems() const;
    bool add(const KeyType &searchKey, const T &newItem) throw(PrecondViolatedExcep);
    bool remove(const KeyType &searchKey);
    void clear();
    T    getItem(const KeyType &searchKey) const throw(NotFoundException);
    bool contains(const KeyType &searchKey) const ;
    
    /** Traverses the items in the dictionary in sorted search
        key order and calls the visit client function once for
        each item */
    void traverse(void visit(T &item)) const;
    
    /**Overloaded Traverse
     */
    void traverse(const T &item, void visit(T &item)) const;
};//end ArrayDicitionary
#endif /* ArrayDictionary_hpp */
