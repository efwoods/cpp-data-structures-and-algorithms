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
