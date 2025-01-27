#include <gtest/gtest.h>
#include "../DoublyLinkedList.h"
#include <iostream>

using namespace std;

// Test the constructor
TEST(DoublyLinkedListTest, Constructor){
    DoublyLinkedList* DLL = new DoublyLinkedList(10);
    DLL->printList();
}

TEST(DoublyLinkedListTest, Append){
    DoublyLinkedList* DLL = new DoublyLinkedList(1);
    DLL->append(2);
    DLL->printList();
}

TEST(DoublyLinkedListTest, DeleteLast){
    DoublyLinkedList* DLL = new DoublyLinkedList(1);
    DLL->append(2);
    DLL->printList();
    // Expect 1, 2

    DLL->deleteLast(); // Delete "2" from two-item list
    DLL->printList();
    // Expect 1

    DLL->deleteLast(); // Delete "1" from singleton list 
    DLL->printList();
    // Expect Empty;

    DLL->deleteLast(); // Delete nothing from empty list
    DLL->printList();
    // Expect Empty;
}

TEST(DoublyLinkedListTest, Prepend){
    DoublyLinkedList* DLL = new DoublyLinkedList(1);
    DLL->prepend(0);
    DLL->printList();
}

TEST(DoublyLinkedListTest, DeleteFirst){
    DoublyLinkedList* DLL = new DoublyLinkedList(0);
    DLL->append(1);
    DLL->printList();

    DLL->deleteFirst(); // Delete "0" from two-item list
    DLL->printList();

    DLL->deleteFirst(); // Delete "1" from singleton list
    DLL->printList();

    DLL->deleteFirst(); // Delete nothing from empty list
    DLL->printList();
}

TEST(DoublyLinkedListTest, Get){
    cout << "Testing DoublyLinkedList Get:" << endl;
    DoublyLinkedList* list = new DoublyLinkedList(1);
    list->append(2);
    list->append(3);
    list->append(4);
    list->append(5);
    list->append(6);

    list->printList();
    // cout << list->get(0)->value << endl;

    Node* nodeResult;
    for (int i = 0; i < 6; i++){
        nodeResult = list->get(i);
        cout << "i: " << i << "\n" <<
        "Node Value: " << nodeResult->value << "\n" << endl;
        EXPECT_TRUE(i+1 == nodeResult->value);
    }

    DoublyLinkedList* emptyList = new DoublyLinkedList(1);
    emptyList->deleteLast();
    emptyList->printList(); // List is empty
    EXPECT_TRUE(emptyList->getHead() == nullptr);

    nodeResult = emptyList->get(7); // get index is out of range; nodeResult should be nullptr;

    EXPECT_TRUE(nodeResult == nullptr);
}