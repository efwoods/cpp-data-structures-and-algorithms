#include <gtest/gtest.h>
#include "../Classes/Stack/Stack.h"
#include <iostream>
#include <limits.h>

using namespace std;

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

TEST(StackTest, Push){
    Stack* stack = new Stack(0);
    EXPECT_TRUE(stack != nullptr);

    stack->push(1);
    EXPECT_TRUE(stack->getTop()->value == 1);
    EXPECT_TRUE(stack->getHeight() == 2);
}

TEST(StackTest, Pop){
    Stack* stack = new Stack(0);
    EXPECT_TRUE(stack != nullptr);

    int poppedValue = stack->pop();
    EXPECT_TRUE(poppedValue == 0);
    poppedValue = stack->pop();
    EXPECT_TRUE(poppedValue == INT_MIN);
}