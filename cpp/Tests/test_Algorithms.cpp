#include "../Algorithms/Algorithms.h"
#include <gtest/gtest.h>
#include <iostream>
#include <limits.h>

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

TEST(AlgorithmsTest, MergeTest){
    int myArray[] = {1, 3, 7, 8, 2, 4, 5, 6};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;
    int midIndex = (size / 2) - 1;

    merge(myArray, leftIndex, midIndex, rightIndex);

    for (auto value : myArray) {
        cout << value << " ";
    }
}


TEST(AlgorithmsTest, MergeSortTest){
    int myArray[] = {3, 1, 4, 2};

    int size = sizeof(myArray) / sizeof(myArray[0]);
    int leftIndex = 0;
    int rightIndex = size - 1;

    mergeSort(myArray, leftIndex, rightIndex);

    for (auto value : myArray) {
        cout << value << " ";
    }
}

TEST(AlgorithmsTest, PivotTest){
    int myArray[] = {4, 6, 1, 7, 3, 2, 5};
    EXPECT_TRUE(pivot(myArray, 0, 6) == 3);

    int testArray[] = {2, 1, 3};
    EXPECT_TRUE(pivot(testArray, 0, 2) == 1);

    int singleArray[] = {1};
    EXPECT_TRUE(pivot(singleArray, 0, 0) == INT_MIN);

    int emptyArray[] = {};
    EXPECT_NO_THROW(pivot(emptyArray, 0, 0) == INT_MIN);
}