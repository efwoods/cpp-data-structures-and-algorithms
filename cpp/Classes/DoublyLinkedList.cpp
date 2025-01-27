#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;
DoublyLinkedList::DoublyLinkedList(int value){
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

void DoublyLinkedList::printList() {
    Node* temp = head;
    while(temp){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void DoublyLinkedList::getHead() {
    cout << "Head: " << head->value << endl;
}

void DoublyLinkedList::getTail(){
    cout << "Tail: " << tail->value << endl;
}

void DoublyLinkedList::getLength(){
    cout << "Length: " << length << endl;
}
