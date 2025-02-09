#include <gtest/gtest.h>
#include "../Classes/DoublyLinkedList/DoublyLinkedList.h"
#include <iostream>

using namespace std;

// Test the constructor
TEST(DoublyLinkedListTest, Constructor){
    DoublyLinkedList* DLL = new DoublyLinkedList(10);
    DLL->printList();
}

TEST(DoublyLinkedListTest, Destructor){
    DoublyLinkedList* list = new DoublyLinkedList(0);
    EXPECT_TRUE(list->getLength() == 1);
    list->~DoublyLinkedList();
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

TEST(DoublyLinkedListTest, Set){
    DoublyLinkedList* list = new DoublyLinkedList(0);
    list->deleteFirst();
    EXPECT_TRUE(list->getHead() == nullptr);

    list->set(0, 1);
    EXPECT_TRUE(list->get(0)->value == 1);

    list->set(0, 2);
    EXPECT_TRUE(list->get(0)->value == 2);

    list->set(12, 3);
    EXPECT_TRUE(list->get(0)->value == 2);

}

TEST(DoublyLinkedListTest, Insert){
    DoublyLinkedList* list = new DoublyLinkedList(0);
    
    // Set empty list
    list->deleteFirst();
    EXPECT_TRUE(list->getHead() == nullptr);

    // Test empty list length less
    list->insert(-1, 0);
    EXPECT_TRUE(list->getHead()->value == 0);

    // Set empty list
    list->deleteFirst();
    EXPECT_TRUE(list->getHead() == nullptr);

    // Test empty list length equal
    list->insert(0, 0);
    EXPECT_TRUE(list->getHead()->value == 0);

    // Set empty list
    list->deleteFirst();
    EXPECT_TRUE(list->getHead() == nullptr);

    // Test empty list length greater
    list->insert(6, 0);
    EXPECT_TRUE(list->getHead()->value == 0);


    // Test list index == length
    list->insert(1, 1);
    EXPECT_TRUE(list->get(1)->value == 1);

    // Test list index > length
    list->insert(15, 2);
    EXPECT_TRUE(list->get(2)->value == 2);

    // Test list index < length
    list->insert(-1, -1);
    EXPECT_TRUE(list->getHead()->value == -1);

    list->printList();
    // Test insert at index closer to head
    list->insert(1, 1);
    EXPECT_TRUE(list->get(1)->value == 1);
    list->printList();

    // Test insert at index closer to tail
    list->insert(3, 3);
    EXPECT_TRUE(list->get(3)->value == 3);

    list->printList();
}

TEST(DoublyLinkedListTest, DeleteNode){
    DoublyLinkedList* list = new DoublyLinkedList(1);
    
    // Test delete singleton list
    list->deleteNode(0);
    EXPECT_TRUE(list->getHead() == nullptr);

    // Test delete empy list
    list->deleteNode(0);
    EXPECT_TRUE(list->getHead() == nullptr);

    // Populate for testing
    list->insert(0, 0);
    list->insert(1, 1);
    list->insert(2, 2);

    EXPECT_TRUE(list->get(0)->value == 0);
    EXPECT_TRUE(list->get(1)->value == 1);
    EXPECT_TRUE(list->get(2)->value == 2);

    // Test delete middle
    list->deleteNode(1);
    EXPECT_TRUE(list->get(0)->value == 0);
    EXPECT_TRUE(list->get(1)->value == 2);

    // Test delete last greater than length
    list->deleteNode(1234);
    EXPECT_TRUE(list->get(0)->value == 0);
    EXPECT_TRUE(list->get(1) == nullptr);

    // Populate for testing
    list->append(1);
    EXPECT_TRUE(list->get(0)->value == 0);
    EXPECT_TRUE(list->get(1)->value == 1);

    // Test delete first less than length
    list->deleteNode(-1342);
    EXPECT_TRUE(list->get(0)->value == 1);
    EXPECT_TRUE(list->get(1) == nullptr);

    // Populate list for testing
    list->set(0, 0);
    list->insert(1, 1);
    list->insert(2, 2);

    EXPECT_TRUE(list->get(0)->value == 0);
    EXPECT_TRUE(list->get(1)->value == 1);
    EXPECT_TRUE(list->get(2)->value == 2);

    // Test delete first by index
    list->deleteNode(0);
    EXPECT_TRUE(list->get(0)->value == 1);
    EXPECT_TRUE(list->get(1)->value == 2);

    // Test delete last by index
    list->deleteNode(1);
    EXPECT_TRUE(list->get(0)->value == 1);
    EXPECT_TRUE(list->get(1) == nullptr);
}

TEST(DoublyLinkedListTest, Reverse){
    // Create list and populate
    DoublyLinkedList* list = new DoublyLinkedList(0);
    list->append(1);
    list->append(2);

    EXPECT_TRUE(list->get(0)->value == 0);
    EXPECT_TRUE(list->get(1)->value == 1);
    EXPECT_TRUE(list->get(2)->value == 2);

    // Test Reverse
    list->reverse();

    EXPECT_TRUE(list->get(0)->value == 2);
    EXPECT_TRUE(list->get(1)->value == 1);
    EXPECT_TRUE(list->get(2)->value == 0);
    EXPECT_TRUE(list->getHead()->value == 2);
    EXPECT_TRUE(list->getTail()->value == 0);
}

TEST(DoublyLinkedListTest, IsPalindrome){
    DoublyLinkedList list(0);

    list.append(1);
    list.append(2);

    EXPECT_TRUE(list.get(0)->value == 0);
    EXPECT_TRUE(list.get(1)->value == 1);
    EXPECT_TRUE(list.get(2)->value == 2);

    // Test Non-Palindrome
    EXPECT_FALSE(list.isPalindrome());

    // Populate palindrome
    list.set(2, 0);
    EXPECT_TRUE(list.get(0)->value == 0);
    EXPECT_TRUE(list.get(1)->value == 1);
    EXPECT_TRUE(list.get(2)->value == 0);

    // Test Palindrome
    EXPECT_TRUE(list.isPalindrome());

    list.deleteLast();
    list.deleteLast();

    // Test singleton list
    EXPECT_TRUE(list.getLength() == 1);
    EXPECT_TRUE(list.isPalindrome());

    // Test empty list
    list.deleteFirst();
    EXPECT_TRUE(list.getLength() == 0);
    EXPECT_TRUE(list.isPalindrome());
}

TEST(DoublyLinkedListTest, SwapPairs){
    DoublyLinkedList* list = new DoublyLinkedList(0);
    cout << "*** Testing Length 1 ***" << endl;
    list->swapPairs();
    EXPECT_TRUE(list->getLength() == 1);

    cout << "*** Testing Length 2 ***" << endl;
    list->append(1);
    list->swapPairs();
    EXPECT_TRUE(list->getLength() == 2);

    cout << "*** Testing Length 3 ***" << endl;
    list->set(0, 0);
    list->set(1, 1);
    list->append(2);
    list->swapPairs();
    EXPECT_TRUE(list->getLength() == 3);

    // Ensure correct head
    Node *test_head = list->getHead();
    EXPECT_TRUE(test_head->next == list->get(1));
    EXPECT_TRUE(test_head->prev == nullptr);
    EXPECT_TRUE(test_head->value == list->get(0)->value);

    // Ensure correct tail
    Node *test_tail = list->getTail();
    EXPECT_TRUE(test_tail->next == nullptr);
    EXPECT_TRUE(test_tail->prev == list->get(1));
    EXPECT_TRUE(test_tail->value == list->get(2)->value);

    // Ensure Correct Values
    EXPECT_TRUE(list->get(0)->value == 1);
    EXPECT_TRUE(list->get(1)->value == 0);
    EXPECT_TRUE(list->get(2)->value == 2);

    cout << "*** Testing Length 4 ***" << endl;
    list->set(0, 0);
    list->set(1, 1);
    list->set(2, 2);
    list->append(3);
    list->swapPairs();
    EXPECT_TRUE(list->getLength() == 4);

    // Ensure correct head
    test_head = list->getHead();
    EXPECT_TRUE(test_head->next == list->get(1));
    EXPECT_TRUE(test_head->prev == nullptr);
    EXPECT_TRUE(test_head->value == list->get(0)->value);

    // Ensure correct tail
    test_tail = list->getTail();
    EXPECT_TRUE(test_tail->next == nullptr);
    EXPECT_TRUE(test_tail->prev == list->get(2));
    EXPECT_TRUE(test_tail->value == list->get(3)->value);

    // Ensure correct values
    EXPECT_TRUE(list->get(0)->value == 1);
    EXPECT_TRUE(list->get(1)->value == 0);
    EXPECT_TRUE(list->get(2)->value == 3);
    EXPECT_TRUE(list->get(3)->value == 2);

    cout << "*** Testing Length 5 ***" << endl;
    list->set(0, 0);
    list->set(1, 1);
    list->set(2, 2);
    list->set(3, 3);
    list->append(4);
    list->swapPairs();
    EXPECT_TRUE(list->getLength() == 5);

        // Ensure correct head
    test_head = list->getHead();
    EXPECT_TRUE(test_head->next == list->get(1));
    EXPECT_TRUE(test_head->prev == nullptr);
    EXPECT_TRUE(test_head->value == list->get(0)->value);

    // Ensure correct tail
    test_tail = list->getTail();
    EXPECT_TRUE(test_tail->next == nullptr);
    EXPECT_TRUE(test_tail->prev == list->get(3));
    EXPECT_TRUE(test_tail->value == list->get(4)->value);

    // Ensure correct values
    EXPECT_TRUE(list->get(0)->value == 1);
    EXPECT_TRUE(list->get(1)->value == 0);
    EXPECT_TRUE(list->get(2)->value == 3);
    EXPECT_TRUE(list->get(3)->value == 2);
    EXPECT_TRUE(list->get(4)->value == 4);

    cout << "*** Testing Length 6 ***" << endl;
    list->set(0, 0);
    list->set(1, 1);
    list->set(2, 2);
    list->set(3, 3);
    list->set(4, 4);
    list->append(5);
    list->swapPairs();
    EXPECT_TRUE(list->getLength() == 6);

    // Ensure correct head
    test_head = list->getHead();
    EXPECT_TRUE(test_head->next == list->get(1));
    EXPECT_TRUE(test_head->prev == nullptr);
    EXPECT_TRUE(test_head->value == list->get(0)->value);

    // Ensure correct tail
    test_tail = list->getTail();
    EXPECT_TRUE(test_tail->next == nullptr);
    EXPECT_TRUE(test_tail->prev == list->get(4));
    EXPECT_TRUE(test_tail->value == list->get(5)->value);

    // Ensure correct values
    EXPECT_TRUE(list->get(0)->value == 1);
    EXPECT_TRUE(list->get(1)->value == 0);
    EXPECT_TRUE(list->get(2)->value == 3);
    EXPECT_TRUE(list->get(3)->value == 2);
    EXPECT_TRUE(list->get(4)->value == 5);
    EXPECT_TRUE(list->get(5)->value == 4);

    cout << "*** Testing Length 7 ***" << endl;
    list->set(0, 0);
    list->set(1, 1);
    list->set(2, 2);
    list->set(3, 3);
    list->set(4, 4);
    list->set(5, 5);
    list->append(6);
    list->swapPairs();
    EXPECT_TRUE(list->getLength() == 7);

    // Ensure correct head
    test_head = list->getHead();
    EXPECT_TRUE(test_head->next == list->get(1));
    EXPECT_TRUE(test_head->prev == nullptr);
    EXPECT_TRUE(test_head->value == list->get(0)->value);

    // Ensure correct tail
    test_tail = list->getTail();
    EXPECT_TRUE(test_tail->next == nullptr);
    EXPECT_TRUE(test_tail->prev == list->get(5));
    EXPECT_TRUE(test_tail->value == list->get(6)->value);

    // Ensure correct values
    EXPECT_TRUE(list->get(0)->value == 1);
    EXPECT_TRUE(list->get(1)->value == 0);
    EXPECT_TRUE(list->get(2)->value == 3);
    EXPECT_TRUE(list->get(3)->value == 2);
    EXPECT_TRUE(list->get(4)->value == 5);
    EXPECT_TRUE(list->get(5)->value == 4);
    EXPECT_TRUE(list->get(6)->value == 6);
}

TEST(DoublyLinkedListTest, GetInvalidIndex){
        // cout << "\n------- DLL Test: Get Invalid Index -------\n";
        
        DoublyLinkedList dll(5);
        dll.append(10);
        
        // cout << "Before get: ";
        // dll.printList();
        
        Node* result1 = dll.get(-1);
        Node* result2 = dll.get(2);
        
        // cout << "Value at index -1: " << ptrToNum(result1) << endl;
        // cout << "Value at index 2: " << ptrToNum(result2) << endl;
}