#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;
DoublyLinkedList::DoublyLinkedList(int value){
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

DoublyLinkedList::~DoublyLinkedList(){
    Node* temp = head;
    while(head){
        head = head->next;
        delete temp;
        temp = head;
    }
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

void DoublyLinkedList::deleteNode(int index){
    if (length == 0){
        return;
    } else if (index >= length - 1) {
        deleteLast();
    } else if (index <= 0){
        deleteFirst();
    } else {
        int i = 0;
        Node* temp;
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
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        length--;
    }
}

void DoublyLinkedList::reverse(){
    if(length < 2){
        return;
    }
    Node* current = head->next;
    Node* temp;
    
    while(current != tail){
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = current->prev;
    }
    temp = head;
    head = current;
    tail = temp;
    head->next = head->prev;
    head->prev = nullptr;
    tail->prev = tail->next;
    tail->next = nullptr;
}

bool DoublyLinkedList::isPalindrome(){
    if (length < 2){
        return true;
    }
    Node* forwardNode = head;
    Node* backwardNode = tail;

    for(int i = 0; i < length / 2; i++){
        if(forwardNode->value != backwardNode->value){
            return false;
        }
        forwardNode = forwardNode->next;
        backwardNode = backwardNode->prev;
    }
    return true;
}

int DoublyLinkedList::numSwapsPerSide(int length){
    int numSwapsPerSide;
    if((length / 2) % 2 == 0){ // 1 center node
        // There are two nodes per pair & two sides;
        // Removing the number of central nodes
        // and dividing by 4;
        numSwapsPerSide = (length - 1) / 4;
    } else { // 3 center nodes
        numSwapsPerSide = (length - 3) / 4;
    }
    return numSwapsPerSide;
}

void DoublyLinkedList::swapPairs(){
    if(length < 2){
        return;
    }
    // check for even or odd length
    if (length % 2 == 1){
        // odd; check for even or odd remainder
        int numSwaps = numSwapsPerSide(length);
        Node* temp;
        Node* first = head;
        Node* second = head->next;
        Node* tail_temp;
        Node* ultimate = tail;
        Node* penultimate = tail->next;
        for(int i = 0; i < numSwaps; i++){
            // handling before the midpoint
            temp = first;
            first->next = second->next;
            first->prev = second->prev;
            second->next = temp->next;
            second->prev = temp->prev;
            first = first->next;
            second = first->next;
            
            // handling after the midpoint
            tail_temp = ultimate;
            ultimate->prev = penultimate->prev;
            ultimate->next = penultimate->next;
            penultimate->next = tail_temp->next;
            penultimate->prev = tail_temp->prev;
            ultimate = ultimate->prev;
            penultimate = ultimate->prev;
        }
    } else {
        // even; swap two from head to tail
        Node* first = head;
        Node* second = first->next;
        for(int i = 0; i < length/2; i++){
            Node* temp = new Node(first->value);
            temp->next = first->next;
            temp->prev = first->prev;

            first->next = second->next;
            first->prev = second;
            second->prev = temp->prev;
            second->next = first;

            // if (i == 0){ // save head information
            //     Node* head_pointer = new Node(second->value);
            //     head_pointer->prev = second; // this is reserving the address of the head; this will be updated to nullptr in the head
            //     head_pointer->next = second->next; // points at the second node
            // }

            // if (first->next == nullptr){
            //     // first is at tail; update the tail
            //     tail->prev = first->prev;
            //     tail = first;

            //     // update the head;
            //     head->next = head_pointer->next;
            //     head = head_pointer->prev;
            //     delete head_pointer;
            //     delete temp;
            //     break;
            // } else {
            //     first = first->next;
            //     second = first->next;
            //     delete temp;
            // }

            // store potential tail
            // temp->next = first->next;
            // temp->prev = first->prev;

            // first = first->next; // move to the next position

            // if(i == 0){ // handle head
            //     head->prev = second->prev;
            //     head->next = second->next;
            // }

            // if(first == nullptr){ // handle tail
            //     tail->next = temp->next;
            //     tail->prev = temp->prev;
            //     delete temp;
            //     break;
            // } else { // continue to next pair to swap
            //     second = first->next;
            //     delete temp;
            // }
        }
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
