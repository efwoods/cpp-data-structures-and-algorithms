#include "Heap.h"

int Heap::leftChild(int index){
    return 2 * index + 1;
}

int Heap::rightChild(int index){
    return 2 * index + 2;
}

int Heap::parent(int index){
    return (index - 1) / 2;
}

int Heap::swap(int index1, int index2){
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

int Heap::remove(int value){
    heap.erase(value);
    if (heap.empty()){
        return INT_MIN;
    }
}
