#include "Algorithms.h"

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

