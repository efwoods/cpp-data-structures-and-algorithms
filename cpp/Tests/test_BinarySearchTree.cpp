#include <gtest/gtest.h>
#include <iostream>
#include "../Classes/BinarySearchTree/BinarySearchTree.h"

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

TEST(BinarySearchTreeTest, MinValue){
    // Initialize BST data
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(27);
    bst->insert(52);
    bst->insert(82);

    EXPECT_TRUE(bst->minValue(bst->root) == 18);
    cout << bst->minValue(bst->root) << endl;
}

TEST(BinarySearchTreeTest, getRoot){
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(0);
    EXPECT_TRUE(bst->getRoot()->value == 0);
    EXPECT_TRUE(bst->getRoot()->left == nullptr);
    EXPECT_TRUE(bst->getRoot()->right == nullptr);
}

TEST(BinarySearchTreeTest, deleteNode){
    // Initialize BST data
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(2);
    bst->insert(1);
    bst->insert(3);

    EXPECT_TRUE(bst->getRoot()->value == 2);
    EXPECT_TRUE(bst->getRoot()->left->value == 1);
    EXPECT_TRUE(bst->getRoot()->right->value == 3);

    bst->deleteNode(2);
    cout << bst->getRoot()->value << endl;
    cout << bst->getRoot()->left->value << endl;
    cout << bst->getRoot()->right << endl;

    EXPECT_TRUE(bst->getRoot()->value == 3);
    EXPECT_TRUE(bst->getRoot()->left->value == 1);
    EXPECT_TRUE(bst->getRoot()->right == nullptr);

    bst->deleteNode(3);
    EXPECT_TRUE(bst->getRoot()->value == 1);
    EXPECT_TRUE(bst->getRoot()->left == nullptr);
    EXPECT_TRUE(bst->getRoot()->right == nullptr);

    bst->deleteNode(1);
    EXPECT_TRUE(bst->getRoot() == nullptr);
}

TEST(BinarySearchTreeTest, BreadthFirstSearch){
    // Initialize BinarySearchTree
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(27);
    bst->insert(52);
    bst->insert(82);

    EXPECT_NO_THROW(bst->BFS());
}

TEST(BinarySearchTreeTest, DepthFirstSearchPreOrder){
    // Initialize BinarySearchTree
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(27);
    bst->insert(52);
    bst->insert(82);

    EXPECT_NO_THROW(bst->DFSPreOrder());
}

TEST(BinarySearchTreeTest, DepthFirstSearchPostOrder){
    // Initialize BinarySearchTree
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(27);
    bst->insert(52);
    bst->insert(82);

    EXPECT_NO_THROW(bst->DFSPostOrder());
}

TEST(BinarySearchTreeTest, DepthFirstSearchInOrder){
    // Initialize BinarySearchTree
    BinarySearchTree* bst = new BinarySearchTree();
    bst->insert(47);
    bst->insert(21);
    bst->insert(76);
    bst->insert(18);
    bst->insert(27);
    bst->insert(52);
    bst->insert(82);

    EXPECT_NO_THROW(bst->DFSInOrder());
}

TEST(BinarySearchTreeTest, RecursiveInsertIntoEmptyTree){
        cout << "\n----- Test: rInsert into Empty Tree -----\n";
        BinarySearchTree bst;
        int valueToInsert = 42;
        bst.rInsert(valueToInsert);
        EXPECT_TRUE(bst.rContains(42));
        // cout << "Inserting value " << valueToInsert << " into an empty tree.\n";
        // cout << "EXPECTED: Node with value 42 exists\n";
        // cout << (bst.rContains(42) ? "PASS\n" : "FAIL\n");
    }

TEST(BinarySearchTreeTest, RecursiveInsertUniqueValues){
        cout << "\n----- Test: rInsert Unique Values -----\n";
        BinarySearchTree bst;
        bst.rInsert(10);
        bst.rInsert(5);
        bst.rInsert(15);
        for(int i : {10, 5, 15}){
            EXPECT_TRUE(bst.rContains(i));
        }
        // cout << "Inserting unique values 10, 5, 15.\n";
        // cout << "EXPECTED: Each value is contained within the tree\n";
        // cout << (bst.rContains(10) && bst.rContains(5) && bst.rContains(15) ? "PASS\n" : "FAIL\n");
    }

TEST(BinarySearchTreeTest, RecursiveInsertDuplicateValue){
        cout << "\n----- Test: rInsert Duplicate Value -----\n";
        BinarySearchTree bst;
        bst.rInsert(10);
        EXPECT_NO_THROW(bst.rInsert(10)); // Attempting duplicate insert
        EXPECT_TRUE(bst.rContains(10));
        // cout << "Inserting value 10 twice.\n";
        // Note: rInsert does not explicitly handle duplicates; it depends on tree structure verification
        // cout << "EXPECTED: Tree structure unchanged by duplicate insert\n";
        // cout << (bst.rContains(10) ? "PASS\n" : "FAIL\n");
    }

TEST(BinarySearchTreeTest, RecursiveInsertToFormComplexStructure){
        cout << "\n----- Test: rInsert to Form Complex Structure -----\n";
        BinarySearchTree bst;
        // Inserting multiple values to form a more complex tree structure
        bst.rInsert(50);
        bst.rInsert(30);
        bst.rInsert(70);
        bst.rInsert(20);
        bst.rInsert(40);
        bst.rInsert(60);
        bst.rInsert(80);
        for(int i : {50, 30, 70, 20, 40, 60, 80}){
            EXPECT_TRUE(bst.contains(i));
        }
        // cout << "Inserting values to form a complex tree structure.\n";
        // cout << "EXPECTED: All inserted values are correctly contained within the tree\n";
        // cout << (bst.rContains(50) && bst.rContains(30) && bst.rContains(70) &&
                //  bst.rContains(20) && bst.rContains(40) && bst.rContains(60) &&
                //  bst.rContains(80) ? "PASS\n" : "FAIL\n");
    }