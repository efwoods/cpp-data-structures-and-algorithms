#include <gtest/gtest.h>
#include <iostream>
#include "../BinarySearchTree/BinarySearchTree.h"

TEST(BinarySearchTreeTest, Constructor){
    EXPECT_NO_THROW({
        BinarySearchTree* bst = new BinarySearchTree();
    });
}