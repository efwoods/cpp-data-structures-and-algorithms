#include <gtest/gtest.h>
#include "../Queue/Queue.h"
#include <iostream>
#include <limits.h>

using namespace std;

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

TEST(QueueTest, Enqueue){
    Queue* queue = new Queue(0);
    EXPECT_NO_THROW({
        queue->enqueue(1);
    });
    EXPECT_TRUE(queue->getFirst()->value == 0);
    EXPECT_TRUE(queue->getLast()->value == 1);
    EXPECT_TRUE(queue->getLength() == 2);
}

TEST(QueueTest, dequeue){
    Queue* queue = new Queue(0);
    int dequeueResult;

    cout << "*** Test Singleton Queue ***" << endl;
    EXPECT_NO_THROW({
        dequeueResult = queue->dequeue();
    });
    EXPECT_TRUE(dequeueResult == 0);

    cout << "*** Test Empty Queue ***" << endl;
    EXPECT_TRUE(queue->dequeue() == INT_MIN);


    cout << "*** Test Two-element Queue ***" << endl;
    EXPECT_NO_THROW({
        queue->enqueue(0);
        queue->enqueue(1);
    });

    EXPECT_TRUE(queue->dequeue() == 0);
    EXPECT_TRUE(queue->dequeue() == 1);
    EXPECT_TRUE(queue->dequeue() == INT_MIN);
}
