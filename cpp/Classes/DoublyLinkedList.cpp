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

void DoublyLinkedList::append(int value){
    Node* newNode = new Node(value);
    if(tail){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    } else {
        head = newNode;
        tail = newNode;
    }
    length++;
}

void DoublyLinkedList::deleteLast(){
    if(length > 1){
        Node* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
        length--;
    } else if (length == 1) {
        delete tail;
        head = nullptr;
        tail = nullptr;
        length = 0;
    } else {
        return;
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
