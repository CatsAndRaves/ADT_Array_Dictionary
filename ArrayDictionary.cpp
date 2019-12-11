/** @file ArrayDicitionary.cpp */
#include "ArrayDictionary.hpp"



//Private methods
template<class KeyType, class T>
void ArrayDicitionary<KeyType, T>::destroyDictionary()
{
    itemCount = 0;                  //Zero out the itemCount
    delete[] items;                 //and free the memory
    items = nullptr;                //No hanging pointers
}//end destroyDictionary

template<class KeyType, class T>
int ArrayDicitionary<KeyType, T>::findEntryIndex(int firstIndex,
                                                 int lastIndex,
                                                 const KeyType &searchKey) const
                                                  
{
    //Locate the midpoint of the array
    int midPoint = firstIndex + (lastIndex - firstIndex) / 2;
    
    //Should be O(log n) using a recursive binary search algorithm 
    if(firstIndex > lastIndex)
    {
        return -1;                  //Item not found
    }
    else if(searchKey == items[midPoint].getKey())
    {
        return midPoint;            //Item found
    }
    else if(searchKey < items[midPoint].getKey())
    {
        //Search the lower half
        return findEntryIndex(firstIndex,
                              midPoint - 1,
                              searchKey);
    }
    else
    {
        //Search the upper half
        return findEntryIndex(midPoint + 1,
                              lastIndex,
                              searchKey);
    }
}//end findEntryIndex

//Public methods
template<class KeyType, class T>
ArrayDicitionary<KeyType, T>::ArrayDicitionary() : itemCount(0), maxItems(DEFAULT_CAPACITY)
{
    items = new Entry<KeyType, T>[DEFAULT_CAPACITY];
}  // end constructor

template<class KeyType, class T>
ArrayDicitionary<KeyType, T>::ArrayDicitionary(int maxNumberOfEntries) :
    itemCount(0), maxItems(maxNumberOfEntries)
{
    items = new Entry<KeyType, T>[maxNumberOfEntries];
}  // end constructor

/** Destructor calls private destroyDictionary() */
template<class KeyType, class T>
ArrayDicitionary<KeyType, T>::~ArrayDicitionary()
{
    destroyDictionary();
}//end destructor

template<class KeyType, class T>
bool ArrayDicitionary<KeyType, T>::isEmpty() const
{
    return itemCount == 0;
}//end isEmpty


template<class KeyType, class T>
int ArrayDicitionary<KeyType, T>::getNumberOfItems() const
{
    return itemCount;
}//getNumberOfItems

template<class KeyType, class T>
bool ArrayDicitionary<KeyType, T>::add(const KeyType &searchKey,
                                       const T &newItem) throw(PrecondViolatedExcep)
{
    bool ableToInsert(itemCount < maxItems);
    
    if(ableToInsert)
    {
        /** Make room for the new entry by shifting all entries
            at poinsitions >= newPosition toward the end of the
            array; no shift if position == itemCount + 1; goal
            here is to shift the entries while looking for the
            insertion point */
        int index = itemCount;
        
        //Short-circuit evaluations here
        //While index is greater than 0 and searchKey is less than
        //items index's key
        while((index > 0) && (searchKey < items[index - 1].getKey()))
        {
            //Shift the items
            items[index] = items[index - 1];
            index--;
        }//end while
        
        //The insertion point has been found, insert new entry
        items[index] = Entry<KeyType, T>(newItem, searchKey);
        itemCount++;//Increment the item count
        return ableToInsert;
    }//end if
    else
    {
        throw PrecondViolatedExcep("The dictionary is full.\n\n");
    }
    
}//end add

template<class KeyType, class T>
bool ArrayDicitionary<KeyType, T>::remove(const KeyType &searchKey)
{
    //Find the item
    int foundIndex = findEntryIndex(0, (itemCount - 1), searchKey);
    
    //Is the item able to be removed? If so shift the entries over to the left
    bool canRemove = (!isEmpty()) && (foundIndex >= 0);
    if(canRemove)
    {
        //Shift some items to the left
        while (foundIndex < itemCount - 1)
        {
            //Shif the items down the array
            items[foundIndex] = items[foundIndex + 1];
            foundIndex++;           //Increment for shifting next item
        }//end while
        itemCount--;                //Decrement the total number of entries
    }//end if
    return canRemove;
}//end remove

template<class KeyType, class T>
void ArrayDicitionary<KeyType, T>::clear()
{
    destroyDictionary();                //destroyDictionary function
}//end clear

template<class KeyType, class T>
T  ArrayDicitionary<KeyType, T>::getItem(const KeyType &searchKey) const
                                         throw(NotFoundException)
{
    //Get the index of the searchKey using findEntry function - O(log n) 
    int foundIndex = findEntryIndex(0, itemCount - 1, searchKey);
    if(foundIndex < 0)
    {
        throw NotFoundException("The item is not in the dictionary.\n\n");
    }//end if
    return items[foundIndex].getItem();
}//end getItem

template<class KeyType, class T>
bool ArrayDicitionary<KeyType, T>::contains(const KeyType &searchKey) const
{
    bool contains = findEntryIndex(0, itemCount - 1, searchKey);
    return contains;
}//end

//traverse calls void host function
template<class KeyType, class T>
void ArrayDicitionary<KeyType, T>::traverse(void visit(T &item)) const
{
    for(int index = 0; index < itemCount; index++)
    {
        string currentItem = static_cast<string>(items[index].getItem());
        string searchKey   = static_cast<string>(items[index].getKey());
        visit(searchKey);
        visit(currentItem);
    }//end for 
}//end traverse

//Overloaded traverse calls void host function
/** @param item the item to search for
    @param visit(item) the host visit fuction 
 */
template<class KeyType, class T>
void ArrayDicitionary<KeyType, T>::traverse(const T &item, void visit(T &item)) const
{
    for(int index = 0; index < itemCount; index++)
    {
        string currentItem = static_cast<string>(items[index].getItem());
        string searchKey   = static_cast<string>(items[index].getKey());
        if(currentItem.find(item) != string::npos)
        {
            visit(searchKey);
            visit(currentItem);
        }//end if 
    }//end for
}//end traverse
