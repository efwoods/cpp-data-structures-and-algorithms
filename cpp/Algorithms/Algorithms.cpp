#include "Algorithms.h"
#include <iostream>
#include <limits.h>

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