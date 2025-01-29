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

void DoublyLinkedList::prepend(int value){
    Node* newNode = new Node(value);
    if(head){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        length++;
    }
    else {
        head = newNode;
        tail = newNode;
        length = 1;
    }
}

void DoublyLinkedList::deleteFirst(){
    if(length > 1){
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    } else if (length == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
        length = 0;
    } else {
        return;
    }
}

Node* DoublyLinkedList::get(int index){
    if (index == 0){
        return head;
    } else if (index >= length) {
        return nullptr;
    } else {
        Node* temp;
        if((length / 2) - 1 >= index){
            // head is closer
            temp = head;
            int i = 0;
            while(i < index){
                temp = temp->next;
                i++;
            }
        } else {
            // tail is closer
            temp = tail;
            int i = length -1;
            while(i > index){
                temp = temp->prev;
                i--;
            }
        }
        return temp;
    }
}

void DoublyLinkedList::set(int index, int value){
    if(length == 0){
        head = new Node(value);
        tail = head;
        length++;
    }
    else if (index == 0){
        head->value = value;
    } else if (index >= length) {
        return;
    } else {
        Node* temp;
        if((length / 2) - 1 >= index){
            // head is closer
            temp = head;
            int i = 0;
            while(i < index){
                temp = temp->next;
                i++;
            }
        } else {
            // tail is closer
            temp = tail;
            int i = length -1;
            while(i > index){
                temp = temp->prev;
                i--;
            }
        }
        temp->value = value;
    }
}

void DoublyLinkedList::insert(int index, int value){
    if (length == 0) {
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    } else if(index >= length) {
        append(value);
    } else if(index <= 0){
        prepend(value);
    } else {
        Node* temp;
        int i;
        if((length / 2) - 1 >= index){
            // head is closer
            temp = head;
            i = 0;
            while(i < index){
                temp = temp->next;
                i++;
            }
        } else {
            // tail is closer
            temp = tail;
            i = length - 1;
            while(i > index){
                temp = temp->prev;
                i--;
            }
        }
        Node* newNode = new Node(value);
        Node* swap = temp->prev;
        
        swap->next = newNode;
        newNode->prev = swap;

        newNode->next = temp;
        temp->prev = newNode;
        length++;
    }
}

Node* DoublyLinkedList::getHead() {
    return head;
}

Node* DoublyLinkedList::getTail(){
    return tail;
}

int DoublyLinkedList::getLength(){
    return length;
}
