#include <gtest/gtest.h>
#include "../Queue/Queue.h"
#include <iostream>

TEST(QueueTest, Constructor){
    Queue* queue = new Queue(0);
    EXPECT_TRUE(queue != nullptr);
}

TEST(QueueTest, GetFirst){
    Queue* queue = new Queue(0);
    EXPECT_TRUE(queue->getFirst()->value == 0);
}

TEST(QueueTest, GetLast){
    Queue* queue = new Queue(0);
    EXPECT_TRUE(queue->getLast()->value == 0);
}

TEST(QueueTest, GetLength){
    Queue* queue = new Queue(0);
    EXPECT_TRUE(queue->getLength() == 1);
}

TEST(QueueTest, PrintQueue){
    Queue* queue = new Queue(0);
    EXPECT_NO_THROW({
        queue->printQueue();
    });
}