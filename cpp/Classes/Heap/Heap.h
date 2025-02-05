#pragma once
#include <gtest/gtest.h>

using namespace std;

class Heap{
    private:
        vector<int> heap;
        int parent(int index);
        int leftChild(int index);
        int rightChild(int index);
        void swap(int index1, int index2);

    public:
        void printHeap();
};