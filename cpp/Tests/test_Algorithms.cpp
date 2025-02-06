#include "../Algorithms/Algorithms.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(AlgorithmsTest, BubbleSortTest){
    int myArray[] = {6, 4, 2, 5, 1, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    EXPECT_NO_THROW(bubbleSort(myArray, size));

    for (auto value : myArray){
        cout << value << " ";
    }
}

TEST(AlgorithmsTest, SelectionSortTest){
    int myArray[] = {6, 4, 2, 5, 1, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    EXPECT_NO_THROW(selectionSort(myArray, size));

    for (auto value : myArray){
        cout << value << " ";
    }
}

TEST(AlgorithmsTest, InsertionSortTest){
    int myArray[] = {6, 4, 2, 5, 1, 3};
    int size = sizeof(myArray) / sizeof(myArray[0]);

    EXPECT_NO_THROW(insertionSort(myArray, size));

    for (auto value : myArray){
        cout << value << " ";
    }
}

