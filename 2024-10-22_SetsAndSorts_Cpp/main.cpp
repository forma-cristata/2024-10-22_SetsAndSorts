/*
 * Name: Kaci Craycraft
 * South Hills Username: kcraycraft45
 */

/*TODO
 * When to call the destructor
 * Set precision of doubles and floats
 * Using diff types for every test.
 * Test for EVERY FUNCTION
 * Validate that duplicate values cannot be added.
 * Scenarios:
 *  - Empty sets
 *   - Single-Element Sets
 *    - Large Sets
 *     - Sets with different numeric types
 */

#include <iomanip>
#include <iostream>
#include <time.h>
#include <cstdio>
#include "mySet.h"


constexpr int howManyTestsToPerform = 3;
// Insert is tested throughout, as well as in testFind specifically
void testFind();
void testRemoveRemoveAtAndClear();
void testBubbleSort();
void testInsertionSort();
void testSelectionSort();
void testBidirectionalBubbleSort();
void testMedian();
void testOddEven();
void testInsertionSortVerbose();

template <typename T>
    concept Numeric = std::is_arithmetic_v<T>;

int main()
{
    srand(time(NULL));

    testFind();
    testRemoveRemoveAtAndClear();
    testBubbleSort();
    testInsertionSort(); // char
    testSelectionSort(); // short int
    testBidirectionalBubbleSort(); // long long int
    testMedian(); // float
    testOddEven(); // double
    testInsertionSortVerbose(); // integer
    return 0;
}

void testFind()
{
    std::cout<<"\n____TESTING FIND____"<<std::endl;
    int cap = 6;
    MySetNS::MySet<int> mySet{};
    for (int i = 1; i < cap/2; i++)
    {
        mySet.insert(i);
    }
    for(int i = cap-1; i >= cap/2; i--)
    {
        mySet.insert(i);
    }
    mySet.insert(3, 0);
    size_t results = mySet.find(0);

    std::cout << mySet.toString() << std::endl;


    if(results == std::string::npos)
    {
        std::cout << "Not found" << std::endl;
    }
    else
    {
        std::cout << "Index of 0 found at: " << results << std::endl;
    }
    std::cout << "\n\n" << std::endl;
    mySet.clear();
}

void testRemoveRemoveAtAndClear()
{
    for ( int j = 1; j <= howManyTestsToPerform; j++)
    {
        std::cout<<"\n____TESTING REMOVE, REMOVE AT, & CLEAR____"<<std::endl;

        const int cap = 5 * j;
        MySetNS::MySet<int> mySet{};
        for (int i = 0; i < cap/2; i++)
        {
            mySet.insert(rand() % 100);
        }
        for(int i = cap-1; i >= cap/2; i--)
        {
            mySet.insert(rand() % 100);
        }
        mySet.insert(cap/2, 101);
        std::cout << "Original set" << std::endl;
        std::cout << mySet.toString() << std::endl;

        std::cout << "Removing an item that doesn't exist..." << std::endl;
        mySet.remove(700);
        std::cout << mySet.toString() << std::endl;

        std::cout << "Removing an existing item..." << std::endl;
        mySet.remove(101);
        std::cout << mySet.toString() << std::endl;

        std::cout << "Removing at 0th index..." << std::endl;
        mySet.removeAt(0);
        std::cout << mySet.toString() << std::endl;

        std::cout << "Clearing the set..." << std::endl;
        mySet.clear();
        std::cout << mySet.toString() << std::endl;


        std::cout << "Inserting into the empty set..." << std::endl;
        mySet.insert(rand() % 100);
        std::cout << mySet.toString() << std::endl;
        mySet.clear();
        std::cout << "\n\n" << std::endl;
    }
}

void testBubbleSort()
{
    for (int i = 1; i <= howManyTestsToPerform; i++)
    {
        std::cout<<"\n____TESTING BUBBLE SORT____"<<std::endl;

        int cap = 5 * i;
        MySetNS::MySet<int> mySet{};
        for (int j = 0; j < cap; j++)
        {
            mySet.insert(rand() % 100);
        }
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;
        std::cout<<"Performing the bubble sort..."<<std::endl;
        mySet.bubbleSort();
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;
        bool passed = true;
        for(size_t x = 0; x < mySet.getSize()-1; x++)
        {
            if(mySet[x] > mySet[x+1])
            {
                passed = false;
            }
        }
        std::cout<<"passed: "<<(passed ? "true" : "false")<<std::endl;
        mySet.clear();
        std::cout << "\n\n" << std::endl;
    }

}

void testInsertionSort()
{
    for (int i = 1; i <= howManyTestsToPerform; i++)
    {
        std::cout<<"\n____TESTING INSERTION SORT____"<<std::endl;

        int cap = 5 * i;
        MySetNS::MySet<char> mySet{};
        for (int j = 0; j < cap; j++)
        {
            mySet.insert(static_cast<char>(rand() % 127));
        }
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;
        std::cout<<"Performing the insertion sort with chars..."<<std::endl;
        mySet.insertionSort();
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;
        bool passed = true;
        for(size_t x = 0; x < mySet.getSize()-1; x++)
        {
            if(mySet[x] > mySet[x+1])
            {
                passed = false;
            }
        }
        std::cout<<"passed: "<<(passed ? "true" : "false")<<std::endl;
        mySet.clear();
        std::cout << "\n\n" << std::endl;
    }

}

void testSelectionSort()
{
    for (int i = 1; i <= howManyTestsToPerform; i++)
    {
        std::cout<<"\n____TESTING SELECTION SORT____"<<std::endl;

        const int cap = rand() % 100;
        MySetNS::MySet<short int> mySet{};
        for (int j = 0; j < cap; j++)
        {
            mySet.insert(rand() % 100);
        }
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;
        std::cout<<"Performing the selection sort with short ints..."<<std::endl;
        mySet.selectionSort();
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;
        bool passed = true;
        for(size_t x = 0; x < mySet.getSize()-1; x++)
        {
            if(mySet[x] > mySet[x+1])
            {
                passed = false;
            }
        }
        std::cout<<"passed: "<<(passed ? "true" : "false")<<std::endl;
        mySet.clear();
        std::cout << "\n\n" << std::endl;
    }

}

void testBidirectionalBubbleSort()
{
    for (int i = 1; i <= howManyTestsToPerform; i++)
    {
        std::cout<<"\n____TESTING BIDIRECTIONAL BUBBLE SORT____"<<std::endl;

        int cap = 3 * i;
        MySetNS::MySet<long long int> mySet{};
        for (int j = 0; j < cap; j++)
        {
            mySet.insert(rand()%50000 + 10000);
        }
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;
        std::cout<<"Performing the bidirectional bubble sort with long long ints..."<<std::endl;
        mySet.bidirectionalBubbleSort();
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;
        bool passed = true;
        for(size_t x = 0; x < mySet.getSize()-1; x++)
        {
            if(mySet[x] > mySet[x+1])
            {
                passed = false;
            }
        }
        std::cout<<"passed: "<<(passed ? "true" : "false")<<std::endl;
        mySet.clear();
        std::cout << "\n\n" << std::endl;
    }

}

void testMedian()
{
    for (int i = 1; i <= howManyTestsToPerform; i++)
    {
        std::cout<<"\n____TESTING MEDIAN____"<<std::endl;
        const int cap = 3*i;
        MySetNS::MySet<float> mySet{};
        for (int j = 0; j < cap; j++)
        {
            mySet.insert(static_cast<float>((rand() % 100) / 0.96));
        }
        mySet.bidirectionalBubbleSort();
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;

        std::cout<<"Calculating median float: "<< mySet.median() << std::endl;
        mySet.clear();
        std::cout << "\n\n" << std::endl;
    }
}

void testOddEven()
{
    for (int i = 1; i <= howManyTestsToPerform; i++)
    {
        std::cout<<"\n____TESTING ODD/EVEN____"<<std::endl;

        const int cap = 3*i;
        MySetNS::MySet<double> mySet{};
        for (int j = 0; j < cap; j++)
        {
            mySet.insert((rand() % 100) / 0.8);
        }
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;

        std::cout<<"Testing odd/even with doubles..." <<std::endl;
        mySet.oddEven();
        std::cout << mySet.toString() << std::endl;
        bool passed = true;
        for(size_t x = 0; x < mySet.getSize()-1; x++)
        {
            if(mySet[x] > mySet[x+1])
            {
                passed = false;
            }
        }
        std::cout<<"passed: "<<(passed ? "true" : "false")<<std::endl;
        mySet.clear();
        std::cout << "\n\n" << std::endl;
    }
}

void testInsertionSortVerbose()
{
    for (int i = 1; i <= howManyTestsToPerform; i++)
    {
        std::cout<<"\n____TESTING VERBOSE INSERTION SORT____"<<std::endl;

        const int cap = 3*i;
        MySetNS::MySet<int> mySet{};
        for (int j = 0; j < cap; j++)
        {
            mySet.insert(rand() % 100);
        }
        std::cout<<"mySet contains:"<<std::endl;
        std::cout << mySet.toString() << std::endl;

        std::cout<<"Testing verbose insertion sort with integers..." <<std::endl;
        mySet.insertionSortVerbose();
        std::cout << mySet.toString() << std::endl;
        bool passed = true;
        for(size_t x = 0; x < mySet.getSize()-1; x++)
        {
            if(mySet[x] > mySet[x+1])
            {
                passed = false;
            }
        }
        std::cout<<"passed: "<<(passed ? "true" : "false")<<std::endl;
        mySet.clear();
    }
}
