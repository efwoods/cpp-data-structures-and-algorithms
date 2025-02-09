#include "Heap.h"
#include <limits.h>

int Heap::leftChild(int index){
    return 2 * index + 1;
}

int Heap::rightChild(int index){
    return 2 * index + 2;
}

int Heap::parent(int index){
    return (index - 1) / 2;
}

void Heap::swap(int index1, int index2){
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

void Heap::insert(int value){
    heap.push_back(value);
    int current = heap.size() - 1;
    while((heap[parent(current)] < heap[current]) && (current > 0)){
        swap(current, parent(current));
        current = parent(current);
    }
}

void Heap::sinkDown(int index){
    int maxIndex = index;
    while(true){
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);

        if(leftIndex < heap.size() && heap[leftIndex] > heap[rightIndex]){
            maxIndex = leftIndex;
        }

        if (rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex]){
            maxIndex = rightIndex;
        }

        if (maxIndex != index){
            swap(index, maxIndex);
            index = maxIndex;
        } else {
            return;
        }
    }
}

int Heap::remove(){
    if (heap.empty()){
        return INT_MIN;
    }

    int maxValue = heap.front();

    if(heap.size() == 1){
        heap.pop_back();
    } else {
        heap[0] = heap.back();
        heap.pop_back();
        sinkDown(0);
    }

    return maxValue;
}


int MinHeap::leftChild(int index) {
    return 2 * index + 1;
}

int MinHeap::rightChild(int index) {
    return 2 * index + 2;
}

int MinHeap::parent(int index) {
    return (index - 1) / 2;
}

void MinHeap::swap(int index1, int index2) {
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}

void MinHeap::printHeap() {
    cout << "\n[";
    for (size_t i = 0; i < heap.size(); i++) {
        cout << heap[i];
        if (i < heap.size() - 1) { 
            cout << ", ";
        }
    }
    cout << "]" << endl;
}
        
const vector<int>& MinHeap::getHeap() const {
    return heap;
}
    
void MinHeap::insert(int value){
    heap.push_back(value);  
    int current = heap.size() - 1;
    while((heap[parent(current)] > heap[current]) && (current > 0)){
        swap(current, parent(current));
        current = parent(current);
    }
}

void MinHeap::sinkDown(int index){
    int minIndex = index;
    while(true){
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);

        if(leftIndex < heap.size() && heap[leftIndex] < heap[rightIndex]){
            minIndex = leftIndex;
        }

        if (rightIndex < heap.size() && heap[rightIndex] < heap[minIndex]){
            minIndex = rightIndex;
        }

        if (minIndex != index){
            swap(index, minIndex);
            index = minIndex;
        } else {
            return;
        }
    }
}

int MinHeap::remove(){
    if (heap.empty()){
        return INT_MIN;
    }

    int minValue = heap.front();

    if(heap.size() == 1){
        heap.pop_back();
    } else {
        heap[0] = heap.back();
        heap.pop_back();
        sinkDown(0);
    }

    return minValue;
}
