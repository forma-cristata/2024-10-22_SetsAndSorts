#include "mySet.h"

#include <iomanip>
#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace MySetNS;

/**
 * SWAP
 * Performs swaps
 * Used in bubble and selection sorts and any variants of them
 * @param index
 * @param index2
 */
template <typename T>
void MySet<T>::swap(size_t index, size_t index2)
{
    T temp = items[index];
    items[index] = items[index2];
    items[index2] = temp;
    /*std::tuple<size_t, size_t> temp(items[i+1], items[i]);
    std::tuple<size_t, size_t> temp2(items[i], items[i+1]);
    temp.swap(temp2);*/
}

/**
 * Default constructor
 */
template<typename T>
MySet<T>::MySet() : MySet(DEFAULT_CAPACITY) {}

/**
 * Capacity constructor
 * Initializes the set's capacity
 * @param capacity
 */
template<typename T>
MySet<T>::MySet(const size_t capacity)
{
    this->capacity = capacity;
    size = 0;
    items = new T[capacity];
}

/**
 * Destructor
 * Ensure memory allocated is freed
 */
template<typename T>
MySet<T>::~MySet()
{
    delete[] items;
}

/**
 * Indexing support
 * @param index
 * @return
 */
template <typename T>
T& MySet<T>::operator[](const size_t index)
{
    if (index >= 0 && index < size)
    {
        return items[index];
    }
    throw std::out_of_range("Index is out of range");
}

/**
 * Getter for capacity (how many slots available)
 * @return capacity
 */
template <typename T>
size_t MySet<T>::getCapacity() const
{
    return capacity;
}

/**
 * Getter for size (how many non-empty elements are in the array)
 * @return size
 */
template <typename T>
size_t MySet<T>::getSize() const
{
    return size;
}

/**
 * FIND
 * returns the index of a given element
 * returns std::string::npos if not found.
 * @param item
 * @return size_t
 */
template <typename T>
size_t MySet<T>::find(T item) const
{
    for(size_t i = 0; i < size; i++)
    {
        T element = items[i];
        if(element == item)
        {
            return i;
        }
    }
    return std::string::npos;
}

/**
 * INSERT
 * Inserts an item at the end of the array
 * @param item
 */
template <typename T>
void MySet<T>::insert(T item)
{
    insert(size, item);
}

/**
 * INSERT
 * Inserts an item at a specified index
 * (no duplicates allowed)
 * @param index
 * @param item
 */
template <typename T>
void MySet<T>::insert(size_t index, T item)
{
    if(find(item) == std::string::npos)
    {
        if(index > size)
        {
            throw std::out_of_range("Index is out of range");
        }
        if(size+1 >= capacity)
        {
            grow();
        }
        size++;
        for(size_t i = size-1; i > index; i--)
        {
            items[i] = items[i-1];
        }
        items[index] = item;
    }
}

/**
 * REMOVE
 * Removes a specific element
 * @param item
 */
template <typename T>
void MySet<T>::remove(T item)
{
    const size_t index = find(item);
    if(index != std::string::npos)
    {
        removeAt(index);
        std::cout << item << " has been removed." << std::endl;
    }
    else
    {
        std::cout << item << " not found." << std::endl;
    }
}

/**
 * REMOVE AT
 * Removes an element at a specified index
 * @param index
 */
template <typename T>
void MySet<T>::removeAt(const size_t index)
{
    for(size_t i = index; i < size - 1; i++)
    {
        items[i] = items[i+1];
    }
    if(--size < capacity / 4)
    {
        shrink();
    }
}

/**
 * CLEAR
 * Clears the set
 */
template <typename T>
void MySet<T>::clear()
{
    delete[] items;
    items = new T[DEFAULT_CAPACITY];
    capacity = DEFAULT_CAPACITY;
    size = 0;
}

/**
 * TOSTRING
 * Returns the contents of the set as a string
 * @return string
 */
template <typename T>
std::string MySet<T>::toString() const
{
    std::string x = "[";
    for(size_t i = 0; i < size; i++)
    {
        if(i == size-1) x += std::to_string(items[i]);

        else x += std::to_string(items[i]) + ", ";
    }
    x += "]";
    return x;
}

/**
 * GROW
 * Increases the capacity of the array
 */
template <typename T>
void MySet<T>::grow()
{
    capacity = capacity == 0 ? 1 : size * 2;
    T* tempArray = new T[capacity];
    for(size_t i = 0; i < size; i++)
    {
        tempArray[i] = items[i];
    }
    delete[] items; //This deletes the old array
    items = tempArray;
}

/**
 * SHRINK
 * Decreases the capacity of the array
 */
template <typename T>
void MySet<T>::shrink()
{
    capacity = size / 2;
    T* tempArray = new T[capacity];

    for(size_t i = 0; i < size; i++)
    {
        tempArray[i] = items[i];
    }
    delete[] items;
    items = tempArray;
}

/**
 * BUBBLE SORT
 * Sorting algorithm that repeatedly steps through the input list
 * ...element-by-element, comparing the current element with the one after it,
 * ...swapping their values if needed
 */
template <typename T>
void MySet<T>::bubbleSort()
{
    bool sorted = false;
    size_t unsortedUntilIndex = size - 1;
    while(!sorted)
    {
        sorted = true;
        for(size_t i = 0; i < unsortedUntilIndex; i++)
        {
            if(items[i]>items[i+1])
            {
                swap(i, i+1);
                sorted = false;
            }
        }
        --unsortedUntilIndex;
    }
}

/**
 * INSERTION SORT
 * Sorting algorithm that builds the final sorted array
 * ...one item at a time by comparisons
 */
template <typename T>
void MySet<T>::insertionSort()
{
    for(size_t i = 1; i < size; i++)
    {
        T temp = items[i];
        size_t j = i-1;
        for(; j != std::string::npos && (items[j]>temp); j--)
            //for(; j != std::string::npos && i >= 1 && (items[j]-temp > 0); j--)
        {
            items[j+1] = items[j];
        }
        items[j+1] = temp;
    }
}

/**
 * SELECTION SORT
 * Comparison based sorting algorithm
 * Sorts an array by repeatedly selecting the largest element
 * ... from the unsorted portion and swapping it with the first unsorted element.
 */
template <typename T>
void MySet<T>::selectionSort()
{
    for(size_t i = 0; i < size-1; i++)
    {
        size_t minIndex = i;
        for(size_t j = i+1; j < size; j++)
        {
            if(items[j] < items[minIndex])
            {
                minIndex = j;
            }
        }
        if(minIndex != i)
        {
            swap(i, minIndex);
        }
    }
}

/**
 * BIDIRECTIONAL BUBBLE SORT
 * Modification of bubble sort
 * Inner loop first carries the largest item from left to right
 * ... then it will reverse and carry the smallest item from right to left
 */
template <typename T>
void MySet<T>::bidirectionalBubbleSort()
{
    bool sorted = false;
    size_t unsortedUntilIndex = size - 1;
    size_t startIndex = 0;
    while(!sorted)
    {
        sorted = true;
        for(size_t i = startIndex; i < unsortedUntilIndex; ++i)
        {
            if(items[i]>items[i+1])
            {
                swap(i, i+1);
                sorted = false;
            }
        }
        if(sorted) break;
        sorted = true;
        --unsortedUntilIndex;
        for(size_t i = unsortedUntilIndex-1; i >= startIndex && i != std::string::npos; --i)
        {
            if(items[i] > items[i+1])
            {
                swap(i, i+1);
                sorted = false;
            }
        }
        ++startIndex;
    }
}

/**
 * MEDIAN
 * Returns the median value in the set
 * @return T
 */
template <typename T>
float MySet<T>::median() const
{
    if(size%2 == 0)
    {
        return (items[size/2] + items[size/2-1]) / 2;
    }
    return items[size/2];
}

/**
 * ODD EVEN
 * Repeatedly passes through the array's even and odd indices
 * Swapping as necessary
 */
template <typename T>
void MySet<T>::oddEven()
{
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(size_t i = 1; i < size-1; i = i + 2)
        {
            if(items[i] > items[i+1])
            {
                swap(i, i+1);
                sorted = false;
            }
        }
        for(size_t i = 0; i < size-1; i = i + 2)
        {
            if(items[i] > items[i+1])
            {
                swap(i, i+1);
                sorted = false;
            }
        }
    }
}

/**
 * VERBOSE INSERTION SORT
 * Modified insertion sort that counts the number of copies and the number of comparisons
 * ... it makes during a sort and displays the totals.
 */
template <typename T>
void MySet<T>::insertionSortVerbose()
{
    int copies = size-1;
    int comparisons = 0;
    for(size_t i = 1; i < size; i++)
    {
        T temp = items[i];
        size_t j = i-1;
        for(; j != std::string::npos && i >= 1 && (items[j]>temp); j--, comparisons++)
        {
            items[j+1] = items[j];
        }
        items[j+1] = temp;
    }
    std::cout<<"Copies: "<<copies<<"\n"<<"Comparisons: "<<comparisons<<std::endl;
}



