#include "../Algorithms/Algorithms.h"
#include <gtest/gtest.h>
#include <iostream>
#include <limits.h>

using namespace std;

void printIntegers(vector<int> & nums){
    for(auto integer : nums){
        cout << integer << endl;
    }
}

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
    EXPECT_TRUE(pivot(singleArray, 0, 0) == 0);

    int emptyArray[] = {};
    EXPECT_NO_THROW(pivot(emptyArray, 0, 0) == 0);
}

TEST(AlgorithmsTest, QuickSortTest){
    int myArray[] = {4, 6, 1, 7, 3, 2, 5};
    vector<int> expected_values = {1, 2, 3, 4, 5, 6};

    EXPECT_NO_THROW(quickSort(myArray, 0, (sizeof(myArray)/ sizeof(myArray[0]) - 1)));

    cout << "Print items in myArray" << endl;
    for (auto item : myArray){
        cout << item << endl;
    }

    for(int i = 0; i < (sizeof(myArray)/ sizeof(myArray[0])) - 1; i++){
        cout << "i: " << i << endl;
        EXPECT_TRUE(myArray[i] == expected_values[i]);
    }
}

TEST(AlgorithmsTest, RemoveElement){
    cout << "Remove Elements Test Two Elements" << endl;
    vector<int> nums = {3, 1};
    vector<int> expected_values = {1};
    int index;
    // printIntegers(nums);

    EXPECT_NO_THROW(removeElement(nums, 3));
    EXPECT_TRUE(nums[0] == 1);
    EXPECT_TRUE(nums.size() == 1);

    printIntegers(nums);
    
    // cout << "Remove Elements Test One Element Remove" << endl;
    nums = {10};
    expected_values = {};
    printIntegers(nums);

    EXPECT_NO_THROW(removeElement(nums, 10));
    EXPECT_TRUE(nums.size() == 0);
    for(index = 0; index < expected_values.size(); index++){
        EXPECT_TRUE(expected_values[index] == nums[index]);
    }

    // printIntegers(nums);

    // cout << "Remove Elements Test One Element Non-remove" << endl;
    nums = {1};
    
    // printIntegers(nums);

    EXPECT_NO_THROW(removeElement(nums, 3));
    EXPECT_TRUE(nums.size() == 1);
    EXPECT_TRUE(nums[0] == 1);

    // printIntegers(nums);

    // cout << "Remove Elements Test Empty Vector" << endl;
    nums = {};
    
    // printIntegers(nums);
    EXPECT_NO_THROW(removeElement(nums, 3));
    EXPECT_TRUE(nums.size() == 0);

    // printIntegers(nums);

    cout << "Remove Elements Test Multiple Elements" << endl;
    nums = {3, 2, 3, 6, 3, 4, 5, 3};
    
    printIntegers(nums);

    EXPECT_NO_THROW(removeElement(nums, 3));
    EXPECT_TRUE(nums.size() == 4);
    EXPECT_TRUE(nums[0] == 2);
    EXPECT_TRUE(nums[1] == 6);
    EXPECT_TRUE(nums[2] == 4);
    EXPECT_TRUE(nums[3] == 5);

    printIntegers(nums);

    cout << " Test All Elements are Target" << endl;
    nums = {3, 3, 3, 3};
    
    // printIntegers(nums);

    EXPECT_NO_THROW(removeElement(nums, 3));
    EXPECT_TRUE(nums.size() == 0);

    // printIntegers(nums);

    // cout << "Multiple Target Elements" << endl;
    nums = {1, 10, 2, 10, 3, 10, 4, 10, 5};
    expected_values = {1, 2, 3, 4, 5};
    
    // printIntegers(nums);

    EXPECT_NO_THROW(removeElement(nums, 10));
    EXPECT_TRUE(nums.size() == 5);
    for (index = 0; index < expected_values.size(); index++){
        EXPECT_TRUE(expected_values[index] == nums[index]);
    }

    // printIntegers(nums);


    // cout << "Test Target at Elements at End" << endl;
    nums = {1, 2, 3, 10, 10};
    expected_values = {1, 2, 3};
    
    // printIntegers(nums);

    EXPECT_NO_THROW(removeElement(nums, 10));
    EXPECT_TRUE(nums.size() == 3);
    // cout << "Compare Values" << endl;
    for (index = 0; index < expected_values.size(); index++){
        EXPECT_TRUE(expected_values[index] == nums[index]);
    }

    // printIntegers(nums);

    cout << "Test Target at Elements at Beginning" << endl;
    nums = {10, 10, 1, 2, 3};
    expected_values = {1, 2, 3};
    
    printIntegers(nums);

    EXPECT_NO_THROW(removeElement(nums, 10));
    EXPECT_TRUE(nums.size() == 3);
    // cout << "Compare Values" << endl;
    for (index = 0; index < expected_values.size(); index++){
        EXPECT_TRUE(expected_values[index] == nums[index]);
    }

    printIntegers(nums);
}