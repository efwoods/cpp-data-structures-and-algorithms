#include <gtest/gtest.h>
#include "../Queue/Queue.h"
#include <iostream>

TEST(QueueTest, Constructor){
    Queue* queue = new Queue(0);
    EXPECT_TRUE(queue != nullptr);
}

