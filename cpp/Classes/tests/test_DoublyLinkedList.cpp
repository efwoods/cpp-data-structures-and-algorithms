#include <gtest/gtest.h>
#include "../DoublyLinkedList.h"
#include <iostream>

using namespace std;

// Test the constructor
TEST(DoublyLinkedListTest, Constructor){
    DoublyLinkedList* DLL = new DoublyLinkedList(10);
    DLL->printList();
}