#include <gtest/gtest.h>
#include <iostream>
#include "../Heap/Heap.h"

using namespace std;

TEST(HeapTest, Constructor){
    EXPECT_NO_THROW({
        Heap* myHeap = new Heap();
        });
}

TEST(HeapTest, ParentTest){
    // Initialize Heap
    Heap* myHeap = new Heap();

    EXPECT_TRUE(myHeap->parent(1) == 0);
}

TEST(HeapTest, LeftChildTest){
        // Initialize Heap
    Heap* myHeap = new Heap();

    EXPECT_TRUE(myHeap->leftChild(0) == 1);
    EXPECT_TRUE(myHeap->leftChild(1) == 3);

}

TEST(HeapTest, RightChildTest){
    // Initialize Heap
    Heap* myHeap = new Heap();

    EXPECT_TRUE(myHeap->rightChild(0) == 2);
    EXPECT_TRUE(myHeap->rightChild(1) == 4);
}

TEST(HeapTest, Insert) {
    Heap* myHeap = new Heap();
    EXPECT_NO_THROW(myHeap->insert(100));
}

TEST(HeapTest, SwapTest){
    // Initialize Heap
    Heap* myHeap = new Heap();
    myHeap->insert(100);
    myHeap->insert(99);
    myHeap->insert(98);

    EXPECT_NO_THROW(myHeap->swap(2, 3));
}

TEST(HeapTest, Remove){
    // Initialize Heap
    Heap* myHeap = new Heap();
    myHeap->insert(100);
    myHeap->insert(99);
    myHeap->insert(98);

    EXPECT_TRUE(myHeap->remove() == 100);
}

TEST(HeapTest, SinkDown){
    // Initialize Heap
    Heap* myHeap = new Heap();
    myHeap->insert(100);
    myHeap->insert(99);
    myHeap->insert(98);

    EXPECT_NO_THROW(myHeap->sinkDown(0));
}