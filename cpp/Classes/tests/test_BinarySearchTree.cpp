#include <gtest/gtest.h>
#include <iostream>
#include "../BinarySearchTree/BinarySearchTree.h"

using namespace std;

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

TEST(BinarySearchTreeTest, Contains){
    BinarySearchTree* bst = new BinarySearchTree();
    cout << "*** Test Empty Binary Search Tree ***" << endl;
    EXPECT_FALSE(bst->contains(-1));

    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(52);
    bst->insert(82);
    bst->insert(27);

    cout << "*** Test Binary Search Tree Value is Not Contained ***" << endl;
    EXPECT_FALSE(bst->contains(-1));

    cout << "*** Test Binary Search Tree Value is Contained ***" << endl;
    EXPECT_TRUE(bst->contains(27));
}

TEST(BinarySearchTreeTest, Destroy){
    BinarySearchTree* bst = new BinarySearchTree();
    EXPECT_NO_THROW({
        bst->insert(2);
        bst->insert(1);
        bst->insert(3);
    });

    EXPECT_NO_THROW({
        bst->destroy(bst->root);
    });
}

TEST(BinarySearchTreeTest, Deconstructor){
    BinarySearchTree* bst = new BinarySearchTree();
    EXPECT_NO_THROW(bst->~BinarySearchTree());
}

TEST(BinarySearchTreeTest, rContains){
    // Initialize BST data
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(27);
    bst->insert(52);
    bst->insert(82);

    cout << "\nBST Contains 27:\n";
    cout << bst->rContains(27);

    cout << "\nBST Contains 17:\n";
    cout << bst->rContains(17);

    
}