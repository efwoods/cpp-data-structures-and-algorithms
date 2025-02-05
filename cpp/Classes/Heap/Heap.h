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
        FRIEND_TEST(HeapTest, FriendTest);

    public:
        void printHeap();
        void insert(int value);
        int remove(int value);
        void sinkDown(int value);
};