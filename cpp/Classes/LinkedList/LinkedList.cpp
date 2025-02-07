#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(int value){
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
}

LinkedList::~LinkedList() {
    Node* temp = head;
    while(head){
        head = head->next;
        delete temp;
        temp = head;
    }
}

void LinkedList::append(int value){
    Node* newNode = new Node(value);
    if(tail){
        tail->next = newNode;
        tail = newNode;
    } else {
        head = newNode;
        tail = newNode;
    }
    length++;
}
void LinkedList::deleteLast(){
    if(length > 1){
        Node* temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
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

void LinkedList::prepend(int value){
    Node* newNode = new Node(value);
    if(head){
        newNode->next = head;
        head = newNode;
        length++;
    }
    else {
        head = newNode;
        tail = newNode;
        length = 1;
    }
}

void LinkedList::deleteFirst(){
    Node* temp = head;
    if (length > 1){
        head = head->next;
        delete temp;
        length--;
    } else if (length == 1){
        delete tail;
        head = nullptr;
        tail = nullptr;
        length = 0;
    } else {
        return;
    }
}

Node* LinkedList::get(int index){
    if (index == 0){
        return head;
    } else if (index >= length) {
        return nullptr;
    } else {
        Node *temp = head;
        int i = 0;
        while(i < index){
            temp = temp->next;
            i++;
        }
        return temp;
    }
}

void LinkedList::set(int index, int value){
    if (length == 0){
        head = new Node(value);
        tail = head; 
        length++;
    } else if (index == 0){
        head->value = value;
    } else if (index >= length) {
        return;
    } else {
        Node *temp = head;
        int i = 0;
        while (i < index){
            temp = temp->next;
            i++;
        }
        temp->value = value;
    }
}

void LinkedList::insert(int index, int value){
    if (length == 0){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    } else if (index >= length) {
        append(value);
    } else if (index <= 0) {
        prepend(value);
    } else {
        int i = 0;
        Node* pre = head;
        Node* post = head;
        while (i < index){
            pre = post;
            post = post->next;
            i++;
        }
        pre->next = new Node(value);
        pre->next->next = post;
        length++;
    }
}

void LinkedList::deleteNode(int index){
    if (length == 0){
        return;
    } else if (index >= length - 1) {
        deleteLast();
    } else if (index <= 0){
        deleteFirst();
    } else {
        int i = 0;
        Node* pre = head;
        Node* post = head;
        while(i < index){
            pre = post;
            post = post->next;
            i++;
        }
        pre->next = post->next;
        delete post;
        length--;
    }
}

void LinkedList::reverse(){
    if (length <= 1){
        return;
    } else {
        Node* first = head;
        Node* last = tail;
        Node* penultimate;
        int temp;
        for (int i = 0; i < length/2; i++){
            temp = first->value;
            first->value = last->value;
            last->value = temp;
            first = first->next;
            penultimate = first;
            if (length > 3 && (i < (length/2 - 1))){
                while(penultimate->next != last){
                    penultimate = penultimate->next;
                }
                last = penultimate;
            }
        }
    }
}

void LinkedList::printList() {
    Node* temp = head;
    while(temp){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

Node* LinkedList::getHead() {
    return head;
}

Node* LinkedList::getTail(){
    return tail;
}

int LinkedList::getLength(){
    return length;
}

void LinkedList::bubbleSort(){
    if (length < 2){
        return;
    }
    Node* current = head;
    Node* sortUntil = tail;
    Node* prev;
    
    while(current != sortUntil){
        while(current != sortUntil){
            if (current->value > current->next->value){
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
            }
            if (current->next == sortUntil){
                prev = current;
            }
            current = current->next;
        }
        sortUntil = prev;
        current = head;
    }
}

void LinkedList::selectionSort(){
    if(length < 2){
        return;
    }

    Node* current = head;
    Node* traveler = head;
    int index = 0;
    while(current != tail){
        for(int i = index; i < length; i++){
            if (current->value > traveler->value){
                int temp = current->value;
                current->value = traveler->value;
                traveler->value = temp;
            }
            traveler = traveler->next;
        }
        current = current->next;
        traveler = current;
        index++;
    }
}

void LinkedList::insertionSort(){
    if(length < 2){
        return;
    }

    Node* sorted = head;
    Node* unsorted = head->next;
    int index = 1;
    while(sorted != tail){
        unsorted = sorted->next;
        int minimumValue = sorted->value;
        for (int i = index; i < length; i++){
            if (minimumValue > unsorted->value){
                int temp = minimumValue;
                minimumValue = unsorted->value;
                unsorted->value = temp;
            }
            unsorted = unsorted->next;
        }
        sorted->value = minimumValue;
        sorted = sorted->next;
        index++;
    }
}

void LinkedList::merge(LinkedList& otherList){
        
        Node* mergeNode = new Node(0);
        Node* current = mergeNode;
    
        while(length > 0 && otherList.getLength() > 0){
            if(head->value <= otherList.getHead()->value){
                current->next = new Node(head->value);
                deleteFirst();
            } else {
                current->next = new Node(otherList.getHead()->value);
                otherList.deleteFirst();
            }
            current = current->next;
        }
        if(length == 0){
            while(otherList.getLength() > 0){
                current->next = new Node(otherList.getHead()->value);
                otherList.deleteFirst();
                current = current->next;
            }
        } else if(otherList.getLength() == 0){
            while(length > 0){
                current->next = new Node(head->value);
                deleteFirst();
                current = current->next;
            }
        }

        head = mergeNode->next;
        delete(mergeNode);
        if(current != head){
            tail = current;
        } else { // both lists were empty & current did not traverse; head will be nullptr
            tail = nullptr;
        }

        // update length
        current = head;
        length = 0;
        while(current != nullptr){
            length++;
            current = current->next;
        }
}