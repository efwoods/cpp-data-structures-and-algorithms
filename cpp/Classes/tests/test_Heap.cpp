#include <gtest/gtest.h>
#include <iostream>
#include "../Heap/Heap.h"

using namespace std;

TEST(HeapTest, Constructor){
    EXPECT_NO_THROW(Heap* myHeap = new Heap());
}

TEST(HeapTest, Insert) {
    Heap* myHeap = new Heap();
    EXPECT_NO_THROW(myHeap.insert(100));
}


