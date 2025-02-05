#include <gtest/gtest.h>
#include <iostream>
#include "../Heap/Heap.h"

using namespace std;

TEST(HeapTest, Constructor){
    EXPECT_NO_THROW(Heap* myHeap = new Heap());
}

TEST(HeapTest, Insert) {
    Heap* myHeap = new Heap();
    EXPECT_NO_THROW(myHeap->insert(100));
}

TEST(HeapTest, FriendTest){
    Heap* myHeap = new Heap();
    myHeap->insert(100);
    myHeap->insert(99);
    myHeap->insert(98);
    
    EXPECT_TRUE(myHeap->parent(1) == 0);
    EXPECT_TRUE(myHeap->leftChild(0) == 98);
    EXPECT_TRUE(myHeap->rightChild(0) == 99);
    EXPECT_NO_THROW(myHeap->swap(0, 1));
}

TEST(HeapTest, FriendTestParent){

}


