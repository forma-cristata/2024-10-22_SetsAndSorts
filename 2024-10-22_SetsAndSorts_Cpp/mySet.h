#ifndef IT230_PROJECT1_MYSET_H
#define IT230_PROJECT1_MYSET_H
#include <string>

namespace MySetNS
{
template<typename T>
class MySet
{
private:
    static constexpr size_t DEFAULT_CAPACITY = 4;
    size_t capacity = 0;
    size_t size = 0;
    T* items;
    /**
     * Performs swaps
     * Used in bubble and selection sorts and any variants of them
     * @param index
     * @param index2
     */
    void swap(size_t index, size_t index2);
public:
    /**
     * Default constructor
     */
    MySet();

    /**
     * Capacity constructor
     * Initializes the set's capacity
     * @param capacity
     */
    explicit MySet(size_t capacity);

    /**
     * Destructor
     * Ensure memory allocated is freed
     */
    ~MySet();

    /**
     * Indexing support
     * @param index
     * @return T&
     */
    T& operator[](size_t index);

    /**
     * Getter for capacity (how many slots available)
     * @return capacity
     */
    [[nodiscard]] size_t getCapacity() const;

    /**
     * Getter for size (how many non-empty items in the array)
     * @return size
     */
    [[nodiscard]] size_t getSize() const;

    /**
     * FIND
     * returns the index of a given element
     * returns std::string::npos if not found
     * @param item
     * @return size_t
     */
    size_t find(T item) const;

    /**
     * INSERT
     * Inserts an item at the end of the array
     * @param item
     */
    void insert(T item);

    /**
     * INSERT
     * Inserts an item at a specified index
     * (no duplicates allowed)
     * @param index
     * @param item
     */
    void insert(size_t index, T item);

    /**
     * REMOVE
     * Removes a specific element
     * @param item
     */
    void remove(T item);

    /**
     * REMOVE AT
     * Removes an element at a specified index
     * @param index
     */
    void removeAt(size_t index);

    /**
     * CLEAR
     * Clears the set
     */
    void clear();
    /**
     * TOSTRING
     * Returns the contents of the set as a string.
     * @return string
     */
    [[nodiscard]] std::string toString() const;

    /**
     * GROW
     * Increases the capacity of the array
     */
    void grow();

    /**
     * SHRINK
     * Decreases the capacity of the array
     */
    void shrink();

    /**
     * BUBBLE SORT
     * Sorting algorithm that repeatedly steps through the input list
     * ...element-by-element, comparing the current element with the one after it,
     * ...swapping their values if needed
     */
    void bubbleSort();

    /**
     * INSERTION SORT
     * Sorting algorithm that builds the final sorted array
     * ...one item at a time by comparisons
     */
    void insertionSort();

    /**
     * SELECTION SORT
     * Comparison based sorting algorithm
     * Sorts an array by repeatedly selecting the largest element
     * ... from the unsorted portion and swapping it with the first unsorted element.
     */
    void selectionSort();

    /**
     * BIDIRECTIONAL BUBBLE SORT
     * Modification of bubble sort
     * Inner loop first carries the largest item from left to right
     * ... then it will reverse and carry the smallest item from right to left
     */
    void bidirectionalBubbleSort();

    /**
     * MEDIAN
     * Returns the median value in the set
     * @return T
     */
    [[nodiscard]] float median() const;

    /**
     * ODD EVEN
     * Repeatedly passes through the array's even and odd indices
     * Swapping as necessary
     */
    void oddEven();

    /**
     * VERBOSE INSERTION SORT
     * Modified insertion sort that counts the number of copies and the number of comparisons
     * ... it makes during a sort and displays the totals.
     */
    void insertionSortVerbose();

};

template class MySet<int>;
template class MySet<short int>;
template class MySet<long int>;
template class MySet<long long int>;
template class MySet<unsigned int>;
template class MySet<unsigned long int>;
template class MySet<unsigned long long int>;
template class MySet<unsigned short int>;
template class MySet<float>;
template class MySet<double>;
template class MySet<long double>;
template class MySet<char>;
}

#endif //IT230_PROJECT1_MYSET_H
