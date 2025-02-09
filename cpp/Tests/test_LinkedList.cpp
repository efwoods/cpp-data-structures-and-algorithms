#include <gtest/gtest.h>
#include "../Classes/LinkedList/LinkedList.h"
#include <iostream>

using namespace std;

// Test the constructor
TEST(LinkedListTest, Constructor){
    LinkedList* list = new LinkedList(10);
    EXPECT_EQ(list->get(0)->value, 10);
}

TEST(LinkedListTest, BubbleSortTest){
    // Populating the Linked List
    LinkedList list(5);
    list.append(2);
    list.append(9);
    list.append(1);
    list.append(5);
    list.append(6);

    list.bubbleSort();

    int expectedValues[] = {1, 2, 5, 5, 6, 9};

    for (int i = 0; i < list.getLength(); i++){
        EXPECT_TRUE(list.get(i)->value == expectedValues[i]);
    }
}

TEST(LinkedListTest, SelectionSortTest){
    // Populating the Linked List
    LinkedList list(5);
    list.append(2);
    list.append(9);
    list.append(1);
    list.append(5);
    list.append(6);

    list.selectionSort();

    int expectedValues[] = {1, 2, 5, 5, 6, 9};

    list.printList();

    for (int i = 0; i < list.getLength(); i++){
        EXPECT_TRUE(list.get(i)->value == expectedValues[i]);
    }
}

TEST(LinkedListTest, InsertionSortTest){
    // Populating the Linked List
    LinkedList list(5);
    list.append(2);
    list.append(9);
    list.append(1);
    list.append(5);
    list.append(6);

    list.insertionSort();

    int expectedValues[] = {1, 2, 5, 5, 6, 9};

    list.printList();

    for (int i = 0; i < list.getLength(); i++){
        EXPECT_TRUE(list.get(i)->value == expectedValues[i]);
    }
}

TEST(LinkedListTest, MergeTest){
    cout << "TEST(LinkedListTest, MergeTest)" << endl;
    // Populating the Linked List
    LinkedList list(1);
    list.append(3);
    list.append(5);

    // Populating the Other List
    LinkedList otherList(2);
    otherList.append(4);
    otherList.append(6);

    list.merge(otherList);

    vector<int> expected_values = {1, 2, 3, 4, 5, 6};
    
    for (auto val : expected_values){
        // cout << "val:" << val << "\n";
        // cout << "list.get(val -1)->value: " << list.get(val - 1)->value << "\n\n";

        EXPECT_TRUE(list.get(val - 1)->value == val);
    }
    // list.printList();

    list.~LinkedList();
    otherList.~LinkedList();

    // cout << "Testing empty first list" << endl;

    new (&list) LinkedList(0);
    list.deleteFirst();

    new (&otherList) LinkedList(5);

    EXPECT_TRUE(list.getLength() == 0);

    list.merge(otherList);

    expected_values = {5};

    for (int i = 0; i < list.getLength(); i++){
        cout << "val:" << i << "\n";
        cout << "list.get(val -1)->value: " << list.get(i)->value << "\n\n";
        EXPECT_TRUE(list.get(i)->value == expected_values[i]);
    }
    list.printList();

    EXPECT_TRUE(list.getLength() == 1);
    EXPECT_TRUE(list.getHead()->value == 5);
    EXPECT_TRUE(list.getTail()->value == 5);
}

void testPrint(){
    // Testing print statements
    LinkedList* myLinkedList = new LinkedList(4);
    myLinkedList->getHead();
    myLinkedList->getTail();
    myLinkedList->getLength();

    myLinkedList->printList();
}

void printTestAppend(){
    // Testing Append
    LinkedList* myAppendedList = new LinkedList(1);
    myAppendedList->printList();

    myAppendedList->append(2);
    myAppendedList->printList();
    myAppendedList->~LinkedList();
}

void printTestDeleteLast(){
    // Testing DeleteLast
    LinkedList* myList = new LinkedList(1);
    myList->append(2);
    myList->printList();

    cout << '\n';

    myList->deleteLast();
    myList->printList();
    
    myList->deleteLast();
    myList->printList();

    myList->deleteLast();
    myList->printList();

    myList->~LinkedList();
}

void printTestPrepend(){
    // Testing Prepend:
    LinkedList* myList = new LinkedList(2);
    myList->printList();

    myList->prepend(1);
    myList->printList();

    myList->deleteLast();
    myList->deleteLast();
    myList->printList();

    myList->prepend(1);
    myList->printList();

    myList->~LinkedList();
}

void printTestDeleteFirst(){
    // Testing Delete First
    LinkedList* myList = new LinkedList(1);
    myList->append(2);
    myList->printList();

    cout << "\n";

    // Delete 1
    myList->deleteFirst();
    myList->printList();

    cout << "\n";

    // Delete 2
    myList->deleteFirst();
    myList->printList();

    cout << "\n";

    // Does not delete
    myList->deleteFirst();
    myList->printList();

    myList->~LinkedList();
}

void printTestInsert(){
    // Testing Insert
    LinkedList* myList = new LinkedList(1);
    myList->deleteFirst();
    myList->printList();

    cout << "Empty List." << "\n\n";

    myList->insert(0,1); // insert into empty LinkedList
    myList->printList();

    cout << "\n";

    myList->insert(2, 2); // insert at end of list
    myList->printList();

    cout << "\n";

    myList->insert(0, 0); // insert at beginning of list
    myList->printList();

    cout << "\n";

    myList->insert(1, 3); // insert after index == 1; values: 0, 3, 1, 2
    myList->printList();

    myList->~LinkedList();
}

void printTestDeleteNode(){
    // Testing Delete Node
    LinkedList *myList = new LinkedList(1);
    myList->printList();
    cout << "\n";

    // Testing delete length of 1 @ index of node index;
    myList->deleteNode(0);
    myList->printList();
    cout << "Empyt List." << "\n";
    cout << "\n";

    // Testing delete length of 1 @ index less than node index;
    myList->append(1);
    myList->printList();
    cout << "\n";

    myList->deleteNode(-1);
    myList->printList();
    cout << "Empyt List." << "\n";
    cout << "\n";

    // Testing delete length of 1 @ index greather than node index;
    myList->append(1);
    myList->printList();
    cout << "\n";

    myList->deleteNode(1);
    myList->printList();
    cout << "Empyt List." << "\n";
    cout << "\n";

    myList->append(1);
    myList->append(2);
    myList->printList();
    cout << "\n";

    // Delete first node of 2 nodes
    myList->deleteNode(0);
    myList->printList();
    cout << "\n";

    // Reset to: 1, 2
    myList->prepend(1);
    myList->printList();
    cout << "\n";

    // Delete last of 2 nodes
    myList->deleteNode(1);
    myList->printList();
    cout << "\n";

    // Reset to: 0, 1, 2
    myList->prepend(0);
    myList->append(2);
    myList->printList();
    cout << "\n";

    // Testing Delete index 1 (this is value 1) to: 0, 2
    myList->deleteNode(1);
    myList->printList();
    cout << "\n";

    myList->~LinkedList();
}

void printTestReverseList(){
    // Test Reversing the List
    LinkedList* myList = new LinkedList(1);
    myList->printList();
    cout << "\n";

    myList->deleteFirst();
    myList->printList();
    cout << "Empty List.\n" << "\n";

    // Testing Reversing an empty List
    myList->reverse();
    myList->printList();
    cout << "Empty List.\n" << "\n";

    myList->append(0);
    myList->printList();
    cout << "\n";

    // Testing reversing a singleton list;
    myList->reverse();
    myList->printList();
    cout << "\n";

    // Reset: 0, 1
    myList->append(1);
    myList->printList();
    cout << "\n";

    // Testing reversing a two-element list from 0, 1 to 1, 0;
    myList->reverse();
    myList->printList();
    cout << "\n";

    // Reset: 0, 1, 2
    myList->reverse();
    myList->append(2);
    myList->printList();
    cout << "\n";

    // Testing reversing a three element list from 0, 1, 2 to 2, 1, 0;
    myList->reverse();
    myList->printList();
    cout << "\n";

    // Reset to 0, 1, 2, 3
    myList->reverse();
    myList->append(3);
    myList->printList();
    cout << "\n";

    // Testing reversing a 4 element list from 0, 1, 2, 3 to 3, 2, 1, 0
    myList->reverse();
    myList->printList();
    cout << "\n";

    // Rest to 0, 1, 2, 3, 4
    myList->prepend(4);
    myList->reverse();
    myList->printList();
    cout << "\n";

    // Testing reversing a 5 element list from 0 -> 4 to 4, 3, 2, 1, 0
    myList->reverse();
    myList->printList();
    cout << "\n";

    myList->~LinkedList();
}

TEST(LinkedListTest, DeleteOutOfBoundsTest){
        // cout << "\n------ LinkedList Test: DeleteOutOfBounds ------\n";

        LinkedList ll(1);
        ll.append(2);
        
        // cout << "Before: ";
        ll.printList();
        
        ll.deleteNode(2);
        
        // cout << "deleteNode( 2 )\n";
        
        // cout << "After: ";
        ll.printList();
        
        EXPECT_TRUE(ll.getLength() == 2);
}

TEST(LinkedListTest, DeleteIndexNegativeTest){
        // cout << "\n------ LinkedList Test: DeleteInvalidIndexNegative ------\n";

        LinkedList ll(1);
        
        cout << "Before: ";
        ll.printList();
        
        ll.deleteNode(-1);
        
        cout << "deleteNode( -1 )\n";
        
        cout << "After: ";
        ll.printList();
        
        EXPECT_TRUE(ll.getLength() == 1);
        // checkTestResult(ll.getLength() == 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    // Custom Tests
    // testPrint();
    // printTestAppend();
    // printTestDeleteLast();
    // printTestPrepend();
    // printTestDeleteFirst();
    // printTestInsert();
    // printTestDeleteNode();
    // printTestReverseList();

    // GTests
    return RUN_ALL_TESTS();

}