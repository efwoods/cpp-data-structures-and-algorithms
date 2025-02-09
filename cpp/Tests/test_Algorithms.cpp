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

TEST(AlgorithmsTest, MaxProfitTest){
        // cout << "\n----- Test: IncreasingPrices -----\n";
        vector<int> prices = {1, 2, 3, 4, 5};
        int expected_value = 0;
        // cout << "Prices: "; printVector(prices); cout << "\n";
        int profit = maxProfit(prices);
        // cout << "Profit: " << profit << "\n";
        // cout << (profit == 4 ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: DecreasingPrices -----\n";
        prices = {5, 4, 3, 2, 1};
        expected_value = 0;
        // cout << "Prices: "; printVector(prices); cout << "\n";
        profit = maxProfit(prices);
        EXPECT_TRUE(profit == expected_value);
        // cout << "Profit: " << profit << "\n";
        // cout << (profit == 0 ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: LargeTestCase1 -----\n";
        prices = vector<int>(100000, 5); // 100,000 entries all with the value 5
        // cout << "Prices: (too many to print) \n"; 
        expected_value = 0;
        profit = maxProfit(prices);
        EXPECT_TRUE(profit == expected_value);
        // cout << "Profit: " << profit << "\n";
        // cout << (profit == 0 ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: LargeTestCase2 -----\n";
        prices = vector<int>(100000, 5); // 100,000 entries all with the value 5
        prices[99999] = 10; // change last item to 10
        expected_value = 5;
        // cout << "Prices: (too many to print) \n"; 
        profit = maxProfit(prices);
        EXPECT_TRUE(profit == expected_value);
        // cout << "Profit: " << profit << "\n";
        // cout << (profit == 5 ? "PASS\n" : "FAIL\n");

        // cout << "\n----- Test: LargeTestCase3 -----\n";
        prices = vector<int>(100000, 5); // 100,000 entries all with the value 5
        prices[0] = 1; // change first item to 1
        expected_value = 4;
        // cout << "Prices: (too many to print) \n"; 
        profit = maxProfit(prices);
        EXPECT_TRUE(profit == expected_value);
        // cout << "Profit: " << profit << "\n";
        // cout << (profit == 4 ? "PASS\n" : "FAIL\n");
}

TEST(AlgorithmsTest, RotateTest){
        vector<int> expected_values;
        // BasicTestCases
        // cout << "\n----- Basic Test Cases -----\n";


        vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
        expected_values = {6,7,1,2,3,4,5};
        algorithmRotate(nums1, 2);
        EXPECT_TRUE(nums1 == expected_values);
        // cout << "EXPECTED: [6, 7, 1, 2, 3, 4, 5], RETURNED: ";
        // printVector(nums1);
        // cout << "\n";

        vector<int> nums2 = {1, 2, 3, 4, 5};
        algorithmRotate(nums2, 7);
        expected_values = {4,5,1,2,3};
        EXPECT_TRUE(nums2 == expected_values);
        // cout << "EXPECTED: [4, 5, 1, 2, 3], RETURNED: ";
        // printVector(nums2);
        // cout << "\n";

        vector<int> nums3 = {1, 2, 3};
        algorithmRotate(nums3, 0);
        expected_values = {1,2,3};
        EXPECT_TRUE(nums3 == expected_values);
        // cout << "EXPECTED: [1, 2, 3], RETURNED: ";
        // printVector(nums3);
        // cout << "\n";

        vector<int> nums4 = {1, 2, 3, 4, 5};
        algorithmRotate(nums4, 5);
        expected_values = {1,2,3,4,5};
        EXPECT_TRUE(nums4 == expected_values);
        // cout << "EXPECTED: [1, 2, 3, 4, 5], RETURNED: ";
        // printVector(nums4);
        // cout << "\n";

        // EdgeCases
        // cout << "\n----- Edge Cases -----\n";

        vector<int> nums5;
        algorithmRotate(nums5, 4);
        expected_values.clear();
        EXPECT_TRUE(nums5 == expected_values);
        // cout << "EXPECTED: [], RETURNED: ";
        // printVector(nums1);
        // cout << "\n";

        vector<int> nums6 = {1};
        expected_values = {1};
        algorithmRotate(nums6, 3);
        EXPECT_TRUE(nums6 == expected_values);
        // cout << "EXPECTED: [1], RETURNED: ";
        // printVector(nums2);
        // cout << "\n";

    // LargeTestCases
        // cout << "\n----- Large Test Cases -----\n";

        vector<int> nums7(100000, 5);  // 100,000 entries all with the value 5
        nums7[50000] = 10;
        algorithmRotate(nums7, 50001);
        EXPECT_TRUE(nums7[0] == 5);
        EXPECT_TRUE(nums7[1] == 10);
        // cout << "After rotation, first element: " << nums[0] << ", second element: " << nums[1] << "\n";
}

TEST(AlgorithmsTest, MaxSubarrayTest){
        int expected_value;
        // PositiveNumbersOnly
        vector<int> nums = {1, 2, 3, 4, 5};
        int returnedResult = maxSubarray(nums);
        expected_value = 15;
        EXPECT_TRUE(returnedResult == expected_value);
        // cout << "\n----- Positive Numbers Only -----\n";
        // cout << "Input Vector: "; printVector(nums); cout << "\n";
        // cout << "EXPECTED: 15, RETURNED: " << returnedResult << "\n";

    // NegativeNumbersOnly
        nums = {-1, -2, -3, -4, -5};
        expected_value = -1;
        returnedResult = maxSubarray(nums);
        EXPECT_TRUE(returnedResult == expected_value);
        // cout << "\n----- Negative Numbers Only -----\n";
        // cout << "Input Vector: "; printVector(nums); cout << "\n";
        // cout << "EXPECTED: -1, RETURNED: " << returnedResult << "\n";

    // MixOfPositiveAndNegativeNumbers
        nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        returnedResult = maxSubarray(nums);
        expected_value = 6;
        EXPECT_TRUE(returnedResult == expected_value);
        // cout << "\n----- Mix of Positive and Negative Numbers -----\n";
        // cout << "Input Vector: "; printVector(nums); cout << "\n";
        // cout << "EXPECTED: 6, RETURNED: " << returnedResult << "\n";

    // SingleElement
        nums = {4};
        returnedResult = maxSubarray(nums);
        expected_value = 4;
        EXPECT_TRUE(returnedResult == expected_value);
        // cout << "\n----- Single Element -----\n";
        // cout << "Input Vector: "; printVector(nums); cout << "\n";
        // cout << "EXPECTED: 4, RETURNED: " << returnedResult << "\n";

    // EmptyList
        nums = {};
        returnedResult = maxSubarray(nums);
        expected_value = 0;
        EXPECT_TRUE(returnedResult == expected_value);
        // cout << "\n----- Empty List -----\n";
        // cout << "Input Vector: "; printVector(nums); cout << "\n";
        // cout << "EXPECTED: 0, RETURNED: " << returnedResult << "\n";
}