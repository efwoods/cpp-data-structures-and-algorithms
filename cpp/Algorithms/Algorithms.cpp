#include "Algorithms.h"
#include <iostream>
#include <limits.h>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
// #include <prev>

using namespace std;

void bubbleSort(int array[], int size){
    for (int i = size -1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void selectionSort(int array[], int size){
    for (int i = 0; i < size; i++){
        int minIndex = i;
        for (int j = i +1; j < size; j++){
            if (array[j] < array[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

void insertionSort(int array[], int size){
    for (int i = 1; i < size; i++){
        int temp = array[i];
        int j = i - 1;
        while(j > -1 && temp < array[j]){
            array[j+1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}

void merge(int array[], int leftIndex, int midIndex, int rightIndex){
    int i, j, k = 0;
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    int leftArray[leftArraySize];
    int rightArray[rightArraySize];

    for (i = 0; i < leftArraySize; i++){
        leftArray[i] = array[leftIndex + i];
    }

    for (j = 0; j < rightArraySize; j++){
        rightArray[j] = array[midIndex + j +1];
    }

    for (i = 0, j = 0, k = leftIndex; k < rightIndex; k++){
        if (leftArray[i] <= rightArray[j]){
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        if (i >= leftArraySize || j >= rightArraySize){
            break;
        }
    }
    if (i >= leftArraySize){
        while(j < rightArraySize){
            k++;
            array[k] = rightArray[j];
            j++;
        }
    } else if (j >= rightArraySize){
        while(i < leftArraySize){
            k++;
            array[k] = leftArray[i];
            i++;
        }
    }
}

void mergeSort(int array[], int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex){
        return;
    }
    int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
    mergeSort(array, leftIndex, midIndex);
    mergeSort(array, midIndex+1, rightIndex);
    merge(array, leftIndex, midIndex, rightIndex);
}

int pivot(int array[], int leftIndex, int rightIndex){
    int swapIndex = leftIndex;
    int pivotIndex = leftIndex;
    int temp;

    for(int i = leftIndex + 1; i < rightIndex + 1; i++){
        if(array[i] > array[pivotIndex]){
            continue;
        } else if(array[i] < array[pivotIndex]){
            swapIndex++;
            temp = array[swapIndex];
            array[swapIndex] = array[i];
            array[i] = temp;
        }
    }
    temp = array[swapIndex];
    array[swapIndex] = array[pivotIndex];
    array[pivotIndex] = temp;
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex){
        return;
    }
    int pivotIndex = pivot(array, leftIndex, rightIndex);
    quickSort(array, leftIndex, pivotIndex - 1);
    quickSort(array, pivotIndex+1, rightIndex);
}

void removeElement(vector<int>& nums, int val){
    vector<int>::iterator j = nums.begin(); // j iterates through the array
    int size = nums.size();
    if (size == 0){
        return;
    }
    if(size == 1){
        if(nums[0] == val){
            nums.pop_back();
        }
        return;
    }
    while(j != nums.end()){
        if (*j == val){
            nums.erase(j);
        } else {
            j++;
        }
    }
}

vector<int> findMaxMin(vector<int>& myList){
    vector<int> result;
    int maximum = INT_MIN;
    int minimum = INT_MAX;

    for (int integer : myList){
        if (integer > maximum){
            maximum = integer;
        }
        if(integer < minimum){
            minimum = integer;
        }
    }
    result.push_back(maximum);
    result.push_back(minimum);
    return result;
}

string findLongestString(vector<string>& stringList){
    string longestString = "";
    for (auto string : stringList){
        if (longestString.length() < string.length()){
            longestString = string;
        }
    }
    return longestString;
}

int removeDuplicates(vector<int>& nums){
    if(nums.size() < 2){
        return nums.size();
    }

    int uniqueIntegers = 1;
    int readPointerIndex = 0;
    int currentSize = nums.size();
    auto writePointer = &nums[0];
    auto readPointer = &nums[0];
    readPointer++;
    readPointerIndex++;
    while(currentSize > 0 && readPointerIndex <= currentSize){
        while(*writePointer == *readPointer && currentSize > readPointerIndex){
            // delete(readPointer);
            readPointer++;
            readPointerIndex++;
        }
        if(readPointerIndex >= currentSize){
            for (int count = (nums.size() - uniqueIntegers); count > 0; count--){
                nums.pop_back();
            }
            return nums.size();
        } else {
            uniqueIntegers++;
            writePointer++;
            *writePointer = *readPointer;
        }
    }
    return nums.size();
}

int maxProfit(vector<int>& prices){
    if(prices.size() < 2){
        return 0;
    }

    unordered_map<int, int> pricesMap;
    auto prices_set_iter = prices.begin();
    int minPrice = INT_MAX;
    int maxProfit = 0;
    auto pricesSize = prices.size();
    unordered_set<int> unique_values;
    set<int> ordered_unique_values;
    int current_profit;
    int starting_price;
    int selling_price;

    for(int dayIndex = 0; dayIndex < pricesSize; dayIndex++, prices_set_iter++) {
        if(prices[dayIndex] < minPrice){
            minPrice = prices[dayIndex];
        }
        if(pricesMap.find(prices[dayIndex]) != pricesMap.end()){ // if the price on a given day is in the map; continue to the next day; The unordered set of subsequent prices will already acount for profits at the current price.
            continue;
        }
        unique_values.clear(); // clear the unique values
        unique_values = {prices_set_iter+1, prices.end()}; // collect all unique values that come after the current key; 
        // unique_values.insert(prices_set_iter+1, prices.end()); 
        if(unique_values.empty()){
            continue;
        }
        ordered_unique_values.clear();
        ordered_unique_values.insert(unique_values.begin(), unique_values.end()); // order the values from least to greatest
        starting_price = prices[dayIndex];
        selling_price = *prev(ordered_unique_values.end());
        current_profit = selling_price - starting_price; // calculate the profit
        pricesMap[prices[dayIndex]] = current_profit; // get the last element in the ordered set
    }

    for(auto pair : pricesMap){
        if(maxProfit < pair.second){
            maxProfit = pair.second;
        }
    }

    return maxProfit;
}

void reverse(vector<int>& nums, vector<int>::iterator leftIndexPtr,vector<int>::iterator rightIndexPtr, int arraySize){
    int temp;
    for (int counter = 0; counter < arraySize / 2; counter++){
        temp = *leftIndexPtr;
        *leftIndexPtr = *rightIndexPtr;
        *rightIndexPtr = temp;
        leftIndexPtr++;
        rightIndexPtr--;
    }
}

void algorithmRotate(vector<int>& nums, int k){
    if (nums.size() < 2 || nums.empty()){
        return;
    }
    vector<int>::iterator leftIndexPtr;
    vector<int>::iterator rightIndexPtr; 
    int arraySize;
    int rotation = k % nums.size();
    for(int iteration = 0; iteration < 3; iteration++){
        leftIndexPtr = nums.begin();
        rightIndexPtr = prev(nums.end());
        switch(iteration){
            case 0:
                arraySize = nums.size();
                break;
            case 1:
                leftIndexPtr += rotation;
                arraySize = nums.size() - rotation;
                break;
            case 2:
                arraySize = rotation;
                rightIndexPtr -= (nums.size() - rotation); // move the right pointer backwards
                break;
            default:
                break;
        }
        reverse(nums, leftIndexPtr, rightIndexPtr, arraySize);
    }
}

int max(int element, int sum){
    if (element > sum){
        return element;
    } else {
        return sum;
    }
}

int maxSubarray(vector<int>& nums){
    if(nums.empty()){
        return 0;
    }
    if(nums.size() == 1){
        return nums[0];
    }

    int current_max = nums[0];
    int overall_max = nums[0];

    for(int index = 1; index < nums.size(); index++){
        current_max = max(nums[index], current_max + nums[index]);
        overall_max = max(overall_max, current_max);
    }
    return overall_max;
}