#include <gtest/gtest.h>
#include "../Stack/Stack.h"
#include <iostream>

TEST(StackTest, Constructor){
    Stack* stack = new Stack(0);
    EXPECT_TRUE(stack != nullptr);
}

TEST(StackTest, GetTop){
    Stack* stack = new Stack(0);
    EXPECT_TRUE(stack->getTop() != nullptr);
}

TEST(StackTest, PrintStatements){
    Stack* stack = new Stack(0);
    stack->printStack();
    stack->getHeight();
}
