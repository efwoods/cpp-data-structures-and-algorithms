#pragma once
#include <vector>
#include <string>

using namespace std;

void bubbleSort(int array[], int size);
void selectionSort(int array[], int size);
void insertionSort(int array[], int size);
void merge(int array[], int leftIndex, int midIndex, int rightIndex);
void mergeSort(int array[], int leftIndex, int rightIndex);
int pivot(int array[], int leftIndex, int rightIndex);
void quickSort(int array[], int leftIndex, int rightIndex);
void removeElement(vector<int>& nums, int val);
vector<int> findMaxMin(vector<int>& myList);
string findLongestString(vector<string>& stringList);
int removeDuplicates(vector<int>& nums);
int maxProfit(vector<int>& prices);
void algorithmRotate(vector<int>& nums, int k);
int reverse(int array[], int leftIndex, int rightIndex);
int maxSubarray(vector<int>& nums);
int max(int element, int sum);