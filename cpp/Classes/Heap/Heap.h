#pragma once
#include <gtest/gtest.h>

using namespace std;

class Heap{
    private:
        // Private
        vector<int> heap;

        // Private Helper methods
        int parent(int index);
        int leftChild(int index);
        int rightChild(int index);
        void swap(int index1, int index2);

        // Declare Friend Tests to access private members
        FRIEND_TEST(HeapTest, ParentTest);
        FRIEND_TEST(HeapTest, LeftChildTest);
        FRIEND_TEST(HeapTest, RightChildTest);
        FRIEND_TEST(HeapTest, SwapTest);

    public:
        void printHeap();
        void insert(int value);
        int remove();
        void sinkDown(int value);
};