#include "../Algorithms/Algorithms.h"
#include <gtest/gtest.h>
#include <iostream>
#include <limits.h>
#include <string>
#include <vector>

using namespace std;

void printVector(vector<int> & nums){
    for(auto integer : nums){
        cout << integer << endl;
    }
}

void printVector(const vector<string>& strings) {
    cout << "[ ";
    for (const auto& str : strings) {
        cout << "\"" << str << "\" ";
    }
    cout << "]";
}

void printVector(const vector<int>& nums, int newSize = -1) {
    cout << "[";
    int sizeToPrint = (newSize == -1) ? nums.size() : newSize;
    for (int i = 0; i < sizeToPrint; i++) {
        cout << nums[i];
        if (i < sizeToPrint - 1) {
            cout << ", ";
        }
    }
    cout << "]";
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
    // printVector(nums);

    EXPECT_NO_THROW(removeElement(nums, 3));
    EXPECT_TRUE(nums[0] == 1);
    EXPECT_TRUE(nums.size() == 1);

    printVector(nums);
    
    // cout << "Remove Elements Test One Element Remove" << endl;
    nums = {10};
    expected_values = {};
    printVector(nums);

    EXPECT_NO_THROW(removeElement(nums, 10));
    EXPECT_TRUE(nums.size() == 0);
    for(index = 0; index < expected_values.size(); index++){
        EXPECT_TRUE(expected_values[index] == nums[index]);
    }

    // printVector(nums);

    // cout << "Remove Elements Test One Element Non-remove" << endl;
    nums = {1};
    
    // printVector(nums);

    EXPECT_NO_THROW(removeElement(nums, 3));
    EXPECT_TRUE(nums.size() == 1);
    EXPECT_TRUE(nums[0] == 1);

    // printVector(nums);

    // cout << "Remove Elements Test Empty Vector" << endl;
    nums = {};
    
    // printVector(nums);
    EXPECT_NO_THROW(removeElement(nums, 3));
    EXPECT_TRUE(nums.size() == 0);

    // printVector(nums);

    cout << "Remove Elements Test Multiple Elements" << endl;
    nums = {3, 2, 3, 6, 3, 4, 5, 3};
    
    printVector(nums);

    EXPECT_NO_THROW(removeElement(nums, 3));
    EXPECT_TRUE(nums.size() == 4);
    EXPECT_TRUE(nums[0] == 2);
    EXPECT_TRUE(nums[1] == 6);
    EXPECT_TRUE(nums[2] == 4);
    EXPECT_TRUE(nums[3] == 5);

    printVector(nums);

    cout << " Test All Elements are Target" << endl;
    nums = {3, 3, 3, 3};
    
    // printVector(nums);

    EXPECT_NO_THROW(removeElement(nums, 3));
    EXPECT_TRUE(nums.size() == 0);

    // printVector(nums);

    // cout << "Multiple Target Elements" << endl;
    nums = {1, 10, 2, 10, 3, 10, 4, 10, 5};
    expected_values = {1, 2, 3, 4, 5};
    
    // printVector(nums);

    EXPECT_NO_THROW(removeElement(nums, 10));
    EXPECT_TRUE(nums.size() == 5);
    for (index = 0; index < expected_values.size(); index++){
        EXPECT_TRUE(expected_values[index] == nums[index]);
    }

    // printVector(nums);


    // cout << "Test Target at Elements at End" << endl;
    nums = {1, 2, 3, 10, 10};
    expected_values = {1, 2, 3};
    
    // printVector(nums);

    EXPECT_NO_THROW(removeElement(nums, 10));
    EXPECT_TRUE(nums.size() == 3);
    // cout << "Compare Values" << endl;
    for (index = 0; index < expected_values.size(); index++){
        EXPECT_TRUE(expected_values[index] == nums[index]);
    }

    // printVector(nums);

    cout << "Test Target at Elements at Beginning" << endl;
    nums = {10, 10, 1, 2, 3};
    expected_values = {1, 2, 3};
    
    printVector(nums);

    EXPECT_NO_THROW(removeElement(nums, 10));
    EXPECT_TRUE(nums.size() == 3);
    // cout << "Compare Values" << endl;
    for (index = 0; index < expected_values.size(); index++){
        EXPECT_TRUE(expected_values[index] == nums[index]);
    }

    printVector(nums);
}

TEST(AlgorithmsTest, FindMaxMinTest){
        // cout << "\n----- Test: SingleElement -----\n";
        vector<int> nums = {5};
        vector<int> result = findMaxMin(nums);
        vector<int> expected = {5, 5};
        // cout << "Input: "; printVector(nums); cout << "\n";
        // cout << "Output: "; printVector(result); cout << "\n";
        EXPECT_TRUE(result == expected);
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: AscendingOrder -----\n";
        nums = {1, 2, 3, 4, 5};
        result = findMaxMin(nums);
        expected = {5, 1};
        // cout << "Input: "; printVector(nums); cout << "\n";
        // cout << "Output: "; printVector(result); cout << "\n";
        EXPECT_TRUE(result == expected);
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: DescendingOrder -----\n";
        nums = {5, 4, 3, 2, 1};
        result = findMaxMin(nums);
        expected = {5, 1};
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(nums); cout << "\n";
        // cout << "Output: "; printVector(result); cout << "\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: RandomOrder -----\n";
        nums = {3, 5, 1, 4, 2};
        result = findMaxMin(nums);
        expected = {5, 1};
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(nums); cout << "\n";
        // cout << "Output: "; printVector(result); cout << "\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: AllSameElements -----\n";
        nums = {3, 3, 3, 3, 3};
        result = findMaxMin(nums);
        expected = {3, 3};
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(nums); cout << "\n";
        // cout << "Output: "; printVector(result); cout << "\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: PositiveAndNegative -----\n";
        nums = {-3, 5, -1, 4, 2};
        result = findMaxMin(nums);
        expected = {5, -3};
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(nums); cout << "\n";
        // cout << "Output: "; printVector(result); cout << "\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: OnlyNegative -----\n";
        nums = {-3, -5, -1, -4, -2};
        result = findMaxMin(nums);
        expected = {-1, -5};
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(nums); cout << "\n";
        // cout << "Output: "; printVector(result); cout << "\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");
}

TEST(AlgorithmsTest, LongestStringTest){
        // cout << "\n----- Test: SingleString -----\n";
        vector<string> stringList = {"apple"};
        string result = findLongestString(stringList);
        string expected = "apple";
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(stringList); cout << "\n";
        // cout << "Output: \"" << result << "\"\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: FirstStringIsLongest -----\n";
        stringList = {"watermelon", "apple", "banana"};
        result = findLongestString(stringList);
        expected = "watermelon";
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(stringList); cout << "\n";
        // cout << "Output: \"" << result << "\"\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");


        cout << "\n----- Test: LastStringIsLongest -----\n";
        stringList = {"apple", "banana", "watermelon"};
        result = findLongestString(stringList);
        expected = "watermelon";
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(stringList); cout << "\n";
        // cout << "Output: \"" << result << "\"\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        cout << "\n----- Test: MiddleStringIsLongest -----\n";
        stringList = {"apple", "watermelon", "banana"};
        result = findLongestString(stringList);
        expected = "watermelon";
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(stringList); cout << "\n";
        // cout << "Output: \"" << result << "\"\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        cout << "\n----- Test: AllStringsSameLength -----\n";
        stringList = {"apple", "melon", "fruit"};
        result = findLongestString(stringList);
        expected = "apple"; // since "apple" is the first string of that length
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(stringList); cout << "\n";
        // cout << "Output: \"" << result << "\"\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        cout << "\n----- Test: EmptyList -----\n";
        stringList = {};
        result = findLongestString(stringList);
        expected = "";
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(stringList); cout << "\n";
        // cout << "Output: \"" << result << "\"\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        cout << "\n----- Test: SomeEmptyStrings -----\n";
        stringList = {"apple", "", "banana", ""};
        result = findLongestString(stringList);
        expected = "banana";
        EXPECT_TRUE(result == expected);
        // cout << "Input: "; printVector(stringList); cout << "\n";
        // cout << "Output: \"" << result << "\"\n";
        // cout << (result == expected ? "PASS\n" : "FAIL\n");

        cout << "\n----- Test: DifferentCharacterStrings -----\n";
        stringList = {"12345", "b@n@n@", "apple!"};
        result = findLongestString(stringList);
        expected = "b@n@n@";
        EXPECT_TRUE(result == expected);
        cout << "Input: "; printVector(stringList); cout << "\n";
        cout << "Output: \"" << result << "\"\n";
        cout << (result == expected ? "PASS\n" : "FAIL\n");
}

TEST(AlgorithmsTest, RemoveDuplicatesTest){
        // cout << "\n----- Test: EmptyList -----\n";
        vector<int> nums = {};
        vector<int> expected_values = {};
        // cout << "Before: "; printVector(nums); cout << "\n";
        int newSize = removeDuplicates(nums);
        EXPECT_TRUE(newSize == 0);
        EXPECT_TRUE(nums.empty());
        // cout << "After: "; printVector(nums, newSize); cout << "\n";
        // cout << (newSize == 0 && nums.empty() ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: SingleElement -----\n";
        nums = {5};
        // cout << "Before: "; printVector(nums); cout << "\n";
        newSize = removeDuplicates(nums);
        EXPECT_TRUE(nums[0] == 5);
        EXPECT_TRUE(newSize == 1);
        EXPECT_TRUE(nums.size() == 1);
        // cout << "After: "; printVector(nums, newSize); cout << "\n";
        // cout << (newSize == 1 && nums[0] == 5 ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: MultipleDuplicates -----\n";
        nums = {1, 1, 1, 2, 2, 3, 4, 4, 4};
        // cout << "Before: "; printVector(nums); cout << "\n";
        newSize = removeDuplicates(nums);
        expected_values = {1, 2, 3, 4};
        EXPECT_TRUE(newSize == 4);
        EXPECT_TRUE(nums == expected_values);
        EXPECT_TRUE(nums.size() == 4);

        // cout << "After: "; printVector(nums, newSize); cout << "\n";
        // if (newSize == 4 && nums[0] == 1 && nums[1] == 2 && nums[2] == 3 && nums[3] == 4) {
            // cout << "PASS\n";
        // } else {
            // cout << "FAIL\n";
        // }

        // cout << "\n----- Test: NoDuplicates -----\n";
        nums = {1, 2, 3, 4, 5};
        // cout << "Before: "; printVector(nums); cout << "\n";
        newSize = removeDuplicates(nums);
        expected_values = {1, 2, 3, 4, 5};
        EXPECT_TRUE(newSize == 5);
        EXPECT_TRUE(nums.size() == 5);
        EXPECT_TRUE(nums == expected_values);
        // cout << "After: "; printVector(nums, newSize); cout << "\n";
        // bool pass = true;
        // if (newSize != 5) {
            // pass = false;
        // } else {
            // for (int i = 0; i < newSize; i++) {
                // if (nums[i] != i + 1) {
                    // pass = false;
                    // break;
                // }
            // }
        // }
        // cout << (pass ? "PASS\n" : "FAIL\n");
}