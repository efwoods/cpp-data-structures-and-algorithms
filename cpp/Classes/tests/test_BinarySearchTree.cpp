#include <gtest/gtest.h>
#include <iostream>
#include "../BinarySearchTree/BinarySearchTree.h"

TEST(BinarySearchTreeTest, Constructor){
    EXPECT_NO_THROW({
        BinarySearchTree* bst = new BinarySearchTree();
    });
    BinarySearchTree* bst = new BinarySearchTree();
    EXPECT_TRUE(bst->root == nullptr);
}

TEST(BinarySearchTreeTest, Insert){
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(52);
    bst->insert(82);

    bst->insert(27);

    EXPECT_TRUE(bst->root->left->right->value == 27);
}